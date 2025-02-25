class Mahasiswa extends User {
  private Dosen dosenWali;
  private String kelas;

  public Mahasiswa() {
    this("", "", new Dosen(), "");
  }

  public Mahasiswa(String username, String password, String phone) {
    super("", phone, username, password);
    this.dosenWali = new Dosen();
    this.kelas = "";
  }

  public Mahasiswa(String username, String password, Dosen dosenWali, String kelas) {
    super(username, password);
    this.dosenWali = dosenWali;
    this.kelas = kelas;
  }
}
