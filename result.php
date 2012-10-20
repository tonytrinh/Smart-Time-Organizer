<?php 
	require_once 'connection.php';
	//function to count the number of clashes for each sessions id array, 0 mean no clash
	//function to draw table from session ids
	include('process_func.inc');
 	
	//---get the chosen subjects and subject code
	class lecture_lab_group
	{
		public $type;
		public $gid;
		public $session_string;
	}
	$course_array = array();
	$i = 0;
	while($_REQUEST['code_list_'.$i])
	{
		$temp_code = $_REQUEST['code_list_'.$i];
		array_push($course_array, $temp_code);
		$i++;	
	} 	
	/*print_r($course_array);
	echo "</br>";
	echo "</br>";*/
	
	
	
	//-----get all the group (lab and lecture separately) together with sessions of each group
	include('divide_group.inc');
	
	
	
	
	
	//-----get all combinations: a combination is a collection of 1 lecture or lab from  each group
	include('generate_combination.inc');
 	
 	
 	//-----get the sessions id of each combination
 	include('session_id_of_combination.inc');
 	
	
	
	
	//this is to print to PDF
	$print_string = '';
	foreach ($course_array as $key => $value)
	{
		if($key != 0) $print_string .= '&';
		$print_string .= "code_list_$key=$value";							
	}
	if(isset($_REQUEST['no_of_comb'])) $no_of_comb = $_REQUEST['no_of_comb'];
	else $no_of_comb = 3;
	$print_string .= "&no_of_comb=".$no_of_comb;
	
	if(isset($_REQUEST['print']) )
	{
		$url = $_SERVER['SERVER_NAME'].$_SERVER['PHP_SELF'].'?'.$print_string ;
		$ch = curl_init($url);
		curl_setopt($ch, CURLOPT_HEADER, 0);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		$content = curl_exec($ch);
		curl_close($ch);
		$pdf_name = 'YourTimetable_'.date('YmdHis');				
		try
		{
			$postdata =  array('OutputFileName' => $pdf_name, 'ApiKey' => '', 'CUrl'=>$content);
			$ch = curl_init("http://do.convertapi.com/web2pdf");
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
			curl_setopt($ch, CURLOPT_HEADER, 1);
			curl_setopt($ch, CURLOPT_POST, 1);
  			curl_setopt($ch, CURLOPT_POSTFIELDS, $postdata);
			$result = curl_exec($ch); 
			$headers = curl_getinfo($ch);
			
			$header=ParseHeader(substr($result,0,$headers["header_size"]));
			$body=substr($result, $headers["header_size"]);
			
			curl_close($ch);
			if ( 0 < $headers['http_code'] && $headers['http_code'] < 400 ) 
			{
				// Check for Result = true
				if (!$header['Result'])
				{
					$message = "Something went wrong with request, did not reach ConvertApi service.<br />";
				}
				// Check content type 
				if ($headers['content_type']<>"application/pdf")
				{
			 		$message = "Exception Message : returned content is not PDF file.<br />";
				}
				header('Content-type: ' . $headers['content_type']);
				header('Content-Length: '.strlen($body));
				header('Content-Disposition: attachment; filename="' . $header["OutputFileName"] . '"');
				echo $body;
			}
			else 
			{
			 $message = "Exception Message : ".$result .".<br />Status Code :".$headers['http_code'].".<br />"; 
			}
		}
		catch (Exception $e) 
		{	
			$message = "Exception Message :".$e.Message."</br>";
		}
		//echo $url;
		//echo $content;
		
	}
	function ParseHeader($header='')
	{
		$resArr = array();
		$headerArr = explode("\n",$header);
		foreach ($headerArr as $key => $value) 
		{
			$tmpArr=explode(": ",$value);
			if (count($tmpArr)<1) continue;
			$resArr = array_merge($resArr, array($tmpArr[0] => count($tmpArr) < 2 ? "" : $tmpArr[1]));
		}
		return $resArr;
	}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>Result Page</title>
