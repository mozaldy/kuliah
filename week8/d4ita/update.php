<?php
include "conn.php";

if (isset($_GET['nrp'])) {
  $nrp = $_GET['nrp'];
  $nrp_short = substr($nrp, -2);

  $sql = "SELECT * FROM `mahasiswa` WHERE `nrp` = '$nrp'";
  $result = $conn->query($sql);

  if ($result->num_rows > 0) {
    $row = $result->fetch_assoc();
    $nama = $row['nama'];
    $kelamin = $row['jenis_kelamin'];
    $jurusan = $row['jurusan'];
    $email = $row['email'];
    $alamat = $row['alamat'];
    $nohp = $row['nohp'];
    $asal_sma = $row['asal_sma'];
    $tempat_lahir = $row['tempat_lahir'];
    $tanggal_lahir = $row['tanggal_lahir'];
  } else {
    echo "No data found.";
    exit;
  }
} else {
  echo "NRP not provided.";
  exit;
}

$conn->close();
?>

<!DOCTYPE html>
<html>

<head>
  <script src="https://cdn.tailwindcss.com"></script>
</head>

<body class="bg-slate-800">
  <div class="container text-white mx-auto w-10/12">
    <div class="lg:flex lg:items-center mt-10 lg:justify-between">
      <div class="min-w-0 flex-1">
        <h2 class="text-4xl  font-bold leading-7 ">Update Data kelas D4 IT A '23</h2>
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
  </div>
  <form method="post" class="w-10/12 mx-auto mt-5">
    <div class="text-white">
      <div class="border-b border-gray-900/10 pb-12">
        <div class="sm:col-span-4">
          <label for="nrp" class="block text-sm font-medium leading-6 ">NRP</label>
          <div class="mt-2">
            <div class="flex rounded-md shadow-sm ring-1 ring-inset ring-gray-300 focus-within:ring-2 focus-within:ring-inset focus-within:ring-indigo-600 sm:max-w-md">
              <span class="flex select-none items-center pl-3  sm:text-sm">31236000</span>
              <input type="text" name="nrp" id="nrp" autocomplete="nrp" class="block flex-1 border-0 bg-transparent py-1.5 pl-1 text-gray-900 placeholder:text-gray-400 font-bold focus:ring-0 sm:text-sm sm:leading-6 text-white" placeholder="00" value="<?php echo $nrp_short ?>">
            </div>
          </div>
        </div>
        <div class="border-b border-gray-900/10 pb-12">

          <div class="mt-10 grid grid-cols-1 gap-x-6 gap-y-8 sm:grid-cols-6">
            <div class="col-span-full">
              <label for="name" class="block text-sm font-medium leading-6 ">Name</label>
              <div class="mt-2">
                <input type="text" name="name" id="name" value="<?php echo $nama ?>" autocomplete="name" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>
            <div class="col-span-3">
              <label for="kelamin" class="block text-sm font-medium leading-6 ">Jenis Kelamin</label>
              <div class="mt-2">
                <select id="kelamin" name="kelamin" class="block w-full rounded-md border-0 py-1.5 shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3 focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
                  <option value="Laki-laki" <?php if ($kelamin == 'Laki-laki') echo 'selected'; ?>>Laki-laki</option>
                  <option value="Perempuan" <?php if ($kelamin == 'Perempuan') echo 'selected'; ?>>Perempuan</option>
                </select>
              </div>
            </div>
            <div class="col-span-3">
              <label for="jurusan" class="block text-sm font-medium leading-6 ">Jurusan</label>
              <div class="mt-2">
                <select id="jurusan" name="jurusan" autocomplete="jurusan" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
                  <option>D4 Teknik Informatika</option>
                </select>
              </div>
            </div>
            <div class="col-span-3">
              <label for="email" class="block text-sm font-medium leading-6 ">Email</label>
              <div class="mt-2">
                <input id="email" name="email" type="email" value="<?php echo $email ?>" autocomplete="email" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>


            <div class="col-span-3">
              <label for="alamat" class="block text-sm font-medium leading-6 ">Alamat</label>
              <div class="mt-2">
                <input type="text" name="alamat" id="alamat" value="<?php echo $alamat ?>" autocomplete="alamat" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>

            <div class="col-span-3 ">
              <label for="nohp" class="block text-sm font-medium leading-6 ">No. HP</label>
              <div class="mt-2">
                <input type="text" name="nohp" id="nohp" value="<?php echo $nohp ?>" autocomplete="nohp" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>

            <div class="col-span-3">
              <label for="tempat_lahir" class="block text-sm font-medium leading-6 ">Tempat Lahir</label>
              <div class="mt-2">
                <input type="text" name="tempat_lahir" value="<?php echo $tempat_lahir ?>" id="tempat_lahir" autocomplete="tempat_lahir" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>
            <div class="col-span-3">
              <label for="tanggal_lahir" class="block text-sm font-medium leading-6 ">Tanggal Lahir</label>
              <div class="mt-2">
                <input type="date" name="tanggal_lahir" value="<?php echo $tanggal_lahir ?>" id="tanggal_lahir" autocomplete="tanggal_lahir" class="block w-full rounded-md border-0 py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>
            <div class="col-span-3">
              <label for="asal_sma" class="block text-sm font-medium leading-6 ">Asal SMA</label>
              <div class="mt-2">
                <input type="text" name="asal_sma" id="asal_sma" value="<?php echo $asal_sma ?>" autocomplete="asal_sma" class="block w-full rounded-md border-1 border-white py-1.5  shadow-sm ring-1 ring-inset ring-gray-300 placeholder:text-gray-400 text-indigo-500 font-semibold pl-3  focus:ring-2 focus:ring-inset focus:ring-indigo-600 sm:text-sm sm:leading-6">
              </div>
            </div>

          </div>
        </div>
      </div>
      <div class="flex items-center gap-x-6">
        <a href="index.php" class="w-3/12 text-sm text-center border py-2 rounded-md border-indigo-600 font-semibold leading-6 ">Cancel</a>
        <button type="submit" name="submit" class="w-3/12 rounded-md bg-indigo-600 px-3 py-3 text-sm font-semibold text-white shadow-sm">Save</button>
      </div>
  </form>
