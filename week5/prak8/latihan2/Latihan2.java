public class Latihan2 {
  public static void main(String args[]) {
    boolean status;
    Truk truk = new Truk(900);
    System.out.println("Muatan maksimal = " + truk.getMuatanMaks());
    status = truk.tambahMuatan(500.0);
    System.out.println("Tambah muatan : 500");
    if (status) System.out.println("Ok");
    else System.out.println("Gagal");
    status = truk.tambahMuatan(300.0);
    System.out.println("Tambah muatan : 300");
    if (status) System.out.println("Ok");

    System.out.println("Gagal");
    status = truk.tambahMuatan(150.0);
    System.out.println("Tambah muatan : 150");
    if (status) System.out.println("Ok");
    else System.out.println("Gagal");
    status = truk.tambahMuatan(50.0);
    System.out.println("Tambah muatan : 50");
    if (status) System.out.println("Ok");
    else System.out.println("Gagal");
    System.out.println("Muatan sekarang = " + truk.getMuatan());
  }
}
