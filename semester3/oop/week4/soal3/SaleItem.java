class SaleItem{
  public Product product;
  public int quantity;

  public SaleItem(Product product, int quantity){
    this.product = product;
    this.quantity = quantity;
  }

  public double getTotalPrice(){
    return this.product.price * this.quantity;
  }
}
