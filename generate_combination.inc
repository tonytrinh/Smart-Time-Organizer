<?php
	global $group_size_arr;
	global $final_string;
	$final_string = '';
	//$group_size_arr = array(2,1,2,2);
	$no_of_group_collection = count($group_size_arr);
	
	function loop($i,$j,$result,$size)
	{
		global $group_size_arr;
		global $final_string;
		$result .= ($i) . "-" . $j;		
		if($i == ($size - 1))			
			$final_string .= $result;			
		else 		
		{
			$result .= ' ' ;			
			for($inside_index=0; $inside_index < $group_size_arr[$i+1] ; $inside_index++)
			{
				loop($i+1,$inside_index,$result,$size);
				if($inside_index < $group_size_arr[$i+1] - 1) 
					$final_string .= '</br>';					
			}		
		}
		
	}
	
	for($index=0; $index < $group_size_arr[0] ; $index++)
	{
		loop(0,$index,"",$no_of_group_collection);
		if($index < $group_size_arr[0] - 1) 
			$final_string .= '</br>';
	} 
 	//echo $final_string . '<br/>'. '<br/>';
 	
 	$combination_arr_int = array();	
 	$combination_arr =  explode('</br>',trim($final_string));
 	foreach($combination_arr as $one_combination)
 	{
 		$one_combination_int = array();
 		$one_combination_arr = explode(' ',trim($one_combination));
 		foreach($one_combination_arr as $one_group)
 		{
 			$one_group_int = array();
 			$one_group_arr = explode('-',trim($one_group));
 			foreach($one_group_arr as $one_digit)
 			{
 				$one_group_int[] = intval($one_digit);
 			}
 			$one_combination_int[] = $one_group_int;
 			unset($one_group_int);
 			unset($one_group_arr);			
 		}
 		$combination_arr_int[] = $one_combination_int;
 		unset($one_combination_int);
 		unset($one_combination_arr);		
 	}
 	/*echo "<b>this is to show all possible combination with with coordination based on the group collection</b><br/>";
	print_r($combination_arr_int);
 	echo '<br/><br/>';*/
 ?>