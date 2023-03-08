<h1>Soal No.5</h1>
<?php 
    $total = 0;
    for ($angka = 10; $angka <= 20; $angka++){
        if($angka == 20){
            $total += $angka;
            echo "$angka = $total";            
        }
        else if($angka % 2 == 0){
            $total += $angka;
            echo "$angka + ";
        }
    }
?>