<!DOCTYPE html>
<html>

<head>
  <title>Coba PHP</title>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
</head>

<body>
  <?php
  if ($_GET['nama'] == "0") {
    $nama_str = "<p style='color:red'>Nama Belum Diisi !</p>";
  } else {
    $nama_str = "";
  }

  ?>
  <form action="try10.php" method="post">
    <fieldset>
      Nama <br />
      <input type="text" name="nama"><?php echo $nama_str ?><br>

      <br />
      <input type="submit">
    </fieldset>
  </form>
</body>

</html>
