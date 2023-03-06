class Office {
  String _name; // atribut nama office
  List<Employee> employees = []; // atribut list employee
  static List<String> availablePositions = [
    // posisi yang available
    'CEO',
    'Programmer',
    'Akuntan',
    'Sekretaris'
  ];

  set name(String name) => _name = name; // Set nama office

  String get getName => _name; // Get nama office

  get getEmployees {
    // get semua pekerja
    print('No. \t Name \t\t\t\t Position \t Salary'); // kolom
    int no = 1; // inisialisai nomor tabel
    for (Employee employee in employees) {
      // baris
      print(
          "$no. \t ${employee._name} \t ${employee._position} \t${employee._salary}");
      no++; // increment no tabel untuk setiap baris
    }
  }

  void hire(Employee employee) {
    employees.add(employee); // hire pekerja
  }
}

class Employee {
  String _name; // atribut nama
  String _position; // atribut jabatan
  int _salary; // atribut gaji

  bool validEmployee = true; // apabila pekerja valid

  set name(String name) {
    // set method name employee
    if (name.length > 10) {
      _name = name;
    } else {
      validEmployee = false;
      print('Name is invalid, make sure you input the full name!');
    }
  }

  set position(String position) {
    // set method position employee
    if (Office.availablePositions.contains(position)) {
      // apabila jabatan yg di input ada di availabel positions
      _position = position;
    } else {
      validEmployee = false;
      print(
          'Invalid position, make sure you input available positions: ${Office.availablePositions}');
    }
  }

  set salary(int salary) {
    // set method gaji employee
    if (salary > 1000000) {
      // apabila gaji diatas 1 jt
      _salary = salary;
    } else {
      validEmployee = false;
    }
  }
}
