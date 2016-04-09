BEGIN TRANSACTION
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Velky hores','druzstevna 253/3','24816','slovakia'),('Velky hores','mytna 4583/3','24816','slovakia'),('Velky hores','hlavna 253/3','24816','slovakia'),
	('Bratislava','Ilkovicova 3','258416','slovakia'),('Bratislava','Pionerska 3','258416','slovakia
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Pribenik','hlavna 253/3','34816','slovakia'),('Pribenik','hlavna 23/4','34816','slovakia'),('Pribenik','hlavna 243/3','34816','slovakia'),
	('Bratislava','Ipelska 7/15','258416','slovakia'),('Bratislava','longova 3/4','258416','slovakia');
	Insert INTO Branch(BranchName,Adres_ID) values ('pobocka hores',3),('pobocka bratislava',5);
	Insert into Pozition_type(PozitionName,privileges) values ('CEO',2),('human resources',3),('public relations',20),('clerk',4);
	INSERT INTO Accounttype (acc_type,acc_description) values('Deposit','A acount that allows the user to make withdrawals'),('Savings','Does not allow withdrawalls');
	INSERT INTO Accountstatus(Acstatus)values('active'),('Frozen'),('terminated');
	OPEN SYMMETRIC KEY SymmetricKey1
	DECRYPTION BY CERTIFICATE Certificate1;
	INSERT INTO Employes(FirstName,LastName,UserName,Paswd,Date_of_Birth,Adres_ID,Branch_ID,Pozition_ID) values('Ronald','Demeter','root',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'aa')),'08/01/1996',1,2,1),
	('Marcel','Furucz','drake',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'bb')),'12/03/1995',4,4,2);
	INSERT INTO Customers (FirstName,LastName,Date_of_Birth,Adres_ID) values ('Erich','Grisha','02-08-1966',6),('Xaver','Sebestian','1996-02-25',7),('Vikto','Rolf','1976-08-20',10),('Shea','Ó Cathasaigh ','1991-11-11',8),('Nika','Sasha','1950-9-9',9)
COMMIT
