<?php

	$mode	= quote_smart($_REQUEST['mode']);
	$cid1 	= quote_smart($_REQUEST['cid']);
	
	if ($mode == "del") {
		if ($id != "") {
			$sql = "DELETE course WHERE cid = '$cid1'";
			if ($condb->execQuery($sql))
				$del_status = 1;
			else
				$del_status = 0;
		}
		
		echo "<BR>DEBUG: Delete Status:" . $del_status;
		
	} else if ($id != "") {
		$sql = "SELECT * FROM course WHERE cid = '$cid1'";
		$result = $condb->getResult($sql);
		$row = mysql_fetch_array($result);
		$loginname = trim($row['loginname']);
		$email = trim($row['email']);
		$lastlogin = trim($row['lastlogin']);
		$status = trim($row['status']);
	}
?>

<table width="770" border="0" cellspacing="0" cellpadding="0">
	  <tr>
		<td><img src="../images/empty.gif" width="5" height="10" /></td>
	  </tr>
	  
	  <tr>
		<td height="60" valign="top"><table width="300" border="0" cellspacing="0" cellpadding="0">
		  <tr>
			<td width="32"><img src="../images/icon_til.gif" width="32" height="40" /></td>
			<td class="title">Course - Delete</td>
		  </tr>
		</table>
