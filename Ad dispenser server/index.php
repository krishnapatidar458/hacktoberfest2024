<?php
function OpenCon(){
    $host = "127.0.0.1";
    $dbuser = "root";
    $dbpass = " ";
    $db = "ad_dispenser";
    $conn = new mysqli($db, $dbuser, $dbpass, $host) or die("Connect failed: %\n". $conn -> error);
    return $conn;
}
function CloseCon($conn){
    $conn -> close;
}