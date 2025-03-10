class Transaction {
  public SaleItem saleItems[];

  public Transaction() {
    saleItems = new SaleItem[100];
  }

  public void addSaleItem(SaleItem saleItem) {
    for (int i = 0; i < saleItems.length; i++) {
      if (saleItems[i] == null) {
        saleItems[i] = saleItem;
        break;
      }
    }
  }

  public double calculateTotalRevenue() {
    int totalRevenue = 0;
    for (SaleItem saleItem : saleItems) {
      if (saleItem != null) {
        totalRevenue += saleItem.getTotalPrice();
      }
    }
    return totalRevenue;
  }
}
