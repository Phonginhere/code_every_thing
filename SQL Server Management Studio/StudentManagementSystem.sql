--1
CREATE DATABASE StudentManagementSystem
USE StudentManagementSystem

--2
CREATE TABLE Class (
	ClassId int NOT NULL,
	ClassCode nvarchar(50)
)
CREATE TABLE Student (
	StudentId int NOT NULL,
	StudentName nvarchar(50),
	BirthDate DATETIME,
	ClassId INT 
)
CREATE TABLE Subject (
	SubjectId int NOT NULL,
	SubjectName nvarchar(100),
	SessionCount Int --Number of sessions
)

CREATE TABLE Result (
	StudentId int NOT NULL ,
	SubjectId int NOT NULL,
	Mark int
)
DROP TABLE IF EXISTS Result, Subject
--3
CREATE INDEX NCI_Student_StudentName ON Student(StudentName);

ALTER TABLE Result 
ALTER COLUMN Mark float
--4
ALTER TABLE Class
ADD PRIMARY KEY (ClassId)
ALTER TABLE Student
ADD PRIMARY KEY (StudentId)
ALTER TABLE Subject
ADD PRIMARY KEY (SubjectId)
ALTER TABLE Result
ADD PRIMARY KEY (StudentId, SubjectId)

ALTER TABLE Student
ADD CONSTRAINT PK_STUDENT_CLASS
FOREIGN KEY (ClassId) REFERENCES Class(ClassId);
ALTER TABLE Result
ADD CONSTRAINT FK_Result_Student
FOREIGN KEY (StudentId) REFERENCES Student(StudentId);
ALTER TABLE Result
ADD CONSTRAINT FK_Result_Subject
FOREIGN KEY (SubjectId) REFERENCES Subject(SubjectId);

ALTER TABLE Subject 
ADD CONSTRAINT CK_Subject_SessionCount
 CHECK (SessionCount > 0);
--5
 INSERT INTO Class(ClassId, ClassCode)
 VALUES('1', 'C1106KV')
 INSERT INTO Class(ClassId, ClassCode)
 VALUES('2', 'C1108GV')
 INSERT INTO Class(ClassId, ClassCode)
 VALUES('3', 'C1108IV')
 INSERT INTO Class(ClassId, ClassCode)
 VALUES('4', 'C1108HV')
 INSERT INTO Class(ClassId, ClassCode)
 VALUES('5', 'C1109GV')

 INSERT INTO Student(StudentId, StudentName, BirthDate, ClassId)
 VALUES('1', 'PhạmTuấnAnh', '05/08/1993', '1')
 INSERT INTO Student(StudentId, StudentName, BirthDate, ClassId)
 VALUES('2', 'PhanVănHuy', '10/06/1992', '1')
 INSERT INTO Student(StudentId, StudentName, BirthDate, ClassId)
 VALUES('3', 'NguyễnHoàng Minh', '07/09/1992', '2')
 INSERT INTO Student(StudentId, StudentName, BirthDate, ClassId)
 VALUES('4', 'TrầnTuấnTú', '10/10/1993', '2')
 INSERT INTO Student(StudentId, StudentName, BirthDate, ClassId)
 VALUES('5', 'ĐỗAnhTài', '06/06/1992', '3')

 INSERT INTO Subject VALUES (1, 'C Programming', 22)
 INSERT INTO Subject VALUES (2, 'Web Design', 18)
 INSERT INTO Subject VALUES (3, 'Database Management', 23)

insert Result values (1,1,8)
insert Result values (1,2,7)
insert Result values (2,3,5)
insert Result values (3,2,6)
insert Result values (4,3,9)
insert Result values (5,2,8)

--6
	SELECT StudentId, StudentName, BirthDate
	FROM Student
	WHERE BirthDate BETWEEN '10/10/1992' AND '10/10/1993'

SELECT Class.ClassId, Class.ClassCode, count(*)as'Si So Lop'
FROM Class
JOIN Student
ON Class.ClassId = Student.ClassId
GROUP BY Class.ClassId, ClassCode

SELECT Student.StudentId, Student.StudentName, sum(Mark)as'Total Mark'
FROM Student
JOIN Result
On Student.StudentId = Result.StudentId
GROUP BY Student.StudentId,StudentName
having sum(Mark)>10
--7
go
CREATE VIEW view_StudentSubjectMark
AS SELECT TOP 3 Student.StudentId, Student.StudentName, Result.Mark
FROM Student
JOIN Result
ON Student.StudentId = Result.StudentId
ORDER BY Mark DESC

SELECT * FROM view_StudentSubjectMark
--8
DROP PROC up_IncreaseMark
CREATE PROC up_IncreaseMark @SubjectId int
AS
BEGIN
	update Result
	set Mark = Mark + @SubjectId
	END

up_IncreaseMark 1

SELECT * FROM Result

DROP PROC up_IncreaseMark2
CREATE PROC up_IncreaseMark2 @SubjectId2 int
AS
BEGIN
	update Result
	set Mark = Mark + 2
	where SubjectID = @Subjectid2
	END
up_IncreaseMark2 1
SELECT * FROM Result
--9
go
create trigger TG_Result_Insert
on Result
for insert
AS
BEGIN
    declare @result INT

    select @result = Mark from inserted    

    if(@result < 0)
    BEGIN
        print 'Cannot insert mark less than zero.'
        rollback
    end
END

INSERT INTO Result VALUES(5, 1, 9)
INSERT INTO Result VALUES(4, 2, -9)
--10
go
create trigger TG_Subject_Update
on Subject
for update
AS
	BEGIN 
	declare @subject nvarchar

	select @subject = SubjectName from updated

	if(@subject = '')
    BEGIN
        print 'You don’t update this column'
        rollback
    end
END




