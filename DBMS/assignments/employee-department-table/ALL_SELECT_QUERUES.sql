-- 1. Display Employee Name, Job, Hire Date, Employee Number; for each employee with the Employee Number appearing first.
SELECT Eno, Ename, Job_type, Hire_date FROM EMPLOYEE ORDER BY Eno ASC;

-- 2. Display unique Jobs from the Employee Table.
SELECT DISTINCT Job_type FROM EMPLOYEE;

-- 3. Display the Employee Name concatenated by a Job separated by a comma.
SELECT Ename || ',' || Job_type AS name_and_Job FROM EMPLOYEE;

-- 4. Display all the data from the Employee Table. Separate each Column by a comma and name the said column as THE_OUTPUT.
SELECT Eno || ',' || Ename || ',' || Job_type || ',' || Manager || ',' || Hire_date || ',' || Dno || ',' || Commission || ',' || Salary AS THE_OUTPUT FROM EMPLOYEE;

-- 5. Display the Employee Name and Salary of all the employees earning more than $2850.
SELECT Ename, Salary FROM EMPLOYEE WHERE Salary > 2850;

-- 6. Display Employee Name and Department Number for the Employee No= 4.
SELECT Ename, Dno FROM EMPLOYEE WHERE Eno = 4;

-- 7. Display Employee Name and Salary for all employees whose salary is not in the range of $1500 and $2850.
SELECT Ename, Salary FROM EMPLOYEE WHERE Salary NOT BETWEEN 1500 AND 2850;

-- 8. Display Employee Name and Department No. of all the employees in Dept 10 and Dept 30 in the alphabetical order by name.
SELECT Ename, Dno FROM EMPLOYEE WHERE Dno IN (1, 3) ORDER BY Ename ASC;

-- 9. Display Name and Hire Date of every Employee who was hired in 2023.
SELECT Ename, Hire_date FROM EMPLOYEE WHERE EXTRACT(YEAR FROM Hire_date) = 2023;

-- 10. Display Name and Job of all employees who don’t have a current Manager.
SELECT Ename, Job_type FROM EMPLOYEE WHERE Manager IS NULL;

-- 11.	Display the Name, Salary and Commission for all the employees who earn commission.
SELECT ename, salary, commission FROM EMPLOYEE WHERE commission IS NOT NULL;

-- 12.	Sort the data in descending order of Salary and Commission.
SELECT * FROM EMPLOYEE ORDER BY SALARY DESC, COMMISSION DESC;

-- 13.	Display Name of all the employees where the third letter of their name is ‘A’.
SELECT ENAME FROM EMPLOYEE WHERE ENAME LIKE '__A%';

-- 14. Display Name of all employees either have one ‘R’s or two ‘A’s in their name and are either in Dept No = 3 or their Mangers Employee No = 5.
SELECT Ename FROM EMPLOYEE WHERE (LENGTH(Ename) - LENGTH(REPLACE(UPPER(Ename), 'R', '')) >= 1 OR LENGTH(Ename) - LENGTH(REPLACE(UPPER(Ename), 'A', '')) >= 2) AND (Dno = 2 OR Manager = 5);

-- 15. Display Name, Salary and Commission for all employees whose Commission Amount is 14 greater than their Salary increased by 5%.
SELECT Ename, Salary, Commission FROM EMPLOYEE WHERE Commission = Salary * 1.05 + 14;

-- 16. Display the Current Date.
SELECT CURRENT_DATE AS "Today’s Date";

-- 17. Display Name, Hire Date and Salary Review Date which is the 1st Monday after six months of employment.
SELECT Ename, Hire_date, (DATE_TRUNC('week', Hire_date + INTERVAL '6 months') + INTERVAL '7 days')::date AS Review_Date FROM EMPLOYEE;

-- 18. Display Name and calculate the number of months between today and the date each employee was hired.
SELECT Ename, Hire_date, EXTRACT(YEAR FROM AGE(CURRENT_DATE, Hire_date)) * 12 + EXTRACT(MONTH FROM AGE(CURRENT_DATE, Hire_date)) AS Months_Worked FROM EMPLOYEE;

