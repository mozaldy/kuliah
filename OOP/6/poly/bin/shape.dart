class Shape {
  // artribut
  double luas;
  double keliling;

  // method
  double hitungLuas() => 1;
  double hitungKeliling() => 1;
}

class Circle extends Shape {
  double r;

  Circle(this.r);

  @override
  double hitungLuas() => 3.14 * r * r;

  @override
  double hitungKeliling() => 3.14 * r * 2;
}

class Polygon extends Shape {
  int jumlahSisi;
}

class Triangle extends Polygon {
  double alas;
  double tinggi;

  Triangle(this.alas, this.tinggi);

  @override
  double hitungLuas() => alas * tinggi / 2;

  @override
  double hitungKeliling() => alas * 3;
}

class Rectangle extends Polygon {
  double panjang;
  double lebar;

  Rectangle(this.panjang, this.lebar);

  @override
  double hitungLuas() => panjang * lebar;

  @override
  double hitungKeliling() => panjang * 2 + lebar * 2;
}
