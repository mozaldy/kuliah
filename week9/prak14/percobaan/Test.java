public class Test {
  public static void main(String args[]) {
    Fans fans1 = new Fans();
    Fans fans2 = new Fans("Mona");
    Fans fans3 = new KpopFans("Tomi");
    KpopFans fans4 = new KpopFans("Febi");
    fans1.watchingPerformance(); // watchingPerfomance() dari Fans tanpa parameter
    fans2.watchingPerformance(new Musician()); // watchingPerfomance dari Fans dengan parameter
    // dan memanggil method perform() dari Musician
    fans2.watchingPerformance(new Singer()); // watchingPerfomance dari Fans dengan parameter
    // dan memanggil method perform() dari Singer
    fans3.watchingPerformance(new Biduan()); // watchingPerfomance dari Fans dengan parameter
    // dan memanggil method perform() dari Biduan
    fans4.watchingPerformance(
        new Kpop(), "teriak histeris"); // watchingPerfomance dari Fans dengan parameter
    // dan memanggil method perform() dari Kpop

  }
}