</body>

</html>
<?php
if (isset($_POST['submit'])) {

  include "conn.php";

  $nrp = $_POST['nrp'];
  $nama = $_POST['name'];
  $kelamin = $_POST['kelamin'];
  $jurusan = $_POST['jurusan'];
  $email = $_POST['email'];
  $alamat = $_POST['alamat'];
  $nohp = $_POST['nohp'];
  $asal_sma = $_POST['asal_sma'];
  $tempat_lahir = $_POST['tempat_lahir'];
  $tanggal_lahir = $_POST['tanggal_lahir'];

  $sql = "UPDATE `mahasiswa` SET 
        `nama` = '$nama', 
        `jenis_kelamin` = '$kelamin', 
        `jurusan` = '$jurusan', 
        `email` = '$email', 
        `alamat` = '$alamat', 
        `nohp` = '$nohp', 
        `asal_sma` = '$asal_sma', 
        `tempat_lahir` = '$tempat_lahir', 
        `tanggal_lahir` = '$tanggal_lahir', 
        `nrp` = '31236000$nrp'
        WHERE `nrp` = '31236000$nrp_short'";

  if ($conn->query($sql) === TRUE) {
    echo '<div class="mt-5 p-4 mb-4 text-sm text-green-800 rounded-lg bg-green-50 dark:bg-gray-700 dark:text-green-400" role="alert"><span class="font-medium">';
    echo "New record updates successfully";
    echo '</span></div>';
  } else {
    echo '<div class="mt-5 p-4 mb-4 text-sm text-red-800 rounded-lg bg-red-50 dark:bg-gray-700 dark:text-green-400" role="alert"><span class="font-medium">';
    echo "Error updating record: " . $conn->error;
    echo '</span></div>';
  }

  $conn->close();
}
?>
