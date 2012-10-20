<?php
	$clicksearch= quote_smart($_REQUEST['clicksearch']); 
	$keyword	= quote_smart($_REQUEST['keyword']);
	
	if ($clicksearch == "1") {
		unset($_SESSION['search_keyword']);
	} else if ($keyword == "") {
		$keyword = $_SESSION['search_keyword'];
	}
	
	if ($keyword != "") {
		$searchCondition .= " WHERE s_desc LIKE '%" . $keyword . "%'";
		
		
		$_SESSION['search_keyword'] = $keyword;
	}
	else{
		$searchCondition = " WHERE 1=1 ";
	}
	
	
	
	// Sorting...
	$sort_item	= quote_smart($_GET['sort_item']);
	$sort_asc	= quote_smart($_GET['sort_asc']);
	
	if ($sort_asc == "")
		$sort_asc = "ASC";

	if ($sort_asc == "ASC")
		$sort_order = "DESC";
	else
		$sort_order = "ASC";
		
	if ($sort_item == "")
		$sort_sql = " order by gid $sort_asc";
	else
		$sort_sql = " order by $sort_item $sort_asc";
		
	$query_count	= "SELECT count(*) as num FROM subject_session $searchCondition ";     
	$query			= "SELECT * FROM subject_session $searchCondition $sort_sql ";
	
	$targetpage 	=  "main.php?m=session&p=view";
	$targetpage 	.= "&keyword=$keyword";
	$targetpage 	.= "&sort_item=$sort_item";
	$targetpage 	.= "&sort_asc=$sort_asc";
	
	$targetpage_wo_sort 	=  "main.php?m=session&p=view";
	$targetpage_wo_sort 	.= "&keyword=$keyword";
	
	$page 		= $_GET['page'];
	
	$pagination = getPagination($query_count, $query, $targetpage, $results_per_page, $page, $result);
?>

<table width="770" border="0" cellspacing="0" cellpadding="0">
<tr>
<td><img src="../images/empty.gif" width="5" height="10" /></td>
</tr>
<tr>
<td>
<table width="260" border="0" align="right" cellpadding="0"
cellspacing="0">
<tr>
<td width="190">
<form name="searchform" method="post" action="main.php?m=session&p=view">
<input name="clicksearch" value="1" type="hidden">
<input name="keyword" value="<?php echo $keyword; ?>" type="text" class="box" size="30" />
</td>
<td width="70" class="main"><input type="submit" value="search"></td></form>
</tr>
</table>
<div align="right"></div>
<div align="right"></div>
<div align="right"></div>
</td>
</tr>
<tr>
<td height="60" valign="top">
<table width="300" border="0" cellspacing="0" cellpadding="0">
<tr>
<td width="32"><img src="../images/icon_til.gif" width="32" height="40" /></td>
<td class="title">Session</td>
</tr>
</table>
</td>
</tr>
<tr>
<td>
<table  border="0" cellspacing="0" cellpadding="0">
<tr class="tabletil">
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=sid" class="sort_header">Session ID</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=gid" class="sort_header">Group ID</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=wday" class="sort_header">Day</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=start_time" class="sort_header">Start Time</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=end_time" class="sort_header">End Time</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=venue" class="sort_header">Venue</a></td>
	<td width="50" height="20" bgcolor="#CCCCCC" class="tabletil"><a href="<?php echo $targetpage_wo_sort?>&sort_asc=<?php echo $sort_order?>&sort_item=s_desc" class="sort_header">Description</a></td>
	<td width="150" height="20" bgcolor="#CCCCCC" class="sort_header">Action</td>
</tr>
<?php
	if ($result && (mysql_num_rows($result)>0)) {
		while($row=mysql_fetch_array($result)) {
			
			$sid1 		= trim($row['sid']);
			$gid1 		= trim($row['gid']);
			$wday1 		= trim($row['wday']);
			$start_time1 = trim($row['start_time']);
			$end_time1 	= trim($row['end_time']);
			$venue1 	= trim($row['venue']);
			$s_desc1 	= trim($row['s_desc']);
           
			
			?>
				<tr class="tabletex">
					<td width="50" height="30" class="tabletex"><?php echo $sid1 ?></td>
					<td width="50" class="tabletex"><?php echo $gid1 ?></td>
					<td width="50" class="tabletex"><?php echo $wday1 ?></td>
					<td width="50" class="tabletex"><?php echo $start_time1 ?></td>
					<td width="50" class="tabletex"><?php echo $end_time1 ?></td>
					<td width="50" class="tabletex"><?php echo $venue1 ?></td>
					<td width="50" class="tabletex"><?php echo $s_desc1 ?></td>
					<td width="150" class="tabletex">
					<?php
						$updHREF = "<a href='main.php?m=session&p=update&sid=$sid1'><img src='../images/icon_update.gif' border='0' title='Update record'></a>";
						$delHREF = "<a href='javascript:gotoDelete(\"$sid1\")'><img src='../images/icon_delete.gif' border='0' title='Delete record'></a>";

						echo $updHREF . "&nbsp;&nbsp;" . $delHREF;
					?>
					</td>
				</tr>
				<tr>
					<td colspan="6"><img src="../images/grey_dot.gif" width="770" height="1" /></td>
				</tr>
	<?php }
	}
?>
</table>
</td>
</tr>
<tr height="30" bgcolor="#FFFFFF" class="tabletil">
	<td align="right">
		<?php echo $pagination?>
	</td>
</tr>
</table>
</body>
</html>



<script language="javascript">
	function gotoDelete(deleteID) {
		
		if (confirm("Are you sure you want to delete this session?")) 
		{
			location.href="submitsession.php?del=1&sid=" + deleteID;
		}
	}

</script>
