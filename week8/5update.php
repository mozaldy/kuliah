<?php
include '2koneksi.php';
$sql = "UPDATE siswa SET umur=21 WHERE nrp=10001";
if (mysqli_query($conn, $sql)) {
  echo "Update berhasil";
} else {
  echo "Update Gagal, Error : " . $conn->error;
}
mysqli_close($conn);
