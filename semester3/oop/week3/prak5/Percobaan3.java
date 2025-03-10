class Percobaan3 {
  public static void main(String[] args) {
    String str1 = "Monas";
    System.out.println(str1);
    String str2 = "monas";
    System.out.println(str2);
    String str3 = str1 + str2;
    System.out.println(str3);
    String str4 = str1.concat(str2);
    System.out.println(str4);
    str1 += str2;
    System.out.println(str1);
  }
}
