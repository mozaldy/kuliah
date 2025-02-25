import java.util.Scanner;

class Tugas5 {
  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("String kalimat utama: ");
    String kalimatUtama = scanner.nextLine();

    System.out.print("String yang diganti: ");
    String stringDiganti = scanner.nextLine();

    if (!kalimatUtama.contains(stringDiganti)) {
      System.out.println("String yang diganti tidak ada!");
      return;
    }

    System.out.print("String yang pengganti: ");
    String stringPengganti = scanner.nextLine();

    String hasil = kalimatUtama.replace(stringDiganti, stringPengganti);
    System.out.print("Hasil: " + hasil);
    scanner.close();
  }
}
