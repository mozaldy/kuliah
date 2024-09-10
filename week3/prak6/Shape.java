class Shape{
	public double length;
	public double width;
	public double height;
	public double volume;

	public Shape(double length, double width, double height){
		this.length = length;
		this.width = width;
		this.height = height;
		calculateVolume();
	}

	public double compareTo(Shape shape){
		return shape.volume - this.volume;
	}

	private void calculateVolume(){
		this.volume = this.length * this.width * this.height;
	}

	public void cetak(){
		System.out.printf("Panjang x lebar x tinggi = %.0f x %.0f x %.0f\n", this.length, this.width, this.height);
		System.out.printf("Volume = %.0f\n", this.volume);
	}
}
