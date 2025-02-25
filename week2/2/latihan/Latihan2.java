import java.util.Scanner;

public class Latihan2{
	public static void main(String args[]){
		int n; 
		Scanner scanner = new Scanner(System.in);

		System.out.println("Program Angka Fibonacci");
		System.out.print("Masukkan berapa deret Fibonacci: ");
		n = scanner.nextInt();
		int deret_fibonacci[] = new int[n + 1];
		System.out.print("Deret Fibonacci: ");
		deret_fibonacci[0] = 0;
		deret_fibonacci[1] = 1;

		for (int i = 2; i <= n; i++)
			 deret_fibonacci[i] = deret_fibonacci[i - 1] + deret_fibonacci[i - 2];

		for (int j = 0; j < n; j++)
			System.out.printf("%d ", deret_fibonacci[j]);

		scanner.close();
	}
}
