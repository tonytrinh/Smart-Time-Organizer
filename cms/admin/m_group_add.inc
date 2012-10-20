<?php
	$errCode= $_REQUEST['errCode'];
	if ($errCode != "") {
		$cid1			= $_REQUEST['cid'];
		$group_type1	= $_REQUEST['group_type'];
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
			<td class="title">Group - Add</td>
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
			<form action="submitgroup.php?add=1" method="post" name="addForm" enctype="multipart/form-data">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Course ID</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $cid; ?>" name="cid"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Group Type</td>
				<td width="600" class="tabletex">
				
					<!-- <input type="" value="<?php echo $group_type; ?>" name="group_type"> -->
					<select name="grouplist" id="grouplist">
					  <option value="0" selected>--select--</option>
					  <option value="1">1</option>
					  <option value="2">2</option>
					</select>

				
				</td>
			
			
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
		location.href	= "main.php?m=group&p=view";
	} 
		
	function checkForm() 
	{
		
		if(document.addForm.grouplist.options[document.addForm.grouplist.selectedIndex].value == 0) {
			alert("Please select a value for Group Type");
			document.addForm.grouplist.focus();
			return false;
		}
		return true
		
	}
</script>