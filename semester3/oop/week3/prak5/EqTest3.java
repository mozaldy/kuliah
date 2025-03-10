public class EqTest {
  public static void main(String argv[]) {
    EqTest e = new EqTest();
  }

  EqTest() {
    String s1 = "Java";
    String s2 = "Java";
    String s3 = "java";
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
