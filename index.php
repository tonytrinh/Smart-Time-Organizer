<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>HomePage - Smart Timetable Organizer</title>
<link rel="stylesheet" type="text/css" href="css/style.css" />
<meta name="Author" content="Nem Sopha, UTP" />
<?php
	require_once "connection.php";
	if(isset($_REQUEST['no_of_subject'])) $no_of_subject = $_REQUEST['no_of_subject'];
	else $no_of_subject =3;
	
?>
<script src = "includes/jquery-1.3.2.js" type="text/javascript" >
</script>
<SCRIPT LANGUAGE="JavaScript">

function validateForm()
{

	var returnStatus = 1;
	var no_of_dropdown ;
	no_of_dropdown = $('#no_of_subject').val();
	var check_duplicate = false;
	var check_selected = false;
	var i, j;
	for( i=0; i < no_of_dropdown - 1 ; i++)
	{
		for(j = i+1; j<no_of_dropdown ; j++)
		{
			var first_dropdown = $('#code_list_' + i).val();
			var second_dropdown = $('#code_list_' + j).val();
			if(first_dropdown == second_dropdown)
			{
				check_duplicate = true;
			}
			else if (first_dropdown == 500 || second_dropdown == 500)
			{
				check_selected = true;
			} 
			
		}
	
	}
	//var first_drop = $('select.code_list_0').val();

	if(check_duplicate == true)
	{
		alert("Courses cannot be redundant. Please select different courses for each" );
		check_duplicate = false;
		return false;
	}
	
	if (check_selected == true)
	{
		alert("Please select a course");
		check_selected == false;
		return false;
	}
	
	else 
	{
		$('#course_form').submit();
	
	}
}

</SCRIPT>

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
		
		<div id="content" align="center">
			<h3 align="center">Let's Get Started!</h3>
			<div>
				<img src="images/process.jpg" alt="process" />
				<br/><br/>
			</div>			
			<!--<form id='course_form' name='course_form' method="post" action="checkclash_test.php" >-->
			<form method="post" action="index.php" align="center">
				How many subjects do you want to take?
				<select id = 'no_of_subject' name= 'no_of_subject' >
				<?php
					$max_no_of_subject = 8;
					for($i = 3; $i <= $max_no_of_subject ; $i++)
					{ 
						if($i == $no_of_subject) echo "<option value='$i' selected> $i </option>";
						else echo "<option value='$i'> $i </option>";							
					}
				?>
				</select>
				<input type = "submit" value="Update" "/>
				<br/>
			</form>
			<br/>
			
			<p align="center"> Select them here: </p>
			<form id='course_form' name='course_form' method="post" action="result.php"  align="center">
			
			<?php 			
				$query = "SELECT ccode, cname FROM course ORDER BY cname";
				//$no_of_subject = 4;
				for($i = 0; $i <$no_of_subject ; $i++)
				{ 
					echo "Course " . ($i+1) . ": "; 
					echo "<select id = 'code_list_".($i)."' name= 'code_list_".($i). "' > ";
					echo "<option value='500'> -- Select a course from the list -- </option>";	
					$result = mysql_query ($query);
					while($nt=mysql_fetch_array($result))	
					//foreach($result as $nt)				
					{
						echo "<option value='$nt[ccode]'>$nt[cname]</option>";					
					}
					echo "</select><br/> ";
				}
			
			?>
			
			<br/>
				
			<input type = "button" value="PROCEED" onClick="validateForm()"/> 
			</form>
			<br/>
			<br/>
			---------- * ----------
			<br/>
			<br/>
		<p align="center"> Can't find some subjects? Maybe they're in our 
			<a href="exception_list.php">exception list</a> !</p>
		<p> Want this application for your Android device? </br> Download it here! </br>
		 <img src="images/QR_STO_Android.png" alt="QR Code for Android" width=100 height=100/>
		 <br/> (Scan the QR code to go to download page or click 
		 <a href="http://www.appsgeyser.com/getwidget/Smart%20Time%20Organizer">here</a>) </p>
		</div>

	</div>
	<?php include('footer.inc');?>
</div>
</body>
</html>