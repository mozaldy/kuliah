class Gun extends Weapon {
  public int bullets;

  public Gun(int bullets) {
    this.bullets = bullets;
  }

  @Override
  public void attack() {
    super.info();
    System.out.println("Menembakkan peluru");
    bullets--;
    System.out.println("Sisa peluru: " + bullets);
  }

  @Override
  public void info() {
    System.out.println("This is a gun");
  }
}
