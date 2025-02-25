class Fans {
  private String name;

  public Fans() {
    this.name = "noname";
  }

  public Fans(String name) {
    this.name = name;
  }

  public void showName() {
    System.out.print(name + ": ");
  }

  public void watchingPerformance() {
    this.showName();
    System.out.print("melihat idolanya dari YouTube.");
  }

  public void watchingPerformance(Musician musician) {
    System.out.println();
    this.showName();
    musician.perform();
  }
}
