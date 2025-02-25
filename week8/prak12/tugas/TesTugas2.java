public class TesTugas2 {
  public static void main(String[] args) {
    Katak katak = new Katak(5, "Froggy");
    System.out.println(
        "O1 - Nama: "
            + katak.nama
            + ", Umur: "
            + katak.umur
            + ", Cara Bergerak: "
            + katak.caraBergerak());

    Kecebong kecebong = new Kecebong(2, "Junior Frog", 10);
    System.out.println(
        "O2 - Nama: "
            + kecebong.nama
            + ", Umur: "
            + kecebong.umur
            + ", Panjang Ekor: "
            + kecebong.panjangEkor
            + ", Cara Bergerak: berenang");
  }
}
