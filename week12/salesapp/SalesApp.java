package salesapp;

import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

public class SalesApp {
  private static Scanner scanner = new Scanner(System.in);

  private static ArrayList<Product> inputProducts() {
    ArrayList<Product> products = new ArrayList<>();
    boolean addMore = true;

    while (addMore) {
      System.out.println("\nAdd New Product");
      System.out.print("Enter product type (1 = Food/Beverage, 2 = Electronics, 3 = Others): ");
      int type = scanner.nextInt();
      scanner.nextLine();

      System.out.print("Enter product ID: ");
      String id = scanner.nextLine();

      System.out.print("Enter product name: ");
      String name = scanner.nextLine();

      System.out.print("Enter price: ");
      double price = scanner.nextDouble();

      System.out.print("Enter stock quantity: ");
      int stock = scanner.nextInt();
      scanner.nextLine();

      if (type == 1) {
        System.out.print("Enter calories: ");
        int calories = scanner.nextInt();
        scanner.nextLine();
        products.add(new FoodAndBeverage(id, name, price, stock, new Date(), calories));
      } else if (type == 2) {
        System.out.print("Enter serial number: ");
        String serialNumber = scanner.nextLine();
        System.out.print("Enter warranty period: ");
        String warranty = scanner.nextLine();
        products.add(new Electronics(id, name, price, stock, serialNumber, warranty));
      } else {
        products.add(new Product(id, name, price, stock));
      }

      System.out.print("\nDo you want to add another product? (yes/no): ");
      String response = scanner.nextLine();
      addMore = response.equalsIgnoreCase("yes");
    }

    return products;
  }

  private static void displayProducts(ArrayList<Product> products) {
    System.out.println("\nAvailable Products:");
    for (int i = 0; i < products.size(); i++) {
      System.out.println(
          (i + 1)
              + ". "
              + products.get(i).getName()
              + " - Rp."
              + products.get(i).getPrice()
              + " ("
              + products.get(i).getStock()
              + " pcs)");
    }
  }

  public static void main(String[] args) {
    System.out.println("Welcome to Point of Sales Application");

    System.out.print("Enter customer name: ");
    String customerName = scanner.nextLine();
    System.out.print("Enter customer country: ");
    String country = scanner.nextLine();
    System.out.print("Enter customer province: ");
    String province = scanner.nextLine();
    System.out.print("Enter customer street address: ");
    String street = scanner.nextLine();

    Address address = new Address(country, province, street);
    Customer customer = new Customer(1, customerName, address);

    ArrayList<Product> availableProducts = inputProducts();

    displayProducts(availableProducts);

    System.out.print("\nEnter the product number you want to buy: ");
    int productChoice = scanner.nextInt();

    if (productChoice < 1 || productChoice > availableProducts.size()) {
      System.out.println("Invalid product number.");
      scanner.close();
      return;
    }

    Product selectedProduct = availableProducts.get(productChoice - 1);

    System.out.print("Enter quantity: ");
    int quantity = scanner.nextInt();

    if (quantity > selectedProduct.getStock()) {
      System.out.println("Sorry, we don't have enough stock.");
      scanner.close();
      return;
    }

    selectedProduct.setStock(selectedProduct.getStock() - quantity);
    Product[] orderedProducts = {selectedProduct};

    Order order = new Order(1, customer, orderedProducts);
    int totalAmount = (int) (selectedProduct.getPrice() * quantity);

    System.out.print("\nEnter shipping method (e.g., JNE, POS): ");
    scanner.nextLine();
    String shippingMethod = scanner.nextLine();
    Shipping shipping = new Shipping("1", shippingMethod, false);

    System.out.print("\nEnter payment method (e.g., Cash, QRIS): ");
    String paymentMethod = scanner.nextLine();
    Payment payment = new Payment("1", paymentMethod, totalAmount, false);

    Transaction transaction = new Transaction(1, order, payment, totalAmount, shipping);

    transaction.displayInfo();

    System.out.print("\nConfirm payment? (yes/no): ");
    String confirm = scanner.nextLine();
    if (confirm.equalsIgnoreCase("yes")) {
      payment.setPaid(true);
      shipping.setShipped(true);
      System.out.println("Payment confirmed and order shipped!");
    } else {
      System.out.println("Transaction canceled.");
    }

    scanner.close();
  }
}
