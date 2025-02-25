class Ballpoint implements Pointable, Storable {
  @Override
  public void laserPointer() {
    System.out.println("Ballpoint laser pointer is on");
  }

  @Override
  public void storageMedia() {
    System.out.println("Ballpoint is stored in a case");
  }

  public void draw() {
    System.out.println("Drawing with a ballpoint");
  }
}
