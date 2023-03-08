<?php
    $x = rand(0, 100);
    echo "<h1>$x adalah angka genap atau ganjil?</h1>";
    if ($x % 2 == 0){
        echo "$x adalah bilangan genap";
    }
    else{
        echo "$x adalah bilangan ganjil";
    }
?>