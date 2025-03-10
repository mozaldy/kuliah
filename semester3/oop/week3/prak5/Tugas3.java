import java.util.Scanner;

public class Tugas3 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Masukkan string:");
    String input = scanner.nextLine();

    String[] words = input.split(" ");
    for (int i = 0; i < words.length; i++) {
      char firstChar = Character.toUpperCase(words[i].charAt(words[i].length() - 1));
      char lastChar = Character.toLowerCase(words[i].charAt(0));
      words[i] = firstChar + words[i].substring(1, words[i].length() - 1) + lastChar;
    }

    String output = String.join(" ", words);
    System.out.println("String hasil: " + output);
  }
}
