<!DOCTYPE html>
<html>

<body>
  <?php
  $cars = array("Volvo", "BMW", "Toyota");
  rsort($cars);
  $clength = count($cars);
  for ($x = 0; $x < $clength; $x++) {
    echo $cars[$x];
    echo "<br>";
  }
  ?>
</body>

</html>
<!DOCTYPE html>
<html>

<body>
  <?php
  $numbers = array(4, 6, 2, 22, 11);
  sort($numbers);
  $arrlength = count($numbers);
  for ($x = 0; $x < $arrlength; $x++) {
    echo $numbers[$x];
    echo "<br>";
  }
  ?>
</body>

</html>
<!DOCTYPE html>
<html>

<body>
  <?php
  $numbers = array(4, 6, 2, 22, 11);
  rsort($numbers);
  $arrlength = count($numbers);
  for ($x = 0; $x < $arrlength; $x++) {
    echo $numbers[$x];
    echo "<br>";
  }
  ?>
</body>


</html>
