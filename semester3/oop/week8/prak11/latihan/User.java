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

  public String getId() {
    return id;
  }

  public void setId(String id) {
    this.id = id;
  }

  public String getPhone() {
    return phone;
  }

  public void setPhone(String phone) {
    this.phone = phone;
  }

  public String getUsername() {
    return username;
  }

  public void setUsername(String username) {
    this.username = username;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
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
