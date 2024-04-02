<!DOCTYPE html>
<html>

<body>
  <?php
  $x = 1;
  while ($x <= 5) {
    echo "Angka yang di masukan : $x <br>";
    $x++;
  }
  ?>
</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  $x = 6;
  do {
    echo " Angka : $x <br>";
    $x++;
  } while ($x <= 5);
  ?>
</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  for ($x = 0; $x <= 10; $x++) {
    echo "Angka : $x <br>";
  }
  ?>
</body>

</html>

<!DOCTYPE html>
<html>

<body>
  <?php
  $colors = array("merah", "hijau", "biru", "kuning");
  foreach ($colors as $value) {
    echo "$value <br>";
  }
  ?>
</body>

</html>
