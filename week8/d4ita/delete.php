
<?php
if (isset($_GET['nrp']) && !empty($_GET['nrp'])) {
  include 'conn.php';

  $nrp = mysqli_real_escape_string($conn, $_GET['nrp']);

  $sql = "DELETE FROM mahasiswa WHERE nrp = '$nrp'";

  if ($conn->query($sql) === TRUE) {
    header("Location: index.php");
    exit();
  } else {
    echo "Error deleting record: " . $conn->error;
  }

  $conn->close();
} else {
  header("Location: index.php");
  exit();
}
?>
