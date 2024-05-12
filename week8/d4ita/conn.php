<?php
$servername = "localhost";
$username = "root";
$password = "root";
$dbname = "d4ita";
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) {
  die("Koneksi Gagal: " . mysqli_connect_error());
}
