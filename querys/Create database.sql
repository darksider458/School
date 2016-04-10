--create tables and database 
GO
CREATE DATABASE Bank;
GO
use Bank;
GO
CREATE TABLE Adresy
( AID int not null identity(1,1),
  CityName varchar(60) not null,
  StreetName varchar(100) not null,
  PSC varchar(20) not null,
  Country nvarchar(100) not null
  PRIMARY KEY (AID) 
);

CREATE TABLE Pozition_type
( PT_ID int not null identity(1,1),
  PozitionName varchar(50)not null,
  privileges int not null,
  PRIMARY KEY (PT_ID) 
);

CREATE TABLE Branch
(
	BR_ID int not null identity(1,1),
	BranchName nvarchar(50) not null,
	Adres_ID int ,
	PRIMARY KEY (BR_ID),
	FOREIGN KEY (Adres_ID) REFERENCES Adresy(AID) ON DELETE SET NULL
);

CREATE MASTER KEY ENCRYPTION BY PASSWORD = 'Password123';

CREATE CERTIFICATE Certificate1
WITH SUBJECT = 'Protect Data';

CREATE SYMMETRIC KEY SymmetricKey1 
 WITH ALGORITHM = AES_256
 ENCRYPTION BY CERTIFICATE Certificate1;


CREATE TABLE Employes
(
	EID int not null identity(1,1),
	FirstName nvarchar(100) not null,
	LastName nvarchar(100) not null,
	UserName nvarchar(100) not null UNIQUE,
	Paswd varbinary(128) not null,
	Date_of_Birth date not null,
	Adres_ID int,
	Branch_ID int ,
	Pozition_ID int not null,
	PRIMARY KEY (EID),
	FOREIGN KEY (Adres_ID) REFERENCES Adresy(AID) ON DELETE SET NULL,
	FOREIGN KEY (Pozition_ID) REFERENCES Pozition_type(PT_ID) ,
	FOREIGN KEY (Branch_ID) REFERENCES Branch(BR_ID)ON DELETE SET NULL 
);

CREATE TABLE Accounttype
(
	ACT_ID int not null IDENTITY(1,1),
	acc_description varchar(150) not null,
	acc_type varchar(50) not null
	PRIMARY KEY (ACT_ID)
);
CREATE TABLE Accountstatus
(
	ACS_ID int not null identity(1,1),
	Acstatus varchar(50) not null
	PRIMARY KEY (ACS_ID),
);
CREATE TABLE Customers
(
	CID int not null identity(1,1),
	FirstName nvarchar(100) not null,
	LastName nvarchar(100) not null,
	Adres_ID int,
	EID int not null,
	Date_of_Birth date not null,
	PRIMARY KEY (CID),
	FOREIGN KEY (EID) REFERENCES Employes(EID),
	FOREIGN KEY (Adres_ID) REFERENCES Adresy(AID) ON DELETE SET null
);
CREATE TABLE LOAN
(
	PRSP_ID int not null identity(1,1),
	Vyska_pouzicky int not null,
	Urok int not null,
	Pocet_Splatok int not null,
	Vyska_Splatok int not null,
	CID int,
	Vyska_PoslenejSplatky int not null,
	PRIMARY KEY (PRSP_ID),
	FOREIGN KEY (CID) REFERENCES Customers(CID)
);
CREATE TABLE Accounts
(
	Acc_ID int not null IDENTITY(1,1),
	Date_of_Creation date not null,
	Money_on_Account money not null,
	AccT_ID int not null,
	AccS_ID int not null,
	CID int not null,
	PRIMARY KEY (Acc_ID),
	FOREIGN KEY (AccT_ID) REFERENCES Accounttype(ACT_ID),
	FOREIGN KEY (AccS_ID) REFERENCES Accountstatus(ACS_ID),
	FOREIGN KEY (CID) REFERENCES Customers(CID)

);
CREATE TABLE MoneyTransfer
(
	MT_ID int not null IDENTITY(1,1),
	FirstAccount int not null,
	SecondAccount int not null,
	Amount money not null,
	Date_of_transfer date not null,
	PRIMARY KEY (MT_ID),
	FOREIGN KEY (FirstAccount) REFERENCES Accounts(Acc_ID),
	FOREIGN KEY (SecondAccount) REFERENCES Accounts(Acc_ID)
	
);



CREATE TABLE CustomerHistory
(
	HISID int not null identity(1,1),
	EID int DEFAULT 1 ,
	CID int DEFAULT 1,
	History date not null,
	PRIMARY KEY (HISID),
	FOREIGN KEY (EID) REFERENCES Employes(EID) ON DELETE SET DEFAULT,
	FOREIGN KEY (CID) REFERENCES Customers(CID) ON DELETE SET NULL

);


