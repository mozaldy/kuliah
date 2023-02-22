import 'dart:io'; // Import dependencies agar user bisa input

// Deklarasi Class Student
class Student {
  String nama; // Atribut nama
  int nim; // Atribut nim

  // Constructor Utama class Student
  Student() {
    // Membaca informasi tentang Student dari input user
    stdout.write('Nama: '); // Menanyakan user nama
    nama = stdin.readLineSync(); // Membaca jawaban user
    stdout.write('Nim: '); // Menanyakan user Nim
    nim = int.parse(stdin.readLineSync()); // Membaca jawaban user
  }

  // Konstruktor statik tanpa meminta input dari user
  Student.statidInput(this.nama, this.nim);

  // Menampilkan informasi tentang student
  void displayInfo() {
    print('$nama\t$nim');
  }
}

// Deklarasi class Book
class Book {
  String judul; // Atribut judul
  String pengarang; // Atribut pengarang
  bool ketersediaan =
      true; // Atribut boolean ketersediaan (True sebagai default)

  // Konstruktor utama
  Book() {
    // Membaca informasi Book dari input user
    stdout.write('Judul: '); // Menanyakan
    judul = stdin.readLineSync(); // Membaca
    stdout.write('Pengarang: '); // Menanyakan
    pengarang = stdin.readLineSync(); // Membaca
  }
  // Konstruktor statik tanpa meminta input dari user
  Book.staticInput(this.judul, this.pengarang, this.ketersediaan);
  // Menampilkan informasi tentang student
  void displayInfo() {
    print('$judul\t\t$pengarang\t${ketersediaan ? 'Sedia' : 'Tidak sedia'}');
  }
}

// Deklarasi class Transaction
class Transaction {
  Student siswa; // Atribut siswa
  Book buku; // Atribut buku
  DateTime tglPinjam; // Atribut tanggal pinjam
  DateTime tglKembali; // Atribut tanggal kembali
  // Konstruktor Transtraction
  Transaction(students, books, aktifitas) {
    // Membaca informasi Book dari input user
    stdout.write('Nama: '); // Menanyakan nama
    var nama = stdin.readLineSync(); // Membaca nama
    stdout.write('Judul buku: '); // Menanyakan judul
    var judul = stdin.readLineSync(); // Membaca judul
    for (Student siswa in students) {}
    siswa = students.firstWhere((siswa) => (siswa.nama == nama),
        orElse: () =>
            null); // Mencari objek siswa yang sesuai dengan yang di input
    buku = books.firstWhere((buku) => (buku.judul == judul),
        orElse: () =>
            null); // Mencari objek buku yang sesuai dengan yang di input
    if (siswa == null || buku == null) {
      printMerah('Siswa $nama atau Buku $judul tidak valid!');
      return;
    }
    // Apabila nama dan judul yang diinput sudah terdaftar
    if (aktifitas == 'pinjam') // apabila aktifitas adalah pinjam
      lendBook(siswa, buku); // maka jalankan method lendBook
    else // apabila tidak
      returnBook(siswa, buku); // maka masuk method returnBook
  }
  // untuk menampilkan info object dari class ini
  void displayInfo(Student siswa, Book buku) {
    print('${siswa.nama}\t${buku.judul}\t$tglPinjam\t$tglKembali');
  }

  // method untuk peminjaman
  void lendBook(Student siswa, Book buku) {
    if (buku.ketersediaan == true) {
      // Apabila buku tersedia
      tglPinjam = DateTime.now(); // simpan waktu sekarang
      buku.ketersediaan = false; // ubah ketersediaan menjadi false
      printBiru(
          '${siswa.nama} telah meminjam ${buku.judul} pada tanggal $tglPinjam.');
      // tampilkan proses yang telah terjadi
    } else // apabila tidak ada buku yg tersedia
      printMerah('${buku.judul} tidak tersedia.');
  }