-- 19. Display the following for each employee <E-Name> earns < Salary> monthly but wants <3*Current Salary>. Label the Column as Dream Salary.
SELECT Ename || ' earns ' || Salary || ' monthly but wants ' || (Salary * 3) AS "Dream Salary" FROM EMPLOYEE;

-- 20. Display Name with the 1st letter capitalized and all other letters lower case and length of their name of all the employees whose name starts with ‘J’, ‘A’ and ‘M’.
SELECT INITCAP(Ename) AS Proper_Name, LENGTH(Ename) AS Name_Length FROM EMPLOYEE WHERE UPPER(SUBSTRING(Ename, 1, 1)) IN ('J', 'A', 'M');

-- 21. Display Name, Hire Date and Day of the week on which the employee started.
SELECT Ename, Hire_date, TO_CHAR(Hire_date, 'Day') AS Day_Of_Week FROM EMPLOYEE;

-- 22. Display Name, Department Name and Department No for all the employees.
SELECT E.Ename, D.Dname, E.Dno FROM EMPLOYEE E JOIN DEPARTMENT D ON E.Dno = D.Dno;

-- 23. Display Unique Listing of all Jobs that are in Department # 30.
SELECT DISTINCT Job_type FROM EMPLOYEE WHERE Dno = 30;

-- 24. Display Name, Department Name of all employees who have an ‘A’ in their name.
SELECT Ename, (SELECT Dname FROM DEPARTMENT D WHERE D.Dno = E.Dno) AS Department_Name FROM EMPLOYEE E WHERE UPPER(Ename) LIKE '%A%';

-- 25. Display Name, Job, Department No. and Department Name for all the employees working at the Dallas location.
SELECT E.Ename, E.Job_type, D.Dno, D.Dname FROM EMPLOYEE E JOIN DEPARTMENT D ON E.Dno = D.Dno WHERE D.Location = 'Dallas';

-- 26.	Display Name and Employee no. Along with their Manger’s Name and the Manager’s employee no; along with the Employees Name who do not have a Manager.
SELECT  E.Ename AS Employee_Name, E.Eno AS Employee_No, M.Ename AS Manager_Name, M.Eno AS Manager_No FROM  EMPLOYEE E LEFT JOIN EMPLOYEE M ON E Manager = M.Eno;


-- 27.	Display Name, Department No. And Salary of any employee whose department no. and salary matches both the department no. And the salary of any employee who earns a commission.
SELECT E1.Ename, E1.Dno, E1.Salary FROM EMPLOYEE E1 WHERE EXISTS (SELECT 1 FROM EMPLOYEE E2 WHERE E2.Commission IS NOT NULL AND E1.Dno = E2.Dno AND E1.Salary = E2.Salary);


-- 28.	Display Name and Salaries represented by asterisks, where each asterisk (*) signifies $100.
SELECT Ename, REPEAT('*', Salary / 100) AS Salary_In_Stars FROM EMPLOYEE;


-- 29.	Display the Highest, Lowest, Sum and Average Salaries of all the employees.
SELECT MAX(Salary) AS Highest_Salary, MIN(Salary) AS Lowest_Salary, SUM(Salary) AS Total_Salary, AVG(Salary) AS Average_Salary FROM EMPLOYEE;


-- 30.	Display the number of employees performing the same Job type functions.
SELECT Job_type, COUNT(*) AS Num_Employees FROM EMPLOYEE GROUP BY Job_type;


-- 31.	Display the no. of managers without listing their names.
SELECT COUNT(DISTINCT Manager) AS Num_Managers FROM EMPLOYEE WHERE Manager IS NOT NULL;


-- 32.	Display the Department Name, Location Name, No. of Employees and the average salary for all employees in that department.
SELECT D.Dname, D.Location, COUNT(E.Eno) AS Num_Employees, AVG(E.Salary) AS Avg_Salary FROM DEPARTMENT D JOIN EMPLOYEE E ON D.Dno = E.Dno GROUP BY D.Dname, D.Location;


-- 33.	Display Name and Hire Date for all employees in the same dept. as Blake.
SELECT Ename, Hire_date FROM EMPLOYEE WHERE Dno = (SELECT Dno FROM EMPLOYEE WHERE Ename = 'BLAKE');



