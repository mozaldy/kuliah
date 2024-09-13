class Main{
  public static void main(String args[]){
    Movie movie = new Movie("Inception", 148, "PG-13");
    Seat seat = new Seat("A12", true);
    Reservation reservation = new Reservation("R001", movie, seat);
    
    reservation.reserveSeat();
    System.out.println("Kursi tersedia? " + seat.isAvailable);
  }
}
