BEGIN TRANSACTION
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Velky hores','druzstevna 253/3','24816','slovakia'),('Velky hores','mytna 4583/3','24816','slovakia'),('Velky hores','hlavna 253/3','24816','slovakia'),
	('Bratislava','Ilkovicova 3','258416','slovakia'),('Bratislava','Pionerska 3','258416','slovakia');
	Insert INTO Branch(BranchName,Adres_ID) values ('pobocka hores',3),('pobocka bratislava',5);
	Insert into Pozition_type(PozitionName,privileges) values ('CEO',2),('human resources',3),('public relations',20),('clerk',4);
	OPEN SYMMETRIC KEY SymmetricKey1
	DECRYPTION BY CERTIFICATE Certificate1;
	INSERT INTO Employes(FirstName,LastName,UserName,Paswd,Date_of_Birth,Adres_ID,Branch_ID,Pozition_ID) values('Ronald','Demeter','root',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'aa')),'08/01/1996',1,2,1),
	('Marcel','Furucz','drake',ENCRYPTBYKEY(Key_GUID('SymmetricKey1'),CONVERT(nvarchar,'bb')),'12/03/1995',4,2,2);
COMMIT
