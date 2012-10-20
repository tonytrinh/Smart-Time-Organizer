<?php
	$errCode= $_REQUEST['errCode'];
	if ($errCode != "") {
		$gid1			= $_REQUEST['gid'];
		$sid1			= $_REQUEST['sid'];
		$wday1			= $_REQUEST['wday'];
		$start_time1	= $_REQUEST['start_time'];
		$end_time1		= $_REQUEST['end_time'];
		$venue1			= $_REQUEST['venue'];
		$s_desc1		= $_REQUEST['s_desc'];
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
			<td class="title">Session - Add</td>
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
			<form action="submitsession.php?add=1" method="post" name="addForm" enctype="multipart/form-data">
			<table width="770" border="0" cellspacing="0" cellpadding="0">
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Group ID</td>
				<td width="600" class="tabletex"><input type="text" value="<?php echo $gid1; ?>" name="gid"></td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Day</td>
				<td width="600" class="tabletex">
					<!-- <input type="text" value="<?php echo $wday1; ?>" name="wday"> -->
					<select name="wday" id="wday">
					  <option value="0" selected>--select--</option>
					  <option value="2">Monday</option>
					  <option value="3">Tuesday</option>
					  <option value="4">Wednesday</option>
					  <option value="5">Thursday</option>
					  <option value="6">Friday</option>
					  <option value="7">Saturday</option>
					  <option value="8">Sunday</option>
					</select>
				</td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">Start Time</td>
				<td width="600" class="tabletex">
					<!-- <input type="text" value="<?php echo $start_time1; ?>" name="start_time"> -->
					<select name="start_time" id="start_time">
					  <option value="0" selected>--select--</option>
					  <option value="8:00:00">8:00:00</option>
					  <option value="8:30:00">8:30:00</option>
					  <option value="9:00:00">9:00:00</option>
					  <option value="9:30:00">9:30:00</option>
					  <option value="10:00:00">10:00:00</option>
					  <option value="10:30:00">10:30:00</option>
					  <option value="11:00:00">11:00:00</option>
					  <option value="11:30:00">11:30:00</option>
					  <option value="12:00:00">12:00:00</option>
					  <option value="12:30:00">12:30:00</option>
					  <option value="13:00:00">13:00:00</option>
					  <option value="13:30:00">13:30:00</option>
					  <option value="14:00:00">14:00:00</option>
					  <option value="14:30:00">14:30:00</option>
					  <option value="15:00:00">15:00:00</option>
					  <option value="15:30:00">15:30:00</option>
					  <option value="16:00:00">16:00:00</option>
					  <option value="16:30:00">16:30:00</option>
					  <option value="17:00:00">17:00:00</option>
					  <option value="17:30:00">17:30:00</option>
					  <option value="18:00:00">18:00:00</option>
					  <option value="18:30:00">18:30:00</option>
					  <option value="19:00:00">19:00:00</option>
					  <option value="19:30:00">19:30:00</option>
					  <option value="20:00:00">20:00:00</option>
					  <option value="20:30:00">20:30:00</option>
					  <option value="21:00:00">21:00:00</option>
					  <option value="21:30:00">21:30:00</option>
					  <option value="22:00:00">22:00:00</option>
					</select>
				</td>
			</tr>
			<tr class="tabletex">
				<td width="170" height="30" class="tabletex">End Time</td>
				<td width="600" class="tabletex">
					<!-- <input type="text" value="<?php echo $end_time1; ?>" name="end_time"> -->
					<select name="end_time" id="end_time">
					  <option value="0" selected>--select--</option>
					  <option value="8:00:00">8:00:00</option>
					  <option value="8:30:00">8:30:00</option>
					  <option value="9:00:00">9:00:00</option>
					  <option value="9:30:00">9:30:00</option>
					  <option value="10:00:00">10:00:00</option>
					  <option value="10:30:00">10:30:00</option>
					  <option value="11:00:00">11:00:00</option>
					  <option value="11:30:00">11:30:00</option>
					  <option value="12:00:00">12:00:00</option>
					  <option value="12:30:00">12:30:00</option>
					  <option value="13:00:00">13:00:00</option>
					  <option value="13:30:00">13:30:00</option>
					  <option value="14:00:00">14:00:00</option>
					  <option value="14:30:00">14:30:00</option>
					  <option value="15:00:00">15:00:00</option>
					  <option value="15:30:00">15:30:00</option>
					  <option value="16:00:00">16:00:00</option>
					  <option value="16:30:00">16:30:00</option>
					  <option value="17:00:00">17:00:00</option>
					  <option value="17:30:00">17:30:00</option>
					  <option value="18:00:00">18:00:00</option>
					  <option value="18:30:00">18:30:00</option>
					  <option value="19:00:00">19:00:00</option>
					  <option value="19:30:00">19:30:00</option>
					  <option value="20:00:00">20:00:00</option>
					  <option value="20:30:00">20:30:00</option>
					  <option value="21:00:00">21:00:00</option>
					  <option value="21:30:00">21:30:00</option>
					  <option value="22:00:00">22:00:00</option>
					</select>
				</td>
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
			</table></form>
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
		
		if(document.addForm.wday.options[document.addForm.wday.selectedIndex].value == 0) {
			alert("Please select a day for the session");
			document.addForm.wday.focus();
			return false;
		}
		if(document.addForm.start_time.options[document.addForm.start_time.selectedIndex].value == 0) {
			alert("Please select start time for the session");
			document.addForm.start_time.focus();
			return false;
		}
		if(document.addForm.end_time.options[document.addForm.end_time.selectedIndex].value == 0) {
			alert("Please select end time for the session");
			document.addForm.end_time.focus();
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
			alert("Description length must be between 2 ~ 15 characters");
			document.addForm.s_desc.focus();
			return false;
		}
		return true;
	}
</script>