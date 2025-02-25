public class Bomb extends Ammunition {
  private int blastRadius;

  public void setBlastRadius(int blastRadius) {
    if (blastRadius > 0) {
      this.blastRadius = blastRadius;
    } else {
      this.blastRadius = 0;
      System.out.println("Blast Radius is not allowed to be less than 0!");
    }
  }

  public void displayBombInfo() {
    displayAmmunitionInfo();
    System.out.println("Blast Radius: " + blastRadius + " meters");
  }
}
