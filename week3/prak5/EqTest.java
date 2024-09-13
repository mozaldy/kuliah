public class EqTest {
  public static void main(String argv[]) {
    String str = "Java";
    StringBuffer buffer = new StringBuffer(str);
    if (str.equals(buffer)) {
      System.out.println("Both are equal");
    } else {
      System.out.println("Both are not equal");
    }
  }
}
