package Inheritance.soal;

public class TestClass {
  public static void main(String args[]) {
    Car car = new Car("Red");
    Motorcycle motorcycle = new Motorcycle("Chrome");
    Truck truck = new Truck("Green");

    car.setYear(2050);
    motorcycle.setYear(1957);
    truck.setYear(2011);

    car.setNumberOfDoors(2);
    truck.setCargoCapacity(1500);

    car.displayInfo();
    motorcycle.displayInfo();
    truck.displayInfo();

    car.displayCarInfo();
    motorcycle.displayMotorcycleInfo();
    truck.displayTruckInfo();
  }
}
