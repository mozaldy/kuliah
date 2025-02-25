public class Mahasiswa2 {
  private int nrp;
  private String nama;

  public void Mahasiswa(int nrp, String nama) {
    setNrp(nrp);
    setNama(nama);
  }

  public int getNrp() {
    return nrp;
  }

  public void setNrp(int nrp) {
    this.nrp = nrp;
  }

  public String getNama() {
    return nama;
  }

  public void setNama(String nama) {
    this.nama = nama;
  }
}
