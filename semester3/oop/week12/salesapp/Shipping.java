package salesapp;

class Shipping {
  private String shippingId;
  private String shippingName;
  private boolean isShipped;

  public Shipping(String shippingId, String shippingName, boolean isShipped) {
    setShippingId(shippingId);
    setShippingName(shippingName);
    setShipped(isShipped);
  }

  public String getShippingId() {
    return shippingId;
  }

  public void setShippingId(String shippingId) {
    this.shippingId = shippingId;
  }

  public String getShippingName() {
    return shippingName;
  }

  public void setShippingName(String shippingName) {
    this.shippingName = shippingName;
  }

  public boolean isShipped() {
    return isShipped;
  }

  public void setShipped(boolean isShipped) {
    this.isShipped = isShipped;
  }
}
