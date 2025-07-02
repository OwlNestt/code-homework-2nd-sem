-- Questions and answers:

-- 1) Find out the names of all clients.
SELECT name FROM client_master;

-- 2) Retrieve the names and cities of all the clients.
SELECT name, city FROM client_master;

-- 3) Find the product with description '1.44 drive' and '1.22 drive'.
SELECT * FROM product_master WHERE description IN ('1.44 drive', '1.22 drive');
SELECT * FROM product_master WHERE description = '1.44 drive' OR description = '1.22 drive';

-- 4) Find the product whose selling price is greater than 5000.
SELECT * FROM product_master WHERE sell_price > 5000;

-- 5) Find the list of all client who stay in city 'Delhi', 'Mumbai' and 'Madras'.
SELECT * FROM client_master WHERE city IN ('Delhi', 'Mumbai', 'Madras');