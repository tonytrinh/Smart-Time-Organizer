<table width="970" border="0" cellspacing="0" cellpadding="0">
  <tr>
	<td width="200" valign="top"><table width="170" bgcolor="#f98837" border="0" cellspacing="0" cellpadding="0">
	  <tr>
		<td width="25">&nbsp;</td>
		<td>&nbsp;</td>
	  </tr>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td><span class="mainwhite"><a href="main.php?m=course&p=view" class="mainwhite">View Course</a></span></td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
		<td><img src="../images/sidelink_dot.gif" width="140" height="1" /></td>
	  </tr>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td class="mainwhite"><a href="main.php?m=course&p=add" class="mainwhite">Add Course</a></td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
		<td><img src="../images/sidelink_dot.gif" width="140" height="1" /></td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
		<td>&nbsp;</td>
	  </tr>
	</table></td>
	<td valign="top">
	
	<?php
		if ($param_p == "add")
			include("m_course_add.inc");
		else if ($param_p == "update")
			include("m_course_update.inc");
		else
			include("m_course_view.inc");
	?>
	
	
	
	
	</td>
  </tr>
</table>
