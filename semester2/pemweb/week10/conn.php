<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "d4ita";
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) {
  die("Koneksi Gagal: " . mysqli_connect_error());
} else {
  // echo "koneksi berhasil";
}

// $sql = "CREATE TABLE IF NOT EXISTS `mahasiswa` (
//   `id` INT AUTO_INCREMENT PRIMARY KEY,
//   `nrp` VARCHAR(20) NOT NULL,
//   `nama` VARCHAR(100) NOT NULL,
//   `jenis_kelamin` VARCHAR(10) NOT NULL,
//   `jurusan` VARCHAR(100) NOT NULL,
//   `email` VARCHAR(100) NOT NULL,
//   `alamat` TEXT NOT NULL,
//   `nohp` VARCHAR(20) NOT NULL,
//   `asal_sma` VARCHAR(100) NOT NULL,
//   `matkul_favorit` VARCHAR(100) NOT NULL,
//   `tempat_lahir` VARCHAR(100) NOT NULL,
//   `tanggal_lahir` DATE NOT NULL
// )";
//
// mysqli_query($conn, $sql);
