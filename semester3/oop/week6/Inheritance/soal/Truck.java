package Inheritance.soal;

class Truck extends Vehicle {
  private int cargoCapacity;

  public Truck(String color) {
    super.setColor(color);
    super.setModel("Truck");
  }

  public int getCargoCapacity() {
    return cargoCapacity;
  }

  public void setCargoCapacity(int cargoCapacity) {
    this.cargoCapacity = cargoCapacity;
  }

  public void displayTruckInfo() {
    String info = "This truck can hold " + this.cargoCapacity + " tons\n";

    super.displayInfo();
    System.out.println(info);
  }
}
