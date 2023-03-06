import 'candyBasic.dart';

class CandyStriped extends CandyBasic {
  String _direction;

  @override
  void replace(var koordinatAwal, var koordinatTujuan) {
    if (koordinatAwal == koordinatTujuan && super.warna == warna) {
      print('Koordinat sama, tidak berubah');
    } else {
      print('Koordinat dipindah dari $koordinatAwal ke $koordinatTujuan');
    }
  }

  set direction(String direction) => _direction = direction;

}
