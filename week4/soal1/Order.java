class Order {
  public OrderItem orderItems[];

  public Order() {
    orderItems = new OrderItem[10];
  }

  public void addOrderItem(OrderItem saleItem) {
    for (int i = 0; i < orderItems.length; i++) {
      if (orderItems[i] == null) {
        orderItems[i] = saleItem;
        break;
      }
    }
  }

  public double calculateTotal() {
    int totalRevenue = 0;
    for (OrderItem saleItem : orderItems) {
      if (saleItem != null) {
        totalRevenue += saleItem.getTotalPrice();
      }
    }
    return totalRevenue;
  }
}
