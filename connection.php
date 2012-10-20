<?php
	$host = "localhost";
	
	$user = "root";
	$password = "";
	$db = "smart_time";
	
	
	$connection = mysql_connect($host, $user, $password) 
		or die ("Cannot connect to the MySQL server ". mysql_error());

	mysql_select_db($db) 
		or die ("Cannot select database " . mysql_error());
	
?>
