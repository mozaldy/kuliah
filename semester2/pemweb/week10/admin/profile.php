<?php
include 'guard.php';
?>
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Profile | TailAdmin - Tailwind CSS Admin Dashboard Template</title>
  <link rel="icon" href="favicon.ico">
  <link href="style.css" rel="stylesheet">
</head>

<body x-data="{ page: 'profile', 'loaded': true, 'darkMode': true, 'stickyMenu': false, 'sidebarToggle': false, 'scrollTop': false }" x-init="
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
          <div class="mx-auto max-w-242.5">
            <!-- Breadcrumb Start -->
            <div class="mb-6 flex flex-col gap-3 sm:flex-row sm:items-center sm:justify-between">
              <h2 class="text-title-md2 font-bold text-black dark:text-white">
                Profile
              </h2>

              <nav>
                <ol class="flex items-center gap-2">
                  <li>
                    <a class="font-medium" href="index.php">Dashboard /</a>
                  </li>
                  <li class="text-primary">Profile</li>
                </ol>
              </nav>
            </div>
            <!-- Breadcrumb End -->

            <!-- ====== Profile Section Start -->
            <div class="overflow-hidden rounded-sm border border-stroke bg-white shadow-default dark:border-strokedark dark:bg-boxdark">
              <div class="relative z-20 h-35 md:h-65">
                <img src="https://th.bing.com/th/id/OIP._seiyPSuwjDxd4JOIDt7ZwAAAA?rs=1&pid=ImgDetMain" alt="profile cover" class="h-full w-full rounded-tl-sm rounded-tr-sm object-cover object-center" />
                <div class="absolute bottom-1 right-1 z-10 xsm:bottom-4 xsm:right-4">
                  <label for="cover" class="flex cursor-pointer items-center justify-center gap-2 rounded bg-primary px-2 py-1 text-sm font-medium text-white hover:bg-opacity-80 xsm:px-4">
                    <input type="file" name="cover" id="cover" class="sr-only" />
                    <span>
                      <svg class="fill-current" width="14" height="14" viewBox="0 0 14 14" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <path fill-rule="evenodd" clip-rule="evenodd" d="M4.76464 1.42638C4.87283 1.2641 5.05496 1.16663 5.25 1.16663H8.75C8.94504 1.16663 9.12717 1.2641 9.23536 1.42638L10.2289 2.91663H12.25C12.7141 2.91663 13.1592 3.101 13.4874 3.42919C13.8156 3.75738 14 4.2025 14 4.66663V11.0833C14 11.5474 13.8156 11.9925 13.4874 12.3207C13.1592 12.6489 12.7141 12.8333 12.25 12.8333H1.75C1.28587 12.8333 0.840752 12.6489 0.512563 12.3207C0.184375 11.9925 0 11.5474 0 11.0833V4.66663C0 4.2025 0.184374 3.75738 0.512563 3.42919C0.840752 3.101 1.28587 2.91663 1.75 2.91663H3.77114L4.76464 1.42638ZM5.56219 2.33329L4.5687 3.82353C4.46051 3.98582 4.27837 4.08329 4.08333 4.08329H1.75C1.59529 4.08329 1.44692 4.14475 1.33752 4.25415C1.22812 4.36354 1.16667 4.51192 1.16667 4.66663V11.0833C1.16667 11.238 1.22812 11.3864 1.33752 11.4958C1.44692 11.6052 1.59529 11.6666 1.75 11.6666H12.25C12.4047 11.6666 12.5531 11.6052 12.6625 11.4958C12.7719 11.3864 12.8333 11.238 12.8333 11.0833V4.66663C12.8333 4.51192 12.7719 4.36354 12.6625 4.25415C12.5531 4.14475 12.4047 4.08329 12.25 4.08329H9.91667C9.72163 4.08329 9.53949 3.98582 9.4313 3.82353L8.43781 2.33329H5.56219Z" fill="white" />
                        <path fill-rule="evenodd" clip-rule="evenodd" d="M6.99992 5.83329C6.03342 5.83329 5.24992 6.61679 5.24992 7.58329C5.24992 8.54979 6.03342 9.33329 6.99992 9.33329C7.96642 9.33329 8.74992 8.54979 8.74992 7.58329C8.74992 6.61679 7.96642 5.83329 6.99992 5.83329ZM4.08325 7.58329C4.08325 5.97246 5.38909 4.66663 6.99992 4.66663C8.61075 4.66663 9.91659 5.97246 9.91659 7.58329C9.91659 9.19412 8.61075 10.5 6.99992 10.5C5.38909 10.5 4.08325 9.19412 4.08325 7.58329Z" fill="white" />
                      </svg>
                    </span>
                    <span>Edit</span>
                  </label>
                </div>
              </div>
              <div class="px-4 pb-6 text-center lg:pb-8 xl:pb-11.5">
                <div class="relative z-30 mx-auto -mt-22 h-30 w-full max-w-30 rounded-full bg-white/20 p-1 backdrop-blur sm:h-44 sm:max-w-44 sm:p-3">
                  <div class="relative drop-shadow-2">
                    <img src="https://i.kym-cdn.com/photos/images/original/002/301/442/6a6.png" alt="profile" class="rounded-full" />
                    <label for="profile" class="absolute bottom-0 right-0 flex h-8.5 w-8.5 cursor-pointer items-center justify-center rounded-full bg-primary text-white hover:bg-opacity-90 sm:bottom-2 sm:right-2">
                      <svg class="fill-current" width="14" height="14" viewBox="0 0 14 14" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <path fill-rule="evenodd" clip-rule="evenodd" d="M4.76464 1.42638C4.87283 1.2641 5.05496 1.16663 5.25 1.16663H8.75C8.94504 1.16663 9.12717 1.2641 9.23536 1.42638L10.2289 2.91663H12.25C12.7141 2.91663 13.1592 3.101 13.4874 3.42919C13.8156 3.75738 14 4.2025 14 4.66663V11.0833C14 11.5474 13.8156 11.9925 13.4874 12.3207C13.1592 12.6489 12.7141 12.8333 12.25 12.8333H1.75C1.28587 12.8333 0.840752 12.6489 0.512563 12.3207C0.184375 11.9925 0 11.5474 0 11.0833V4.66663C0 4.2025 0.184374 3.75738 0.512563 3.42919C0.840752 3.101 1.28587 2.91663 1.75 2.91663H3.77114L4.76464 1.42638ZM5.56219 2.33329L4.5687 3.82353C4.46051 3.98582 4.27837 4.08329 4.08333 4.08329H1.75C1.59529 4.08329 1.44692 4.14475 1.33752 4.25415C1.22812 4.36354 1.16667 4.51192 1.16667 4.66663V11.0833C1.16667 11.238 1.22812 11.3864 1.33752 11.4958C1.44692 11.6052 1.59529 11.6666 1.75 11.6666H12.25C12.4047 11.6666 12.5531 11.6052 12.6625 11.4958C12.7719 11.3864 12.8333 11.238 12.8333 11.0833V4.66663C12.8333 4.51192 12.7719 4.36354 12.6625 4.25415C12.5531 4.14475 12.4047 4.08329 12.25 4.08329H9.91667C9.72163 4.08329 9.53949 3.98582 9.4313 3.82353L8.43781 2.33329H5.56219Z" fill="" />
                        <path fill-rule="evenodd" clip-rule="evenodd" d="M7.00004 5.83329C6.03354 5.83329 5.25004 6.61679 5.25004 7.58329C5.25004 8.54979 6.03354 9.33329 7.00004 9.33329C7.96654 9.33329 8.75004 8.54979 8.75004 7.58329C8.75004 6.61679 7.96654 5.83329 7.00004 5.83329ZM4.08337 7.58329C4.08337 5.97246 5.38921 4.66663 7.00004 4.66663C8.61087 4.66663 9.91671 5.97246 9.91671 7.58329C9.91671 9.19412 8.61087 10.5 7.00004 10.5C5.38921 10.5 4.08337 9.19412 4.08337 7.58329Z" fill="" />
                      </svg>
                      <input type="file" name="profile" id="profile" class="sr-only" />
                    </label>
                  </div>
                </div>
                <div class="mt-4">
                  <h3 class="mb-1.5 text-2xl font-medium text-black dark:text-white">
                    Mohammad Rizaldy Ramadhan
                  </h3>
                  <p class="font-medium">3123600011</p>
                  <div class="mx-auto mb-5.5 mt-4.5 grid max-w-94 grid-cols-3 rounded-md border border-stroke py-2.5 shadow-1 dark:border-strokedark dark:bg-[#37404F]">
                    <div class="flex flex-col items-center justify-center gap-1 border-r border-stroke px-4 dark:border-strokedark">
                      <span class="flex-grow text-sm">Tempat Lahir</span>
                      <span class="flex-grow font-semibold text-black dark:text-white">Banyuwangi</span>
                    </div>

                    <div class="flex flex-col items-center justify-center gap-1 border-r border-stroke px-4 dark:border-strokedark">
                      <span class="flex-grow text-sm">Tanggal Lahir</span>
                      <span class="flex-grow font-semibold text-black dark:text-white">20 Oktober 2004</span>
                    </div>
                    <div class="flex flex-col items-center justify-center gap-1 border-r border-stroke px-4 dark:border-strokedark">
                      <span class="flex-grow text-sm">Jenis Kelamin</span>
                      <span class="flex-grow font-semibold text-black dark:text-white">Laki-laki</span>
                    </div>
                  </div>

                  <div class="mx-auto max-w-180">
                    <h4 class="font-medium text-black dark:text-white">
                      Alamat
                    </h4>
                    <p class="mt-4.5 text-sm font-normal">
                      Jl. Basuki Rahmat No. 105
                    </p>
                  </div>

                  <div class="mt-10 mx-auto max-w-180">
                    <h4 class="font-medium text-black dark:text-white">
                      Asal Sekolah
                    </h4>
                    <p class="mt-4.5 text-sm font-normal">
                      SMKN 1 Banyuwangi
                    </p>
                  </div>
                  <div class="mt-10 mx-auto max-w-180">
                    <h4 class="font-medium text-black dark:text-white">
                      No. HP
                    </h4>
                    <p class="mt-4.5 text-sm font-normal">
                      081252881115
                    </p>
                  </div>
                </div>
              </div>
              <!-- ====== Profile Section End -->
            </div>
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
