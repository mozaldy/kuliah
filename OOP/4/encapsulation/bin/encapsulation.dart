import 'perkantoran.dart';
import 'dart:io';

void main() {
  Office myOffice = Office(); // inisialisasi object dari class Office
  myOffice.name = 'Aldyz'; // set nama menjadi 'Aldyz'
  Employee aldy = Employee(); // inisialisasi object dari class Employee
  aldy.name = 'Mohammad Rizaldy Ramadhan'; // Set nama
  aldy.position = 'CEO'; // Set jabatan
  aldy.salary = 999999999; // Set gaji
  myOffice.hire(aldy); // hire ke dalam office

  // Tulisan menu
  String menu = """1. Change office name.
2. Hire new employee.
3. List all employees.
4. Add new position to the office.
5. List available positions.
0. Exit""";

  while (true) {
    print("Welcome to ${blue(myOffice.getName)}'s Information System.");
    print(menu);
    String input = stdin.readLineSync(); // meminta input menu
    if (input == '1') {
      // apabila input 1 maka
      stdout.write('New office name: '); // pertanyaan dari program
      var name = stdin.readLineSync(); // jawaban dari user
      myOffice.name = name; // nama dirubah menggunakan set
    } else if (input == '2') {
      // apabila input 2 maka
      Employee newEmployee = Employee(); // inisialisasi pekerja baru
      stdout.write('Input New Employee name: '); // pertanyaan nama
      newEmployee.name = stdin.readLineSync(); // jawaban nama
      stdout.write('Input New Employee position: '); // pertanyaan jabatan
      newEmployee.position = stdin.readLineSync(); // jawaban jabatan
      stdout.write('Input New Employee salary: '); // pertanyaan gaji
      newEmployee.salary = int.parse(stdin.readLineSync()); // jawab gaji
      if (newEmployee.validEmployee) {
        // apabila pekerja yg diinput vaid
        myOffice.hire(newEmployee); // hire employee
        print(blue('New Employee added succesfully!')); // pesan sukses
      } else // apabila tidak valid
        print(red('Employee is not valid, please try again!')); // pesan gagal
    } else if (input == '3') {
      // apabila input 3
      myOffice.getEmployees; // method get untuk menulis semua pekerja
    } else if (input == '4') {
      // apabila input 4
      stdout.write('Add new position to the office: '); // pertanyaan jabatan
      Office.availablePositions.add(stdin.readLineSync()); // jawaban
    } else if (input == '5') {
      // apabila input 5
      print(Office.availablePositions); // tampilkan semua jabatan yg tersedia
    } else if (input == '0') {
      // apabila input 0
      print(red('Exiting.')); // keluar dari program
      break;
    } else {
      // apabila input invalid
      print(red('Command invalid, please try again.')); // pesan gagal
    }
  }
}

// merubah string menjadi biru
String blue(String text) => '\x1B[34m$text\x1B[0m';

// merubah string menjadi merah
String red(String text) => '\x1B[31m$text\x1B[0m';
