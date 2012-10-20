<?php
	$sid1 	= quote_smart($_REQUEST['sid']);
	$errCode= quote_smart($_REQUEST['errCode']);
	
	if ($sid1 != "") 
	{
		$sql = "SELECT * FROM subject_session WHERE sid = '$sid1'";
		$result = mysql_query($sql);
		
		if ($result && (mysql_num_rows($result)>0)) 
		{
			$row 		= mysql_fetch_array($result);
			$sid1			= $row['sid'];
			$gid1			= $row['gid'];
			$wday1			= $row['wday'];
            $start_time1	= $row['start_time'];
            $end_time1		= $row['end_time'];
			$venue1			= $row['venue'];
			$s_desc1		= $row['s_desc'];
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
			<td class="title">Session - Update</td>
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
			<form action="submitsession.php?update=1" method="post" name="addForm" >
			<input type="hidden" name="sid" value="<?php echo $sid1; ?>">
				<table width="770" border="0" cellspacing="0" cellpadding="0">
					
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Group ID</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $gid1; ?>" name="gid"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Day</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $wday1; ?>" name="wday"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Start Time</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $start_time1; ?>" name="start_time"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">End Time</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $end_time1; ?>" name="end_time"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Venue</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $venue1; ?>" name="venue"></td>
					</tr>
					<tr class="tabletex">
						<td width="170" height="30" class="tabletex">Description</td>
						<td width="600" class="tabletex"><input type="text" value="<?php echo $s_desc1; ?>" name="s_desc"></td>
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
		location.href	= "main.php?m=session&p=view";
	} 
		
	function checkForm() {
		
		if ((document.addForm.wday.value < 2) || (document.addForm.wday.value > 8)) 
		{
			alert("Day must be between Monday-2 to Sunday-8");
			document.addForm.wday.focus();
			return false;
		}
		if ((document.addForm.venue.value.length < 2) || (document.addForm.wday.value.length > 20)) 
		{
			alert("Venue length must be between 2 ~ 20 characters");
			document.addForm.venue.focus();
			return false;
		}
		if ((document.addForm.s_desc.value.length < 2) || (document.addForm.s_desc.value.length > 15)) 
		{
			alert("Description length must be between 2 ~ 150 characters");
			document.addForm.s_desc.focus();
			return false;
		}
		return true;
	}
</script>