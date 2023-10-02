<?php
    $servername = "Server_name";
    $username = "username";
    $password = "password";
    $dbname = "db_name";
    $conn = mysqli_connect($servername, $username, $password, $dbname);
    if(!$conn){
        die("connection failed!". mysqli_connect_error());
    }
?>