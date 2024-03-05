SELECT f.film_id, f.title FROM film f;

CREATE TABLE basket_a (
    a INT,
    fruit_a VARCHAR
);

CREATE TABLE basket_b (
    b INT,
    fruit_b VARCHAR
);

INSERT INTO basket_a (a, fruit_a) VALUES
(1, 'apple'),
(2, 'orange'),
(3, 'banana'),
(4, 'cucumber');

INSERT INTO basket_b (b, fruit_b) VALUES
(1, 'orange'),
(2, 'apple'),
(3, 'watermelon'),
(4, 'pear');

SELECT a, fruit_a, b, fruit_b 
FROM basket_a 
INNER JOIN basket_b ON fruit_a=fruit_b;


SELECT a, fruit_a, b, fruit_b
FROM basket_a
LEFT JOIN basket_b ON fruit_a=fruit_b;

SELECT a, fruit_a, b, fruit_b
FROM basket_a
RIGHT JOIN basket_b ON fruit_a=fruit_b;

SELECT a, fruit_a, b, fruit_b
FROM basket_a
FULL JOIN basket_b ON fruit_a=fruit_b;


CREATE TABLE employee ( 
    employee_id INT PRIMARY KEY,
    first_name VARCHAR (255) NOT NULL, 
    last_name VARCHAR (255) NOT NULL, 
    manager_id INT, 
    FOREIGN KEY (manager_id) 
    REFERENCES employee (employee_id) 
    ON DELETE CASCADE 
); 

INSERT INTO employee ( employee_id, first_name, last_name, manager_id ) 
VALUES 
(1, 'Windy', 'Hays', NULL),
(2, 'Ava', 'Christensen', 1),
(3, 'Hassan', 'Conner', 1),
(4, 'Anna', 'Reeves', 2),
(5, 'Sau', 'Norman', 2),
(6, 'Kelsie', 'Hays', 3),
(7, 'Tory', 'Goff', 3),
(8, 'Salley', 'Lester', 3);

SELECT p.first_name, p.last_name, m.first_name, m.last_name
FROM employee p
INNER JOIN employee m
ON p.manager_id=m.employee_id;


DROP TABLE IF EXISTS departments;
DROP TABLE IF EXISTS employees;
CREATE TABLE departments (
    department_id serial PRIMARY KEY,
    department_name VARCHAR (255) NOT NULL
);
CREATE TABLE employees (
    employee_id serial PRIMARY KEY,
    employee_name VARCHAR (255),
    department_id INTEGER
);

INSERT INTO departments (department_name)
VALUES 
('Sales'),
('Marketing'),
('HR'),
('IT'),
('Production');

INSERT INTO employees (employee_name, department_id)
VALUES 
('Bette Nicholson', 1),
('Christian Gable', 1),
('Joe Swank', 2),
('Fred Costner', 3),
('Sandra Kilmer', 4),
('Julia Mcqueen', NULL);

SELECT employee_name, department_name
FROM employees e
LEFT OUTER JOIN departments d
ON d.department_id = e.department_id;

SELECT employee_name, department_name
FROM employees e
RIGHT OUTER JOIN departments d
ON d.department_id = e.department_id;

SELECT employee_name, department_name
FROM employees e
FULL OUTER JOIN departments d
ON d.department_id = e.department_id;

CREATE TABLE T1 (label CHAR(1) PRIMARY KEY);
CREATE TABLE T2 (score INT PRIMARY KEY);

INSERT INTO T1 (label)
VALUES ('A'),('B');
INSERT INTO T2 (score)
VALUES (1), (2), (3);

SELECT * FROM T1 CROSS JOIN T2;


CREATE TABLE categories (
    category_id serial PRIMARY KEY,
    category_name VARCHAR (255) NOT NULL
);

CREATE TABLE products (
    product_id serial PRIMARY KEY,
    product_name VARCHAR (255) NOT NULL,
    category_id INT NOT NULL,
    FOREIGN KEY (category_id) 
    REFERENCES categories (category_id)
);

INSERT INTO categories (category_name) 
VALUES 
('Smart Phone'),
('Laptop'),
('Tablet');

INSERT INTO products (product_name, category_id)
VALUES
('iPhone', 1),
('Samsung Galaxy', 1),
('HP Elite', 2),
('Lenovo Thinkpad', 2),
('iPad', 3),
('Kindle Fire', 3);

SELECT * FROM products NATURAL JOIN categories;