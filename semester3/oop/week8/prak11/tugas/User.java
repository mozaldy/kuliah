class User {
  private String id;
  private String phone;
  private String username;
  private String password;

  public User() {
    this.id = "";
    this.phone = "";
    this.username = "";
    this.password = "";
  }

  public User(String username, String password) {
    this.id = "";
    this.phone = "";
    this.username = username;
    this.password = password;
  }

  public User(String id, String phone, String username, String password) {
    this.id = id;
    this.phone = phone;
    this.username = username;
    this.password = password;
  }

  public boolean login(String phone, String password) {
    System.out.println("Mencoba login dari User dengan parameter phone dan password.");
    return this.phone.equals(phone) && this.password.equals(password);
  }

  public boolean login(String username, String password, String phone) {
    System.out.println("Mencoba login dari User dengan parameter username, password, dan phone.");
    return this.username.equals(username) && this.password.equals(password);
  }
}
