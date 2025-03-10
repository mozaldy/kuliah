class Alarm {
  public String id;
  public String description;
  public String date;
  public String time;

  public void run() {
    System.out.println("Alarm " + id + " is running. Description: " + description);
  }

  public void terminate() {
    System.out.println("Alarm " + id + " has been terminated.");
  }

  public void snooze() {
    System.out.println("Alarm " + id + " has been snoozed.");
  }

  public static void main(String[] args) {
    Alarm alarm1 = new Alarm();
    alarm1.id = "1";
    alarm1.description = "Wake up!";
    alarm1.date = "2020-12-31";
    alarm1.time = "06:00";
    alarm1.run();
    alarm1.snooze();
    alarm1.terminate();
  }
}
