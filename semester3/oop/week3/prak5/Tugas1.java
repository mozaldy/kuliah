import java.util.Scanner;

public class Tugas1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Masukkan kalimat:");
    String sentence = scanner.nextLine();
    System.out.println("Masukkan karakter yang dicari:");
    char character = scanner.next().charAt(0);

    System.out.print("Karakter '" + character + "' terdapat pada indeks ");
    for (int i = 0; i < sentence.length(); i++) {
      if (sentence.charAt(i) == character) {
        System.out.print(i + " ");
      }
    }
    scanner.close();
  }
}
