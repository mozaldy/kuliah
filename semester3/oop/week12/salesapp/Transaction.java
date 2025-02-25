package salesapp;

class Transaction {
  private int transactionId;
  private Order order;
  private Payment payment;
  private int total;
  private Shipping shipping;

  public Transaction(
      int transactionId, Order order, Payment payment, int total, Shipping shipping) {
    setTransactionId(transactionId);
    setOrder(order);
    setPayment(payment);
    setTotal(total);
    setShipping(shipping);
  }

  public int getTransactionId() {
    return transactionId;
  }

  public void setTransactionId(int transactionId) {
    this.transactionId = transactionId;
  }

  public Order getOrder() {
    return order;
  }

  public void setOrder(Order order) {
    this.order = order;
  }

  public Payment getPayment() {
    return payment;
  }

  public void setPayment(Payment payment) {
    this.payment = payment;
  }

  public int getTotal() {
    return total;
  }

  public void setTotal(int total) {
    this.total = total;
  }

  public Shipping getShipping() {
    return shipping;
  }

  public void setShipping(Shipping shipping) {
    this.shipping = shipping;
  }

  public void displayInfo() {
    Customer customer = order.getCustomer();
    Address address = customer.getAddress();

    for (Product product : order.getProducts()) {
      System.out.println("\nTransaction Summary:");
      System.out.println("Customer: " + customer.getName());
      System.out.println(
          "Address: "
              + address.getStreet()
              + ", "
              + address.getProvince()
              + ", "
              + address.getCountry());
      System.out.println("Product: ");
      product.displayInfo();
    }
    System.out.println("Total: Rp." + total);
    System.out.println("Shipping: " + shipping.getShippingName());
    System.out.println("Payment Method: " + payment.getPaymentMethod());
  }
}
