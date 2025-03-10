<html>

<head>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
</head>

<body class="bg-primary">
  <div class="container text-white">
    <h1 class="display-5 mt-5 fw-bold">Mozaldy's calculator!</h1>

    <form method="post">

      <div class="col-12">
        <input type="number" class="form-control" name="x" placeholder="Input x...">
      </div>
      <div class="col-12 mt-2">
        <select class="form-select" aria-label="Default select example" name="operator">
          <option selected>Operator</option>
          <option value="+">+ (Jumlah)</option>
          <option value="-">- (Minus)</option>
          <option value="*">x (Kali)</option>
          <option value="/">/ (Bagi)</option>
        </select>
      </div>
      <div class="col-12 mt-2">
        <input type="number" class="form-control" name="y" placeholder="Input y...">
      </div>
      <div class="col-12 mt-2">
        <button type="submit" class="btn btn-dark" name="submit">Hitung!</button>
      </div>
    </form>

    <?php
    if (isset($_POST['submit'])) {
      $x = $_POST['x'];
      $y = $_POST['y'];
      $operator = $_POST['operator'];
      echo "<h3>Result:</h3>";

      $foo = sprintf('<h5>%d %s %d = </h5>', $x, $operator, $y);
      echo $foo;
      echo '<h5 class="display-5 fw-bold">';
      switch ($operator) {
        case '+':
          echo $x + $y;
          break;
        case '-':
          echo $x - $y;
          break;
        case '*':
          echo $x * $y;
          break;
        case '/':
          if ($y == 0) {
            echo "Undefined!";
          } else {
            echo $x / $y;
          }
          break;
        default:
          echo "Ada yang salah";
          break;
      }
      echo "</h5>";
    }
    ?>

  </div>
</body>

</html>
