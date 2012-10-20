<?php
	
	date_default_timezone_set('ASIA/Taipei');
	
	if(!defined('DS'))
		define('DS', DIRECTORY_SEPARATOR);
	
	if(!defined('BASE_DIR'))
		define('BASE_DIR', dirname(dirname(__FILE__)).DS);
	if(!defined('SESSION_DIR'))
		define('SESSION_DIR', BASE_DIR . 'tmp' . DS);
	if(!defined('SITE_NAME'))
		define('SITE_NAME', 'STO ADMIN');
	if(!defined('INCLUDES_DIR'))
		define('INCLUDES_DIR', dirname(__FILE__) . DS);
		
    $_PHPLIB['basedir'] = BASE_DIR;
	$_PHPLIB['sessdir'] = SESSION_DIR;
	$_PHPLIB['title'] = SITE_NAME;
	
	session_save_path(SESSION_DIR);
	session_start();

	$results_per_page	= 20;
	
	$host = "localhost";    	
	
	$username = "root";            
	$password = "";       	
	$db_name = "smart_time";  

	/*$user = "pluzmene_tony";
	$password = "tonymissie123";
	$db_name = "pluzmene_smart_time";*/
	
	$con = mysql_connect("$host","$username","$password");
	$con_sqli = mysqli_connect("$host","$username","$password", "$db_name");
	if (!$con) {
		die('Could not connect: ' . mysql_error());
	}
	
	mysql_select_db("$db_name", $con);

	
?>
