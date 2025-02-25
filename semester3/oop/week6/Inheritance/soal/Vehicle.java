package Inheritance.soal;

class Vehicle {
  private String model;
  private int year;
  private String color;

  public void setModel(String model) {
    this.model = model;
  }

  public void setYear(int year) {
    boolean isValidYear = year < 2025 && year > 1800;
    if (isValidYear) {
      this.year = year;
      System.out.println(this.model + "'s year saved.");
    } else {
      System.out.printf(
          "Failed to safe %s's year. Year must be less than 2025 and more than 1800.\n",
          this.model);
    }
    System.out.println();
  }

  public void setColor(String color) {
    this.color = color;
  }

  public void displayInfo() {
    String info = ">> Vehicle Info:\n";
    info += "Model: " + this.model + "\n";
    info += "Year: " + this.year + "\n";
    info += "Color: " + this.color + "\n";
    System.out.println(info);
  }
}
