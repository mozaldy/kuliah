class Main{
  public static void main(String args[]){
    MenuItem burger = new MenuItem("Burger", 50000);
    MenuItem fries = new MenuItem("Fries", 20000);

    OrderItem orderItem1 = new OrderItem(burger, 2);
    OrderItem orderItem2 = new OrderItem(fries, 3);

    Order order = new Order();
    order.addOrderItem(orderItem1);
    order.addOrderItem(orderItem2);

    System.out.printf("Total pesanan: %.1f", order.calculateTotal());
  }
}
