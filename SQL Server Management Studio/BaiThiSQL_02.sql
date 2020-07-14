CREATE DATABASE BaiThiSQL_02
USE BaiThiSQL_02

CREATE TABLE Hang_Hoa(
	MaMH char(4) PRIMARY KEY Not Null, 
	TenHH varchar(50) Not Null
	
)
CREATE TABLE NVL(
	MaNVL char(4) PRIMARY KEY Not Null,
	TenNVL varchar(50) Not Null,
	DvTinh char(10),
	DonGia float CHECK (DonGia >= 0)
)

CREATE TABLE Dinh_Muc(
	MaHH char(4)  Not Null,
	MaNVL char(4)  Not Null,
	primary key (MaHH, MaNVL),
	SlDinhMuc Real CHECK(SlDinhMuc >= 0)
)
CREATE TABLE KHSX(
	NamThang char(6) Not Null,
	MaHH char(4)  Not Null,
	primary key(NamThang, MaHH),
	S1SanXuat int CHECK(S1SanXuat >= 0 )
)

INSERT INTO Hang_Hoa (MaMH, TenHH)
VALUES ('G001', 'Giày thể thao')
INSERT INTO Hang_Hoa (MaMH, TenHH)
VALUES('G002', 'Giày thời trang')
INSERT INTO Hang_Hoa (MaMH, TenHH)
VALUES('G003', 'Giày trẻ em')

INSERT INTO NVL (MaNVL, TenNVL, DvTinh, DonGia)
VALUES ('D001', 'Da', 'Tấm', '100000')
INSERT INTO NVL (MaNVL, TenNVL, DvTinh, DonGia)
VALUES ('D002', 'Giả da', 'Mét', '70000')
INSERT INTO NVL (MaNVL, TenNVL, DvTinh, DonGia)
VALUES ('D003', 'Nhựa', 'Kg', '120000')
INSERT INTO NVL (MaNVL, TenNVL, DvTinh, DonGia)
VALUES ('D004', 'Keo', 'Kg', '80000')
INSERT INTO NVL (MaNVL, TenNVL, DvTinh, DonGia)
VALUES ('D005', 'Chỉ', 'Mét', '30000')

INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G001', 'D001', '0.3')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G001', 'D002', '0.2')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G001', 'D003', '0.3')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G002', 'D001', '0.2')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G002', 'D002', '0.1')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G002', 'D003', '0.2')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G003', 'D002', '0.1')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G003', 'D003', '0.1')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G003', 'D004', '0.3')
INSERT INTO Dinh_Muc ( MaHH, MaNVL, SlDinhMuc)
VALUES ('G003', 'D005', '0.3')

INSERT INTO KHSX (NamThang, MaHH, S1SanXuat)
VALUES ('200504', 'G001', '8000')
INSERT INTO KHSX (NamThang, MaHH, S1SanXuat)
VALUES ('200504', 'G002', '7500')
INSERT INTO KHSX (NamThang, MaHH, S1SanXuat)
VALUES ('200504', 'G003', '7000')
INSERT INTO KHSX (NamThang, MaHH, S1SanXuat)
VALUES ('200505', 'G001', '7500')
INSERT INTO KHSX (NamThang, MaHH, S1SanXuat)
VALUES ('200505', 'G002', '8000')
--2.1
SELECT Dinh_Muc.MaNVL AS 'Mã Nguyên Vật Liệu', NVL.TenNVL AS 'Tên Nguyên Vật Liệu' , NVL.DvTinh AS 'Đơn Vị Tính', Dinh_Muc.SlDinhMuc AS 'Số Lượng Định Mức'
FROM Dinh_Muc
INNER JOIN NVL
ON Dinh_Muc.MaNVL = NVL.MaNVL

