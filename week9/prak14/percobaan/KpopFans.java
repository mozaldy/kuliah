class KpopFans extends Fans {
  public KpopFans() {
    super();
  }

  public KpopFans(String name) {
    super(name);
  }

  public void watchingPerformance(Musician musician, String expression) {
    System.out.println();
    super.showName();
    System.out.print(expression + " ");
    musician.perform();
  }
}
