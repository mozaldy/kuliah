package perbankan;

public class Nasabah {
  private String namaAwal;
  private String namaAkhir;
  private Tabungan tabungan;

  public Nasabah(String namaAwal, String namaAkhir) {
    this.namaAwal = namaAwal;
    this.namaAkhir = namaAkhir;
    this.tabungan = new Tabungan(0);
  }

  public Tabungan getTabungan() {
    return tabungan;
  }

  public void setTabungan(Tabungan tabungan) {
    this.tabungan = tabungan;
  }

  public String getNamaAwal() {
    return namaAwal;
  }

  public String getNamaAkhir() {
    return namaAkhir;
  }

  public void setNamaAwal(String namaAwal) {
    this.namaAwal = namaAwal;
  }

  public void setNamaAkhir(String namaAkhir) {
    this.namaAkhir = namaAkhir;
  }
}
