<?php
$servername = "aldb.cty05xpsomfb.ap-southeast-3.rds.amazonaws.com";
$username = "root";
$password = "mrz201004";
$dbname = "aldb";
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) {
  die("Koneksi Gagal: " . mysqli_connect_error());
}
echo "Koneksi Berhasil<br/>";
