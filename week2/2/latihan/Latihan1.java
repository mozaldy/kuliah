import java.text.NumberFormat;
public class Latihan1{
	public static void main(String args[]){
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMaximumFractionDigits(2);
		Mahasiswa kumpulan_mahasiswa[] = new Mahasiswa[4];
		kumpulan_mahasiswa[0] = new Mahasiswa("1", "Ahmad", 81, 90, 62);
		kumpulan_mahasiswa[1] = new Mahasiswa("2", "Adang", 50, 83, 87);
		kumpulan_mahasiswa[2] = new Mahasiswa("3", "Dani", 89, 55, 65);
		kumpulan_mahasiswa[3] = new Mahasiswa("4", "Edi", 77, 70, 92);

		System.out.println("NRP\tRata-rata");


		for (int i = 0; i < 4; i++){
			double mean = kumpulan_mahasiswa[i].hitungMean();
			String nrp = kumpulan_mahasiswa[i].nrp;
			System.out.println(nrp + "\t" + nf.format(mean));
		}

	}
}
