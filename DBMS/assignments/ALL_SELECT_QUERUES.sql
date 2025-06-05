-- 1. Display Employee Name, Job, Hire Date, Employee Number; for each employee with the Employee Number appearing first.
-- SELECT Eno, Ename, Job_type, Hire_date FROM EMPLOYEE ORDER BY Eno ASC;

-- 2. Display unique Jobs from the Employee Table.
-- SELECT DISTINCT Job_type FROM EMPLOYEE;

-- 3. Display the Employee Name concatenated by a Job separated by a comma.
-- SELECT Ename || ',' || Job_type FROM EMPLOYEE;

-- 4. Display all the data from the Employee Table. Separate each Column by a comma and name the said column as THE_OUTPUT.
-- SELECT Eno || ',' || Ename || ',' || Job_type || ',' || Manager || ',' || Hire_date || ',' || Dno || ',' || Commission || ',' || Salary AS THE_OUTPUT FROM EMPLOYEE;

-- 5. Display the Employee Name and Salary of all the employees earning more than $2850.
-- SELECT Ename, Salary FROM EMPLOYEE WHERE Salary > 2850;

-- 6. Display Employee Name and Department Number for the Employee No= 4.
-- SELECT Ename, Dno FROM EMPLOYEE WHERE Eno = 4;

-- 7. Display Employee Name and Salary for all employees whose salary is not in the range of $1500 and $2850.
-- SELECT Ename, Salary FROM EMPLOYEE WHERE Salary NOT BETWEEN 1500 AND 2850;

-- 8. Display Employee Name and Department No. of all the employees in Dept 10 and Dept 30 in the alphabetical order by name.
-- SELECT Ename, Dno FROM EMPLOYEE WHERE Dno IN (1, 3) ORDER BY Ename ASC;

-- 9. Display Name and Hire Date of every Employee who was hired in 2023.
-- SELECT Ename, Hire_date FROM EMPLOYEE WHERE EXTRACT(YEAR FROM Hire_date) = 2023;

-- 10. Display Name and Job of all employees who don’t have a current Manager.
-- SELECT Ename, Job_type FROM EMPLOYEE WHERE Manager IS NULL;
