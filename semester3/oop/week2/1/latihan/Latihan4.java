import java.util.Scanner;

public class Latihan4{
	public static void main(String args[]){
		System.out.println("Program Menampilkan Deret Bilangan Genap (Kecuali Kelipatan 6)");

		for (int i = 2; i <= 20; i+=2){
			if (i % 6 != 0){
				System.out.printf("%d ", i);
			}
		}

	}
}
