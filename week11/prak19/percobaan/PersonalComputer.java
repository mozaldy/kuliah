public class PersonalComputer {
  public MotherBoard motherBoard;
  public OperatingSystem os;
  public Mouse mouse;

  public PersonalComputer() {
    this.motherBoard = new MotherBoard();
  }

  public void installOS() {
    this.os = new OperatingSystem();
  }

  public void readData(CompactDisk cd) {
    // cd.read();
  }

  public void detectMouse(Mouse mouse) {
    // this.mouse = new Mouse();
    this.mouse = mouse;
  }
}
