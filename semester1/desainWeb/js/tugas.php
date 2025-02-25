<!DOCTYPE html>
<html>

<head>
    <title>Station Data</title>
</head>

<body>
    <h1>Enter Station Name</h1>

    <!-- Input Station -->
    <form action="tugas.php" method="post">
        <label for="inputStation">Station:</label>
        <input type="text" id="inputStation" name="station">
        <br>

        <!-- Fetch Button -->
        <input type="submit" value="Fetch Data">
    </form>

    <!-- Station Data -->
    <h2>Station Data:</h2>
    <?php
    if (isset($_POST["station"])) {
        // Get station from POST data
        $station = $_POST["station"];

        // Open calibrations.dat file
        $file = fopen("calibrations.dat", "r");

        // Read file line by line
        while (($line = fgets($file)) !== false) {
            // Split line into parts
            $parts = explode(" ", $line);

            // Check if this line is for the input station
            if ($parts[0] == $station) {
                // Return station data in HTML table format
                echo "<table>";
                echo "<tr><th>Station</th><th>Mean</th><th>5%tile</th><th>95%tile</th><th>Mean</th><th>5%tile</th><th>95%tile</th><th>Mean</th><th>5%tile</th><th>95%tile</th><th>R^2</th></tr>";
                echo "<tr>";
                foreach ($parts as $part) {
                    echo "<td>" . $part . "</td>";
                }
                echo "</tr>";
                echo "</table>";
                fclose($file);
                return;
            }
        }

        // Close file
        fclose($file);

        // If we reach here, the station was not found in the file
        echo "Station not found.";
    }
    ?>
</body>

</html>