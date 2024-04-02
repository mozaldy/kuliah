<!DOCTYPE html>
<html>

<body>
  <?php
  echo "Tanggal hari ini " . date("Y/m/d") . "<br>";
  echo "Tanggal hari ini " . date("Y.m.d") . "<br>";
  echo "Tanggal hari ini " . date("Y-m-d") . "<br>";
  echo "Tanggal hari ini " . date("l");
  ?>
</body>

</html>
<!DOCTYPE html>
<html>

<body>
  <?php
  date_default_timezone_set("Asia/Jakarta");
  echo "Sekarang waktu Jakarta : " . date("h:i:sa");
  echo "<br/>";
  date_default_timezone_set("Asia/Tokyo");
  echo "Sekarang waktu Tokyo : " . date("h:i:sa");
  echo "<br/>";
  date_default_timezone_set("America/New_York");
  echo "Sekarang waktu New York : " . date("h:i:sa");
  ?>
</body>

</html>
