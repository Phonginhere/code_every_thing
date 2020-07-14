--Create DATABASE CustomerRelationship
USE CustomerRelationship

CREATE TABLE Companies(
	Company_ID int PRIMARY KEY,
	name varchar(60)
)

CREATE TABLE Titles(
	Titile_ID int PRIMARY KEY,
	name varchar(60) UNIQUE,
	Companies_Company_ID int
)

CREATE TABLE Client(
	Client_ID int PRIMARY KEY,
	last_name varchar(40),
	first_name varchar(40),
	katakana varchar(60),
	email varchar(60),
	phone varchar(20),
	image varchar(20),
	 GDI_student BIT,
	DateTime DATETIME,
	Titles_Title_ID int,
	Addresses_Address_ID int
)

CREATE TABLE Address(
	Address_ID int,
	postal_code varchar(20),
	prefecture varchar(20),
	city varchar(30),
	street_1 varchar(80),
	street_2 varchar(80)
)

CREATE TABLE Users(
	User_ID int,
	username varchar(60),
	pass char(40),
	Clients_client_ID int
)