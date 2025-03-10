package salesapp;

import java.util.Date;

class FoodAndBeverage extends Product {
  private Date expirationDate;
  private int calories;

  public FoodAndBeverage(
      String productId, String name, double price, int stock, Date expirationDate, int calories) {
    super(productId, name, price, stock);
    setExpirationDate(expirationDate);
    setCalories(calories);
  }

  public Date getExpirationDate() {
    return expirationDate;
  }

  public void setExpirationDate(Date expirationDate) {
    this.expirationDate = expirationDate;
  }

  public int getCalories() {
    return calories;
  }

  public void setCalories(int calories) {
    this.calories = calories;
  }

  @Override
  public void displayInfo() {
    super.displayInfo();
    System.out.println("Expiration Date: " + getExpirationDate());
    System.out.println("Calories: " + getCalories());
  }
}
