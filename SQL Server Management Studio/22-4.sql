CREATE DATABASE hw22
USE hw22

create table NHA_CUNG_CAP (
    Ma int primary key,
    Ten nvarchar(100),
    DiaChi nvarchar(100),
    DienThoai varchar(20)
)
create table MAT_HANG (
    Ma int primary key,
    Ten nvarchar(100),
    DonViTinh nvarchar(100),
    QuiCach nvarchar(100),
    SoLuongTon int
)
create table DAT_HANG (
    So int primary key,
    Ngay DATETIME,
    GhiChu nvarchar(100),
    SoLuongMatHang int,
    ThanhTien money,
    MaNhaCungCap int foreign key REFERENCES NHA_CUNG_CAP(Ma),
)
create table GIAO_HANG (
    So int primary key,
    Ngay DATETIME,
    SoDatHang int  foreign key REFERENCES DAT_HANG(So)
)
create table CUNG_UNG (
    MaNhaCungCap int foreign key REFERENCES NHA_CUNG_CAP(Ma),
    MaMatHang int foreign key REFERENCES MAT_HANG(Ma)
)
create table CHI_TIET_DAT_HANG   (
    SoDatHang int foreign key REFERENCES DAT_HANG(So),
    MaMatHang int foreign key REFERENCES MAT_HANG(Ma),
    SoLuongDat int,
    DonGiaDat money
)
create table CHI_TIET_GIAO_HANG (
    SoGiaoHang int foreign key REFERENCES GIAO_HANG(So),
    MaMatHang int foreign key REFERENCES MAT_HANG(Ma),
    SoLuongGiao int,
)

insert NHA_CUNG_CAP values (1, N'nha cung cap 1', 'dia chi 1', 'dien thoai 1')
insert NHA_CUNG_CAP values (2, N'nha cung cap 2', 'dia chi 2', 'dien thoai 2')
insert NHA_CUNG_CAP values (3, N'nha cung cap 3', 'dia chi 3', 'dien thoai 3')

insert MAT_HANG values (1, 'mat hang 1', 'don vi tinh 1', 'qui cach 1', 1)
insert MAT_HANG values (2, 'mat hang 2', 'don vi tinh 2', 'qui cach 2', 2)
insert MAT_HANG values (3, 'mat hang 3', 'don vi tinh 3', 'qui cach 3', 3)

insert CUNG_UNG values (1, 1)
insert CUNG_UNG values (1, 2)
insert CUNG_UNG values (1, 3)
insert CUNG_UNG values (2, 2)
insert CUNG_UNG values (2, 3)
insert CUNG_UNG values (3, 3)

insert DAT_HANG values (1, '2020-04-23', 'ghi chu 1', 10, 100000, 1)
insert DAT_HANG values (2, '2020-04-22', 'ghi chu 2', 8, 200000, 2)
insert DAT_HANG values (3, '2020-04-21', 'ghi chu 3', 8, 150000, null)

insert CHI_TIET_DAT_HANG values (1, 1, 5, 50000)
insert CHI_TIET_DAT_HANG values (1, 2, 4, 40000)
insert CHI_TIET_DAT_HANG values (1, 3, 6, 30000)
insert CHI_TIET_DAT_HANG values (2, 1, 3, 60000)
insert CHI_TIET_DAT_HANG values (2, 2, 3, 60000)
insert CHI_TIET_DAT_HANG values (3, 3, 8, 20000)

insert GIAO_HANG values (1, '2020-04-23', 1)
insert GIAO_HANG values (2, '2020-04-22', 2)
insert GIAO_HANG values (3, '2020-04-21', 3)

insert CHI_TIET_GIAO_HANG values (1, 1, 5)
insert CHI_TIET_GIAO_HANG values (1, 2, 4)
insert CHI_TIET_GIAO_HANG values (1, 3, 6)
insert CHI_TIET_GIAO_HANG values (2, 1, 3)
insert CHI_TIET_GIAO_HANG values (2, 2, 2)

