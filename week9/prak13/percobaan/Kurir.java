class Kurir extends Pegawai {
  private int bonus;

  public Kurir(String nama, int gaji, int bonus) {
    super(nama, gaji);
    this.bonus = bonus;
  }

  public int infoBonus() {
    return bonus;
  }
}
