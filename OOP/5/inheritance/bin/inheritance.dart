import 'candyBasic.dart';
import 'candyStripped.dart';

void main(List<String> arguments) {
  var permenMerah = CandyBasic();
  permenMerah.warna = 'merah';
  permenMerah.point = 10;

  var permenMerahStripped = CandyStriped();
  permenMerahStripped.warna = 'merah';
  permenMerahStripped.point = 30;
  permenMerahStripped.direction = 'horizontal';

  permenMerah.replace(5, 7);
  permenMerahStripped.replace(2, 4);

  List<CandyBasic> candies = [];
  candies.add(CandyBasic());
  candies.add(CandyStriped());
  candies.add(CandyStriped());

  for (var i in candies){
    print(i);
  }
}
