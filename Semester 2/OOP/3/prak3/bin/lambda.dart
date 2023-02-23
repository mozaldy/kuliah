evenodd(int angka) => (angka % 2 == 0); // returns true if even and false if odd
subtraction(int x, y) => x - y; // returns result of x - y

void main() {
  var angka = 12; // initialization
  // prints 'genap' if evenodd returns true and 'ganjil' if false
  print('$angka adalah angka ${evenodd(angka) ? 'genap' : 'ganjil'}');
  int x = 30; // initialization
  int y = 23; // initialization
  // prints result of x - y
  print('hasil $x - $y adalah ${subtraction(x, y)}');
}
