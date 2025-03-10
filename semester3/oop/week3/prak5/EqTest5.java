public class EqTest {
  public static void main(String argv[]) {
    EqTest e = new EqTest();
  }

  EqTest() {
    String s = "Java";
    String s2 = "java";
    if (s.equalsIgnoreCase(s2)) {
      System.out.println("Equal");
    } else {
      System.out.println("Not equal");
    }
  }
}
