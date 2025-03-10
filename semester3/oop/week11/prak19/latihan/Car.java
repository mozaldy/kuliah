class Car {
  Engine engine;
  Wheel wheels;
  Audio audio;

  public Car() {
    engine = new Engine();
  }

  public void replaceWheel() {
    wheels = new Wheel();
  }

  public void installAudio(Audio audio) {
    this.audio = audio;
  }

  public void playMusic(UsbFlash usb) {
    System.out.println("Playing music of " + usb.getContent());
  }
}
