<?php
	$errCode= $_REQUEST['errCode'];
	if ($errCode != "") {
		$ccode1			= $_REQUEST['ccode'];
		$cname1			= $_REQUEST['cname'];
		$c_short1		= $_REQUEST['c_short'];
        
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
			<td class="title">Course - Add</td>
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
			<form action="submitcourse.php?add=1" method="post" name="addForm" enctype="multipart/form-data">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Course Code</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $ccode1; ?>" name="ccode"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Course Name</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $cname1; ?>" name="cname"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Course Short Name</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $c_short1; ?>" name="c_short"></td>
			</tr>
			
			
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">&nbsp;</td>
				<td width="600" class="tabletex">
					<input type="submit" value="Save" onClick="return checkForm();" name="uploadForm">&nbsp;&nbsp;
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
		location.href	= "main.php?m=course&p=view";
	} 
		
	function checkForm() {
		
		if ((document.addForm.ccode.value.length <7) || (document.addForm.ccode.value.length > 10)) 
		{
			alert("Course Code length must be between 7 ~ 10 characters");
			document.addForm.ccode.focus();
			return false;
		}
		
		if ((document.addForm.cname.value.length <5) || (document.addForm.cname.value.length > 60)) 
		{
			alert("Course Name length must be between 5 ~ 60 characters");
			document.addForm.cname.focus();
			return false;
		}
		if ((document.addForm.c_short.value.length <2) || (document.addForm.c_short.value.length > 15)) 
		{
			alert("Course Name length must be between 2 ~ 15 characters");
			document.addForm.c_short.focus();
			return false;
		}
		return true;
	}
</script>