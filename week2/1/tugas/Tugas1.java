import java.util.Scanner;

public class Tugas1{
	public static void main(String args[]){
		int n, prevNumber = 0, currentNumber = 1; 
		Scanner scanner = new Scanner(System.in);

		System.out.println("Program Angka Fibonacci");
		System.out.print("Masukkan berapa deret Fibonacci: ");
		n = scanner.nextInt();
		System.out.print("Deret Fibonacci: ");

		for (int i = 0; i < n; i++){
			System.out.printf("%d ", currentNumber);
			int temp = currentNumber;
			currentNumber += prevNumber;
			prevNumber = temp;

		}

		scanner.close();
	}
}
