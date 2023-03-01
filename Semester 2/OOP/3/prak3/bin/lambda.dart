evenodd(int angka) => (angka % 2 == 0); // returns true if even and false if odd
subtraction(int x, y) => (x - y); // returns result of x - y

evenodd2(int angka) => (angka % 2 == 0) ? 'genap' : 'ganjil';

void main() {
  var angka = 13; // initialization
  // prints 'genap' if evenodd returns true and 'ganjil' if false
  print('$angka adalah angka ${evenodd2(angka)}');
  int x = 30; // initialization
  int y = 23; // initialization
  // prints result of x - y
  print('hasil $x - $y adalah ${subtraction(x, y)}');
}