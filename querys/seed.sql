use Bank;
BEGIN TRANSACTION
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Velky hores','druzstevna 253/3','24816','slovakia'),('Velky hores','mytna 4583/3','24816','slovakia'),('Velky hores','hlavna 253/3','24816','slovakia'),
	('Bratislava','Ilkovicova 3','258416','slovakia'),('Bratislava','Pionerska 3','258416','slovakia')
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Pribenik','hlavna 253/3','34816','slovakia'),('Pribenik','hlavna 23/4','34816','slovakia'),('Pribenik','hlavna 243/3','34816','slovakia'),
	('Bratislava','Ipelska 7/15','258416','slovakia'),('Bratislava','longova 3/4','258416','slovakia');
	Insert INTO Branch(BranchName,Adres_ID) values ('pobocka hores',3),('pobocka bratislava',5);
	Insert into Pozition_type(PozitionName,privileges) values ('CEO',2),('human resources',3),('public relations',20),('clerk',4);
	INSERT INTO Accounttype (acc_type,acc_description) values('Deposit','A acount that allows the user to make withdrawals'),('Savings','Does not allow withdrawalls');
	INSERT INTO Accountstatus(Acstatus)values('active'),('Frozen'),('terminated');
COMMIT;
BEGIN TRANSACTION	
	
	OPEN SYMMETRIC KEY SymmetricKey1
	DECRYPTION BY CERTIFICATE Certificate1;
	INSERT INTO Employes(FirstName,LastName,UserName,Paswd,Date_of_Birth,Adres_ID,Branch_ID,Pozition_ID) values('Ronald','Demeter','root',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'aa')),'08/01/1996',1,2,1),
	('Marcel','Furucz','drake',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'bb')),'12/03/1995',4,2,4);
	INSERT INTO Customers (FirstName,LastName,Date_of_Birth,Adres_ID) values ('Erich','Grisha','02-08-1966',6),('Xaver','Sebestian','1996-02-25',7),('Vikto','Rolf','1976-08-20',10),('Shea','Cathasaigh ','1991-11-11',8),('Nika','Sasha','1950-9-9',9)
	
COMMIT;
BEGIN TRANSACTION
	INSERT INTO Accounts (Date_of_Creation,Money_on_Account,AccT_ID,AccS_ID,CID) values('2005-02-20',$3000,1,1,1),('2008-05-20',$2000,1,2,2),('2014-11-02',$600,1,1,3),('2009-02-20',$1500,1,1,4),('2007-05-15',$2555,1,1,5);
	INSERT INTO LOAN(Vyska_pouzicky,Pocet_Splatok,Vyska_Splatok,Vyska_PoslenejSplatky,Urok,CID) values(3500,DATEDIFF(MONTH,GETDATE(),'2030-01-01'),360,180,5,3),(35000,DATEDIFF(MONTH,GETDATE(),'2040-01-01'),800,480,10,4);
COMMIT;
