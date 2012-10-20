<?php
	$id 	= $_REQUEST['id'];
	$errCode= $_REQUEST['errCode'];
	
	if ($id != "") {


		if ($_SESSION["active_accessright"] <= 1) {
                	// full access
					$sql = "SELECT * FROM users WHERE id = '$id'" ;
		} else {
                	// limited access
			$sql = "SELECT * FROM users WHERE id = '$id'" . " AND id = '" . $_SESSION["active_admin_id"] ."'";
        	}
		$result = mysql_query($sql);
		
		if ($result && (mysql_num_rows($result)>0)) {
			$row 		= mysql_fetch_array($result);
			$loginname	= $row['loginname'];
			$email		= $row['email'];
			$accessright	= $row['accessright'];
			$status		= $row['status'];
			//$loginname = "abc";
		}
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
			<td class="title">Administration - Update</td>
		  </tr>
		</table></td>
	  </tr>
	  
	  <?php if ($errCode != "") { ?>
	  <tr>
		<td height="30" class="tabletex_red">
			<?php echo $errCode; ?>
		</td>
	  </tr>
	  <?php } ?>
	  
	  
	  <tr>
		<td>
			<form action="submituser.php?update=1" method="post" name="addForm">
			<input type="hidden" name="id" value="<?php echo $id; ?>">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Login Name</td>
				<td width="600" class="tabletex"><b><?php echo$loginname; ?></b></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Password</td>
				<td width="600" class="tabletex"><input type="password" value='' name="password"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Retype Password</td>
				<td width="600" class="tabletex"><input type="password" value="" name="password_retype"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Email Address</td>
				<td width="600" class="tabletex"><input type="text" value='<?php echo $email; ?>' name="email"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Access Right</td>
				<td width="600" class="tabletex">
				<?php
					if ($_SESSION["active_accessright"] <= 1) {
						usergroupControl("accessright", $accessright, "--Select--", "", "", "");
					} else {
						usergroupControl("accessright", $accessright, "--Select--", "", "", "1");
					}
				?></td>
			</tr>



			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Status</td>
				<td width="600" class="tabletex">
					<?php
					if ($_SESSION["active_accessright"] <= 1) {
						statusControl("status", $status, "--Select--", "", "", "");
					} else {
						statusControl("status", $status, "--Select--", "", "", "1");
					}
				?></td>
			</tr>
			
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">&nbsp;</td>
				<td width="600" class="tabletex">
					<input type="submit" value="Save" onClick="return checkForm();">&nbsp;&nbsp;
					<input  type="button" value="Cancel" onClick="gotoBack()" >
				</tr>
			</table></form>
		</td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
	  </tr>
	</table>
	
	
<script type="text/javascript">
	function gotoBack() {
		location.href	= "main.php?m=admin&p=view";
	} 
		
	function checkForm() {
		
		if (document.addForm.password.value != "") {
			if (!isValidPasswdChar(document.addForm.password.value)) {
				alert("Invalid Login Name input.");
				document.addForm.password.focus();
				return false;
			}
			if (!isValidPasswdLength(document.addForm.password.value)) {
				alert("Password length must be between 4 ~ 12 characters");
				document.addForm.password.focus();
				return false;
			}
			if (!isValidPasswdChar(document.addForm.password.value)) {
				alert("Invalid password input.");
				document.addForm.password.focus();
				return false;
			}
			if (document.addForm.password.value != document.addForm.password_retype.value) {
				alert("Password and Retype Password not match.");
				document.addForm.password.focus();
				return false;
			}
		}
		
		if (!isValidEmail(document.addForm.email.value)) {
			alert("Invalid email address");
			document.addForm.email.focus();
			return false;
		}
		
		if(document.addForm.accessright.options[document.addForm.accessright.selectedIndex].value == 0) {
			alert("Please assign access right to this account.");
			document.addForm.accessright.focus();
			return false;
		}
			
		if(document.addForm.status.options[document.addForm.status.selectedIndex].value == 0) {
			alert("Please assign record status.");
			document.addForm.status.focus();
			return false;
		}
		
		return true;
	}
</script>
