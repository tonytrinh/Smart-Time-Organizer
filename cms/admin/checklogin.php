<?php
	include("../includes/config.php");
	include("../includes/func.php");
	
	$login_name		= trim(quote_smart($_POST['admin_login_name'])); 
	$login_password	= trim(quote_smart($_POST['admin_login_password'])); 

	$checkLoginStatus = db_CheckAdminLogin($login_name, $login_password, $lret_ValArray);
	
	if ($checkLoginStatus == 1) {
		$id 			= $lret_ValArray['id'];
		$loginname 		= $lret_ValArray['loginname'];
		$email			= $lret_ValArray['email'];
		$accessright	= $lret_ValArray['accessright'];
		$status			= $lret_ValArray['status'];
		$lastlogin		= $lret_ValArray['lastlogin'];
		
		$_SESSION["active_admin_id"] 	 	= $id;
		$_SESSION["active_login_name"] 	 	= $loginname;
		$_SESSION["active_accessright"]		= $accessright;
				
		header("location: main.php");
	} else {
		header("location: admin_login.php?msgCode=0&v1=$login_name"); 
	}
?>	
