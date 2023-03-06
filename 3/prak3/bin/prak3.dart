void main() {
  var myNumbers = [
    132,
    24,
    41,
    999,
    432,
    34,
    1
  ]; // Initialization fo array of numbers
  print('''numbers: $myNumbers
max value: ${maxValue(myNumbers)}
average value: ${averageValue(myNumbers)}
      '''); // prints result of calculations
}

int maxValue(var numbers) {
  // sorting algorithm in descending order (high to low)
  for (int i = 0; i < numbers.length - 1; i++) {
    for (int j = 0; j < numbers.length - i - 1; j++) {
      if (numbers[j] < numbers[j + 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
  return numbers[0]; // returns the first number
}

double averageValue(var numbers) {
  var sum = 0; // initialize sum
  for (int i = 0; i < numbers.length; i++) {
    // for each number in array
    sum += numbers[i]; // add each number to sum
  }
  return sum / numbers.length; // return sum divided by length of numbers
}
