<?php
include 'guard.php';
?>
<!doctype html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Tables | TailAdmin - Tailwind CSS Admin Dashboard Template</title>
  <link rel="icon" href="favicon.ico" />
  <link href="style.css" rel="stylesheet" />
</head>

<body x-data="{ page: 'tables', 'loaded': true, 'darkMode': true, 'stickyMenu': false, 'sidebarToggle': false, 'scrollTop': false }" x-init="
          darkMode = JSON.parse(localStorage.getItem('darkMode'));
          $watch('darkMode', value => localStorage.setItem('darkMode', JSON.stringify(value)))" :class="{'dark text-bodydark bg-boxdark-2': darkMode === true}">
  <!-- ===== Page Wrapper Start ===== -->
  <div class="flex h-screen overflow-hidden">
    <!-- ===== Sidebar Start ===== -->

    <aside :class="sidebarToggle ? 'translate-x-0' : '-translate-x-full'" class="absolute left-0 top-0 z-9999 flex h-screen w-72.5 flex-col overflow-y-hidden bg-indigo-800 duration-300 ease-linear dark:bg-boxdark lg:static lg:translate-x-0" @click.outside="sidebarToggle = false">
      <!-- SIDEBAR HEADER -->
      <div class="flex items-center justify-between gap-2 px-6 py-5.5 lg:py-6.5">
        <a href="index.php">
          <p class="text-2xl text-white">
            Selamat datang, <span class="font-extrabold"><?php
                                                          echo $_SESSION["user_data"]["username"]
                                                          ?>!</span>
          </p>
        </a>

        <button class="block lg:hidden" @click.stop="sidebarToggle = !sidebarToggle">
          <svg class="fill-current" width="20" height="18" viewBox="0 0 20 18" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path d="M19 8.175H2.98748L9.36248 1.6875C9.69998 1.35 9.69998 0.825 9.36248 0.4875C9.02498 0.15 8.49998 0.15 8.16248 0.4875L0.399976 8.3625C0.0624756 8.7 0.0624756 9.225 0.399976 9.5625L8.16248 17.4375C8.31248 17.5875 8.53748 17.7 8.76248 17.7C8.98748 17.7 9.17498 17.625 9.36248 17.475C9.69998 17.1375 9.69998 16.6125 9.36248 16.275L3.02498 9.8625H19C19.45 9.8625 19.825 9.4875 19.825 9.0375C19.825 8.55 19.45 8.175 19 8.175Z" fill="" />
          </svg>
        </button>
      </div>
      <!-- SIDEBAR HEADER -->

      <div class="no-scrollbar flex h-full flex-col overflow-y-auto duration-300 ease-linear">
        <!-- Sidebar Menu -->
        <nav class="mt-5 flex h-full flex-col justify-between px-4 py-4 lg:mt-9 lg:px-6" x-data="{selected: $persist('overview')}">
          <!-- Menu Group -->
          <div>
            <h3 class="mb-4 ml-4 text-sm font-medium text-bodydark2">MENU</h3>

            <ul class="mb-6 flex flex-col gap-1.5">
              <!-- Menu Item Dashboard -->
              <li>
                <a class="group relative flex items-center gap-2.5 rounded-md px-4 py-2 font-medium text-bodydark1 duration-300 ease-in-out hover:bg-indigo-600 dark:hover:bg-meta-4" href="index.php" :class="{ 'bg-indigo-600 dark:bg-meta-4': (selected === 'overview') }" @click="selected = (selected === 'overview' ? 'overview':'')">
                  <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="h-6 w-6">
                    <path stroke-linecap="round" stroke-linejoin="round" d="m2.25 12 8.954-8.955c.44-.439 1.152-.439 1.591 0L21.75 12M4.5 9.75v10.125c0 .621.504 1.125 1.125 1.125H9.75v-4.875c0-.621.504-1.125 1.125-1.125h2.25c.621 0 1.125.504 1.125 1.125V21h4.125c.621 0 1.125-.504 1.125-1.125V9.75M8.25 21h8.25" />
                  </svg>

                  Overview
                </a>
              </li>
              <!-- Menu Item Dashboard -->

              <!-- Menu Item Profile -->
              <li>
                <a class="group relative flex items-center gap-2.5 rounded-md px-4 py-2 font-medium text-bodydark1 duration-300 ease-in-out hover:bg-indigo-600 dark:hover:bg-meta-4" href="profile.php" @click="selected = (selected === 'Profile' ? '':'Profile')" :class="{ 'bg-indigo-600 dark:bg-meta-4': (selected === 'Profile') }" :class="page === 'profile' && 'bg-indigo-600'">
                  <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="h-6 w-6">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M15.75 6a3.75 3.75 0 1 1-7.5 0 3.75 3.75 0 0 1 7.5 0ZM4.501 20.118a7.5 7.5 0 0 1 14.998 0A17.933 17.933 0 0 1 12 21.75c-2.676 0-5.216-.584-7.499-1.632Z" />
                  </svg>

                  Profil User
                </a>
              </li>
              <!-- Menu Item Profile -->

              <!-- Menu Item Data Mahasiswa -->
              <li>
                <a class="group relative flex items-center gap-2.5 rounded-md py-2 px-4 font-medium text-bodydark1 duration-300 ease-in-out hover:bg-indigo-600 dark:hover:bg-meta-4" href="data_mahasiswa.php" @click="selected = (selected === 'data_mahasiswa' ? '':'data_mahasiswa')" :class="{ 'bg-indigo-600 dark:bg-meta-4': (selected === 'data_mahasiswa') && (page === 'tables') }">
                  <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="h-6 w-6">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M18 18.72a9.094 9.094 0 0 0 3.741-.479 3 3 0 0 0-4.682-2.72m.94 3.198.001.031c0 .225-.012.447-.037.666A11.944 11.944 0 0 1 12 21c-2.17 0-4.207-.576-5.963-1.584A6.062 6.062 0 0 1 6 18.719m12 0a5.971 5.971 0 0 0-.941-3.197m0 0A5.995 5.995 0 0 0 12 12.75a5.995 5.995 0 0 0-5.058 2.772m0 0a3 3 0 0 0-4.681 2.72 8.986 8.986 0 0 0 3.74.477m.94-3.197a5.971 5.971 0 0 0-.94 3.197M15 6.75a3 3 0 1 1-6 0 3 3 0 0 1 6 0Zm6 3a2.25 2.25 0 1 1-4.5 0 2.25 2.25 0 0 1 4.5 0Zm-13.5 0a2.25 2.25 0 1 1-4.5 0 2.25 2.25 0 0 1 4.5 0Z" />
                  </svg>

                  Data Mahasiswa
                </a>
              </li>
              <!-- Menu Item Tables -->

              <!-- Menu Item Settings -->
              <li>
                <a class="group relative flex items-center gap-2.5 rounded-md py-2 px-4 font-medium text-bodydark1 duration-300 ease-in-out hover:bg-indigo-600 dark:hover:bg-meta-4" href="data_tugas.php" @click="selected = (selected === 'data_tugas' ? '':'data_tugas')" :class="{ 'bg-indigo-600 dark:bg-meta-4': (selected === 'data_tugas') }" :class="page === 'settings' && 'bg-indigo-600'">
                  <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="h-6 w-6">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M6 6.878V6a2.25 2.25 0 0 1 2.25-2.25h7.5A2.25 2.25 0 0 1 18 6v.878m-12 0c.235-.083.487-.128.75-.128h10.5c.263 0 .515.045.75.128m-12 0A2.25 2.25 0 0 0 4.5 9v.878m13.5-3A2.25 2.25 0 0 1 19.5 9v.878m0 0a2.246 2.246 0 0 0-.75-.128H5.25c-.263 0-.515.045-.75.128m15 0A2.25 2.25 0 0 1 21 12v6a2.25 2.25 0 0 1-2.25 2.25H5.25A2.25 2.25 0 0 1 3 18v-6c0-.98.626-1.813 1.5-2.122" />
                  </svg>

                  Data Tugas
                </a>
              </li>
              <!-- Menu Item Settings -->
            </ul>
          </div>

          <!-- Others Group -->
          <div>
            <ul class="mb-6 flex flex-col gap-1.5">
              <!-- Menu Item Auth Pages -->
              <li class="mt-auto">
                <a class="group relative flex items-center gap-2.5 rounded-md bg-red-600 px-4 py-2 font-medium text-bodydark1 duration-300 ease-in-out hover:bg-red-900 dark:hover:bg-meta-4" href="logout.php" :class="{ 'bg-indigo-600 dark:bg-meta-4': (selected === 'AuthPages') || (page === 'register' || page === 'login') }">
                  <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="h-6 w-6">
                    <path stroke-linecap="round" stroke-linejoin="round" d="M8.25 9V5.25A2.25 2.25 0 0 1 10.5 3h6a2.25 2.25 0 0 1 2.25 2.25v13.5A2.25 2.25 0 0 1 16.5 21h-6a2.25 2.25 0 0 1-2.25-2.25V15m-3 0-3-3m0 0 3-3m-3 3H15" />
                  </svg>

                  Log Out
                </a>
              </li>
              <!-- Menu Item Auth Pages -->
            </ul>
          </div>
        </nav>
        <!-- Sidebar Menu -->
      </div>
    </aside>

    <!-- ===== Sidebar End ===== -->

    <!-- ===== Content Area Start ===== -->
    <div class="relative flex flex-1 flex-col overflow-y-auto overflow-x-hidden">
      <!-- ===== Header Start ===== -->

      <!-- ===== Header End ===== -->

      <!-- ===== Main Content Start ===== -->
      <main>
        <div class="mx-auto max-w-screen-2xl p-4 md:p-6 2xl:p-10">
          <!-- Breadcrumb Start -->
          <div class="mb-6 flex flex-col gap-3 sm:flex-row sm:items-center sm:justify-between">
            <h2 class="text-title-md2 font-bold text-black dark:text-white">
              Data Mahasiswa
            </h2>

            <nav>
              <ol class="flex items-center gap-2">
                <li>
                  <a class="font-medium" href="index.php">Dashboard /</a>
                </li>
                <li class="font-medium text-primary">Data Mahasiswa</li>
              </ol>
            </nav>
          </div>
          <!-- Breadcrumb End -->

          <!-- ====== Table Section Start -->
          <div class="flex flex-col gap-10">
            <!-- ====== Table Two Start -->
            <div class="rounded-sm border border-stroke bg-white shadow-default dark:border-strokedark dark:bg-boxdark">
              <div class="px-4 py-6 md:px-6 xl:px-7.5">
                <h4 class="text-xl font-bold text-black dark:text-white">
                  Top Products
                </h4>
              </div>

              <div class="grid grid-cols-6 border-t border-stroke px-4 py-4.5 dark:border-strokedark sm:grid-cols-8 md:px-6 2xl:px-7.5">
                <div class="col-span-1 flex items-center">
                  <p class="font-medium">NRP</p>
                </div>
                <div class="col-span-2 hidden items-center sm:flex">
                  <p class="font-medium">Nama</p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="font-medium">Jenis Kelamin</p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="font-medium">Tempat Lahir</p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="font-medium">Tanggal Lahir</p>
                </div>
                <div class="col-span-2 flex items-center">
                  <p class="font-medium">Alamat</p>
                </div>
              </div>

              <div class="grid grid-cols-6 border-t border-stroke px-4 py-4.5 dark:border-strokedark sm:grid-cols-8 md:px-6 2xl:px-7.5">
                <div class="col-span-1 flex items-center">
                  <div class="flex flex-col gap-4 sm:flex-row sm:items-center">
                    <p class="text-sm font-medium text-black dark:text-white">
                      3123600011
                    </p>
                  </div>
                </div>
                <div class="col-span-2 hidden items-center sm:flex">
                  <p class="text-sm font-medium text-black dark:text-white">
                    Mohammad Rizaldy Ramadhan
                  </p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="text-sm font-medium text-black dark:text-white">
                    Laki-laki
                  </p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="text-sm font-medium text-black dark:text-white">
                    Banyuwangi
                  </p>
                </div>
                <div class="col-span-1 flex items-center">
                  <p class="text-sm font-medium text-black dark:text-white">
                    20-10-2004
                  </p>
                </div>
                <div class="col-span-2 flex items-center">
                  <p class="text-sm font-medium text-black dark:text-white">
                    Jl. Basuki Rahmat No. 105
                  </p>
                </div>
              </div>
            </div>

            <!-- ====== Table Two End -->
          </div>
          <!-- ====== Table Section End -->
        </div>
      </main>
      <!-- ===== Main Content End ===== -->
    </div>
    <!-- ===== Content Area End ===== -->
  </div>
  <!-- ===== Page Wrapper End ===== -->
  <script defer src="bundle.js"></script>
</body>

</html>
