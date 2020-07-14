CREATE DATABASE sixfive
use sixfive
DROP TABLE hw
CREATE TABLE hw (
	Emp_no int primary key,
	Project_id char,
	Project_Name varchar,
	Emp_Name varchar,
	Grade char,
	Salary int
)
INSERT into hw values(142, '113, 124', 'Blue Star, MAGNUM', 'John', 'A', '20,000')
INSERT into hw values(168, 113, 'Blue Star, MAGNUM', 'John', 'A', '20,000')
INSERT into hw values(263, 113, 'Blue Star, MAGNUM', 'John', 'A', '20,000')
INSERT into hw values(109,  124, 'Blue Star, MAGNUM', 'John', 'A', '20,000')

SELECT * from hw