  // method untuk pengembalian
  void returnBook(Student siswa, Book buku) {
    // apabila buku tidak tersedia
    if (buku.ketersediaan == false) {
      tglKembali = DateTime.now(); // simpan waktu saat ini
      buku.ketersediaan = true; // ubah ketersediaan menjadi true
      printBiru(
          '${siswa.nama} telah mengembalikan ${buku.judul} pada tanggal $tglKembali');
    } // tampilkan proses yang telah terjadi
    else // apabila buku sudah tersedia
      printMerah('${buku.judul} belum dipinjam.');
  }
}

void main() {
  // inisialisasi array books yang didalamnya ada objek dari class Book
  List<Book> books = [
    Book.staticInput('Animal Farm', 'George Orwell', true),
    Book.staticInput('Harry Potter', 'J.K. Rowling', true),
    Book.staticInput('The Hobbit', 'J. R. R. Tolkien', true)
  ];
  // inisialisasi array students yang dialamnya ada objek dari class Student
  List<Student> students = [
    Student.statidInput('Mohammad Rizaldy', 362258302191),
    Student.statidInput('Mohammad Ramadhan', 362258302192),
    Student.statidInput('Rizaldy Ramadhan', 362258302193)
  ];
  // inisialisasi array transactions yang didalamnya ada objek dari class Transactions
  List<Transaction> transactions = [];
  // Loop selamanya
  while (true) {
    // Menanyakan user tentang menu yang ingin dipilih
    printBiru('''Welcome to Aldy'z Library''');
    stdout.write('''
1. Registrasi siswa baru
2. Daftar siswa
3. Registrasi buku baru
4. Daftar buku
5. Pinjam buku
6. Kembalikan Buku
7. Daftar transaksi
0. Keluar
> ''');
    var menu = stdin.readLineSync(); // baca menu yang diinput oleh user
    printBiru('-' * 100); // Baris berwarna bitu
    if (menu == '1') {
      // Aoabila memilih menu 1
      students.add(Student()); // tambahkan object Student ke array students
    } else if (menu == '2') {
      // Aoabila memilih menu 2
      printBiru('Nama\t\t\tNim'); // head tabel untuk siswa
      for (Student student in students) {
        // untuk setiap object student di array students
        student.displayInfo(); // masuk ke method dispalyInfo
      }
    } else if (menu == '3') {
      // Aoabila memilih menu 3
      books.add(Book()); // tambahkan object Book ke array books
    } else if (menu == '4') {
      // Aoabila memilih menu 4
      printBiru('Judul\t\t\tPengarang\tKetersediaan'); // head tabel untuk buku
      for (Book book in books) {
        // untuk setiap object book di array books
        book.displayInfo(); // masuk ke method dispalyInfo
      }
    } else if (menu == '5') {
      // Aoabila memilih menu 5
      transactions.add(Transaction(students, books,
          'pinjam')); // tambahkan object Transaction ke array transactions dan
      // masukkan parameter aktifitas 'pinjam
    } else if (menu == '6') {
      // Aoabila memilih menu 6
      transactions.add(Transaction(students, books, 'kembali'));
      // tambahkan object Transaction ke array transactions dan
      // masukkan parameter aktifitas 'pinjam
    } else if (menu == '7') {
      // Aoabila memilih menu 7
      printBiru(
          'Siswa\t\t\tBuku\t\t\tTanggal Pinjam\t\tTanggal Kembali'); // head tabel untuk transaksi
      for (Transaction transaction in transactions) {
        // untuk setiap object transaction di array transactions
        transaction.displayInfo(transaction.siswa, transaction.buku); // masuk ke method dispalyInfo
      }
    } else if (menu == '0') {
      // Aoabila memilih menu 8
      // apabila input menu 0
      printMerah('Keluar.'); // tampilkan pesan Keluar
      break; // break keluar dari while loop
    } else {
      // apabila input tidak dikenal
      printMerah('Input tidak valid.');
    }
    printBiru('-' * 100); // baris warna biru
  }
}

// fungsi untuk mewarnai string/text menjadi biru
void printBiru(String text) {
  print('\x1B[34m$text\x1B[0m');
}

// fungsi untuk mewarnai string/text menjadi merah
void printMerah(String text) {
  print('\x1B[31m$text\x1B[0m');
}
