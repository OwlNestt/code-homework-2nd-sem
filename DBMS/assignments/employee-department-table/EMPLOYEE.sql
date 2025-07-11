-- Employee Table

-- DROP TABLE EMPLOYEE;

-- Creating the EMPLOYEE table
CREATE TABLE EMPLOYEE (
    Eno INT  PRIMARY KEY NOT NULL,
    Ename VARCHAR(50) NOT NULL,
    Job_type VARCHAR(50) NOT NULL,
    Manager INT,
    Hire_date DATE NOT NULL,
    Dno INT,
    Commission DECIMAL(10,2),
    Salary DECIMAL(7,2) NOT NULL,
	FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Dno)
);

-- Inserting data into EMPLOYEE table
 INSERT INTO EMPLOYEE VALUES
(0, 'RAKESH', 'SOFTWARE',4, '12-12-2024',2, 50000.56,20000.00),
(1, 'PRIYA', 'ANALYST', 0, '2023-11-15', 1, 3000.00, 25000.00),
(2, 'ARJUN', 'MANAGER', 1, '2022-05-10', 2, NULL, 55000.00),
(3, 'NEHA', 'DEVELOPER', 1, '2024-01-20', 3, 2000.00, 40000.00),
(4, 'VIJAY', 'TESTER', 2, '2023-03-08', 4, NULL, 35000.00),
(5, 'ANITA', 'DESIGNER', 3, '2021-08-25', 2, 1500.00, 30000.00);

-- SELECT * FROM EMPLOYEE;
