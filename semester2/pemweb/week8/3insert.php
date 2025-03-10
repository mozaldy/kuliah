<?php
include '2koneksi.php';
$sql = "INSERT INTO siswa(nrp,nama,jenis_kelamin,agama,umur,alamat)
VALUES (10001,'Mas Paijo','laki','Islam',20,'Jl. Mangga No 30 Blitar')";
if (mysqli_query($conn, $sql)) {
  echo "Data Baru berhasil di tambahkan";
} else {
  echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
mysqli_close($conn);
