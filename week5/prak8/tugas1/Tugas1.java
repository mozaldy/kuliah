public class Tugas1 {
  public static void main(String[] args) {
    MultiTabungan tabungan = new MultiTabungan(10000);
    System.out.println("Tabungan awal: " + tabungan.getSaldo());

    tabungan.simpanUang(10, "USD");
    System.out.println("Setelah deposit USD: " + tabungan.getSaldo());

    tabungan.ambilUang(5, "AUD");
    System.out.println("Setelah tarikan AUD: " + tabungan.getSaldo());
  }
}
