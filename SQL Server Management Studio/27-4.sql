CREATE DATABASE bt274
USE bt274

create table KhoaHoc (
    ma int primary key,
    namBatDau int check (namBatDau >= 1990),
    namKetThuc int check (namKetThuc >= 1990)
)
create table Khoa (
    ma int primary key,
    tenKhoa nvarchar(100),
    namThanhLap int check (namThanhLap >= 1990)
)
create table MonHoc (
    ma int primary key,
    tenMonHoc nvarchar(100),
    khoa int foreign key REFERENCES Khoa(ma)
)
create table ChuongTrinh (
    ma varchar(10) primary key check(ma in ('CQ', 'CD', 'TC')),
    tenChuongTrinh nvarchar(100)
)
create table Lop (
    ma int primary key,
    maKhoa int foreign key REFERENCES Khoa(ma),
    maChuongTrinh varchar(10) foreign key REFERENCES ChuongTrinh(ma),
    maKhoaHoc int foreign key REFERENCES KhoaHoc(ma),
    soThuTu int
)
create table SinhVien (
    ma int primary key,
    hoTen nvarchar(100),
    danToc nvarchar(100),
    namSinh int,
    maLop int foreign key REFERENCES Lop(ma)
)
create table KetQua (
    maSinhVien int foreign key REFERENCES SinhVien(ma),
    maMonHoc int foreign key REFERENCES MonHoc(ma),
    lanThi int,
    diem float check (diem <= 10)
)
create table GiangKhoa (
    maChuongTrinh varchar(10) foreign key REFERENCES ChuongTrinh(ma),
    maKhoa int foreign key REFERENCES Khoa(ma),
    maMonHoc int foreign key REFERENCES MonHoc(ma),
    namHoc int check (namHoc in (1,2,3,4)),
    hocKy varchar(10) check (hocKy in ('HK1', 'HK2')),
    soTinChi int check (soTinChi <= 6),
    soTietThucHanh int check (soTietThucHanh <= 120),
    soTietLyThuyet int check (soTietLyThuyet <= 120),
)
insert KhoaHoc values (1, 2010, 2014)
insert KhoaHoc values (2, 2014, 2018)
insert KhoaHoc values (3, 2018, 2022)
insert Khoa values (1, 'IT', 2000)
insert Khoa values (2, 'Economy', 2001)
insert Khoa values (3, 'Electronics', 2001)
insert MonHoc values (1, 'C', 1)
insert MonHoc values (2, 'Web programming', 1)
insert MonHoc values (3, 'SQL', 1)
insert MonHoc values (4, 'Marketing', 2)
insert ChuongTrinh values ('CD', 'chuong trinh 1')
insert ChuongTrinh values ('CQ', 'chuong trinh 2')
insert Lop values (1,1,'CD',1,1)
insert Lop values (2,1,'CD',1,2)
insert Lop values (3,2,'CQ',2,1)
insert SinhVien values (1,'ho ten 1','kinh',2000,1)
insert SinhVien values (2,'ho ten 2','tay',2001,1)
insert SinhVien values (3,'ho ten 3','kinh',2000,2)
insert SinhVien values (4,'ho ten 4','kinh',2001,3)
insert KetQua values (1,1,1,7)
insert KetQua values (1,1,2,9)
insert KetQua values (1,2,1,null)
insert GiangKhoa values ('CD',1,1,1, 'HK1', 3, 40, 40)
insert GiangKhoa values ('CD',1,2,2, 'HK1', 3, 50, 40)
create table XepLoai (
    maSinhVien int foreign key REFERENCES SinhVien(ma),
    diemTrungBinh float,
    ketQua nvarchar(100),
    hocLuc nvarchar(100)
)

-- 4.1
go
create proc proc41 @maLop int
AS
BEGIN
    select * from SinhVien where maLop = @maLop
END

proc41 2

-- 4.2
go
create proc proc42 @maSinhVien INT
as
BEGIN
    select maSinhVien, maMonHoc, tenMonHoc, lanThi, diem
    from KetQua
        join MonHoc
            on KetQua.maMonHoc = MonHoc.ma
    where maSinhVien = @maSinhVien
END

proc42 1

go
create proc proc421 @maSinhVien INT
as
BEGIN
    select maSinhVien, maMonHoc, tenMonHoc, lanThi, diem
    from KetQua
        join MonHoc
            on KetQua.maMonHoc = MonHoc.ma
    where maSinhVien = @maSinhVien and diem is not null
END

proc421 1

-- scalar function
GO
alter function chuyenDoiDiem(@diem float)
returns nvarchar(100)
AS
BEGIN
    if(@diem is null)
        return N'chưa có điểm'
    
    return @diem
