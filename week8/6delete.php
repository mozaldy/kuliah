<?php
include '2koneksi.php';
$sql = "DELETE FROM siswa WHERE nrp=10001";
if (mysqli_query($conn, $sql)) {
  echo "Data Berhasil Terhapus";
} else {
  echo "Gagal, Error : " . mysqli_error($conn);
}
mysqli_close($conn);
