<html>

<head>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
</head>

<body class="container mt-5">
  <h2 class="display-5">Percobaan 2: Menampilkan Deret Prima</h2>
  <h4>
    Tanggal Sekarang:
    <span class="fw-bolder">
      <?php
      $list_hari = array(1 => "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu");
      $list_bulan = array(1 => "Januari", "February", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember");

      $hari = date("N");
      $tanggal = date("j");
      $bulan = date("n");
      $tahun = date("Y");

      echo "$list_hari[$hari], $tanggal $list_bulan[$bulan] $tahun";
      ?>
    </span>
  </h4>
</body>

</html>
