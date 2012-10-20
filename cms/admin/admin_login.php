<?php
	include("../includes/config.php"); 
	include("../includes/func.php"); 

	$admin_login_name 	= trim(quote_smart($_GET['v1']));
	$msgCode	  		= trim(quote_smart($_GET['msgCode'])); 
?>



<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><?php echo $config->sitename; ?></title>
<link href="../includes/text.css" rel="stylesheet" type="text/css" />
<link rel='stylesheet' id='wp-admin-css'  href='../css/wp-admin.css' type='text/css' media='all' />
</head>

<body>
<table width="970" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td width="20">&nbsp;</td>
    <td width="34" background="../images/bg.gif">&nbsp;</td>
    <td width="1055"><table width="970" border="0" align="center" cellpadding="0" cellspacing="0">
      <tr>
        <td height="40"></td>
      </tr>
      <tr>
        <td height="120" valign="top"><table width="970" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><img src="../images/logo.jpg" width="232" height="39" /></td>
            <td width="680"><table width="680" bgcolor="#f98837" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="25" height="30">&nbsp;</td>
                <td width="100" class="mainwhite"></td>
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
		<br>
		<div id="navigate_to_main" align="center">
			<a href="../../index.php">Back to Smart Timetable Organizer</a>	
	    </div>
			<!-- LOGIN AS ADMINISTRATOR -->
			<?php include('login_form.inc');?>			
		
		</td>
	  
	  </tr>
	  
	  <tr>
        <td height="1" background="../images/dotline.gif"><img src="../images/dotline.gif" width="8" height="1" /></td>
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




