import 'dart:io';

class Rectangle {
  double width;
  double height;

  Rectangle(this.width, this.height);

  double getArea() {
    return width * height;
  }

  double getRound() {
    return 2 * (width + height);
  }
}

void main(List<String> arguments) {
  Rectangle rect1, rect2;
  rect1 = Rectangle(5, 40);
  rect2 = Rectangle(5, 999);
  print(rect1.getRound());
  print(rect1.getArea());
  print(rect2.getRound());
  print(rect2.getArea());
}
