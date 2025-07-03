-- Creating the product_master table
CREATE TABLE product_master (
    product_no     VARCHAR(6),
    description    VARCHAR(20),
    profit_percent NUMERIC,
    unit_measure   VARCHAR(10),
    qty_on_hand    NUMERIC,
    reorder_lvl    NUMERIC,
    sell_price     NUMERIC
);

-- Inserting data into product_master table
-- Inserting sample data into product_master table
INSERT INTO product_master (product_no, description, profit_percent, unit_measure, qty_on_hand, reorder_lvl, sell_price) VALUES
('P001', 'Notebook A5', 10.5, 'pcs', 100, 20, 4500),
('P002', 'Ball Pen Blue', 12.0, 'box', 200, 50, 12000),
('P003', 'Stapler Small', 8.75, 'pcs', 75, 10, 8550),
('P004', 'Paper Ream A4', 15.0, 'ream', 50, 15, 25000),
('P005', 'Marker Black', 9.5, 'pcs', 120, 30, 3525);
