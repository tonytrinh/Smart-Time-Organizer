<?php
	$gid1 	= quote_smart($_REQUEST['gid']);
	$errCode= quote_smart($_REQUEST['errCode']);
	
	if ($gid1 != "") 
	{
		$sql = "SELECT * FROM subject_group WHERE gid = '$gid1'";
		$result = mysql_query($sql);
		
		if ($result && (mysql_num_rows($result)>0)) 
		{
			$row 		= mysql_fetch_array($result);
			$gid1		= $row['gid'];
			$cid1		= $row['cid'];
			$group_type1	= $row['group_type'];
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
			<td class="title">Group - Update</td>
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
			<form action="submitgroup.php?update=1" method="post" name="addForm" >
			<input type="hidden" name="gid" value="<?php echo $gid1; ?>">
				<table width="770" border="0" cellspacing="0" cellpadding="0">
					
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Course ID</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $cid1; ?>" name="cid"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Group Type</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $group_type1; ?>" name="group_type"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">&nbsp;</td>
						<td width="600" class="tabletex">
							<input type="submit" value="Save" onClick="return checkForm();" name="uploadForm">&nbsp;&nbsp;
							<input  type="button" value="Cancel" onClick="gotoBack()" >
					</tr>
				</table>
			</form>
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
		
		if ((document.addForm.group_type.value == 1) || (document.addForm.group_type.value == 2)) 
		{
			return true;
		}
		
		else
		{
			alert("Group Type must be either 1-Fixed, or 2-Alternate");
			document.addForm.group_type.focus();
			return false;
		}
	}
</script>