package salesapp;

class Electronics extends Product {
  private String imei;
  private String warrantee;

  public Electronics(
      String productId, String name, double price, int stock, String imei, String warrantee) {
    super(productId, name, price, stock);
    setImei(imei);
    setWarrantee(warrantee);
  }

  public String getImei() {
    return imei;
  }

  public void setImei(String imei) {
    this.imei = imei;
  }

  public String getWarrantee() {
    return warrantee;
  }

  public void setWarrantee(String warrantee) {
    this.warrantee = warrantee;
  }

  @Override
  public void displayInfo() {
    super.displayInfo();
    System.out.println("IMEI: " + getImei());
    System.out.println("Warrantee: " + getWarrantee());
  }
}
