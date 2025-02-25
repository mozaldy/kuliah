package Inheritance.soal;

class Car extends Vehicle {
  private int numberOfDoors;

  public Car(String color) {
    super.setColor(color);
    super.setModel("Car");
  }

  public int getNumberOfDoors() {
    return numberOfDoors;
  }

  public void setNumberOfDoors(int numberOfDoors) {
    this.numberOfDoors = numberOfDoors;
  }

  public void displayCarInfo() {
    String info = "This car has " + this.numberOfDoors + " doors\n";

    super.displayInfo();
    System.out.println(info);
  }
}
