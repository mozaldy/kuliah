public class Equipment {
  private String name;
  private String maker;
  private int price;

  public void setName(String name) {
    this.name = name;
  }

  public void setMaker(String maker) {
    this.maker = maker;
  }

  public void setPrice(int price) {
    if (price > 0) {
      this.price = price;
    } else {
      this.price = 0;
      System.out.println("Price is not allowed to be less than 0!");
    }
  }

  public void displayInfo() {
    System.out.println("Name: " + name);
    System.out.println("Maker: " + maker);
    System.out.println("Price: $" + price);
  }
}
