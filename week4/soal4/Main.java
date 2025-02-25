class Main{
  public static void main(String args[]){
    Movie movie = new Movie("Inception", 148, "PG-13");
    Seat seat = new Seat("A12", true);
    Reservation reservation = new Reservation("R001", movie, seat);

    Reservation reservation2 = new Reservation("R002", movie, seat);
    
    System.out.println("Kursi tersedia? " + seat.isAvailable);
    reservation.reserveSeat();
    reservation2.reserveSeat();
  }
}
