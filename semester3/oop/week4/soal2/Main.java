class Main {
  public static void main(String args[]) {
    Room room = new Room("101", 500000);
    Room room2 = new Room("102", 500000);
    Guest guest = new Guest("John Doe");
    Reservation reservation = new Reservation(room, guest, 3);
    Reservation reservation2 = new Reservation(room2, guest, 3);

    System.out.println("Total harga reservasi: " + reservation.calculateTotalPrice());
    System.out.println("Total harga reservasi: " + reservation2.calculateTotalPrice());
  }
}
