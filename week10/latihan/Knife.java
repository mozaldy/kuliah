class Knife extends Weapon {
  public String kniveEdge;

  @Override
  public void attack() {
    super.info();
    System.out.println("Menyayat dan menusuk musuh");
  }

  @Override
  public void info() {
    System.out.println("This is a knive");
  }
}
