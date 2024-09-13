public class EqTest4 {
  public static void main(String argv[]) {
    EqTest e = new EqTest();
  }

  EqTest() {
    String s1 = new String("Java");
    String s2 = new String("Java");
    String s3 = new String("java");
    if (s1 == s2) {
      System.out.println("Equal");
    } else {
      System.out.println("Not equal");
    }
    if (s1 == s3) {
      System.out.println("Equal");
    } else {
      System.out.println("Not equal");
    }
  }
}
