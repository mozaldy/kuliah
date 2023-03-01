class Office {
  String _name;
  List<Employee> employees = [];

  set name(String name) => _name = name;

  String get getName => _name;

  void hire(Employee employee) {
    employees.add(employee);
  }

}

class Employee {
  String _name;
  int _age;
  String _gender;
  String _position;
  int _salary;

  set name(String name) => _name = name;
  String get getName => "${this._name}";
}