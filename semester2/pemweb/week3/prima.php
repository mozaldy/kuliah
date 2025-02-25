<html>

<head>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
</head>

<body class="container mt-5">
  <h2 class="display-5">Percobaan 2: Menampilkan Deret Prima</h2>
  <?php
  $limit = 10;
  $count = 0;
  $number = 2;

  echo "<h5>Limit: " . $limit . "</h5>";

  while ($count < $limit) {
    $flag = 0;
    for ($i = 2; $i <= $number / 2; $i++) {
      if ($number % $i == 0) {
        $flag = 1;
        break;
      }
    }
    if ($flag == 0) {
      echo $number;
      echo "<br>";
      $count++;
    }
    $number++;
  }
  ?>
</body>

</html>
