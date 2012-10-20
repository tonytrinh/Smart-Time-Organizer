<?php
	include("../includes/config.php");
	include("../includes/func.php"); 
	
	
	if (!isset($_SESSION["active_admin_id"]))
		header ("Location: admin_login.php");
	else if ($_SESSION["active_admin_id"] == "")
		header ("Location: admin_login.php");
	


?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

<title><?php echo $_PHPLIB['title']; ?></title>

<link href="../includes/text.css" rel="stylesheet" type="text/css" />
<script src = "../includes/jquery-1.3.2.min.js" type="text/javascript" >
</script>
<script type="text/javascript" src="../includes/script.js"></script>
</head>

<body>
<table width="970" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td width="20">&nbsp;</td>
    <td width="34" background="../images/bg.gif">&nbsp;</td>
    <td width="1055"><table width="970" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td height="40"><table width="355" border="0" align="right" cellpadding="0" cellspacing="0">
          <tr>
            <td width="250" class="main"><div align="right">Welcome, <?php echo $_SESSION["active_login_name"]; ?></div></td>
            <td width="25"><div align="center"><img src="../images/icon_admin.gif" width="17" height="16" align="middle" /></div></td>
            <td width="70" class="main"><div align="center"><a href="logout.php" class="logout">LOGOUT</a></div></td>
            <td width="20"><img src="../images/icon_logout.gif" width="17" height="16" /></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td height="120" valign="top"><table width="970" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><img src="../images/logo.jpg" width="232" height="39" /></td>
            <td width="680"><table width="680" bgcolor="#f98837" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="25" height="30">&nbsp;</td>
                <td width="100" class="mainwhite"><div align="center"><a href="main.php?m=admin&clicksearch=1" class="mainwhite">Administration</a></div></td>
                <td width="60" class="mainwhite"><div align="center"><a href="main.php?m=course&clicksearch=1" class="mainwhite">Course</a></div></td>
                <td width="67" class="mainwhite"><div align="center"><a href="main.php?m=group&clicksearch=1" class="mainwhite">Group</a></div></td>
                <td width="67" class="mainwhite"><div align="center"><a href="main.php?m=session&clicksearch=1" class="mainwhite">Session</a></div></td>
                
                <td width="186">&nbsp;</td>
              </tr>
            </table></td>
          </tr>
        </table></td>
      </tr>
      <tr>
        <td height="1" background="../images/dotline.gif"><img src="../images/dotline.gif" width="8" height="1" /></td>
      </tr>
      <tr>
        <td>
		
			<?php
				$param_m= ($_REQUEST['m']);
				$param_p= ($_REQUEST['p']);
				
				if ($param_m == "course")
					include("m_course.inc");
				else if ($param_m == "group")
					include("m_group.inc");
				else if ($param_m == "session")
					include("m_session.inc");
				else
					include("m_admin.inc");
			?>
		
		
		
		</td>
      </tr>
      <tr>
        <td><p>&nbsp;</p>
          <p>&nbsp;</p>
          <p>&nbsp;</p>
          <p>&nbsp;</p></td>
      </tr>
      <tr>
        <td height="50" class="sml">2012 copyright by Smart Timetable Organizer. All rights reserved.</td>
      </tr>
    </table></td>
    <td width="34" background="../images/bg.gif">&nbsp;</td>
    <td>&nbsp;</td>
  </tr>
</table>
<p>&nbsp;</p>
</body>
</html>
