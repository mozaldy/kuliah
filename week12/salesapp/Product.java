package salesapp;

class Product {
  private String productId;
  private String name;
  private double price;
  private int stock;

  public Product(String productId, String name, double price, int stock) {
    setProductId(productId);
    setName(name);
    setPrice(price);
    setStock(stock);
  }

  public void displayInfo() {
    System.out.println("Product ID: " + getProductId());
    System.out.println("Name: " + getName());
    System.out.println("Price: " + getPrice());
    System.out.println("Stock: " + getStock());
  }

  public String getProductId() {
    return productId;
  }

  public void setProductId(String productId) {
    this.productId = productId;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  public int getStock() {
    return stock;
  }

  public void setStock(int stock) {
    this.stock = stock;
  }
}
