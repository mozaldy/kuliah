class SmartPhone extends Phone implements Camera, CardReader {
  public String lens;

  @Override
  public void call() {
    super.call();
    System.out.println("With smart feature...");
  }

  @Override
  public void receiveCall() {
    super.receiveCall();
    System.out.println("With smart feature...");
  }

  public void captureImage() {
    System.out.println("Capturing image...");
  }

  public void readCard() {
    System.out.println("Reading card...");
  }
}
