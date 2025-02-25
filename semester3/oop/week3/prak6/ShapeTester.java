public class ShapeTester{
	public static void main(String args[]){
		Shape kubus = new Shape(5, 5, 5);
		Shape balok = new Shape(10, 5, 5);
		kubus.cetak();
		balok.cetak();
		Double selisihVolume = kubus.compareTo(balok);
		System.out.printf("Selisih Volume = %.0f", selisihVolume);
	}
}
