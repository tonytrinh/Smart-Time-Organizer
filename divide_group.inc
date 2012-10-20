<?php	
	$group_collection = array();
	$group_size_arr = array();
	for($i=0; $i < count($course_array) ; $i++)
	{
		$sql_lecture = " select * from course_group_session 
						where ccode = '$course_array[$i]' and group_type = '1' ";
		$sql_lab = " select * from course_group_session 
						where ccode = '$course_array[$i]' and group_type = '2' ";
		$lecture_result = mysql_query($sql_lecture);
		$lab_result = mysql_query($sql_lab);
		
		$lecture_temp = array();		
		while($row = mysql_fetch_assoc($lecture_result)) 
		{
        	//$lecture_temp[]=$row['gid'];
        	$temp_group = new lecture_lab_group();
        	$temp_group->type =  $row['group_type'];
        	$temp_group->gid = $row['gid'];
        	$temp_group->session_string = $row['session_string'];
        	$lecture_temp[]=$temp_group;
		}
		
		$lab_temp = array();		
		while($row = mysql_fetch_assoc($lab_result)) 
		{
        	//$lab_temp[]=$row['gid'];
        	$temp_group = new lecture_lab_group();
        	$temp_group->type =  $row['group_type'];
        	$temp_group->gid = $row['gid'];
        	$temp_group->session_string = $row['session_string'];
        	$lab_temp[]=$temp_group;
		}
		
		array_push($group_collection, $lecture_temp);
		array_push($group_collection, $lab_temp);
		$group_size_arr[] = (count($lecture_temp) == 0) ? 1 : count($lecture_temp);
		$group_size_arr[] = (count($lab_temp) == 0) ? 1 : count($lab_temp);
		unset($lecture_temp);
		unset($lab_temp);
			
	}
	
	/*echo "<b>this is list of all group belong to chosen subjects together with session id, each group is an object</b><br/>";
	print_r($group_collection);
	echo '<br/><br/>';
	echo "<b>this is to show the number of group in each collection i.e 3 subjects ==> 6 collection ==> 6 number displayed here (0 and 1 considered same)</b><br/>";
	print_r($group_size_arr);
	echo '<br/><br/>';*/
?>