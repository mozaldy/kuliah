package salesapp;

class Order {
  private int orderId;
  private Customer customer;
  private Product[] products;

  public Order(int orderId, Customer customer, Product[] products) {
    setOrderId(orderId);
    setCustomer(customer);
    setProducts(products);
  }

  public int getOrderId() {
    return orderId;
  }

  public void setOrderId(int orderId) {
    this.orderId = orderId;
  }

  public Customer getCustomer() {
    return customer;
  }

  public void setCustomer(Customer customer) {
    this.customer = customer;
  }

  public Product[] getProducts() {
    return products;
  }

  public void setProducts(Product[] products) {
    this.products = products;
  }
}
