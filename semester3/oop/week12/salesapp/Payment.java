package salesapp;

class Payment {
  private String paymentId;
  private String paymentMethod;
  private int nominal;
  private boolean isPaid;

  public Payment(String paymentId, String paymentMethod, int nominal, boolean isPaid) {
    setPaymentId(paymentId);
    setPaymentMethod(paymentMethod);
    setNominal(nominal);
    setPaid(isPaid);
  }

  public String getPaymentId() {
    return paymentId;
  }

  public void setPaymentId(String paymentId) {
    this.paymentId = paymentId;
  }

  public String getPaymentMethod() {
    return paymentMethod;
  }

  public void setPaymentMethod(String paymentMethod) {
    this.paymentMethod = paymentMethod;
  }

  public int getNominal() {
    return nominal;
  }

  public void setNominal(int nominal) {
    this.nominal = nominal;
  }

  public boolean isPaid() {
    return isPaid;
  }

  public void setPaid(boolean isPaid) {
    this.isPaid = isPaid;
  }
}
