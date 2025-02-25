package Inheritance.soal;

class Motorcycle extends Vehicle {
  private boolean hasSideCar;

  public Motorcycle(String color) {
    super.setColor(color);
    super.setModel("Motorcycle");
  }

  public boolean getHasSideCar() {
    return hasSideCar;
  }

  public void setHasSideCar(boolean hasSideCar) {
    this.hasSideCar = hasSideCar;
  }

  public void displayMotorcycleInfo() {
    String info = "This car does ";
    info += this.hasSideCar ? "have a side car" : "not have a side car";
    info += "\n";

    super.displayInfo();
    System.out.println(info);
  }
}
