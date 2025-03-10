<?php


$count = 20;
echo "<h3>Fibonacci sequence, count = " . $count . "</h3>";
$fibo = array(0);
for ($i = 0; $i < $count; $i++) {
  echo $fibo[$i];
  echo "<br>";
  if ($fibo[$i] == 0) {
    $fibo[$i + 1] = $fibo[$i] + 1;
  } else {
    $fibo[$i + 1] = $fibo[$i] + $fibo[$i - 1];
  }
}
