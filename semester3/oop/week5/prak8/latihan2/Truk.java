public class Truk {
  private double muatan;
  private double muatanMaks;

  public Truk(double beratMaks) {
    this.muatanMaks = beratMaks;
  }

  public double getMuatan() {
    return muatan;
  }

  public double getMuatanMaks() {
    return muatanMaks;
  }

  public boolean tambahMuatan(double berat) {
    if (muatan + berat <= muatanMaks) {
      muatan += berat;
      return true;
    }
    return false;
  }

  public double newtsToKilo(double berat) {
    return berat * 0.453592;
  }

  public double kiloToNewts(double berat) {
    return berat / 0.453592;
  }
}
