import java.util.Scanner;
class Tugas4{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		System.out.print("String nama pertama: ");
		String firstName = scanner.nextLine();
		System.out.print("String nama kedua: ");
		String secondName = scanner.nextLine();
		switchFamilyName(firstName, secondName);
	}

	public static void switchFamilyName(String x, String y){
		String[] xNameSplit = x.split(" ");
		String[] yNameSplit = y.split(" ");

		String xLast = xNameSplit[xNameSplit.length - 1];
		String yLast = yNameSplit[yNameSplit.length - 1];

		String xLastName = xNameSplit.length > 1 ? xLast : "";
		String yLastName = yNameSplit.length > 1 ? yLast : "";

		if(!xLastName.equals(""))
			xNameSplit[xNameSplit.length - 1] = yLastName;
		if(!yLastName.equals(""))
			yNameSplit[yNameSplit.length - 1] = xLastName;

		x = String.join(" ", xNameSplit);
		y = String.join(" ", yNameSplit);

		System.out.println("String nama pertama: " + x);
		System.out.println("String nama kedua: " + y);
	}

}
