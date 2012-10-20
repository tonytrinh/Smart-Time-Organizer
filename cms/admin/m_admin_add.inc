<?php
	$errCode= $_REQUEST['errCode'];
	if ($errCode != "") {
		$loginname		= $_REQUEST['loginname'];
		$email			= $_REQUEST['email'];
		$accessright	= $_REQUEST['accessright'];
		$status			= $_REQUEST['status'];
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
			<td class="title">Administration - Add</td>
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
			<form action="submituser.php?add=1" method="post" name="addForm">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Login Name</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $loginname; ?>" name="loginname"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Password</td>
				<td width="600" class="tabletex"><input type="password" value="" name="password"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Retype Password</td>
				<td width="600" class="tabletex"><input type="password" value="" name="password_retype"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Email Address</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $email; ?>" name="email"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Access Right</td>
				<td width="600" class="tabletex">
				<?php
					usergroupControl("accessright", $accessright, "--Select--", "", "", "");
				?></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Status</td>
				<td width="600" class="tabletex">
					<?php
					statusControl("status", $status, "--Select--", "", "", "");
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
		
		if (!isValidLoginLength(document.addForm.loginname.value)) {
			alert("Login Name length must be between 4 ~ 20 characters");
			document.addForm.loginname.focus();
			return false;
		}
		
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