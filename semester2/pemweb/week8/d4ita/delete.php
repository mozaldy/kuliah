<!DOCTYPE html>
<html>

<head>
  <script src="https://cdn.tailwindcss.com"></script>
</head>

<body class="bg-slate-800">
  <div class="container text-white mx-auto w-10/12">
    <div class="lg:flex lg:items-center mt-10 lg:justify-between">
      <div class="min-w-0 flex-1">
        <h2 class="text-4xl  font-bold leading-7 ">Delete Data kelas D4 IT A '23</h2>
      </div>
      <div class="mt-5 flex lg:ml-4 lg:mt-0">
        <a href="index.php">
          <span class="hidden sm:block">
            <button type="button" class="inline-flex items-center rounded-md bg-indigo-600 px-3 py-2 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600">
              <svg class="-ml-0.5 -mt-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="none">
                <path d="M5 12H19M5 12L11 6M5 12L11 18" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
              </svg>
              Read
            </button>
          </span>
        </a>
        <a class="ml-4" href="create.php">
          <button type="button" class="inline-flex items-center rounded-md bg-indigo-600 px-3 py-2 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600">
            <svg class="-ml-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 20 20" stroke-width="1.5" stroke="currentColor">
              <path stroke-linecap="round" stroke-linejoin="round" d="M12 4.5v15m7.5-7.5h-15" />
            </svg>
            Create
          </button>
        </a>

      </div>

    </div>

    <?php
    if (isset($_GET['nrp']) && !empty($_GET['nrp'])) {
      include 'conn.php';

      $nrp = mysqli_real_escape_string($conn, $_GET['nrp']);

      $sql = "DELETE FROM mahasiswa WHERE nrp = '$nrp'";

      if ($conn->query($sql) === TRUE) {
        echo '<div class="mt-5 p-4 mb-4 text-sm text-green-800 rounded-lg bg-green-50 dark:bg-gray-700 dark:text-green-400" role="alert"><span class="font-medium">';
        echo "Success Deleting Record.";
        echo '</span></div>';
      } else {
        echo '<div class="mt-5 p-4 mb-4 text-sm text-red-800 rounded-lg bg-red-50 dark:bg-gray-700 dark:text-green-400" role="alert"><span class="font-medium">';
        echo "Error deleting record: " . $conn->error;
        echo '</span></div>';
      }

      $conn->close();
    } else {
      header("Location: index.php");
      exit();
    }
    ?>
    <div class="flex items-center gap-x-6 mt-5">
      <a href="index.php">
        <span class="hidden sm:block">
          <button type="button" class="text-8xl inline-flex items-center rounded-md bg-indigo-600 px-3 py-2 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600">
            <svg class="-ml-0.5 -mt-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="none">
              <path d="M5 12H19M5 12L11 6M5 12L11 18" stroke="#ffffff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" />
            </svg>
            Go Back!
          </button>
        </span>
      </a>
    </div>
  </div>

</body>

</html>
