<?php

$SN = $_POST["SN"];
$len = strlen($SN);

$infile = "WVdata.dat";
$in = fopen($infile, "r") or die("Can't open");

$line = fgets($in);

$found = 0;
while ((!feof($in)) && ($found == 0)) {
    list($SN_dat, $A, $B, $C, $beta, $tau) = fscanf($in, "%s %f %f %f %f %f");
    if (strncasecmp($SN_dat, $SN, $len) == 0)
        $found = 1;
}
fclose($in);
if ($found == 0)
    echo "Couldn't find this instrument.";
else {
    echo "<p><table border='2'><tr><th>Quantity</th><th>Value</th>" . "</td></tr>";
    echo "<tr><td>Instrument ID</td><td>$SN</td></tr>";
    echo "<tr bgcolor='silver'><td colspan='2'>Calibration Constants</td></tr>";
    echo "<tr><td>A</td><td>$A</td></tr>";
    echo "<tr><td>B</td><td>$B</td></tr>";
    echo "<tr><td>C</td><td>$C</td></tr>";
    echo "<tr><td>&tau;</td><td>$tau</td></tr>";
    echo "<tr><td>&beta;</td><td>$beta</td></tr>";
    echo "</table>";
}
?>