END

go
alter proc proc423 @maSinhVien INT
as
BEGIN
    select maSinhVien, maMonHoc, tenMonHoc, lanThi, dbo.chuyenDoiDiem(diem) as 'diem'
    from KetQua
        join MonHoc
            on KetQua.maMonHoc = MonHoc.ma
    where maSinhVien = @maSinhVien
END

proc423 1

-- 4.3
go
alter proc proc43 @maSinhVien int
as
BEGIN
    declare @diemTrungBinh FLOAT
    declare @countDiemDuoi4 int
    declare @ketQua nvarchar(100)
    declare @hocLuc nvarchar(100)

    select @diemTrungBinh = avg(diem) from KetQua
    where maSinhVien = @maSinhVien and diem is not null

    select @countDiemDuoi4 = count(*) from KetQua
    where maSinhVien = @maSinhVien and diem <= 4

    if(@diemTrungBinh >= 5 and @countDiemDuoi4 <= 2)
    BEGIN
        set @ketQua = N'Đạt'

        if (@diemTrungBinh >= 8)
            set @hocLuc = N'Giỏi'
        else if (@diemTrungBinh >= 7)
            set @hocLuc = N'Khá'
        else
            set @hocLuc = N'Trung bình'
    END
    else
    BEGIN
        set @ketQua = N'không Đạt'
    END

    insert XepLoai values (@maSinhVien,@diemTrungBinh,@ketQua,@hocLuc)
END

proc43 1

select * from KetQua
select * from XepLoai

--4.4
go
create proc proc44 
as
begin 
	select maSinhVien,avg(diem) as 'AVG mark' from KetQua as k1
	where diem is not null and lanThi = (select max(lanThi) from KetQua k2 where k2.maSinhVien = k1.maSinhVien and k2.maMonHoc = k1.maMonHoc)
	group by maSinhVien
end
select * from KetQua
update KetQua
set diem = 6
where maSinhVien = 1 and maMonHoc = 2

go
create proc proc45 @maSinhVien1 int, @maSinhVien2 int, @maMonHoc int
as
begin 
	declare @diem1 Float
	declare @diem2 Float

	select @diem1 = diem from KetQua
	where maSinhVien = @maSinhVien1
		and maMonHoc = @maMonHoc
		and lanThi = 1

	select @diem2 = diem from KetQua
	where maSinhVien = @maSinhVien2
		and maMonHoc = @maMonHoc
		and lanThi = 1

	if (@diem1 > @diem2)
	print ('Student 1 has higher mark than student 2')
	else if (@diem1 < @diem2)
	print ('student 1 has lower mark than student 2')
	else 
	print ('student 1 is equal student 2')
end
proc45 1,2,1
select * from KetQua
--4.6
go 
create proc proc46 @maSinhVien int, @maKhoa int
as
begin 
	declare @maLop int 
	declare @count int = 0 

	select @maLop = maLop from SinhVien where ma = @maSinhVien

	select @count = count(*) from Lop
	where ma = @maLop and maKhoa = @maKhoa

	if (@count > 0)
	print ('belong to this department')
	else 
	print ('doesnt belong to this department')
end
proc46 3,1

select * from SinhVien
--4.7
go 
create proc proc47 @maSinhVien int , @maMonHoc int
as
begin
	declare @diem float
	
	select @diem = diem from KetQua
	where maSinhVien = @maSinhVien and maMonHoc = @maMonHoc and lanThi  = 1
	if(@diem >= 5)
		print 'passed'
		else 
		print 'falled'
end
proc47 1,2
select * from KetQua

--4.8
go
create proc proc48 @maKhoa int
as begin 
	select * from SinhVien
	where maLop in (select ma from Lop where maKhoa = @maKhoa)
end
proc48 2

--4.9
go
create proc proc49 @maSinhVien int, @maMonHoc int	
as
begin 
	select * from KetQua where maSinhVien = @maSinhVien and maMonHoc = @maMonHoc
end
proc49 1,2
--4.10
go
create proc proc410 @maSinhVien int
as
begin 
	declare @maKhoa int
	declare @maLop int 

	select @maLop = maLop from SinhVien where ma = @maSinhVien

	select @maKhoa = maKhoa from Lop where ma = @maLop

	print ('madatory subject for department are:')
	select * from MonHoc
	where khoa = @maKhoa
	end
proc410 1
--4.11
go
create proc proc411 @maMonHoc int
as
begin 
	select maSinhVien, hoTen
	from KetQua
		join SinhVien
		on KetQua.maSinhVien = SinhVien.ma
		where maMonHoc = @maMonHoc and lanThi = 1 and diem >= 5
end
proc411 1


	