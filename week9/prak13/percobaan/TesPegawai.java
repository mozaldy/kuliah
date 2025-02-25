public class TesPegawai {
  public static void main(String[] args) {
    Pegawai pegawai1 = new Manajer("Yopi", 5000000, 2000);
    Pegawai pegawai2 = new Kurir("Pajar", 3000000, 5000);

    printInfo(pegawai1);
    printInfo(pegawai2);
  }

  public static void printInfo(Pegawai pegawai) {
    System.out.println("Pegawai dari kelas " + pegawai.getClass().getName());
    System.out.println("Nama: " + pegawai.getNama());
    System.out.println("Gaji: " + pegawai.infoGaji());

    if (pegawai instanceof Manajer) {
      Manajer manajer = (Manajer) pegawai;
      System.out.println("Tunjangan: " + manajer.infoTunjangan());
    } else if (pegawai instanceof Kurir) {
      Kurir kurir = (Kurir) pegawai;
      System.out.println("Bonus: " + kurir.infoBonus());
    }
  }
}
