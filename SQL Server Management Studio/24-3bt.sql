--Bai 1
CREATE DATABASE QLSinhVien2
USE QLSinhVien2
--bai 2
CREATE TABLE DMKHOA (
	MaKH char(2),
	TenKH nvarchar(100)
)
CREATE TABLE DMMH(
	MaMH char(2),
	TenMH nvarchar(100),
	HeSo int
)
CREATE TABLE DMSV(
	MaSV char(3),
	TenSV nvarchar(100),
	GioiTinh bit,
	MaKH char(2),
	SoMonDK int,
	DiemTB float
)
CREATE TABLE KETQUA(
	MaSV char(3),
	MaMH char(2),
	Diem float
)
 --bai 3
INSERT INTO DMKHOA (MaKH, TenKH)
VALUES ('AV', 'Anh Văn');
INSERT INTO DMKHOA (MaKH, TenKH)
VALUES ('TH', 'Tin Học');
INSERT INTO DMKHOA (MaKH, TenKH)
VALUES ('TR', 'Triết Học');

INSERT INTO DMMH (MaMH, TenMH, HeSo)
VALUES ('01', 'BDWS', '4');
INSERT INTO DMMH (MaMH, TenMH, HeSo)
VALUES ('02', 'DW8', '2');
INSERT INTO DMMH (MaMH, TenMH, HeSo)
VALUES ('03', 'DDSQL', '6');

INSERT INTO DMSV(MaSV, TenSV, GioiTinh, MaKH, SoMonDK, DiemTB)
VALUES ('C01', 'Phạm Tuấn Anh', '1', 'TH', '2', '8');
INSERT INTO DMSV(MaSV, TenSV, GioiTinh, MaKH, SoMonDK, DiemTB)
VALUES ('C02', 'Phạm Văn Thành', '1', 'TH', '2', '8');
INSERT INTO DMSV(MaSV, TenSV, GioiTinh, MaKH, SoMonDK, DiemTB)
VALUES ('C03', 'Trịnh Thị Hiền', '0', 'TH', '3', '8');
INSERT INTO DMSV(MaSV, TenSV, GioiTinh, MaKH, SoMonDK, DiemTB)
VALUES ('C04', 'Trần Đức Cường', '1', 'AV', '2', '8');
INSERT INTO DMSV(MaSV, TenSV, GioiTinh, MaKH, SoMonDK, DiemTB)
VALUES ('C05', 'Nguyễn Bích Ngọc', '0', 'TR', '3', '8');

INSERT INTO KETQUA(MaSV, MaMH, Diem)
VALUES ('C01', '01', '6');
INSERT INTO KETQUA (MaSV, MaMH, Diem)
VALUES ('C02', '02', '8');
INSERT INTO KETQUA (MaSV, MaMH, Diem)
VALUES ('C03', '03', '8');
INSERT INTO KETQUA (MaSV, MaMH, Diem)
VALUES ('C04', '02', '6');
INSERT INTO KETQUA (MaSV, MaMH, Diem)
VALUES ('C05', '02', '5');
--bai 4
SELECT * FROM DMSV
--bai 5
SELECT MaSV,TenSV , GioiTinh
FROM DMSV
--bai 7
SELECT TOP 50 percent * from DMSV
--bai 8
UPDATE DMSV 
SET 
    DiemTB = '6'
WHERE
    MaSV = 'C02';

UPDATE DMSV 
SET 
    DiemTB = '7'
WHERE
    MaSV = 'C01';
--bai 9
	DELETE FROM DMSV WHERE TenSV='Trịnh Thị Hiền' ;
--bai 10
select * from KETQUA
where Diem < 8

DROP TABLE DMKHOA
DROP TABLE KETQUA
