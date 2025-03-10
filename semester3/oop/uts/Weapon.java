public class Weapon extends Equipment {
  private int weight;
  private int range;

  public void setWeight(int weight) {
    if (weight > 0) {
      this.weight = weight;
    } else {
      this.weight = 0;
      System.out.println("Weight is not allowed to be less than 0!");
    }
  }

  public void setRange(int range) {
    if (range > 0) {
      this.range = range;
    } else {
      this.range = 0;
      System.out.println("Range is not allowed to be less than 0!");
    }
  }

  public void displayWeaponInfo() {
    displayInfo();
    System.out.println("Weight: " + weight + " kg");
    System.out.println("Range: " + range + " meters");
  }
}
