<h1>Soal No.3</h1>
<h1>A.</h1>
<?php
    $total = 0;
    for ($angka = 11; $angka <= 20; $angka++){
        $total += $angka;
        if($angka == 20){
            echo "$angka = $total";            
        }
        else{
            echo "$angka + ";
        }
    }
echo "<hr><h1>B.</h1>";

    $angka = 2;
    $total = $angka;
    $pangkat = 4;
    echo "$angka dipangkat $pangkat adalah ";
    for ($n = 1; $n < $pangkat ; $n++){
        $total *= $angka;
    }
    echo "$total ";
    // $x = 2;
    // $hasil = $x;
    // $y = 4;
    // for ($n = 2; $n < $y; $n++){
    //     $hasil = $hasil * $x;
    // }
    // echo $hasil;
?>