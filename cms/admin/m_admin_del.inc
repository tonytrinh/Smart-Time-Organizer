<?php

	$mode	= $_REQUEST['mode'];
	$id 	= $_REQUEST['id'];
	
	if ($mode == "del") {
		if ($id != "") {
			$sql = "DELETE users WHERE id = '$id'";
			if ($condb->execQuery($sql))
				$del_status = 1;
			else
				$del_status = 0;
		}
		
		echo "<BR>DEBUG: Delete Status:" . $del_status;
		
	} else if ($id != "") {
		$sql = "SELECT * FROM users WHERE id = '$id'";
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
			<td class="title">Administration - Delete</td>
		  </tr>
		</table></td>
	  </tr>
	  <tr>
		<td>
			<form action="index.php?m=admin&p=del" method="post">
			<input type="hidden" name="mode" value="del">
			<input type="hidden" name="id" value="<?php echo $id; ?>">
			<input type="hidden" name="loginname" value="<?php echo $loginname; ?>">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Login Name</td>
				<td width="600" class="tabletex"><b><?php echo $loginname; ?></b></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Email Address</td>
				<td width="600" class="tabletex"><b><?php echo $email; ?></b></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Access Right</td>
				<td width="600" class="tabletex">
					<select name="accessright" disabled>
						<option value="1" <?php if ($accessright == "1") echo "Selected" ?>>Administrator</option>
						<option value="2" <?php if ($accessright == "2") echo "Selected" ?>>Staff</option>
					</select></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Status</td>
				<td width="600" class="tabletex">
					<select name="status" disabled>
						<option value="1" <?php if ($status == "1") echo "Selected" ?>>Active</option>
						<option value="2" <?php if ($status == "2") echo "Selected" ?>>Disable</option>
					</select></td>
			</tr>
			
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">&nbsp;</td>
				<td width="600" class="tabletex">
					<input type="submit" value="Delete">
					<input type="button" value="Cancel" onClick="location.href='index.php?m=admin&p=view'">
				</tr>
			</table></form>
		</td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
	  </tr>
	</table>
