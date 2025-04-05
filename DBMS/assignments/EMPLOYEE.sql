CREATE TABLE EMPLOYEE (
    Eno INT AUTO_INCREMENT PRIMARY KEY,
    Ename VARCHAR(50) NOT NULL,
    Job_type VARCHAR(50) NOT NULL,
    Manager INT,
    Hire_date DATE NOT NULL,
    Dno INT,
    Commission DECIMAL(10,2),
    Salary DECIMAL(7,2) NOT NULL
);

