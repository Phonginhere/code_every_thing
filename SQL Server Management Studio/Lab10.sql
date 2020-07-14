--1
CREATE DATABASE Lab10
USE Lab10
--2

CREATE TABLE Subjects(
	SubjectID int check(SubjectID between 1 and 9999)  PRIMARY KEY ,
	SubjectName nvarchar(50)
)
CREATE TABLE Students (
	StudentID int check (StudentID between 1 and 9999) PRIMARY KEY ,
	StudentName nvarchar(50),
	Age int check (Age between 1 and 9999),
	Email varchar(100)
)
CREATE TABLE Classes (
	ClassID int check (ClassID between 1 and 9999)  PRIMARY KEY ,
	ClassName nvarchar(50) 
)
CREATE TABLE ClassStudent (
	ClassID int check (ClassID between 1 and 9999)  foreign key REFERENCES Classes(ClassID),
	StudentID int check (StudentID between 1 and 9999)  foreign key REFERENCES Students(StudentID) 
	
)
CREATE TABLE Marks (
	SubjectID int  foreign key REFERENCES Subjects(SubjectID) ,
	StudentID int  foreign key REFERENCES Students(StudentID),
	Mark int
)
	SELECT * FROM Students
	insert Students values (1, 'Nguyen Quang An', 18, 'an@yahoo.com')
	insert Students values (2, 'Nguyen Cong Vinh', 20, 'vinh@gmail.com')
	insert Students values (3, 'Nguyen Van Quyen', 19, 'quyen')
	insert Students values (4, 'Pham Thanh Binh', 25, 'binh@com')
	insert Students values (5, 'Nguyen Van Tai Em', 30, 'taiem@sport.vn')

	insert Classes values (1, 'C0706L')
	insert Classes values (2, 'C0708G')

	insert ClassStudent values (1, 1)
	insert ClassStudent values (1, 2)
	insert ClassStudent values (2, 3)
	insert ClassStudent values (2, 4)
	insert ClassStudent values (2, 5)

	insert Subjects values (1,'SQL')
	insert Subjects values (2,'Java')
	insert Subjects values (3,'C')
	insert Subjects values (4,'Visual Basic')

	insert Marks values (1, 1, 8)
	insert Marks values (2, 1, 4)
	insert Marks values (1, 1, 9)
	insert Marks values (1, 3, 7)
	insert Marks values (1, 4, 3)
	insert Marks values (2, 5, 5)
	insert Marks values (3, 3, 8)
	insert Marks values (3, 5, 1)
	insert Marks values (2, 4, 3)

	CREATE VIEW HocVien
	AS
	SELECT Students.StudentID, Students.StudentName, Students.Age
	FROM Students

	SELECT * FROM HocVien
	ORDER BY StudentName ASC;

	CREATE VIEW view8
	AS
	SELECT Subjects.SubjectID, Subjects.SubjectName
	FROM Subjects

	SELECT * FROM view8

	--loi
	CREATE VIEW Nemail
	AS
	SELECT Students.StudentID, Students.Email
	FROM  Students

	SELECT * FROM Nemail
--
	CREATE VIEW LName
	AS 
	SELECT Students.StudentID, Students.StudentName
	FROM Students
	
	SELECT * FROM LName
	WHERE StudentName LIKE 'Nguyen%'

	CREATE VIEW cLass
	AS
	SELECT Classes.ClassID, Classes.ClassName
	FROM Classes

	SELECT * FROM cLass
	WHERE ClassName = 'C0706L'

	CREATE VIEW view1
	AS
	SELECT Marks.StudentID, Students.StudentName, Marks.SubjectID, Marks.Mark
	FROM Marks
	join Students
	ON Marks.StudentID = Students.StudentID
	GROUP BY Marks.StudentID, Students.StudentName, Marks.SubjectID, Marks.Mark

	SELECT * FROM view1
