class Test {
  public static void main(String[] args) {
    UsbFlash usbFlash = new UsbFlash("Musik");

    Audio audio = new Audio();

    Car car = new Car();

    car.replaceWheel();
    car.installAudio(audio);
    car.playMusic(usbFlash);
  }
}