--2.2
SELECT NVL.MaNVL, NVL.TenNVL, KHSX.S1SanXuat 
FROM NVL join Dinh_Muc
ON NVL.MaNVL = Dinh_Muc.MaNVL
join KHSX 
ON Dinh_Muc.MaHH = KHSX.MaHH
GROUP BY NVL.MaNVL, NVL.TenNVL, KHSX.S1SanXuat; 

select NVL.MaNVL as 'Ma NVL', TenNVL as 'Ten NVL', sum(KHSX.S1SanXuat) as 'Tổng số hàng hóa'
from NVL
join Dinh_Muc 
on Dinh_Muc.MaNVL = NVL.MaNVL
join KHSX 
on Dinh_Muc.MaHH = KHSX.MaHH
group by TenNVL,NVL.MaNVL;
--2.3
select NVL.TenNVL,NVL.MaNVL,sum(Dinh_Muc.SlDinhMuc * KHSX.S1SanXuat) as ' du toan san pham'
from NVL
join Dinh_Muc 
on Dinh_Muc.MaNVL = NVL.MaNVL
join KHSX 
on Dinh_Muc.MaHH = KHSX.MaHH
group by TenNVL,NVL.MaNVL;

--2.4
SELECT NVL.MaNVL as 'Ma NVL', TenNVL as 'Ten NVL', sum(Dinh_Muc.SlDinhMuc * KHSX.S1SanXuat) as ' du toan san pham', sum(NVL.DonGia * (Dinh_Muc.SlDinhMuc * KHSX.S1SanXuat)) as 'Số lượng dự toán'
from NVL
join Dinh_Muc 
on Dinh_Muc.MaNVL = NVL.MaNVL
join KHSX 
on Dinh_Muc.MaHH = KHSX.MaHH
group by TenNVL,NVL.MaNVL, KHSX.MaHH

--3.1
CREATE VIEW G_ONE AS 
SELECT Dinh_Muc.MaHH as 'Ma HH', NVL.TenNVL as 'Tên Hàng hóa', KHSX.S1SanXuat AS 'Số lượng sản xuất'
from Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
join KHSX
on Dinh_Muc.MaHH = KHSX.MaHH
Where Dinh_Muc.MaHH = 'G001' AND KHSX.NamThang > 200504

SELECT * FROM G_ONE;
--3.2
CREATE VIEW Products AS 
SELECT Dinh_Muc.MaHH as 'Ma HH', NVL.TenNVL as 'Tên Hàng hóa'
from Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
join KHSX
on Dinh_Muc.MaHH = KHSX.MaHH
Where KHSX.NamThang > 200503
SELECT * FROM Products;
--3.3
CREATE VIEW Promo AS
SELECT Dinh_Muc.MaHH as 'Ma HH', NVL.TenNVL as 'Tên Hàng hóa', NVL.DonGia AS 'Đơn Giá'
From Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
Where NVL.DonGia >= 80000
SELECT * FROM Promo;
--3.4
CREATE VIEW Proset AS
SELECT Dinh_Muc.MaHH as 'Ma HH', NVL.TenNVL as 'Tên Hàng hóa', Dinh_Muc.SlDinhMuc AS 'sldinhmuc'
From Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
where Dinh_Muc.SlDinhMuc = 0.3
SELECT * FROM Proset;
--3.5
CREATE VIEW Prosoe AS
SELECT Dinh_Muc.MaHH as 'Ma HH', Hang_Hoa.TenHH as 'Tên Hàng hóa'
From Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
join Hang_Hoa
on Dinh_Muc.MaHH = Hang_Hoa.MaMH
WHERE Hang_Hoa.TenHH LIKE 'Giày%'
SELECT * FROM Prosoe;
--3.6
select * 
from Hang_Hoa
where TenHH like N'%[_]%'

insert into Hang_Hoa values('G006','Ao_so_mi')
--3.7
select * 
from Hang_Hoa
where MaHH not in (select distinct MaHH from KHSX)

