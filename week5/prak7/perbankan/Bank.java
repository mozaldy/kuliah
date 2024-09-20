package perbankan;

public class Bank {
  private Nasabah[] nasabah;
  private int jumlahNasabah;

  public Bank() {
    nasabah = new Nasabah[10];
    jumlahNasabah = 0;
  }

  public void tambahNasabah(String namaAwal, String namaAkhir) {
    Nasabah nasabahBaru = new Nasabah(namaAwal, namaAkhir);
    nasabah[this.jumlahNasabah] = nasabahBaru;
    this.jumlahNasabah++;
  }

  public int getJumlahNasabah() {
    return this.jumlahNasabah;
  }

  public Nasabah getNasabah(int indeks) {
    return nasabah[indeks];
  }
}
