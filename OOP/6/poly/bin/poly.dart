import 'shape.dart';

void main(List<String> arguments) {
  List<Shape> shapes = [
    Circle(8),
    Rectangle(8, 8),
    Rectangle(4, 4),
    Triangle(4, 4),
  ];

  for (var shape in shapes) {
    print(
        """
Bangun Datar: ${shape.runtimeType}
Keliling: ${shape.hitungKeliling()}
Luas: ${shape.hitungLuas()}""");
    print("=" * 30);
  }
}