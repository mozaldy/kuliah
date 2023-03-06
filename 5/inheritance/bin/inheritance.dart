import 'package:inheritance/inheritance.dart' as inheritance;

class CandyBasic {
  String _warna;
  int _point;

  void replace(var koordinatAwal, var koordinatTujuan) {
    // cek
  }

  set warna(String warna) => _warna = warna;

  String get warna => _warna;
  
  set point(int point) => _point = point;

  int get point => _point;
}

void main(List<String> arguments) {
  print('Hello world: ${inheritance.calculate()}!');
}
