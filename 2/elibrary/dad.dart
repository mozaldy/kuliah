class Siswa {
  String nama;
  int nim;
  String prodi;
  
  Siswa(this.nama, this.nim, this.prodi);
}

class Buku {
  String judul;
  String pengarang;
  String penerbit;
  
  Buku(this.judul, this.pengarang, this.penerbit);
}

class Transaksi {
  void pinjamBuku(Siswa siswa, Buku buku) {
    print("===================");
    print('=> Data Peminjaman');
    print('Nama : ${siswa.nama}');
    print('Nim : ${siswa.nim}');
    print('Prodi : ${siswa.prodi}');
    print('Buku : ${buku.judul}');
    print('Pengarang : ${buku.pengarang}');
    print('Penerbit : ${buku.penerbit}');
  }

    void kembalikanBuku(Siswa siswa, Buku buku) {
    print("===================");
    print('=> Data Pengembalian');
    print("${siswa.nama} (Nim: ${siswa.nim}, Prodi: ${siswa.prodi}) mengembalikan buku ${buku.judul}");
  }
  
  void perpanjangPeminjaman(Siswa siswa, Buku buku) {
  print("===================");
  print('=> Data Perpanjang');
    print('${siswa.nama} memperpanjang peminjaman buku ${buku.judul}');
  }
}

void main() {
  print("Perpustakaan Abal - Abal");
  // inisialisasi objek siswa
  Siswa siswa1 = new Siswa("Alvian", 111, "TRPL");
  Siswa siswa2 = new Siswa("Ari", 222, "AGB");
  Siswa siswa3 = new Siswa("Nugroho", 333, "TRM");


  // inisialisasi objek buku
  Buku buku1 = new Buku("Harry Potter", "J.K. Rowling", "Bloomsbury Publishing");
  Buku buku2 = new Buku("The Hunger Games", "Suzanne Collins", "Scholastic Press");
  Buku buku3 = new Buku("To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.");

  // inisialisasi objek transaksi
  Transaksi transaksi = new Transaksi();
  
  // contoh pemanggilan fungsi pada objek transaksi
  transaksi.pinjamBuku(siswa1, buku1);
  transaksi.pinjamBuku(siswa2, buku2);
  transaksi.pinjamBuku(siswa3, buku3);

// contoh pemanggilan fungsi pada objek transaksi
  transaksi.kembalikanBuku(siswa2, buku2);
  transaksi.perpanjangPeminjaman(siswa3, buku3);
}