class Main{
  public static void main(String args[]){
    Product laptop = new Product("Laptop", 10000000);
    Product phone = new Product("Phone", 5000000);

    SaleItem saleItem1 = new SaleItem(laptop, 2);
    SaleItem saleItem2 = new SaleItem(phone, 3);

    Transaction transaction = new Transaction();
    transaction.addSaleItem(saleItem1);
    transaction.addSaleItem(saleItem2);

    System.out.printf("Total pendapatan: %.1f", transaction.calculateTotalRevenue());
  }
}