-- question 4
-- 4.1
alter table MAT_HANG
add constraint check_SoLuongTon check (SoLuongTon > 0)
-- 4.2
alter table CHI_TIET_DAT_HANG 
add constraint check_SoLuongDat check (SoLuongDat <= 10)
-- 4.3
update MAT_HANG
set DonViTinh = 'lốc'

alter table MAT_HANG 
add constraint check_DonViTinh check (DonViTinh in ('lốc', 'chai', 'thùng', 'túi', 'bao', 'bình', 'hộp', 'hũ', 'gói', 'kg'))

select * from MAT_HANG
-- 4.4
update MAT_HANG
set QuiCach = 'chai'

alter table MAT_HANG 
add constraint check_QuiCach check (QuiCach in ('chai', 'thùng', 'hộp', 'gói'))

-- 4.5
select * from NHA_CUNG_CAP

update NHA_CUNG_CAP
set DienThoai = '111-111111'

update NHA_CUNG_CAP
set DienThoai = '11-1111111'


alter table NHA_CUNG_CAP 
add constraint check_DienThoai check (DienThoai like '[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9]' or DienThoai like '[0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9]')

-- question 5
-- 5.1
GO
create proc proc1 @maNhaCungCap int
as
BEGIN
    select * from DAT_HANG where MaNhaCungCap = @maNhaCungCap
END	

proc1 1
-- 5.2
GO
create procedure proc2 @soDatHang int, @thanhTien money output
as
BEGIN
    select @thanhTien = ThanhTien from DAT_HANG
    where So = @soDatHang
END


declare @tongThanhTien money

exec proc2 1, @thanhTien = @tongThanhTien output 

print 'Tong thanh tien'
print @tongThanhTien
--6
-- 6.1
GO
create trigger trigger61
on GIAO_HANG
for insert
as
BEGIN
    declare @SoDatHang int
    declare @count int = 0

    select @SoDatHang = SoDatHang from inserted

    select @count = count(*) 
    from GIAO_HANG
    where SoDatHang = @SoDatHang

    if(@count > 3)
    BEGIN
        print 'cannot deliver this order over 3 times'
        ROLLBACK
    END
END
select * from GIAO_HANG where SoDatHang = 2
insert GIAO_HANG values (7, '2020-04-21', 2)
-- error here
insert GIAO_HANG values (8, '2020-04-21', 2)

-- 6.2
go
create trigger trigger62
on GIAO_HANG
for INSERT
as
BEGIN
    declare @ngayDatHang DATETIME
    declare @ngayGiaoHang DATETIME
    --declare @ngayDatHang1weeklater DATETIME
    declare @soDatHang int

    select @soDatHang = SoDatHang from inserted

    select @ngayGiaoHang = Ngay from inserted

    select @ngayDatHang = Ngay from DAT_HANG
    where So = @soDatHang

    --set @ngayDatHang1weeklater = DATEADD(DD, 7, @ngayDatHang)

    --if(@ngayGiaoHang > @ngayDatHang1weeklater)
    if(@ngayGiaoHang > DATEADD(DD, 7, @ngayDatHang))
    BEGIN
        print 'cannot deliver later than 1 week'
        rollback
    end
END

declare @d1 datetime = GETDATE()
print DATEADD(DD, 7, @d1)

select * from DAT_HANG
select * FROM GIAO_HANG
insert GIAO_HANG values (8, '2020-04-30', 1)
-- error here
insert GIAO_HANG values (9, '2020-05-01', 1)
--delete from GIAO_HANG where So = 9

-- 6.3
GO
create trigger trigger63
on CHI_TIET_DAT_HANG
for insert
as
BEGIN
    declare @MaNhaCungCap int
    declare @MaMatHang int
    declare @SoDatHang int
    declare @count int = 0;

    select @SoDatHang = SoDatHang from inserted

    select @MaMatHang = MaMatHang from inserted

    select @MaNhaCungCap = MaNhaCungCap from DAT_HANG where So = @SoDatHang

    select @count = count(*) from CUNG_UNG
    where MaNhaCungCap = @MaNhaCungCap and MaMatHang = @MaMatHang

    if(@count = 0)
    BEGIN
        print 'this supplier doesnt provide this item'
        rollback
    END
