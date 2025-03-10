public class Mahasiswa {
  public int nrp;
  public String nama;

  public Mahasiswa() {
    this.nrp = 0;
    this.nama = "";
  }

  public Mahasiswa(String nama) {
    this.nrp = 0;
    this.nama = nama;
  }

  public Mahasiswa(int nrp, String nama) {
    this.nrp = nrp;
    this.nama = nama;
  }
}
