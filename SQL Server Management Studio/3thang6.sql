create database sql26
use sql26

CREATE TABLE hoctap 
( 
	MaSV INT ,
	MaMonHoc  int,
	TenMonHoc varchar(50),
	TenSV  nvarchar(50),
	HocLuc  char(15),
	HocBong char(100)
)	
GO

INSERT INTO hoctap(MaSV, MaMonHoc, TenMonHoc, TenSV, HocLuc, HocBong) VALUES
 (2, 11, N'Toán', N'Tùng', 'A', '200$'),
 (2, 23, N'Tiếng Anh', N'Tùng', 'A', '200$'),
 (8, 11, N'Toán', N'Lâm', 'B', '150$'),
 (3, 11, N'Toán', N'Hùng', 'C', '100$'),
 (9, 23, N'Tiếng Anh', N'Kiên', 'C', '100$')
GO

select * from hoctap