<meta name="Author" content="Nem Sopha, UTP" />
	<link rel="stylesheet" type="text/css" href="css/style.css" />
	<link rel="stylesheet" type="text/css" href="test_flip/coverflip.css" />
	<link rel="stylesheet" type="text/css" href="test_flip/roundabout.css" />
	<script type="text/javascript" src="includes/jquery-1.3.2.js"></script>
	<script type="text/javascript" src="includes/jquery-ui-1.7.3.custom.js"></script>    
	<script type="text/javascript" src="test_flip/jquery.jcoverflip.js"></script>
    <script type="text/javascript" src="test_flip/jquery.roundabout.js"></script>
	<script type="text/javascript">
		$(document).ready(function() {
			$('#result_roundabout').roundabout();
		});
	</script>
</head>

<body>
<div id="container">
	<div id="holder" class="clearfix">
		<h2 align="center">Smart Timetable Organizer 1.0</h2>
		<!--
	  	</div>
		<div id="header">
		</div>
		-->
	
		<?php include('navigation.inc');?>
		
		<br/>
		<a class=".back_button" href="javascript:history.back(1)" ><img src="images/back.png" alt="back to selection"></a>
		
	    <p>
			<?php 
				//echo $print_string;
				echo "<div align='center'><nobr><a href='result.php?print=1&$print_string'>Convert To PDF</a></nobr></div>";
			?>
		</p>
		
		<div>
			<form method="post" action="result.php" >
				<p align="center"> Select no. of combinations you wish to show and hit Update 
					<select id = 'no_of_comb' name= 'no_of_comb' >
						<?php
							$max_no_of_comb = count($final_session_id_arr);
							
							//maximum combinations to display is 10 because too many makes it look stacked
							if($max_no_of_comb > 10 )
							{
								for($i = 3; $i <= 10 ; $i++)
								{ 
									if($i == $no_of_comb) echo "<option value='$i' selected > $i </option>";
									else echo "<option value='$i' > $i </option>";					
								}
							}
							if($max_no_of_comb > 3 && $max_no_of_comb <=10)
							{
								for($i = 3; $i <= $max_no_of_comb ; $i++)
								{ 
									if($i == $no_of_comb) echo "<option value='$i' selected > $i </option>";
									else echo "<option value='$i'  > $i </option>";					
								}
							}
							else if ($max_no_of_comb == 3) 
							{	
								echo "<option value='3' selected> 3 </option>";
								//then disable the button "Update"
							}
							else if ($max_no_of_comb < 3)
							{
								echo "<option value='$max_no_of_comb' selected> $max_no_of_comb </option>";
								//then disable the button "Update"
							}
							
						?>
					</select>
					<?php
						foreach($course_array as $key => $value) 
						{
							echo "<input type = 'hidden' value = '".$value."' name = 'code_list_".$key."' />";
						}
					?>
					
					<input type = "submit" value="Update" "/>
					
				</p>
				
			</form>
		</div>	
					
			
				    <div id="selectoptions">			
				<form NAME="optionform" method="post" action="">				
					
					<h4 align="center"> List of Courses Selected & Processed:	</h4>	
							
					<table id="courseselected">
						<tr>
							<th>No.</th>
							<th>Course Selected</th>
							<th>Status</th>
						</tr>						
						<?php							
							$course_array = array();
							$i = 0;
							while($_REQUEST['code_list_'.$i])
							{
								$temp_code = $_REQUEST['code_list_'.$i];
								array_push($course_array, $temp_code);
								$i++;
							} 
							//print_r($course_array);
							
							$coursename_array = array();								
							for($i = 0; $i <count($course_array) ; $i++)
							{
								$a = "SELECT cname   FROM course	WHERE ccode = '$course_array[$i]' ";
		
								$result = mysql_query($a);
								
								$session_temp ;	
								while($row = mysql_fetch_assoc($result)) 
								{
									$session_temp=$row['cname'];
								}	
								array_push($coursename_array, $session_temp);
								unset($session_temp);
								//array_push($coursename_array, $result);
							}
							//print_r ($course_array);
							//echo "</br>";
							//print_r ($coursename_array);
							$shortname_array = array();								
							for($i = 0; $i <count($course_array) ; $i++)
							{
								$a = "SELECT c_short   FROM course	WHERE ccode = '$course_array[$i]' ";
		
								$result = mysql_query($a);
								
								$session_temp ;	
								while($row = mysql_fetch_assoc($result)) 
								{
									$session_temp=$row['c_short'];
								}	
								array_push($shortname_array, $session_temp);
								unset($session_temp);
								//array_push($coursename_array, $result);
							}
							
							for ($i = 0; $i <count($course_array) ; $i++)
							{
								echo "<tr>";
								echo "<td>";
								echo $i+1;
								echo "</td>";
								echo "<td>";
								echo $course_array[$i];
								echo " : ";
								echo $coursename_array[$i];
								echo " (".$shortname_array[$i].")";
								echo "</td>";
								echo "<td>";
								echo "(SELECTED)";
								//echo "<input type = 'button' value = 'Delete' onClick = '' />";
								echo "</td>";
								echo "</tr>";								
							}
						?>				
					</table>
					<p align="center"> 			
						<!-- <input type = "button" value="ADD COURSE" onClick=""/> -->
						<!-- <input type = "button" value="UPDATE" onClick=""/> -->					
					</p>				
				</form>
			</div>		
		<div id="resulttable">
			<!-- <h3 align="center">Three (3) Best Timetable Combinations :</h3> -->
				<ul id="result_roundabout"style="padding: 0px; position: relative; " class="roundabout-holder">
				<?php 
					asort($clash_count_arr);
					$display = 0;
					$asc_final_session_id_arr = array();
					foreach ($clash_count_arr as $key => $val)
					{
						$asc_final_session_id_arr[] = $final_session_id_arr[$key];
					}
					sort($clash_count_arr);
					
					//if there is only one combination
					if (count($final_session_id_arr) == 1) {
						echo "<br/>";
						echo "<b>Combination (only 1)"."<br/>";
						echo "Number of clash(es): " . $clash_count_arr[0];
						print_table($asc_final_session_id_arr[0]);
					}	
					
					//if there is two combinations
					else if (count($final_session_id_arr) == 2) {
						echo "<br/>";
						echo "<b>Combination No. 1"."<br/>";
						echo "Number of clash(es): " . $clash_count_arr[0];
						print_table($asc_final_session_id_arr[0]);
						echo "<br/>";
						echo "<b>Combination No. 2"."<br/>";
						echo "Number of clash(es): " . $clash_count_arr[1];
						print_table($asc_final_session_id_arr[1]);
					}						
					
					//if there is 3 or more combinations
					else if(count($final_session_id_arr) >= 3) 
					{
						$number_displayed = $no_of_comb;
						for($i=0 ;$i<$number_displayed; $i++)
						{
							if($i == 0)
								echo "<li class='roundabout-moveable-item roundabout-in-focus'><span>";
							else 
								echo "<li class='roundabout-moveable-item'><span>";	
							//print_r(implode(',',$asc_final_session_id_arr[$i]));
							//echo "<br/>";
							echo "<b>Combination No. ". ($i+1)."</b><br/>";
							echo "<br/>Number of clash(es): " . $clash_count_arr[$i];
							echo "</span>";
							print_table($asc_final_session_id_arr[$i]);
							echo "</li>";						
						}
					}	
						
				?>
				
			</ul>
			
			</br></br></br></br></br></br></br></br></br>
			</br></br></br></br></br></br></br></br></br>
			</br></br></br></br></br></br></br></br></br>
			</br></br></br></br></br></br></br></br></br>
			

		</div>
		</div>
	<?php include('footer.inc');?>
		
</div>
</body>
</html>