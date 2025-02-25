import java.awt.Point;

public class Segiempat {
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

  public void buatSegiempat(int x1, int y1, int x2, int y2) {
    this.x1 = x1;
    this.y1 = y1;
    this.x2 = x2;
    this.y2 = y2;
  }

  public void buatSegiempat(Point topLeft, Point bottomRight) {
    x1 = topLeft.x;
    y1 = topLeft.y;
    x2 = bottomRight.x;
    y2 = bottomRight.y;
  }

  public void buatSegiempat(Point topLeft, int w, int h) {
    x1 = topLeft.x;
    y1 = topLeft.y;
    x2 = (x1 + w);
    y2 = (y1 + h);
  }

  void cetakSegiempat() {
    System.out.print("Segiempat: <" + x1 + ", " + y1);
    System.out.println(", " + x2 + ", " + y2 + ">");
  }

  public static void main(String[] arguments) {
    Segiempat rect = new Segiempat();
    System.out.println("Buat segiempat dengan koordinat (25,25)  dan (50,50)");
    rect.buatSegiempat(25, 25, 50, 50);
    rect.cetakSegiempat();
    System.out.println();
    System.out.println("Buat segiempat dengan point (10,10) dan 92 point (20,20):");
    rect.buatSegiempat(new Point(10, 10), new Point(20, 20));
    rect.cetakSegiempat();
    System.out.println();
    System.out.print("Buat segiempat dengan 1 point (10,10), koodinat (50,50)");
    rect.buatSegiempat(new Point(10, 10), 50, 50);
    rect.cetakSegiempat();
  }
}
