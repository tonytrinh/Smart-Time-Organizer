<?php
	include("../includes/config.php");
	include("../includes/func.php"); 

	$update_mode 	= 0;
	$add_mode  	= 0;
	$del_mode  	= 0;

	if (isset($_GET['update']))
		$update_mode = quote_smart($_GET['update']);
	else if (isset($_GET['del']))
		$del_mode = quote_smart($_GET['del']);
	else if (isset($_GET['add']))
		$add_mode = quote_smart($_GET['add']);
		
	if ($update_mode == "1") {
		$id				= quote_smart($_REQUEST['id']);
		$loginname		= quote_smart($_REQUEST['loginname']);
		$password		= quote_smart($_REQUEST['password']);
		$password_retype= quote_smart($_REQUEST['password_retype']);
		$email			= quote_smart($_REQUEST['email']);
		$accessright	= quote_smart($_REQUEST['accessright']);
		$status			= quote_smart($_REQUEST['status']);
		
		if (db_isRecordExist("users", "id", $id)) {

			if (($password != "") && ($password == $password_retype)) {
				$passwordUpdateStr = " password = md5('$password'), ";
			}


			if ($_SESSION["active_accessright"] <= 1) {
				$sql="UPDATE users
					SET email = '$email', 
						accessright = '$accessright', 
						status = '$status', 
						$passwordUpdateStr
						modified = now()
					WHERE id = '$id'
				"; 

			} else {
				$sql="UPDATE users
					SET email = '$email', 
						$passwordUpdateStr
						modified = now()
					WHERE id = '$id'
				"; 
			}

			$result = db_executeSQL($sql);
			
			if ($result) {
				header("location: main.php?m=admin&p=view");
			}
		} else {
			?>
				<body onload="document.autoForm.submit()">
				<form name="autoForm" method="post" action="main.php?m=admin&p=update">
				<input type="hidden" name="errCode" value="Update Failed. Please try again.">
				<input type="hidden" name="id" value="<?php echo $id; ?>">
				</form>
			<?php
		exit;
		}
	} 
	
	else if ($del_mode == "1") {
		$id		= quote_smart($_REQUEST['id']);
		
		$sql="DELETE FROM users WHERE id = '$id'"; 
		$result = db_executeSQL($sql);
		
		if ($result) {
			header("location: main.php?m=admin&p=view");
		}
	}

	else if ($add_mode == "1") {
		$loginname		= quote_smart($_REQUEST['loginname']);
		$password		= quote_smart($_REQUEST['password']);
		$password_retype= quote_smart($_REQUEST['password_retype']);
		$email			= quote_smart($_REQUEST['email']);
		$accessright	= quote_smart($_REQUEST['accessright']);
		$status			= quote_smart($_REQUEST['status']);
		
		if (db_isRecordExist("users", "loginname", $loginname)) {
			?>
			<body onload="document.autoForm.submit()">
				<form name="autoForm" method="post" action="main.php?m=admin&p=add">
					<input type="hidden" name="errCode" 	value="Login name already exists, please use another login name.">
					<input type="hidden" name="loginname" 	value="<?php echo $loginname; ?>">
					<input type="hidden" name="email" 		value="<?php echo $email; ?>">
					<input type="hidden" name="accessright" value="<?php echo $accessright; ?>">
					<input type="hidden" name="status" 		value="<?php echo $status; ?>">
				</form>
			<?php
			exit;
		} else {
			$sql="INSERT INTO users (loginname,password,email,accessright,status,created) 
				VALUE ('$loginname',md5('$password'),'$email','$accessright','$status', now())"; 
			
			$result = db_executeSQL($sql);
			
			if ($result) {
				header("location: main.php?m=admin&p=view");
			}
		}
		
	}
?>


	