select MaHH 
from Hang_Hoa
except 
select MaHH
from khsx
--4.1
CREATE VIEW Kilo AS
SELECT NVL.MaNVL as 'Ma HH', NVL.TenNVL as 'Tên Hàng hóa', NVL.DvTinh AS 'Đơn Vị Tính'
From  Dinh_Muc
join NVL
on Dinh_Muc.MaNVL = NVL.MaNVL
WHERE NVL.DvTinh LIKE 'Kg'

SELECT * FROM Kilo;
--4.2
CREATE VIEW Morepro AS
SELECT NVL.MaNVL as 'Ma NVL', NVL.TenNVL as 'Tên Hàng hóa', NVL.DonGia AS 'Đơn Giá'
From NVL
WHERE NVL.DonGia > 80000

SELECT * FROM Morepro; 
--4.3
CREATE VIEW Manypro AS
SELECT Dinh_Muc.MaHH as 'Ma HH', Hang_Hoa.TenHH as 'Tên Hàng hóa', KHSX.S1SanXuat AS 'Số lượng sản xuất'
From Dinh_Muc
join Hang_Hoa
on Dinh_Muc.MaHH = Hang_Hoa.MaMH
join KHSX
on Dinh_Muc.MaHH = KHSX.MaHH
Where KHSX.S1SanXuat > 10000

SELECT * FROM Manypro;
--4.5
SELECT Hang_Hoa.MaHH AS 'Ma HH', Hang_Hoa.TenHH as 'Tên HH', Dinh_Muc.SlDinhMuc as 'Sl Định Mức'
FROM Hang_Hoa
JOIN Dinh_Muc
ON Hang_Hoa.MaMH = Dinh_Muc.MaHH
ORDER BY Dinh_Muc ASC;

SELECT MaHH, SlDinhMuc
FROM Dinh_Muc
GROUP BY MaHH;



create proc showData
AS
BEGIN
 select * from NVL
END
showData
--trigger
--before: insert, update, delete
--after: insert, update, delete
--DonGia <= 200000

alter trigger validateDonGia
on NVL
for insert
AS
BEGIN
 print 'before insert'
 declare @dongia float
 --inserted ('D006', 'nv1', 'dv1', '150000')
 --setdongia
 select @donGia = DonGia from inserted
	if @donGia > 200000
	begin--{ 
		print 'Don Gia must be <= 200k'
		rollback
	end--}

end

drop trigger ValidateDonGia

insert NVL values('H001', 'nv1', 'dv1', 150000)
insert NVL values('B001', 'nv2', 'dv3', 300000)

insert NVL values ('D006', 'nv1', 'dv1', 150000)
insert NVL values ('D007', 'nv1', 'dv1', 300000)


go
create trigger notifyManagerOnNVLDeleted
on NVL
after delete
as
begin
	declare @noOfRecords int
	select @noOfRecords = count(*) from deleted
	print @noOfRecords 
	print ' are deleted in table NVL'
END
delete from NVL
where MaNVL = 'D006'

go
create trigger notifyManagerOnNVLDeleted
on NVL
for update 
AS
BEGIN
	if update(TenNVL)
	begin
		print 'Ten NVL is updated'
		END
	END

	update NVL
	set DvTinh = 'new dvtinh'
	where MaNVL = 'D005'

	update NVL
	set TenNVL = 'new nvl'
	where MaNVL = 'D005'

	Select * FROM NVL
drop trigger notifyManagerOnNVLDeleted

DROP VIEW UpPro;
DROP VIEW InPro;
DROP VIEW Manypro;
DROP VIEW Morepro;
DROP VIEW Kilo;
DROP VIEW Prosoe;
DROP VIEW Proset;
DROP VIEW Promo;
DROP VIEW G_ONE;
DROP VIEW Products;
DROP TABLE  KHSX
DROP TABLE IF EXISTS Dinh_Muc, NVL, KHSX, Hang_Hoa;