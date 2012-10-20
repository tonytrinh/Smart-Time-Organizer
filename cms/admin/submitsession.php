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
		$sid1			= quote_smart($_REQUEST['sid']);
		$gid1			= quote_smart($_REQUEST['gid']);
		$wday1			= quote_smart($_REQUEST['wday']);
		$start_time1	= quote_smart($_REQUEST['start_time']);
		$end_time1		= quote_smart($_REQUEST['end_time']);
		$venue1			= quote_smart($_REQUEST['venue']);
		$s_desc1		= quote_smart($_REQUEST['s_desc']);
		
		
        if (db_isRecordExist("subject_session", "sid", $sid1)) 
        {
			$sql="UPDATE subject_session
				SET gid 		= '$gid1',  
					wday 		= '$wday1', 
					start_time 	= '$start_time1',
					end_time 	= '$end_time1',
					venue 		= '$venue1',
					s_desc 		= '$s_desc1'
					
				WHERE sid = '$sid1'
			"; 
	
		
		   $result = db_executeSQL($sql);
			
			if ($result) 
			{
				header("location: main.php?m=session&p=view");
			}
		}
		else 
		{
			?>
				<body onload="document.autoForm.submit()">
				<form name="autoForm" method="post" action="main.php?m=session&p=update">
				<input type="hidden" name="errCode" value="Update Failed. Please try again.">
				<input type="hidden" name="sid" value="<?php echo $sid1; ?>">
				</form>
			<?php
		exit;
		}
	} 
	
	else if ($del_mode == "1") 
	{
		$sid1		= quote_smart($_REQUEST['sid']);
		
		$sql="DELETE FROM subject_session WHERE sid = '$sid1'"; 
		$result = db_executeSQL($sql);
		
		if ($result) 
		{
			header("location: main.php?m=session&p=view");
		}
	}

	else if ($add_mode == "1") 
	{
		$sid1			= quote_smart($_REQUEST['sid']);
		$gid1			= quote_smart($_REQUEST['gid']);
		$wday1			= quote_smart($_REQUEST['wday']);
		$start_time1	= quote_smart($_REQUEST['start_time']);
		$end_time1		= quote_smart($_REQUEST['end_time']);
		$venue1			= quote_smart($_REQUEST['venue']);
		$s_desc1		= quote_smart($_REQUEST['s_desc']);
		
		
		$sql="INSERT INTO subject_session (sid,gid,wday,start_time,end_time,venue,added_dt,modified_dt,s_desc,status) 
		VALUE ('','$gid1','$wday1','$start_time1','$end_time1','$venue1','','','$s_desc1','1' )"; 
			
		$result = db_executeSQL($sql);
		
		if ($result) {
			header("location: main.php?m=session&p=view");
		}
	}

		
	
?>


	
