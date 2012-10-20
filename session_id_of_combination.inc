<?php	
	//echo "<b>this is to show sessions id of each combination</b><br/>";
	$final_session_id_arr = array();
 	foreach($combination_arr_int as $one_combination)
 	{
 		$session_string = '';
 		foreach($one_combination as $one_group)
		{
			if(count($one_group) == 2)
			{
				$group_collection_outer = $one_group[0];
				$group_collection_inner = $one_group[1];
				$temp = $group_collection[$group_collection_outer][$group_collection_inner];
				if(is_object($temp))
				 {
				 	$session_string .= ($session_string == '') ? $temp->session_string : (','. $temp->session_string);
				 }
			}
		}
		$session_id_temp_arr = explode(',', trim($session_string));
		$session_id_arr = array();
 		foreach($session_id_temp_arr as $session_id)
		{			
			$session_id_arr[] = intval($session_id);
		}
		$final_session_id_arr[] = $session_id_arr;
		unset($session_id_temp_arr);
		unset($session_id_arr);
		
		//echo $session_string . '<br/>';
 	}
 	/*echo "<b>this is to show the array of sessions id so u can just pass this into ur check clash and done</b><br/>";
	print_r($final_session_id_arr);
	echo '<br/><br/>';*/
 	$clash_count_arr = array();
 	
	foreach($final_session_id_arr as $one_session_id_arr)
	{
		$clash_count_arr[] = getclash_number($one_session_id_arr);
	}
	//print_r($clash_count_arr);	
	
	//echo "<b><br/><br/>after sorting <br/><br/></b>";
	/*
	asort($clash_count_arr);
	foreach ($clash_count_arr as $key => $val) {
		print_r(implode(',',$final_session_id_arr[$key]));
		echo '<br/>';
		print_table($final_session_id_arr[$key]);
		echo '<br/><br/>';
	}
	*/
?>