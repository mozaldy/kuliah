<html>

<head>
  <script src="https://cdn.tailwindcss.com"></script>
</head>

<body class="bg-slate-800">
  <div class="container text-white mx-auto w-10/12">
    <div class="lg:flex lg:items-center mt-10 lg:justify-between">
      <div class="min-w-0 flex-1">
        <h2 class="text-4xl  font-bold leading-7 ">Data kelas D4 IT A '23</h2>
      </div>
      <div class="mt-5 flex lg:ml-4 lg:mt-0">

        <span class="sm:ml-3">
          <a href="create.php">
            <button type="button" class="inline-flex items-center rounded-md bg-indigo-600 px-3 py-2 text-sm font-semibold text-white shadow-sm hover:bg-indigo-500 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600">
              <svg class="-ml-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" fill="white" viewBox="0 0 20 20" stroke-width="1.5" stroke="currentColor">
                <path stroke-linecap="round" stroke-linejoin="round" d="M12 4.5v15m7.5-7.5h-15" />
              </svg>
              Create
            </button>
          </a>
        </span>

      </div>
    </div>
    <table class="w-full table-auto mt-10 text-white border-collapse text-lg">
      <thead>
        <tr>
          <th class="border-4 border-indigo-600">No</th>
          <th class="border-4 border-indigo-600">NRP</th>
          <th class="border-4 border-indigo-600">Nama</th>
          <th class="border-4 border-indigo-600">Jenis Kelamin</th>
          <th class="border-4 border-indigo-600">Action</th>
        </tr>
      </thead>
      <tbody>
        <?php
        include 'conn.php';
        $sql = "SELECT * FROM mahasiswa";
        $result = $conn->query($sql);
        if ($result->num_rows > 0) {
          $counter = 1;
          while ($row = $result->fetch_assoc()) {
            echo '<tr>';
            echo '<td class="text-center border-4 border-indigo-600">' . $counter . '</td>';
            echo '<td class="border-4 p-3 border-indigo-600">' . $row["nrp"] . '</td>';
            echo '<td class="border-4 p-3 border-indigo-600">' . $row["nama"] . '</td>';
            echo '<td class="border-4 p-3 border-indigo-600">' . $row["jenis_kelamin"] . '</td>';
            echo '<td class="border-4 p-3 border-indigo-600 text-center">';
            echo '<button onclick="location.href=\'update.php?nrp=' . $row["nrp"] . '\'" type="button" class="inline-flex items-center rounded-md bg-white px-3 py-2 text-sm font-semibold text-indigo-500 shadow-sm ring-1 ring-inset ring-gray-300 hover:bg-gray-50 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600 mr-2">';
            echo '<svg class="-ml-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="none" stroke="currentColor">';
            echo '<path d="M2.695 14.763l-1.262 3.154a.5.5 0 00.65.65l3.155-1.262a4 4 0 001.343-.885L17.5 5.5a2.121 2.121 0 00-3-3L3.58 13.42a4 4 0 00-.885 1.343z" />';
            echo '</svg>';
            echo 'Edit';
            echo '</button>';
            echo '<button onclick="location.href=\'delete.php?nrp=' . $row["nrp"] . '\'" type="button" class="inline-flex items-center rounded-md bg-red-500 px-3 py-2 text-sm font-semibold text-white shadow-sm ring-1 ring-inset ring-gray-300 hover:bg-red-400 focus-visible:outline focus-visible:outline-2 focus-visible:outline-offset-2 focus-visible:outline-indigo-600 mr-2">';
            echo '<svg class="-ml-0.5 mr-1.5 h-5 w-5" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20" fill="none" stroke="currentColor">';
            echo '<path d="M2.695 14.763l-1.262 3.154a.5.5 0 00.65.65l3.155-1.262a4 4 0 001.343-.885L17.5 5.5a2.121 2.121 0 00-3-3L3.58 13.42a4 4 0 00-.885 1.343z" />';
            echo '</svg>';
            echo 'Delete';
            echo '</button>';
            echo '</td>';
            echo '</tr>';
            $counter++;
          }
        } else {
          echo '<tr>';
          echo '<td class="text-center border-4 border-indigo-600">Data Masih Kosong!</td>';
          echo '</tr>';
        }
        ?>
      </tbody>
    </table>
  </div>
</body>

</html>
