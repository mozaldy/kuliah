import java.util.Scanner;

public class Tugas2{
	public static void main(String args[]){
		int tahun, batasTahunAwal = 1900, batasTahunAkhir = 2005;
		boolean is_kabisat = false;

			Scanner scanner = new Scanner(System.in);

			System.out.print("Masukkan tahun (1900-2005): ");
			tahun = scanner.nextInt();

			if(tahun < batasTahunAwal)
				System.out.printf("Maaf, tahun input anda %d dibawah batas awal %d", tahun, batasTahunAwal);
			else if (tahun > batasTahunAkhir)
				System.out.printf("Maaf, tahun input anda %d diatas batas akhir %d", tahun, batasTahunAkhir);
			else{
				if(tahun % 4 == 0){
					is_kabisat = true;
					if(tahun % 100 == 0){
						is_kabisat = false;
						if(tahun % 400 == 0)
							is_kabisat = true;
					}
				}
				System.out.println(tahun + (is_kabisat ? " adalah tahun kabisat" : " bukan tahun kabisat"));
			}
			scanner.close();
	}
}
