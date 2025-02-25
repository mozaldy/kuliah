public class Ammunition extends Equipment {
  private int quantity;

  public void setQuantity(int quantity) {
    if (quantity > 0) {
      this.quantity = quantity;
    } else {
      this.quantity = 0;
      System.out.println("Quantity is not allowed to be less than 0!");
    }
  }

  public void displayAmmunitionInfo() {
    displayInfo();
    System.out.println("Quantity: " + quantity);
  }
}
