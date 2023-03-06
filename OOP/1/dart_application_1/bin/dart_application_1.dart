import 'dart:io';

class Main {
  void fibonacci() {
    int i = 0;
    var fibonacci = [0, 1];
    int current = 0;
    while (current < 100) {
      i++;
      current = fibonacci[i] + fibonacci[i - 1];
      if (current < 100) fibonacci.add(current);
    }
    print(fibonacci);
  }

  void area() {
    stdout.write('Shape(triangle, rectangle, circle, ellipse): ');
    String shape = stdin.readLineSync();
    stdout.write('Length/radius: ');
    int panjang = int.parse(stdin.readLineSync());
    stdout.write('Width/radius: ');
    int lebar = int.parse(stdin.readLineSync());
    double area = calculate(shape, panjang, lebar);
    print('Your $shape area is $area');
  }

  double calculate(String shape, int panjang, int lebar) {
    double result;
    if (shape == 'triangle')
      result = 1 / 2 * panjang * lebar;
    else if (shape == 'rectangle')
      result = panjang * lebar * 1.0;
    else
      result = 3.14 * panjang * lebar;
    return result;
  }
}

void main() {
  Main main = Main();
  print(
      '1. Generate Fibonacci numbers below 100 using loops and dart language.');
  main.fibonacci();
  print(
      '2. Make an example code on how to calculate the area (luas) from some two-dimensional figures!');
  while (true) main.area();
}
