USE QLSPham;

CREATE TABLE  Supliers(
		SID int NOT NULL IDENTITY PRIMARY KEY,
		Sname nvarchar(100),
		Address nvarchar(100),
);
ALTER TABLE  Supliers
ADD Phone varchar(10);
CREATE TABLE Product(
	PID int primary key identity(1,1),
	PName nvarchar(100),
);
CREATE TABLE [Order](
	[SID] int ,
	[PID] int ,
	Price int not null,
);
ALTER TABLE [Order]
ALTER COLUMN Price float;

INSERT INTO	Supliers(SName,[Address],[Phone])
VALUES ('Hai Ha','Ha Noi',0473008888);
INSERT INTO	Supliers(SName,[Address],[Phone])
VALUES ('Kinh Đo','TP HCM',083978787);

INSERT INTO Product(PName)
VALUES ('Keo mem');
INSERT INTO Product(PName)
VALUES ('Keo cung');
INSERT INTO Product(PName)
VALUES ('Keo deo')

INSERT INTO [Order]([SID],[PID],Price)
VALUES (1,1,100);
INSERT INTO [Order]([SID],[PID],Price)
VALUES (1,2,150);
INSERT INTO [Order]([SID],[PID],Price)
VALUES (1,3,200);
INSERT INTO [Order]([SID],[PID],Price)
VALUES (2,1,120);
INSERT INTO [Order]([SID],[PID],Price)
VALUES (3,1,150);



