-- DEPARTMENT Table

-- Create the DEPARTMENT table
CREATE TABLE DEPARTMENT (
    Dno INT PRIMARY KEY,
    Dname VARCHAR(50),
    Location VARCHAR(50) DEFAULT 'New Delhi'
);


-- Inserting data into DEPARTMENT table
INSERT INTO DEPARTMENT (Dno, Dname, Location) VALUES
(1, 'HR', 'Mumbai'),
(2, 'IT', 'Bangalore'),
(3, 'Finance', 'Hyderabad'),
(4, 'Operations', 'Chennai');

SELECT * FROM DEPARTMENT;