end
select * from DAT_HANG
select * from CHI_TIET_DAT_HANG
-- update DAT_HANG
-- set MaNhaCungCap = 3
-- WHERE So = 3
insert CHI_TIET_DAT_HANG values (3, 3, 8, 20000)
-- error here
insert CHI_TIET_DAT_HANG values (3, 2, 8, 20000)

-- 6.4
GO
create trigger trigger64
on CHI_TIET_GIAO_HANG
for insert
as
BEGIN
    declare @SoGiaoHang int
    declare @MaMatHang int
    declare @SoDatHang int
    declare @count int = 0;

    select @SoGiaoHang = SoGiaoHang from inserted

    select @MaMatHang = MaMatHang from inserted

    select @SoDatHang = SoDatHang from GIAO_HANG where So = @SoGiaoHang

    select @count = count(*) from CHI_TIET_DAT_HANG
    where SoDatHang = @SoDatHang and MaMatHang = @MaMatHang

    if(@count = 0)
    BEGIN
        print 'can only deliver ordered items'
        rollback
    END
end

select * from DAT_HANG
select * from CHI_TIET_DAT_HANG
select * from GIAO_HANG
select * from CHI_TIET_GIAO_HANG

insert CHI_TIET_GIAO_HANG values (5, 3, 2)
-- error here
insert CHI_TIET_GIAO_HANG values (5, 2, 2)

-- 6.5
GO
create trigger trigger65
on CHI_TIET_GIAO_HANG
for insert
as
BEGIN
    declare @SoGiaoHang int
    declare @MaMatHang int
    declare @SoDatHang int
    declare @soLuongGiao int;
    declare @soLuongDat int;

    select @SoGiaoHang = SoGiaoHang from inserted

    select @MaMatHang = MaMatHang from inserted

    select @soLuongGiao = SoLuongGiao from inserted

    select @SoDatHang = SoDatHang from GIAO_HANG where So = @SoGiaoHang

    select top 1 @soLuongDat = SoLuongDat from CHI_TIET_DAT_HANG
    where SoDatHang = @SoDatHang and MaMatHang = @MaMatHang

    if(@soLuongGiao > @soLuongDat)
    BEGIN
        print 'can only deliver amount of items which were ordered'
        rollback
    END
end

select * from CHI_TIET_DAT_HANG
insert CHI_TIET_GIAO_HANG values (5, 3, 7)
-- error here
insert CHI_TIET_GIAO_HANG values (5, 3, 9)

-- 6.6
GO
create trigger trigger66
on CHI_TIET_DAT_HANG
after insert
as
BEGIN
    declare @total int
    declare @SoDatHang int

    select @SoDatHang = SoDatHang from inserted

    select @total = sum(SoLuongDat) from CHI_TIET_DAT_HANG
    where SoDatHang = @SoDatHang

    update DAT_HANG
    set SoLuongMatHang = @total
    where So = @SoDatHang
end

select * from DAT_HANG
select * from CHI_TIET_DAT_HANG
insert CHI_TIET_DAT_HANG values (1, 3, 7, 30000)

-- 6.7
GO
create trigger trigger67
on CHI_TIET_GIAO_HANG
after insert
as
BEGIN
    declare @MaMatHang INT
    declare @SoLuongGiao INT

    select @MaMatHang = MaMatHang from inserted
    select @SoLuongGiao = SoLuongGiao from inserted

    update MAT_HANG
    set SoLuongTon = SoLuongTon - @SoLuongGiao
    where Ma = @MaMatHang
end

select * from CHI_TIET_GIAO_HANG
select * from MAT_HANG
insert CHI_TIET_GIAO_HANG values (5, 3, 4)
