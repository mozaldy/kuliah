import 'shape.dart';

void main(List<String> arguments) {
//   List<Shape> shapes = [
//     Circle(8),
//     Rectangle(8, 8),
//     Rectangle(4, 4),
//     Triangle(4, 4),
//   ];

//   for (var shape in shapes) {
//     print(
//         """
// Bangun Datar: ${shape.runtimeType}
// Keliling: ${shape.hitungKeliling()}
// Luas: ${shape.hitungLuas()}""");
//     print("=" * 30);
//   }
  Shape bentuk1 = Rectangle(5, 4);
  print(bentuk1.hitungLuas());
  Circle bentuk2 = bentuk1;
  bentuk2.r = 10;

  print(bentuk1.hitungLuas());
  print(bentuk2.hitungLuas());
}
