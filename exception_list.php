<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<?php
	require_once "connection.php";
?>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Exception List</title>
<link rel="stylesheet" type="text/css" href="css/style.css" />
<meta name="Author" content="Nem Sopha, UTP" />
</head>

<body>
<div id="container">
	<div id="holder" class="clearfix">
		<div id="logo">
			<h1 align="center">Smart Timetable Organizer 1.0</h1>
	  </div>
	  <div id="header">
	  </div>
		<?php include('navigation.inc');?>
		
		<div id="content">
			<h3>Exception List</h3>
	
			<h4>Why exception?</h4>
			<p> This website is currently a prototype only and there are some limitations that
			the system cannot handle yet, as it is developed in a short time. If the website is
			to be deployed for students' use, a little bit more time and study would do the trick!
			Stay tuned!</p>
			
			<h4>List:</h4>
			<p> Please take note that FYP I (Final Year Project I), FYP II (Final Year Project II),
			TTP (Technopreneurship Team Project) and ETP (Engineering Team Project) is not listed and also not counted
			in the exception list as these subjects do not have a timetable. There would be no
			fixed classes for these subjects, therefore all activities and talks and the such 
			will be usually announced in elearning.</p>
				<?php
				
					$sql = "SELECT * FROM `exception_tab` ";
					$result = mysql_query($sql);
								
					echo "<table style='width:400;  height:300px;' border='1' cellspacing='0' cellpadding='0' align='center'>";
						echo "<th align='center'> CID. </th>";
						echo "<th align='center'> Course Name </th>";
						echo "<th align='center'> Course Code </th>";
						echo "<th align='center'> Course Short Name </th>";					
							
					if ($result) 
					{
						while($row = mysql_fetch_array($result))
						{
							echo "<tr>";
							echo "<td align='center'>";
								echo $row['cid'];
							echo "</td>";
							echo "<td align='center'>";
								echo $row['cname'];
							echo "</td>";
							echo "<td align='center'>";
								echo $row['ccode'];
							echo "</td>";
							echo "<td align='center'>";
								echo $row['c_short'];
							echo "</td>";
							
							echo "</tr>";
						} 		
					}
					else 
					{
						echo "No Exceptions";
					}
					echo "</table>";		
			
			?>
		<br/>
		<br/>	
		</div>
	</div>
	<?php include('footer.inc');?>
</div>
</body>
</html>