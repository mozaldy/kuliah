class Dosen extends User {
  private String pangkat;
  private String golongan;
  private String key;

  public Dosen() {
    super("", "");
    this.pangkat = "";
    this.golongan = "";
    this.key = "";
  }

  public Dosen(String username, String password) {
    this(username, password, "", "", "");
  }

  public Dosen(String username, String password, String pangkat, String golongan, String key) {
    super(username, password);
    this.pangkat = pangkat;
    this.golongan = golongan;
    this.key = key;
  }

  @Override
  public boolean login(String username, String password) {
    System.out.println("Mencoba login dari Dosen dengan parameter username dan password.");
    return super.login(username, password, "");
  }

  public boolean login(String username, String password, String key) {
    System.out.println("Mencoba login dari Dosen dengan parameter username, password, dan key.");
    return login(username, password) && this.key.equals(key);
  }
}
