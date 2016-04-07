--create tables and database 
CREATE DATABASE Bank;

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
	Adres_ID int not null,
	FOREIGN KEY Adresy(AID) ON DELETE CASCADE
);

CREATE TABLE Employes
(
	EID int not null identity(1,1),
	FirstName nvarchar(100) not null,
	LastName nvarchar(100) not null,
	UserName nvarchar(100) not null UNIQUE,
	Paswd varbinary(128) not null,
	Adres_ID int ,
	Branch_ID int DEFAULT 1 not null,
	Pozition_ID int not null,
	FOREIGN KEY (Adres_ID) REFERENCES Adresy(AID) ON DELETE SET NULL,
	FOREIGN KEY (Pozition_ID) REFERENCES Pozition_type(PT_ID) ,
	FOREIGN KEY (Branch_ID) REFERENCES Branch(BR_ID)ON DELETE SET DEFAULT 
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
);
CREATE TABLE PredpisSplatky
(
	PRSP_ID int not null identity(1,1),
	Vyska_pouzicky int not null,
	urok int not null,

);
