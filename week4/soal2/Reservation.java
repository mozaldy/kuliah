class Reservation{
  public Room room;
  public Guest guest;
  public int numberOfNights;

  public Reservation(Room room, Guest guest, int numberOfNights){
    this.room = room;
    this.guest = guest;
    this.numberOfNights = numberOfNights;
  }

  public double calculateTotalPrice(){
    return room.pricePerNight * this.numberOfNights;
  }
}
