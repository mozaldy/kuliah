public class Test {

  public static void main(String[] args) {
    Ballpoint ballpoint = new Ballpoint();
    ballpoint.laserPointer();
    ballpoint.storageMedia();
    ballpoint.draw();

    Gun gun = new Gun();
    gun.laserPointer();

    UsbFlash usbFlash = new UsbFlash();
    usbFlash.storageMedia();
  }
}
