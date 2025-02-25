public class Pegawai {
  int nip;
  String nama;

  public Pegawai(int nip_pegawai) {
    this(nip_pegawai, "NoName");
  }

  public Pegawai(int nip_pegawai, String nama_pegawai) {
    this.nip = nip_pegawai;
    this.nama = nama_pegawai;
  }
}
