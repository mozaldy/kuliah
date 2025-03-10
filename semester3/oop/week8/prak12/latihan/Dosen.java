public class Dosen extends Orang {
  public int nip;

  Dosen(String nama) {
    super(nama);
  }

  Dosen(String nama, int nip) {
    super(nama);
    this.nip = nip;
  }

  Dosen(String nama, int nip, int umur) {
    super(nama, umur);
    this.nip = nip;
  }

  public void Info() {
    System.out.println("Nama : " + nama);
    if (nip == 0) {
      System.out.println("NIP : -");
    } else {
      System.out.println("NIP : " + nip);
    }
    if (umur == 0) {
      System.out.println("Umur : -");
    } else {
      System.out.println("Umur : " + umur);
    }
  }
}
