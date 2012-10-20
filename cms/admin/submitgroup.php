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
		
	if ($update_mode == "1") 
	{
		$gid1			= quote_smart($_REQUEST['gid']);
		$cid1			= quote_smart($_REQUEST['cid']);
		$group_type1	= quote_smart($_REQUEST['group_type']);
				
        if (db_isRecordExist("subject_group", "gid", $gid1)) 
        {	
			$sql="UPDATE subject_group
				SET cid = '$cid1',  
					group_type = '$group_type1' 
					
				WHERE gid = '$gid1'
			"; 
		} 
		
        $result = db_executeSQL($sql);
			
		if ($result) {
			header("location: main.php?m=group&p=view");
		}
		
		else 
		{
			?>
				<body onload="document.autoForm.submit()">
				<form name="autoForm" method="post" action="main.php?m=group&p=update">
				<input type="hidden" name="errCode" value="Update Failed. Please try again.">
				<input type="hidden" name="gid" value="<?php echo $gid1; ?>">
				</form>
			<?php
		exit;
		}
	 
	}
	else if ($del_mode == "1") 
	{
		$gid1		= quote_smart($_REQUEST['gid']);
		
		$sql="DELETE FROM subject_group WHERE gid = '$gid1'"; 
		$result = db_executeSQL($sql);
		
		if ($result) 
		{
			if ($logo != "") 
			{
				if (file_exists("../group/".$logo))
					unlink("../group/".$logo);
			}
			header("location: main.php?m=group&p=view");
		}
	}

	else if ($add_mode == "1") 
	{
		$cid1			= quote_smart($_REQUEST['cid']);
        $group_type1	= quote_smart($_REQUEST['group_type']);
		
		$sql="INSERT INTO subject_group (gid,cid,group_type,added_dt,modified_dt,status) 
			VALUE ('','$cid1','$group_type1','','','1' )"; 
	
		
		$result = db_executeSQL($sql);
		
		if ($result) 
		{
			header("location: main.php?m=group&p=view");
		}		
	}
?>


	
