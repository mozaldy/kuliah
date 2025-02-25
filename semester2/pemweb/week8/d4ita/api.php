<?php

require_once('conn.php');

// Set headers to allow cross-origin requests
header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE");
header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

// Handle GET request to fetch all records
if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    $sql = "SELECT * FROM mahasiswa";
    $result = $conn->query($sql);

    $mahasiswa = array();
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $mahasiswa[] = $row;
        }
        echo json_encode($mahasiswa);
    } else {
        echo json_encode(array('message' => 'No data found'));
    }
}

// Handle POST request to create a record
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $data = json_decode(file_get_contents("php://input"), true);

    $nrp = $data['nrp'];
    $nama = $data['nama'];
    $jenis_kelamin = $data['jenis_kelamin'];

    $sql = "INSERT INTO mahasiswa (nrp, nama, jenis_kelamin) VALUES ('$nrp', '$nama', '$jenis_kelamin')";

    if ($conn->query($sql) === TRUE) {
        echo json_encode(array('message' => 'Record created successfully'));
    } else {
        echo json_encode(array('error' => $conn->error));
    }
}

// Handle PUT request to update a record
if ($_SERVER['REQUEST_METHOD'] === 'PUT') {
    parse_str(file_get_contents("php://input"), $data);

    $nrp = $data['nrp'];
    $nama = $data['nama'];
    $jenis_kelamin = $data['jenis_kelamin'];

    $sql = "UPDATE mahasiswa SET nama='$nama', jenis_kelamin='$jenis_kelamin' WHERE nrp='$nrp'";

    if ($conn->query($sql) === TRUE) {
        echo json_encode(array('message' => 'Record updated successfully'));
    } else {
        echo json_encode(array('error' => $conn->error));
    }
}

// Handle DELETE request to delete a record
if ($_SERVER['REQUEST_METHOD'] === 'DELETE') {
    parse_str(file_get_contents("php://input"), $data);

    $nrp = $data['nrp'];

    $sql = "DELETE FROM mahasiswa WHERE nrp='$nrp'";

    if ($conn->query($sql) === TRUE) {
        echo json_encode(array('message' => 'Record deleted successfully'));
    } else {
        echo json_encode(array('error' => $conn->error));
    }
}

// Close database connection
$conn->close();
?>
