<table width="970" border="0" cellspacing="0" cellpadding="0">
  <tr>
	<td width="200" valign="top"><table width="170" bgcolor="#f98837" border="0" cellspacing="0" cellpadding="0">
	  <tr>
		<td width="25">&nbsp;</td>
		<td>&nbsp;</td>
	  </tr>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td><span class="mainwhite"><a href="main.php?m=group&p=view" class="mainwhite">View group</a></span></td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
		<td><img src="../images/sidelink_dot.gif" width="140" height="1" /></td>
	  </tr>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td class="mainwhite"><a href="main.php?m=group&p=add" class="mainwhite">Add group</a></td>
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
			include("m_group_add.inc");
		else if ($param_p == "update")
			include("m_group_update.inc");
		else
			include("m_group_view.inc");
	?>
	
	
	
	
	</td>
  </tr>
</table>
