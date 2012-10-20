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
		$cid1			= quote_smart($_REQUEST['cid']);
		$ccode1			= quote_smart($_REQUEST['ccode']);
		$cname1			= quote_smart($_REQUEST['cname']);
		$c_short1		= quote_smart($_REQUEST['c_short']);
		
		
        if (db_isRecordExist("course", "cid", $cid1)) 
        {
			$sql="UPDATE course
				SET cname = '$cname1', 
					ccode = '$ccode1', 
					c_short = '$c_short1'
					
				WHERE cid = '$cid1'
			"; 
			
           	$result = db_executeSQL($sql);
			
			if ($result) 
			{
				header("location: main.php?m=course&p=view");
			}
		
		} 
		else 
		{
		?>
			<body onload="document.autoForm.submit()">
			<form name="autoForm" method="post" action="main.php?m=course&p=update">
			<input type="hidden" name="errCode" value="Update Failed. Please try again.">
			<input type="hidden" name="cid" value="<?php echo $cid1; ?>">
			</form>
		<?php
		exit;
		}
	} 
	
	else if ($del_mode == "1") 
	{
		$cid1		= quote_smart($_REQUEST['cid']);
		
		$sql="DELETE FROM course WHERE cid = '$cid1'"; 
		$result = db_executeSQL($sql);
		
		if ($result) 
		{
			header("location: main.php?m=course&p=view");
		}
	}

	else if ($add_mode == "1") {
		$ccode1			= quote_smart($_REQUEST['ccode']);
		$cname1			= quote_smart($_REQUEST['cname']);
        $c_short1		= quote_smart($_REQUEST['c_short']);
		
		
		if (db_isRecordExist("course", "cname", $cname1)) 
		{
			?>
			<body onload="document.autoForm.submit()">
				<form name="autoForm" method="post" action="main.php?m=course&p=add">
					<input type="hidden" name="errCode" value="Course already exists, please use another name.">
					<input type="hidden" name="ccode" 	value="<?php echo $ccode1; ?>">
					<input type="hidden" name="cname" 	value="<?php echo $cname1; ?>">
					<input type="hidden" name="c_short" value="<?php echo $c_short1; ?>">
				
				</form>
			<?php
			exit;
		} 
		else 
		{
			$sql="INSERT INTO course (cid,ccode,cname,added_dt,modified_dt,c_short,status) 
			VALUE ('','$ccode1','$cname1','','', '$c_short1', '1' )"; 

			$result = db_executeSQL($sql);
			
			if ($result) {
				header("location: main.php?m=course&p=view");
			}
		}

		
	}
?>


	
