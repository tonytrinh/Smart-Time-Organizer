<table width="970" border="0" cellspacing="0" cellpadding="0">
  <tr>
	<td width="200" valign="top"><table width="170" bgcolor="#f98837" border="0" cellspacing="0" cellpadding="0">
	  <tr>
		<td width="25">&nbsp;</td>
		<td>&nbsp;</td>
	  </tr>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td><span class="mainwhite"><a href="main.php?m=admin&p=view" class="mainwhite">View Admin</a></span></td>
	  </tr>
	  <tr>
		<td>&nbsp;</td>
		<td><img src="../images/sidelink_dot.gif" width="140" height="1" /></td>
	  </tr>


<?php if ($_SESSION["active_accessright"] <= 1) { ?>
	  <tr>
		<td><div align="center"><img src="../images/sidelink_icon.gif" width="11" height="12" /></div></td>
		<td class="mainwhite"><a href="main.php?m=admin&p=add" class="mainwhite">Add Admin</a></td>
	  </tr>

	  <tr>
		<td>&nbsp;</td>
		<td><img src="../images/sidelink_dot.gif" width="140" height="1" /></td>
	  </tr>
<?php } ?>

	  <tr>
		<td>&nbsp;</td>
		<td>&nbsp;</td>
	  </tr>
	</table></td>
	<td valign="top">
	
	<?php
		if (($param_p == "add") && ($_SESSION["active_accessright"] <= 1))
			include("m_admin_add.inc");
		else if ($param_p == "update")
			include("m_admin_update.inc");
		else
			include("m_admin_view.inc");
	?>
	
	
	
	
	</td>
  </tr>
</table>