--loi
	CREATE VIEW view2
	AS
	SELECT Marks.StudentID, Students.StudentName
	FROM Marks
	JOIN Students
	ON Marks.StudentID = Students.StudentID

	SELECT * FROM view2
--
	CREATE VIEW view3
	AS
	SELECT Subjects.SubjectID, Subjects.SubjectName
	FROM Subjects

	SELECT * FROM view3
	WHERE SubjectID = 4

	DROP VIEW view4
	CREATE VIEW view4
	AS
	SELECT Students.StudentID, Students.StudentName, Marks.Mark
	FROM Students
	JOIN Marks
	ON Students.StudentID = Marks.StudentID
	GROUP BY Students.StudentID, Students.StudentName, Marks.Mark

	SELECT StudentID, StudentName, AVG(Mark) AS 'Diem Trung Binh' FROM view4
	GROUP BY StudentID, StudentName
	
	CREATE VIEW view5
	AS
	SELECT Subjects.SubjectID, Subjects.SubjectName
	FROM Subjects
	
	SELECT TOP 1 * FROM view5

	CREATE VIEW view6
	AS
	SELECT Subjects.SubjectName, Marks.Mark
	FROM Subjects
	JOIN Marks
	ON Subjects.SubjectID = Marks.SubjectID

	SELECT TOP 1 * FROM view6

	
	SELECT Students.StudentID, Students.StudentName	,avg(Mark) 
	FROM Marks
	JOIN Students
	ON Marks.StudentID = Students.StudentID
	GROUP BY Students.StudentID, Students.StudentName

	--5

	ALTER TABLE Students
	ADD CONSTRAINT  Students_Check_Age
	CHECK (Age > 15 AND Age < 50)

	ALTER TABLE ClassStudent
	DROP CONSTRAINT FK__ClassStud__Class__5D95E53A;

	ALTER TABLE ClassStudent
	DROP CONSTRAINT [FK__ClassStud__Stude__5F7E2DAC]

	ALTER TABLE Marks
	DROP CONSTRAINT [FK__Marks__StudentID__65370702]

	ALTER TABLE Marks
	DROP CONSTRAINT [FK__Marks__SubjectID__6442E2C9]
	
	DELETE FROM Students
	WHERE StudentID = '1'

	ALTER TABLE Students
	ADD Status Bit DEFAULT (1)
--loi
	INSERT INTO Students( StudentID) 
	VALUES ('1')
	SELECT * FROM Students
--loi
	--6
	DROP PROC proc1
	go
	CREATE PROC proc1 @Studentid int
	AS
	BEGIN
		select * FROM Marks
		where StudentID = @Studentid
/*	SELECT Students.StudentID 'Mã học viên', Students.StudentName AS 'Tên học viên', Marks.Mark AS 'Điểm'
	FROM Students
	JOIN Marks
	ON Students.StudentID = Marks.StudentID
	GROUP BY Students.StudentID, Students.StudentName, Marks.Mark */
	END

	proc1 1
--
	go
	CREATE PROC proc2 @Subjectid int
	AS
	BEGIN 
		update Marks
		set Mark = 0
		where SubjectID = @Subjectid
	END

	proc2 2
	SELECT * FROM Marks

	go
	CREATE PROC proc3 @studentID int, @subjectId int
	as
	 select * 
	 from Marks
	where SubjectID = @subjectId and StudentID = @studentID

	proc3 1, 2
--9 
go
create trigger tg_insert_mark
on Marks
for insert
AS
BEGIN
    declare @mark INT

    select @mark = Mark from inserted    

    if(@mark < 0)
    BEGIN
        print 'Mark must be greater than 0'
        rollback
    end
END

insert Marks values (3, 5, -1)
insert Marks values (3, 5, 1)
--delete
	DROP TABLE IF EXISTS Marks, Subjects, Students, Classes, ClassStudent
	DROP TABLE IF EXISTS Marks, ClassStudent
	DROP TABLE IF EXISTS Subjects, Students, Classes
	DROP TABLE Marks