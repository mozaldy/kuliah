public class Test {
  public static void main(String args[]) {
    Weapon weapon = new Knife();

    Weapon knife = new Knife();
    Weapon gun = new Gun(10);

    knife.attack();
    gun.attack();
    gun.attack();

    Knife knife2 = new Knife();
    Weapon gun2 = new Gun(10);

    knife2.attack();
    gun2.attack();
    gun2.attack();
  }
}
