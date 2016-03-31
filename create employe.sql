CREATE TABLE Employes
(
	EID int not null  IDENTITY(1,1) ,
	FirstName varchar(50) not null,
	LastName varchar(50) not null,
	Username varchar(50) not null,
	Paswd varchar(50) not null,
	AdresID int not null,
	PozitionID int not null,
	BranchID int not null,
	PRIMARY KEY (EID),
	FOREIGN KEY (AdresID) REFERENCES Adressy(ID),
	FOREIGN KEY (PozitionID) REFERENCES Pozitions(ID),
	FOREIGN KEY (BranchID) REFERENCES Branches(ID),
	CONSTRAINT Loginrule UNIQUE(Username)
	
)