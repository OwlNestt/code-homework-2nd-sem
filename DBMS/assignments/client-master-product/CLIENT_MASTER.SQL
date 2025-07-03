-- Creating the client_master table
CREATE TABLE client_master (
    client_no    VARCHAR(6),
    name         VARCHAR(20),
    address1     VARCHAR(30),
    address2     VARCHAR(30),
    city         VARCHAR(15),
    state        VARCHAR(15),
    pincode      NUMERIC(6),
    bal_due      NUMERIC(10,2)
);


-- Inserting data into client_master table
INSERT INTO client_master (client_no, name, address1, address2, city, state, pincode, bal_due) VALUES
('C001', 'Rakesh Deep', '123 MG Road', 'Near Market', 'Mumbai', 'Maharashtra', 400001, 1500.50),
('C002', 'NB Shree', '56 Main Street', 'Opp Temple', 'Ahmedabad', 'Gujarat', 380001, 250.75),
('C003', 'Subham Tripathy', '12 Park Ave', 'Sector 5', 'Delhi', 'Delhi', 110011, 0.00),
('C004', 'Sourav Das', '78 Ring Road', 'Next to Mall', 'Kolkata', 'West Bengal', 700001, 3200.00),
('C005', 'Reemi Meher', '90 Marine Drive', '3rd Floor', 'Chennai', 'Tamil Nadu', 600002, 890.60);
