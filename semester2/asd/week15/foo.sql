-- Create users table
CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL,
    role ENUM('admin', 'operator', 'superadmin') NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

-- Create locations table
CREATE TABLE locations (
    location_id INT AUTO_INCREMENT PRIMARY KEY,
    location_name VARCHAR(100) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

-- Create assets table
CREATE TABLE assets (
    asset_id INT AUTO_INCREMENT PRIMARY KEY,
    asset_name VARCHAR(100) NOT NULL,
    asset_type ENUM('mesin', 'alat_pendukung_produksi', 'komputer', 'alat_tulis_kantor') NOT NULL,
    initial_location_id INT,
    status ENUM('good', 'idle', 'broken') DEFAULT 'good',
    delete_at BOOLEAN DEFAULT 0,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (initial_location_id) REFERENCES locations(location_id)
);

-- Create asset_movements table
CREATE TABLE asset_movements (
    movement_id INT AUTO_INCREMENT PRIMARY KEY,
    asset_id INT,
    from_location_id INT,
    to_location_id INT,
    moved_by INT,
    movement_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status ENUM('good', 'idle', 'broken'),
    FOREIGN KEY (asset_id) REFERENCES assets(asset_id),
    FOREIGN KEY (from_location_id) REFERENCES locations(location_id),
    FOREIGN KEY (to_location_id) REFERENCES locations(location_id),
    FOREIGN KEY (moved_by) REFERENCES users(user_id)
);

-- Create sto_sessions table
CREATE TABLE sto_sessions (
    session_id INT AUTO_INCREMENT PRIMARY KEY,
    session_date DATE,
    created_by INT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (created_by) REFERENCES users(user_id)
);

-- Create sto_assets table
CREATE TABLE sto_assets (
    sto_asset_id INT AUTO_INCREMENT PRIMARY KEY,
    session_id INT,
    asset_id INT,
    location_id INT,
    status ENUM('good', 'idle', 'broken'),
    sync_status BOOLEAN DEFAULT 0,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (session_id) REFERENCES sto_sessions(session_id),
    FOREIGN KEY (asset_id) REFERENCES assets(asset_id),
    FOREIGN KEY (location_id) REFERENCES locations(location_id)
);

-- Create asset_notes table
CREATE TABLE asset_notes (
    note_id INT AUTO_INCREMENT PRIMARY KEY,
    asset_id INT,
    user_id INT,
    note_text TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (asset_id) REFERENCES assets(asset_id),
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

-- Insert sample data into users table
INSERT INTO users (username, password, role) VALUES
('admin', 'admin_password', 'admin'),
('operator', 'operator_password', 'operator'),
('superadmin', 'superadmin_password', 'superadmin');

-- Insert sample data into locations table
INSERT INTO locations (location_name) VALUES
('Office'),
('Lini Produksi'),
('Warehouse');

-- Insert sample data into assets table
INSERT INTO assets (asset_name, asset_type, initial_location_id, status) VALUES
('Mesin 1', 'mesin', 2, 'good'),
('Komputer 1', 'komputer', 1, 'good'),
('Alat Tulis 1', 'alat_tulis_kantor', 1, 'good'),
('Mesin 2', 'mesin', 2, 'broken');

-- Insert sample data into asset movements table
INSERT INTO asset_movements (asset_id, from_location_id, to_location_id, moved_by, status) VALUES
(1, 2, 1, 2, 'good'),
(2, 1, 2, 2, 'good');

-- Insert sample data into sto_sessions table
INSERT INTO sto_sessions (session_date, created_by) VALUES
('2024-06-01', 1);

-- Insert sample data into sto_assets table
INSERT INTO sto_assets (session_id, asset_id, location_id, status, sync_status) VALUES
(1, 1, 1, 'good', 1),
(1, 2, 2, 'good', 1);

-- Insert sample data into asset notes table
INSERT INTO asset_notes (asset_id, user_id, note_text) VALUES
(1, 1, 'Service dilakukan pada mesin ini.'),
(2, 2, 'Penggantian hardware dilakukan.');
