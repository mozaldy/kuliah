operasi(int angka) => (angka % 2 == 0);

void main() {
  var angka = 21;
  var result = operasi(angka);
  print('Result is ${result ? 'genap' : 'ganjil'}');
}
