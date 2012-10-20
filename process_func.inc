<?php
	function getclash_number($sid_array)
	{
		
		//$sid_array = array(2,3,4,6,7,8,9,10);
		$session_arr = array();
		for($i=0; $i < count($sid_array) ; $i++)
		{
			$sql_sdetails = " select wday, start_time, end_time, venue from subject_session 
							where sid = $sid_array[$i]  ";
			$result = mysql_query($sql_sdetails);
				
			$session_temp = array();		
			while($row = mysql_fetch_assoc($result)) 
			{
				$session_temp[]=$row['wday'];
				$session_temp[]=$row['start_time'];
				$session_temp[]=$row['end_time'];
				$session_temp[]=$row['venue'];
			}	
			array_push($session_arr, $session_temp);
			unset($session_temp);	
		}
		
		//just to test printing out the elements of $session_arr
		/*for ($k=0; $k<count($sid_array); $k++) 
		{
			for ($j=0; $j<4; $j++) 
			{
				echo $session_arr[$k][$j];
				echo "   ";
					
			}
			echo "<br/>";
		}*/
		
		//get the day to compare
		$day_arr = array();
		$time_arr = array();
		for ($m=0; $m<count($sid_array); $m++)
		{
			$day = $session_arr[$m][0];
			array_push ($day_arr, $day);
			
			
			$session_temp = array();
			$temp_start = intval(str_replace(':','',trim($session_arr[$m][1])))	;
			$session_temp[]=$temp_start;
			$temp_end = intval(str_replace(':','',trim($session_arr[$m][2])))	;
			$session_temp[]=$temp_end;	
			$time_arr[] = 	$session_temp;
			unset($session_temp);
		}		
		$comb_size = sizeof($sid_array);
		//$clash_count1=0;
		$clash_count = 0;		
		for ($i= 0; $i<$comb_size - 1; $i++ )
		{
			$a = $day_arr[$i];
			for ($j = $i+1; $j<$comb_size; $j++ )
			{
				$b = $day_arr[$j];
				if ($a == $b)
				{
					//$clash_count1++;
					$s1 = $time_arr[$i][0];
					$e1 = $time_arr[$i][1];	
					$s2 = $time_arr[$j][0];
					$e2 = $time_arr[$j][1];
					
					if ($s1 <= $s2 && $s2 < $e1 || $s1 < $e2 && $e2 <= $e1 || $s2 <= $s1 && $s1 < $e2 || $s2 < $e1 && $e1 < $e2) 
					{
						$clash_count++;
						//echo "</br>";
					}
				}
			}
		}
		/*echo "Clash found: ". $clash_count;		
		echo "</br>";*/
		return $clash_count;
	
	}
	
	
	
 	/*--------------------------------------------------------------------------------------*/
	
	
	
	function print_table($sid_array)
	{	
		echo "<table style='width:400; background-color:#CFECEC; height:300px;' border='1' cellspacing='0' cellpadding='0'>
  				<tr>
					<td>&nbsp;</td>";
		//$sid_array = array(2,3,4,53,55,52,54,57,56,58,61,63,60,62,66,65,67,64);
		//$sid_array = array(20,19,390,391,295,296,2,3,4,260,259,261,388,389,509);
		$temp = implode(",", $sid_array);
		
		//get minimum and maximum start time
		$getdata = 	"SELECT MAX(end_time) AS max_end_time, MIN(start_time) AS min_start_time
					FROM cgs
					WHERE sid IN ($temp) ";	
				
		$result = mysql_query($getdata);		
		while($row = mysql_fetch_assoc($result)) 
		{
			$max_end_time = (int)substr($row['max_end_time'],0,2) - 1;
			$min_start_time = (int)substr($row['min_start_time'],0,2);
		}		
		//print time header
		for($i = $min_start_time; $i <= $max_end_time; $i++)
		{
			echo "<td style=\"vertical-align:middle;text-align:center;background-color:#6D7B8D;\">".$i."-".($i+1)."</td>";
		}
		echo "</tr>";
		
		$wdays = array("", "", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday");
		
		for ($wday = 2; $wday <=8 ; $wday++) 
		{
			$end_time = $max_end_time; 
			$start_time = $min_start_time; 
			
			$buffer = array();
			$table = ""; 
			//get data by each wday
			$getdata = 	"SELECT sid, c_short, cname, start_time, end_time, venue, s_desc, group_type
						FROM cgs
						WHERE sid IN ($temp)
						AND wday=".$wday."
						ORDER BY start_time, end_time ";
			 
			//echo $getdata."<BR/>";	
			$result = mysql_query($getdata);
			$num_rows = mysql_num_rows($result); 
			
			while($row = mysql_fetch_array($result)) 
			{
				$buffer[] = array('start_time'=>$row['start_time'], 'end_time'=>$row['end_time'], 'desc'=>$row['s_desc'], 'shortcut'=>$row['c_short'], 'venue'=>$row['venue'], 'group_type'=>$row['group_type']);
			}
			
			if ($num_rows == 0)
			{
				$table .= "<tr> <td style='vertical-align:middle;text-align:center;background-color:#6D7B8D;'>".$wdays[$wday]."</td>";
				for ($i = $start_time; $i <= $end_time; $i++)
				{
					$table .= "<td>&nbsp</td>";
				}
				
				$table .= "</tr>";
			}
			else 
			{
				$row_by_row = array();
				$arranged_buffer = array();  
				$temp_buffer = array();
				$clash_record = array();
				$is_clash = 0;
				$row_span = 1;
				$check_clash = 0;
				$first_clash_set = 0;
				
				for ($i = 0; $i < $num_rows; $i++) 
				{
					$current = $buffer[$i];
					$current_start_time = (int)substr($current['start_time'],0,2);
					$current_end_time = (int)substr($current['end_time'],0,2);
					
					if ($i < $num_rows-1 )
					{
						$next_start_time = (int)substr($buffer[$i+1]['start_time'],0,2);
						if ($next_start_time >= $current_start_time && $next_start_time < $current_end_time)
						{
							$temp_buffer[] = $current;
							$is_clash = 1; 
						}
						else
						{
							if ($is_clash == 1)
							{
								$temp_buffer[] = $current;
							}
							$is_clash = 0;
						}
					}
					else 
					{
						if ($is_clash == 1)
						{
							$temp_buffer[] = $current;
						}
						$is_clash = 0;
					}
					
					if ($is_clash == 0) 
					{
						
						if (sizeof($temp_buffer) == 0)
						{
							$arranged_buffer[] = $current;
							$clash_record[] = "NO";
						}
						else
						{
							$arranged_buffer[] = $temp_buffer;
							$clash_record[] = "YES";
							
							//get maximum row span
							if(count($temp_buffer) > $row_span) 
							{
								$row_span = sizeof($temp_buffer);
							}
							
							$temp_buffer = NULL;
						}
					}
					
				}
				
				/* echo "<BR/>*********** ".$wdays." <BR/>";
				print_r ($arranged_buffer);
				print_r ($clash_record);
				echo "<BR/>rowspan = ".$row_span; */
				
				//initiate $row_by_row array with string 
				for ($i = 0; $i < $row_span; $i++) 
				{
					$row_by_row[] = "";
				}
				
				//print out Monday, Tuesday....
				$row_by_row[0] .= "<tr> <td rowspan='".$row_span."' style='vertical-align:middle;text-align:center;background-color:#6D7B8D;'>".$wdays[$wday]."</td>";
				
				
				for ($i = 0; $i < count($arranged_buffer); $i++)
				{
					$shorter_start_time = ""; 
					$shorter_end_time = "";
					
					$current = $arranged_buffer[$i];
					$check_clash = $clash_record[$i];
					if ($check_clash == "NO")
					{
						if(substr($current['start_time'],3,2) == '00')
						{
							$shorter_start_time = substr($current['start_time'],0,2); 
						}
						else
						{
							$shorter_start_time = substr($current['start_time'],0,5); 
						}
						if(substr($current['end_time'],3,2) == '00')
						{
							$shorter_end_time = substr($current['end_time'],0,2);
						}
						else
						{
							$shorter_end_time = substr($current['end_time'],0,5); 
						}
						$detail = $shorter_start_time."-".$shorter_end_time."<br/>".$current['desc']."<br/>".$current['shortcut']."<br/>".$current['venue'];	
						
						//for colspan
						$course_start_time = (int)substr($current['start_time'],0,2);
						$course_end_time = (int)substr($current['end_time'],0,2);	
						
						$diff = $course_end_time - $course_start_time;
						
						if ($start_time < $course_start_time)
						{
							for ($j = $start_time; $j < $course_start_time; $j++)
							{
								$row_by_row[0] .= "<td rowspan='".$row_span."'>&nbsp;</td>";
							}
						}
						
						$start_time = $course_start_time;
						
						if ($start_time == $course_start_time)
						{
							$row_by_row[0] .= "<td colspan='".$diff."' rowspan='".$row_span."' style='vertical-align:middle;text-align:center;";	
							if ($current['group_type'] == 1)
								$row_by_row[0] .= "background-color:#F7BA79;";
							else if ($current['group_type'] == 2)
								$row_by_row[0] .= "background-color:#A1F779;";							
							$row_by_row[0] .= "'>".$detail."</td>";
						}
						
						$start_time = $course_end_time;
						
					}
					else
					{
						$clash_start_time = (int)substr($current[0]['start_time'],0,2);
						$clash_end_time = (int)substr($current[count($current)-1]['end_time'],0,2);
						
						$diff_for_clash_cell = $clash_end_time - $clash_start_time;
						
						if ($start_time < $clash_start_time)
						{
							for ($j = $start_time; $j < $clash_start_time; $j++)
							{
								$row_by_row[0] .= "<td rowspan='".$row_span."'>&nbsp;</td>";
							}
							$start_time = $clash_start_time;
						}
						
						if ($start_time == $clash_start_time)
						{
							
							for ($k = 0; $k < count($current); $k++)
							{
								
								$current_clash = $current[$k];
								$inner_start_time; 
								
								if(substr($current_clash['start_time'],3,2) == '00')
								{
									$shorter_start_time = substr($current_clash['start_time'],0,2); 
								}
								else
								{
									$shorter_start_time = substr($current_clash['start_time'],0,5); 
								}
								if(substr($current_clash['end_time'],3,2) == '00')
								{
									$shorter_end_time = substr($current_clash['end_time'],0,2);
								}
								else
								{
									$shorter_end_time = substr($current_clash['end_time'],0,5); 
								}
								$detail = $shorter_start_time."-".$shorter_end_time."<br/>".$current_clash['desc']."<br/>".$current_clash['shortcut']."<br/>".$current_clash['venue'];	
							
								//for colspan
								$inner_clash_start_time = (int)substr($current_clash['start_time'],0,2);
								$inner_clash_end_time = (int)substr($current_clash['end_time'],0,2);	
								
								$diff_clash_course = $inner_clash_end_time - $inner_clash_start_time;
								
								if ($k > 0 && $first_clash_set == 0 ) $row_by_row[$k] .= "<tr>";
								
								if ($start_time < $inner_clash_start_time)
								{
									for ($j = $start_time; $j < $inner_clash_start_time; $j++)
									{
										$row_by_row[$k] .= "<td>&nbsp;</td>";
									}
								}
								
								$inner_start_time = $inner_clash_start_time; 
								
								if ($inner_start_time == $inner_clash_start_time)
								{
									$row_by_row[$k] .= "<td colspan='".$diff_clash_course."' style='vertical-align:middle;text-align:center;";	
									if($k == 0)
									{
										if ($current_clash['group_type'] == 1)
											$row_by_row[$k] .= "background-color:#F7BA79;";
										else if ($current_clash['group_type'] == 2)
											$row_by_row[$k] .= "background-color:#A1F779;";
									}
									else
									{
										$row_by_row[$k] .= "background-color:#FF3333;";
									}
									$row_by_row[$k] .= "';>".$detail."</td>";
								}
								
								$inner_start_time = $inner_clash_end_time;
								
								if ($inner_start_time < $clash_end_time)
								{
									for ($j = $inner_start_time; $j < $clash_end_time; $j++)
									{
										$row_by_row[$k] .= "<td>&nbsp;</td>";
									}
								}
								
								
							}
							
							if (count($current) < $row_span)
							{
								for ($j = count($current); $j < $row_span; $j++)
								{
									$row_by_row[$j] .= "<tr><td colspan='".$diff_for_clash_cell."'>&nbsp;</td>";
								}
							}
						
							$start_time = $clash_end_time;
							$first_clash_set ++;
						}
						
					}
					
				}
				
				if ($start_time <= $end_time)
				{
					//echo "SSS ".$start_time." EEE ".$end_time;
					for ($j = $start_time; $j <= $end_time; $j++)
					{
						$row_by_row[0] .= "<td rowspan='".$row_span."'>&nbsp;</td>";
					}
				}
				
				for($i = 0; $i < $row_span; $i++)
				{
				
					$table .= $row_by_row[$i]."</tr>";
				}
				
				unset($temp_buffer);
				unset($clash_record);
				unset($arranged_buffer);
				unset($row_by_row);
				
			}
			
			unset($buffer);
			echo $table; 
			
		}
		echo "</table>";
			
	}
?>