
class CandyBasic {
  String _warna;
  int _point;

  void replace(var koordinatAwal, var koordinatTujuan) {
    if (koordinatAwal != koordinatTujuan) {
      print('Koordinat dipindah dari $koordinatAwal ke $koordinatTujuan');
    } else {
      print('Koordinat sama, tidak berubah');
    }
  }

  set warna(String warna) => _warna = warna;

  String get warna => _warna;

  set point(int point) => _point = point;

  int get point => _point;
}

