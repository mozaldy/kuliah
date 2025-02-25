<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Konversi Nilai</title>
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <style>
    .container {
      background-color: #fff;
      border-radius: 10px;
      box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
      padding: 30px;
      margin-top: 50px;
    }

    h2 {
      color: #007bff;
    }

    .btn-primary {
      background-color: #ffc107;
      border-color: #ffc107;
    }

    .btn-primary:hover {
      background-color: #ffca2b;
      border-color: #ffca2b;
    }
  </style>
</head>

<body class="bg-primary">
  <div class="container">
    <h2 class="text-center mb-4">Form Konversi Nilai</h2>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
      <div class="form-group">
        <label for="nama">Nama:</label>
        <input type="text" class="form-control" id="nama" name="nama" required>
      </div>
      <div class="form-group">
        <label for="nilai">Nilai Angka:</label>
        <input type="text" class="form-control" id="nilai" name="nilai" required>
      </div>
      <button type="submit" class="btn btn-primary btn-block mt-3">Submit</button>
    </form>

    <?php
    function konversiNilai($nilai)
    {
      if ($nilai >= 81 && $nilai <= 100) {
        return "A";
      } elseif ($nilai >= 71 && $nilai <= 80) {
        return "AB";
      } elseif ($nilai >= 66 && $nilai <= 70) {
        return "B";
      } elseif ($nilai >= 60 && $nilai <= 65) {
        return "BC";
      } elseif ($nilai >= 56 && $nilai <= 60) {
        return "C";
      } elseif ($nilai >= 41 && $nilai <= 55) {
        return "D";
      } else {
        return "E";
      }
    }

    function validateNilai($nilai)
    {
      return is_numeric($nilai);
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $nama = $_POST['nama'];
      $nilai = $_POST['nilai'];

      // Validasi input
      if (validateNilai($nilai)) {
        $nilaiHuruf = konversiNilai($nilai);
        echo "<h2 class='mt-4'>Hasil Konversi:</h2>";
        echo "<p><strong>Nama:</strong> $nama </p>";
        echo "<p><strong>Nilai Angka:</strong> $nilai </p>";
        echo "<p><strong>Nilai Huruf:</strong> $nilaiHuruf </p>";
      } else {
        echo "<div class='alert alert-danger mt-3' role='alert'>Angka yang dimasukkan tidak valid!</div>";
      }
    }
    ?>
  </div>

  <!-- Bootstrap JS and dependencies -->
  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@1.16.1/dist/umd/popper.min.js"></script>
  <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>

</html>
