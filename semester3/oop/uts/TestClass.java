public class TestClass {
  public static void main(String[] args) {
    Weapon rifle = new Weapon();
    rifle.setName("SS2");
    rifle.setMaker("Pindad");
    rifle.setPrice(1000);
    rifle.setWeight(3);
    rifle.setRange(500);
    rifle.displayWeaponInfo();

    System.out.println();

    Bullet bullet = new Bullet();
    bullet.setName("7.62x51mm NATO");
    bullet.setMaker("PT. Pindad");
    bullet.setPrice(1);
    bullet.setQuantity(1000);
    bullet.setCaliber(6);
    bullet.displayBulletInfo();

    System.out.println();

    Weapon aircraft = new Weapon();
    aircraft.setName("F-22 Raptor");
    aircraft.setMaker("Lockheed Martin");
    aircraft.setPrice(150000000);
    aircraft.setWeight(19700);
    aircraft.setRange(2960);
    aircraft.displayWeaponInfo();

    System.out.println();

    Bomb bomb = new Bomb();
    bomb.setName("GBU-43/B MOAB");
    bomb.setMaker("US Air Force");
    bomb.setPrice(16000000);
    bomb.setQuantity(1);
    bomb.setBlastRadius(150);
    bomb.displayBombInfo();
  }
}
