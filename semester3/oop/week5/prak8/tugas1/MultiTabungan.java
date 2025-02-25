public class MultiTabungan {
  private int saldo;

  public MultiTabungan(int saldo) {
    setSaldo(saldo);
  }

  public void setSaldo(int saldo) {
    this.saldo = saldo;
  }

  public int getSaldo() {
    return this.saldo;
  }

  public void simpanUang(int jumlah, String currency) {
    this.saldo += convertToIdr(jumlah, currency);
  }

  public boolean ambilUang(int jumlah, String currency) {
    int jumlahIdr = convertToIdr(jumlah, currency);
    if (jumlahIdr > this.saldo) {
      System.out.println("Saldo tidak mencukupi");
      return false;
    }
    this.saldo -= convertToIdr(jumlah, currency);
    return true;
  }

  public int convertToIdr(int jumlah, String currency) {
    int rate;
    switch (currency) {
      case "AUD":
        rate = 10000;
        break;
      case "USD":
        rate = 9000;
        break;
      default:
        rate = 1;
        break;
    }
    return jumlah * rate;
  }
}
