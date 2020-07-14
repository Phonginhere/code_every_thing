--1
CREATE DATABASE QLDiem1
USE QLDiem1
--2,4
CREATE TABLE Lop (
	MaLop int NOT NULL primary key,
	TenLop nvarchar(50) NULL 
)
CREATE TABLE HocVien (
	MaHV int NOT NULL primary key,
	TenHV nvarchar(50) NULL,
	NgaySinh datetime NULL ,
	MaLop int NOT NULL foreign key references Lop(MaLop)
)
CREATE TABLE MonHoc (
	MaMH int NOT NULL primary key,
	TenMH nvarchar(50) NULL,
	SoBuoi int NULL check (SoBuoi > 0)
)
CREATE TABLE DiemThi (
	MaHV int NOT NULL foreign key references HocVien(MaHV),
	MaMH int NOT NULL foreign key references MonHoc(MaMH),
	Diem int NULL 
	primary key(MaHV, MaMH)
)
--3
create index TenHV_index on HocVien(TenHV)

ALTER TABLE DiemThi
DROP COLUMN Diem;
ALTER TABLE DiemThi
ADD Diem float;
--5 
INSERT INTO Lop (MaLop, TenLop)
VALUES ('1', 'C1106KV')
INSERT INTO Lop (MaLop, TenLop)
VALUES ('2', 'C1108GV')
INSERT INTO Lop (MaLop, TenLop)
VALUES ('3', 'C1108IV')
INSERT INTO Lop (MaLop, TenLop)
VALUES ('4', 'C1106HV')
INSERT INTO Lop (MaLop, TenLop)
VALUES ('5', 'C1109GV')

INSERT INTO HocVien (MaHV, TenHV, NgaySinh, MaLop)
VALUES ('1', 'Phạm Tuấn Anh', '1993-08-05', '1')
INSERT INTO HocVien (MaHV, TenHV, NgaySinh, MaLop)
VALUES ('2', 'Phạm Văn Huy', '1992-06-10', '1')
INSERT INTO HocVien (MaHV, TenHV, NgaySinh, MaLop)
VALUES ('3', 'Nguyễn Hoàng Minh', '1992-09-07', '2')
INSERT INTO HocVien (MaHV, TenHV, NgaySinh, MaLop)
VALUES ('4', 'Trần Tuấn Tú', '1993-10-10', '2')
INSERT INTO HocVien (MaHV, TenHV, NgaySinh, MaLop)
VALUES ('5', 'Dỗ Anh Tài', '1992-06-06', '3')

INSERT INTO MonHoc(MaMH, TenMH, SoBuoi)
VALUES ('1', 'BDWS', '2')
INSERT INTO MonHoc(MaMH, TenMH, SoBuoi)
VALUES ('2', 'DW8', '18')
INSERT INTO MonHoc(MaMH, TenMH, SoBuoi)
VALUES ('3', 'DDSQL', '23')

INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('1', '1', '8')
INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('1', '2', '7')
INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('2', '3', '5')
INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('3', '2', '6')
INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('4', '3', '9')
INSERT INTO DiemThi(MaHV, MaMH, Diem)
VALUES ('5', '2', '8')
--6
SELECT HocVien.MaHV AS 'MÃ Học Viên', HocVien.TenHV AS 'Tên HV', HocVien.NgaySinh AS 'NGày sinh'
FROM HocVien
where NgaySinh BETWEEN '10-10-1992' AND   '10-10-1993'


SELECT HocVien.MaHV, Lop.TenLop, COUNT(HocVien.MaHV) AS 'TỔng Số HỌC sinh'
FROM HocVien
JOIN Lop
ON HocVien.MaLop = Lop.MaLop
GROUP BY HocVien.MaHV, Lop.TenLop

SELECT HocVien.MaHV, HocVien.TenHV, SUM(DiemThi.Diem) AS 'Tổng Điểm'
FROM HocVien
JOIN DiemThi
ON HocVien.MaHV = DiemThi.MaHV
GROUP BY HocVien.MaHV, HocVien.TenHV
--7
CREATE VIEW Inform
AS
SELECT DiemThi.MaHV 'Mã học viên', HocVien.TenHV AS 'Tên học viên', MonHoc.TenMH AS 'Tên môn học', DiemThi.Diem AS 'Điểm'
FROM DiemThi
JOIN HocVien
ON HocVien.MaHV = DiemThi.MaHV
JOIN MonHoc
ON DiemThi.MaMH = MonHoc.MaMH
GROUP BY DiemThi.MaHV, HocVien.TenHV, MonHoc.TenMH, DiemThi.Diem

go
SELECT TOP 3 * FROM [QLDiem].[dbo].[Inform]

SELECT TOP (3) *
  FROM [QLDiem].[dbo].[Inform]
  Order BY Điểm DESC

EXEC sp_helptext 'Inform';
--8
DROP PROC updating 
CREATE PROC updating @MaHV int
AS
SELECT DiemThi.MaHV 'Mã học viên', HocVien.TenHV AS 'Tên học viên', MonHoc.TenMH AS 'Tên môn học', DiemThi.Diem AS 'Điểm'
FROM DiemThi
JOIN HocVien
ON HocVien.MaHV = DiemThi.MaHV
JOIN MonHoc
ON DiemThi.MaMH = MonHoc.MaMH
WHERE DiemThi.MaHV = 1
GROUP BY DiemThi.MaHV, HocVien.TenHV, MonHoc.TenMH, DiemThi.Diem 
updating 1

go
DROP PROC updating
CREATE PROC updating @informa int
AS
BEGIN 
	update DiemThi
	set MaHV = 1
END
	updating 1
sp_helptext updating

go
 create proc updateScore @score float
 AS
 BEGIN 
	update DiemThi
	set Diem = Diem + 1
END
 updateScore 1

 sp_helptext updateScore
  select * FROM DiemThi

  DROP PROC proc2
  CREATE PROC proc2 @MaMH int
  AS
SELECT DiemThi.MaHV 'Mã học viên', HocVien.TenHV AS 'Tên học viên', MonHoc.TenMH AS 'Tên môn học', DiemThi.Diem AS 'Điểm'
FROM DiemThi
JOIN HocVien
ON HocVien.MaHV = DiemThi.MaHV
JOIN MonHoc
ON DiemThi.MaMH = MonHoc.MaMH
WHERE DiemThi.MaHV = 1 AND MonHoc.TenMH = 'DW8'
GROUP BY DiemThi.MaHV, HocVien.TenHV, MonHoc.TenMH, DiemThi.Diem 
proc2 1
	

 --9

 go
create trigger tg_Insert_DiemThi
on DiemThi
for insert
AS
BEGIN
    declare @quant INT

    select @quant = Diem from inserted

    if @quant < 0
    BEGIN
        print 'Diem must be greater than 0'
        rollback -- cancel current operation
    END
END

alter table DiemThi
drop constraint FK__DiemThi__MaHV__3E52440B

insert DiemThi values('6', '3', 6)
insert DiemThi values('7', '2', -1)

--10
SP_WHO 
KILL 
DROP DATABASE QLDiem1
