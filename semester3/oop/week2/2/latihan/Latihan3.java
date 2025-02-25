import java.util.Scanner;

public class Latihan3{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Masukkan Bilangan: ");
		int n = scanner.nextInt();
		boolean is_prima = true;

		for (int i = 2; i <= n / 2; i++){
			if (n % i == 0)
				is_prima = false;
		}

		if (n == 1 || n <= 0){
			is_prima = false;
		}

		System.out.print(n);
		System.out.println(is_prima ? " adalah angka prima" : " bukan angka prima");
	}
}
