<!DOCTYPE html>
<html>

<body>
  <?php
  $t = date("H");
  if ($t < "20") {
    echo "Have a good day!";
  }
  ?>

</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  $t = date("H");
  if ($t < "20") {
    echo "Have a good day!";
  } else {
    echo "Have a good night!";
  }
  ?>

</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  $t = date("H");
  echo "<p>Waktu di Server Komputer adalah " . $t;
  echo ",Pesan untuk anda:</p>";
  if ($t < "10") {
    echo "Selamat Pagi!";
  } elseif ($t < "14") {
    echo "Selamat Siang";
  } elseif ($t < "18") {
    echo "Selamat Sore";
  } else {
    echo "Have a good night!";
  }
  ?>

</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  $favcolor = "red";
  switch ($favcolor) {
    case "red":
      echo '<p style="color: red;"> Warna terpilih MERAH! </p>';
      break;
    case "blue":
      echo '<p style="color: red;"> Warna terpilih BIRU! </p>';
      break;
    case "green":
      echo '<p style="color: red;"> Warna terpilih HIJAU! </p>';
      break;
    default:
      echo "Coba lagi!";
  }
  ?>

</body>

</html>
