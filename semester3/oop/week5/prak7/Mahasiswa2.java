public class Mahasiswa2 {
  private int nrp;
  private String nama;

  public Mahasiswa2() {
    this(0, "");
  }

  public Mahasiswa2(String nama) {
    this(0, nama);
  }

  public Mahasiswa2(int nrp, String nama) {
    this.nrp = nrp;
    this.nama = nama;
  }
}
