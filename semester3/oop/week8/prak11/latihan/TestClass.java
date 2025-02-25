public class TestClass {
  public static void main(String[] arguments) {
    Mahasiswa fadilah = new Mahasiswa();
    fadilah.setUsername("fadilah");
    fadilah.setPassword("123456");
    fadilah.setPhone("083853501388");
    boolean result = fadilah.login(fadilah.getPhone(), fadilah.getPassword());
    System.out.println(result ? "Login berhasil" : "Login gagal");

    Dosen fahrul = new Dosen("fahrul", "123456");
    fahrul.setKey("19990129");
    result = fahrul.login(fahrul.getUsername(), fahrul.getPassword(), fahrul.getKey());
    System.out.println(result ? "Login berhasil" : "Login gagal");
  }
}
