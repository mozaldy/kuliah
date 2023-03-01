import 'perkantoran.dart';
import 'dart:io';

void main() {
  Office myOffice = Office();
  myOffice.name = 'Aldyz';

  String menu = """1. Change office name""";

  while (true) {
    print("Welcome to ${blue(myOffice.getName)}'s Information System.");
    print(menu);
    int input = int.parse(stdin.readLineSync());
    if (input == 1) {
      stdout.write('New office name: ');
      var name = stdin.readLineSync();
      myOffice.name = name;
    }
  }
}

// Convert any inputted text into blue.
String blue(String text) => '\x1B[34m$text\x1B[0m';

// Convert any inputted text into red.
String red(String text) => '\x1B[31m$text\x1B[0m';
