class Seat{
  public String seatNumber;
  public boolean isAvailable;

  public Seat(String seatNumber, boolean isAvailable){
    this.seatNumber = seatNumber;
    this.isAvailable = isAvailable;
  }

  public boolean isAvailable(){
    return isAvailable;
  }
}
