public class Test {
  public static void main(String[] args) {
    Mouse mouse = new Mouse();
    CompactDisk cd = new CompactDisk();

    PersonalComputer pc = new PersonalComputer();
    pc.installOS();
    pc.detectMouse(mouse);
    pc.readData(cd);
  }
}
