<?php
include '2koneksi.php';
$sql = "SELECT * FROM siswa";
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {

  while ($row = mysqli_fetch_assoc($result)) {
    echo "NRP : " . $row["nrp"] . "<br>";
    echo "Nama : " . $row["nama"] . "<br>";
    echo "Umur : " . $row["umur"] . " tahun <br>";
    echo "Jenis Kelamin : " . $row["jenis_kelamin"] . "<br>";
    echo "Alamat : " . $row["alamat"] . "<br>";
  }
} else {
  echo "0 results";
}
mysqli_close($conn);
