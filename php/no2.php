<?php 
    $jenis_kelamin = false;
    // true = laki, false = perempuan
    $kerudung = true;
    if ($jenis_kelamin == true){ // apabila kelamin adalah laki
        echo "<h1>Anda adalah seorang laki, anda wajib menggunakan dasi.</h1>";
    }
    else{ // apabila kelamin adalah perempuan
        if ($kerudung == true){ // apabila berkerudung
            echo "<h1>Anda adalah seorang perempuan, tidak perlu berdasi karena 
            berkerudung.</h1>";
        }
        else{ // apabila tidak berkerudung
            echo "<h1>Anda adalah seorang perempuan, perlu berdasi karena 
            tidak berkerudung.</h1>";
        }
    }
?>