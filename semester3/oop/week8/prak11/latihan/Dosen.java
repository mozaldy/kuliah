class Dosen extends User {
  private String pangkat;
  private String golongan;
  private String key;

  public Dosen() {
    super();
    this.pangkat = "";
    this.golongan = "";
  }

  public Dosen(String username, String password) {
    super(username, password);
    this.pangkat = "";
    this.golongan = "";
  }

  public String getPangkat() {
    return pangkat;
  }

  public void setPangkat(String pangkat) {
    this.pangkat = pangkat;
  }

  public String getGolongan() {
    return golongan;
  }

  public void setGolongan(String golongan) {
    this.golongan = golongan;
  }

  public String getKey() {
    return key;
  }

  public void setKey(String key) {
    this.key = key;
  }

  public boolean login(String username, String password) {
    System.out.println("Mencoba login dari Dosen dengan parameter username dan password.");
    return super.login(username, password);
  }

  public boolean login(String username, String password, String key) {
    System.out.println("Mencoba login dari Dosen dengan parameter username, password, dan key.");
    return getUsername().equals(username) && getPassword().equals(password) && this.key.equals(key);
  }
}
