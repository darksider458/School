BEGIN TRANSACTION
	DECLARE @adresid int;
	INSERT INTO Adresy(CityName,StreetName,PSC,Country) values ('Presov','Pionery 45','6484318','Slovakia');
	SELECT @adresid = IDENT_CURRENT('Adresy');
	Insert into Customers (FirstName,LastName,EID,Adres_ID) values('Peter','Kanuch',2,@adresid);
COMMIT
