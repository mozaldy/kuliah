public class Bullet extends Ammunition {
  private int caliber;

  public void setCaliber(int caliber) {
    if (caliber > 0) {
      this.caliber = caliber;
    } else {
      this.caliber = 0;
      System.out.println("Caliber is not allowed to be less than 0!");
    }
  }

  public void displayBulletInfo() {
    displayAmmunitionInfo();
    System.out.println("Caliber: " + caliber + " mm");
  }
}
