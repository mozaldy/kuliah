class MyClass {
  void myMethod(int i) {
    System.out.println("int version");
  }

  void myMethod(String s) {
    System.out.println("String version");
  }

  public static void main(String args[]) {
    MyClass obj = new MyClass();
    char ch = 'c';
    obj.myMethod(ch);
  }
}
