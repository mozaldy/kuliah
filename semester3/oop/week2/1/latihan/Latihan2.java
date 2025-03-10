import java.util.Scanner;

public class Latihan2{
	public static void main(String args[]){
		int n, hasil = 1; 
		Scanner scanner = new Scanner(System.in);

		System.out.println("Program Faktorial");
		System.out.print("Input n!: ");
		n = scanner.nextInt();
		System.out.printf("Faktorial dari %d adalah: ", n);

		for (int i = 1; i <= n; i++){
			hasil *= i;
		}

		System.out.println(hasil);
		scanner.close();
	}
}
