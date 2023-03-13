-- 1
CREATE TABLE departemen(
    nomor INT NOT NULL PRIMARY KEY,
    nama VARCHAR(15),
    jmlPegawai INT,
    noKTP INT
);
-- 2
CREATE TABLE pegawai(
    noKTP INT NOT NULL,
    namaDepan VARCHAR(20),
    namaBelakang VARCHAR(20),
    jenisKelamin VARCHAR(10),
    alamat VARCHAR(25) Default NULL,
    gaji INT,
    noKTPPimpinan INT,
    nomor INT
);
-- 3
CREATE index dept ON departemen(nomor);
DROP index dept ON departemen;
-- 4
CREATE UNIQUE INDEX dept ON departemen(nomor);
-- 5
DESC pegawai;
ALTER TABLE pegawai ADD CONSTRAINT PRIMARY KEY(noKTP);
DESC pegawai;
-- 6
ALTER TABLE pegawai DROP PRIMARY KEY;
DESC pegawai;
-- 7
ALTER TABLE pegawai ADD noTelp VARCHAR(15);
DESC pegawai;
-- 8
ALTER TABLE pegawai MODIFY Column noTelp CHAR(12);
DESC pegawai;
-- 9
ALTER TABLE pegawai CHANGE Column noTelp Telp VARCHAR(12);
DESC pegawai;
-- 10
ALTER TABLE pegawai DROP Column Telp;
DESC pegawai;

