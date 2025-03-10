public class TesTugas1 {
  public static void main(String args[]) {
    RerataNilai rn = new RerataNilai();
    System.out.println("Rerata nilai 21 dan 13 adalah : " + rn.average(21, 13));
    System.out.println("Rerata nilai 19.3 dan 39.5 adalah : " + rn.average(19.3, 39.5));
    System.out.println("Rerata nilai 123, 567 dan 744 adalah : " + rn.average(123, 567, 744));
  }
}
