<h1>Soal No.4</h1>
<?php 
    $angkaRandom = 0;
    $langkah = 0;
    echo "<h1>Angka Random:</h1>";
    while($angkaRandom != 20){
        $angkaRandom = rand(10,50);
        echo "$angkaRandom ";
        $langkah++;
    }
    echo "<h2>Terjadi $langkah langkah sampai mendapatkan angka 20.</h2>";
?>