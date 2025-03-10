public class Tabungan {

  private int saldo;

  public Tabungan(int initSaldo) {
    this.saldo = initSaldo;
  }

  public int getSaldo() {
    return saldo;
  }

  public void simpanUang(int jumlah) {
    this.saldo += jumlah;
  }

  public boolean ambilUang(int jumlah) {
    if (jumlah > saldo) {
      return false;
    } else {
      this.saldo -= jumlah;
      return true;
    }
  }
}
