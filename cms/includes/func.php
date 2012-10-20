<?php
	function jsRedirect($url) {
		echo "<script language='javascript'>";
		echo "location.href='" . $url . "';";
		echo "</script>";
	}
	
	function debug($str)
	{
		echo "<BR>DEBUG:" . $str;	
	}
	
	function debugstop($str)
	{
		echo "<BR>DEBUG:" . $str;
		exit;
	}
	
	function unhtmlentities( $string ){
		$trans_tbl = get_html_translation_table ( HTML_ENTITIES );
		$trans_tbl = array_flip( $trans_tbl );
		$ret = strtr( $string, $trans_tbl );
		return preg_replace( '/&#(\d+);/me' , "chr('\\1')" , $ret );
	} 
	
	function getPagination($query_count, $query, $targetpage, $limit, $page, &$result) {
	// Pagination...
	$adjacents = 3;
	$total_pages 	= mysql_fetch_array(mysql_query($query_count));
	$total_pages 	= $total_pages[num];
	
	if($page) 
		$start = ($page - 1) * $limit;
	else
		$start = 0;			
	
	$sql = $query . " LIMIT $start, $limit"; 
	$result = mysql_query($sql);
	
	if ($page == 0) $page = 1;					//if no page var is given, default to 1.
	$prev = $page - 1;							//previous page is page - 1
	$next = $page + 1;							//next page is page + 1
	$lastpage = ceil($total_pages/$limit);		//lastpage is = total pages / items per page, rounded up.
	$lpm1 = $lastpage - 1;						//last page minus 1
	
	$pagination = "";
	if($lastpage > 1)
	{	
		$pagination .= "<div class=\"pagination\">";
		//previous button
		if ($page > 1) 
			$pagination.= "<a href=\"$targetpage&page=$prev\">&laquo; previous</a>";
		else
			$pagination.= "<span class=\"disabled\">&laquo; previous</span>";	
		
		//pages	
		if ($lastpage < 7 + ($adjacents * 2))	//not enough pages to bother breaking it up
		{	
			for ($counter = 1; $counter <= $lastpage; $counter++)
			{
				if ($counter == $page)
					$pagination.= "<span class=\"current\">$counter</span>";
				else
					$pagination.= "<a href=\"$targetpage&page=$counter\">$counter</a>";					
			}
		}
		elseif($lastpage > 5 + ($adjacents * 2))	//enough pages to hide some
		{
			//close to beginning; only hide later pages
			if($page < 1 + ($adjacents * 2))		
			{
				for ($counter = 1; $counter < 4 + ($adjacents * 2); $counter++)
				{
					if ($counter == $page)
						$pagination.= "<span class=\"current\">$counter</span>";
					else
						$pagination.= "<a href=\"$targetpage&page=$counter\">$counter</a>";					
				}
				$pagination.= "...";
				$pagination.= "<a href=\"$targetpage&page=$lpm1\">$lpm1</a>";
				$pagination.= "<a href=\"$targetpage&page=$lastpage\">$lastpage</a>";		
			}
			//in middle; hide some front and some back
			elseif($lastpage - ($adjacents * 2) > $page && $page > ($adjacents * 2))
			{
				$pagination.= "<a href=\"$targetpage&page=1\">1</a>";
				$pagination.= "<a href=\"$targetpage&page=2\">2</a>";
				$pagination.= "...";
				for ($counter = $page - $adjacents; $counter <= $page + $adjacents; $counter++)
				{
					if ($counter == $page)
						$pagination.= "<span class=\"current\">$counter</span>";
					else
						$pagination.= "<a href=\"$targetpage&page=$counter\">$counter</a>";					
				}
				$pagination.= "...";
				$pagination.= "<a href=\"$targetpage&page=$lpm1\">$lpm1</a>";
				$pagination.= "<a href=\"$targetpage&page=$lastpage\">$lastpage</a>";		
			}
			//close to end; only hide early pages
			else
			{
				$pagination.= "<a href=\"$targetpage&page=1\">1</a>";
				$pagination.= "<a href=\"$targetpage&page=2\">2</a>";
				$pagination.= "...";
				for ($counter = $lastpage - (2 + ($adjacents * 2)); $counter <= $lastpage; $counter++)
				{
					if ($counter == $page)
						$pagination.= "<span class=\"current\">$counter</span>";
					else
						$pagination.= "<a href=\"$targetpage&page=$counter\">$counter</a>";					
				}
			}
		}
		
		//next button
		if ($page < $counter - 1) 
			$pagination.= "<a href=\"$targetpage&page=$next\">next &raquo;</a>";
		else
			$pagination.= "<span class=\"disabled\">next &raquo;</span>";
		$pagination.= "</div>\n";		
	}
	
		return $pagination;
	}
	
	function quote_smart($value)
	{
	   // Stripslashes
	   if (get_magic_quotes_gpc()) {
	       $value = stripslashes($value);
	   }
	   // Quote if not a number or a numeric string
	   if (!is_numeric($value)) {
	       $value = mysql_real_escape_string($value);
	   }
	   return trim($value);
	}
	
	
	function usergroupControl($strVariable, $strValue, $showFirstCaption, $firstOptionValue, $otherArgs, $disabled=0) {
		if ($disabled == 0)
			echo "<select name='$strVariable' $otherArgs >";
		else
			echo "<select name='$strVariable' disabled='disabled' $otherArgs >";
		
		if ($showFirstCaption != "")
			echo "<option SELECTED value='$firstOptionValue'>$showFirstCaption</option>";
		
		if ($strValue == 1)
			$strSelOpt1 = " SELECTED ";
		else if ($strValue == 2)
			$strSelOpt2 = " SELECTED ";
			
		echo "<option $strSelOpt1 value='1'>Manager</option>";
		echo "<option $strSelOpt2 value='2'>Operator</option>";
		
		echo "</select>";
	}
	
	function booleanControl($strVariable, $strValue, $showFirstCaption, $firstOptionValue, $otherArgs, $disabled=0) {

                if ($disabled == 0)
                        echo "<select name='$strVariable' $otherArgs >";
                else
                        echo "<select name='$strVariable' disabled='disabled' $otherArgs >";

                if ($showFirstCaption != "")
                        echo "<option SELECTED value='$firstOptionValue'>$showFirstCaption</option>";

                if ($strValue == 1)
                        $strSelOpt1 = " SELECTED ";
                else if ($strValue == 2)
                        $strSelOpt2 = " SELECTED ";

                echo "<option $strSelOpt1 value='1'>Yes</option>";
                echo "<option $strSelOpt2 value='2'>No</option>";

                echo "</select>";
        }

	function statusControl($strVariable, $strValue, $showFirstCaption, $firstOptionValue, $otherArgs, $disabled=0) {
			
		if ($disabled == 0)
			echo "<select name='$strVariable' $otherArgs >";
		else
			echo "<select name='$strVariable' disabled='disabled' $otherArgs >";
		
		if ($showFirstCaption != "")
			echo "<option SELECTED value='$firstOptionValue'>$showFirstCaption</option>";
		
		if ($strValue == 1)
			$strSelOpt1 = " SELECTED ";
		else if ($strValue == 2)
			$strSelOpt2 = " SELECTED ";
			
		echo "<option $strSelOpt1 value='1'>Active</option>";
		echo "<option $strSelOpt2 value='2'>Inactive</option>";
		
		echo "</select>";
	}
	
	function statusCaption ($strValue) {
		if ($strValue == 1)
			return "Active";
		else if ($strValue == 2)
			return "Inactive";
		else
			return "Unknown";
	}
	
	function getStatus_Caption ($status_id) {
		if ($status_id == 1) 
			return "Active";
		else if ($status_id == 2) 
			return "Inactive";
		else
			return "-";
	}
	
	function getStationStatus_Caption ($status_id) {
		if ($status_id == 1) 
			return "OPEN";
		else if ($status_id == 2) 
			return "CLOSED";
		else
			return "-";
	}
	
	function check_datestring($strDateTime) {
		list($strDate, $strTime) = split(" ", $strDateTime);
		
		if ($strDate == "0000-00-00")
			return 0;
		
		// yy/mm/dd
		if (preg_match('/^([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})$/',$strDate))
			return 1;
		
		// dd/mm/yy
		else if (preg_match('/^([0-9]{1,2})\/([0-9]{1,2})\/([0-9]{4})$/',$strDate))
			return 1;
		else
			return 0;
	}
	
	function getSQLDateFormat($dateOriFmt,$dateStr) {
		if (trim($dateStr) == "")
			return "null";
		else if ($dateOriFmt == "DD/MM/YYYY") {
			list($d, $m, $y) = split("\/", $dateStr);
			return "\"" . $y . "/" . $m . "/" . $d . "\"" ;
		} else 
			return "null";
	}

	function displayDateFormat($dateStr) {
		if (check_datestring($dateStr) == 1)
			return date("d/m/Y", strtotime($dateStr));
		else
			return "";
	}
	
	function displayDateTimeFormat($dateStr) {
		if (check_datestring($dateStr) == 1)
			return date("d/m/Y G:i a", strtotime($dateStr));
		else
			return "";
	}
	
	function db_isRecordExist($tableName, $fieldName, $value, $option="") {
		$total = 0;
		
		$sqlStatement = "SELECT count(*) as totalrow FROM $tableName WHERE $fieldName = '$value'". " " . $option;
		$result   	= mysql_query($sqlStatement);
		if ($result) {
			$row_count	= mysql_fetch_array($result);
			$total      = $row_count['totalrow'];
		}
		return $total;
	}
	
	function db_executeSQL($sqlStatement) {
		$result=mysql_query($sqlStatement);
		if ($result) {
			return mysql_affected_rows();
		} else {
			debug(mysql_error());
			debug(mysql_errno());
			debugstop($sqlStatement);
			return -1;
		}
	}
	
	function db_NumberOfRows($tableName) {
		$sql="SELECT * FROM $tableName";
		$result=mysql_query($sql);
		if ($result)
			return mysql_num_rows($result);
		else
			return -1;
	}
	
	
	function getCodeMsg($lang, $codeNumber) {
		$var = "MSGCODE_" . $codeNumber;
		if ($lang->$var == "")
			return "cannot find codeNumber=$codeNumber";
		else
			return $lang->$var;
	}
	
	function write_log($str) {
		error_log($str . "\n", 3, "log/".date('Ymd').".log");
	}
	
	function db_CheckAdminLogin($login_name, $login_password, &$retValArray) {
		$sql="SELECT * FROM users WHERE loginname = '$login_name' and password = md5('$login_password')";
		$result = mysql_query($sql) or die(mysql_error()); 
		//$result = mysqli_query($con_sqli, $sql);
		//echo $sql;
		//exit();
		//echo mysql_num_rows($result);
		if ($result) 
		{
			if (mysql_num_rows($result) == 1) 
			{
				$retValArray = mysql_fetch_array($result);
				$local_status = $retValArray["status"];
				$local_id  = $retValArray["id"];			
				if ($local_status == '1') 
				{
					// login success, update last_logindate
					$sql="UPDATE users SET loginattempt=0, lastlogin = now() WHERE id = '$local_id'";
					$result=mysql_query($sql);
					return 1; 			// valid login
				}
			}									
		} 
		else
		{
			
			//echo $sql;
			//printf($result);
			//echo "fail";
			//exit();
			$loginattempt_log = "xxxx";
			$sql="UPDATE users SET loginattempt=IFNULL(loginattempt, 0)+1, loginattempt_log='$loginattempt_log', lastlogin_log = now() WHERE loginname = '$login_name'";
			$result=mysql_query($sql);
		}
		return 0;
	}
	
	function pr($object){
		echo '<pre>';
		print_r($object);
		echo '</pre>';
	}

	function get_tables_name(){
		$result = mysql_query("show tables");
		$tables = Array();
		
		if($result && mysql_num_rows($result)){
			while($row = mysql_fetch_row($result))
				$tables[] = $row[0];
		}
		return $tables;
	}
	
	function get_all_records($table, $fields = null, $status = ''){
		$result = mysql_query('SELECT '. ($fields ? implode(',', $fields) : '*') . ' FROM ' . $table . (($status) ? 'WHERE status_id =' . $status : ''));
		$results = Array();
		if($result && mysql_num_rows($result)){
			while($row = mysql_fetch_assoc($result))
				$results[] = $row;
		}
		return $results;
	}
	
	function generate_db_xml($specific_field = Array(), $filepath = 'service.xml'){
		//	Initialize a DOM document object with version 1.0 and UTF-8 encoding
		$dom = new DomDocument('1.0', 'UTF-8');
		
		// create root node
		$root = $dom->createElement('database');
		$root = $dom->appendChild($root);
		
		// get all system data tables
		$tables = Array();
		if(count($specific_field) > 0){
			foreach($specific_field as $key=>$value){
				$tables[] = $key;
			}
		}
		else
			$tables = get_tables_name();
		
		// loop through all tables
		// create a node for each table with the table name as id for the node
		foreach($tables as $table){
			$table_tag = $dom->createElement('table');
			$table_tag = $root->appendChild($table_tag);
			
			$id = $dom->createAttribute('id');
			$table_tag->appendChild($id);
			
			$table_name_text = $dom->createTextNode($table);
			$id->appendChild($table_name_text);
			
			// Get all records of current looping table
			// If specific fields is pass in as parameters, then check if the specific fields is assign for the particular table,.
			// If true then pass in the fields array, else pass in null
			$records = get_all_records($table,(($specific_field[$table]) ? ($specific_field[$table]) : null));
			
			// Loop through each row of data, create node for each row
			foreach($records as $record){
				$row = $dom->createElement('row');
				$table_tag->appendChild($row);
				
				// Loop through each data
				// Create node for each data with the field name as the node name
				foreach($record as $key=>$value){
					$field = $dom->createElement($key);
					$row->appendChild($field);
					
					$data = $dom->createTextNode($value);
					$field->appendChild($data);
				}
			}
		}
		
		// Save the  XML file 
		$dom->save($filepath);
	}
	
	function special_char_encode($text){
		$special_chars = Array('!', '"', '$', '%', '\'', '(', ')', '*', '+', ',', '-', '.' , '/', "'", '<', '=', '>', '?', '@');
		$special_chars_replace = Array('&#33', '&#34;', '&#36;', '&#37;',  '&#39;', '&#40;', '&#41;', '&#42;', '&#43;', '&#44;', '&#45;', '&#46;', '&#47;', '&#96;','&#60;', '&#61;', '&#62;');
		return str_replace($special_chars, $special_chars_replace, $text);
	}
	
	
	function cur_page_url() {
	 $pageURL = 'http';
	 if ($_SERVER["HTTPS"] == "on" || $_SERVER["HTTPS"] == 1 || $_SERVER["HTTPS"] ==443) {$pageURL .= "s";}
	 $pageURL .= "://";
	 if ($_SERVER["SERVER_PORT"] != "80") {
		$pageURL .= $_SERVER["SERVER_NAME"].":".$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"];
	 } else {
		$pageURL .= $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"];
	 }
	 return $pageURL;
	}
	
	function mysql_begin_transaction(){
		@mysql_query("BEGIN");
	}
	
	function mysql_commit_transaction(){
		@mysql_query('COMMIT');
	}
	
	function mysql_rollback_transaction(){
		@mysql_query('ROLLBACK');
	}
	
	function row_count($table = null, $criteria = null){
		$sql = 'SELECT * FROM ' . $table ;
		$sql .= $criteria ? ' WHERE ' . $criteria : '';
		$result = mysql_query($sql);
		
		return mysql_num_rows($result);
	}
	
	function widget_service_date_expiry_checker(){
		$sql = 'SELECT * FROM ';
	}
	
	
	function isValidATTACHFileType($filename) {
		$filename = strtolower($filename) ;
                $exts = split("[/\\.]", $filename) ;
                $n = count($exts)-1;
                $exts = $exts[$n];
                
                $ext = strtoupper($exts);
                if (
						($ext == "GIF") 	|| 
						($ext == "JPG") 	|| 
						($ext == "JPEG") 	|| 
						($ext == "PNG") 	|| 
						($ext == "PDF") 	|| 
						($ext == "DOCX") 	|| 
						($ext == "DOC") 	|| 
						($ext == "XLS") 	|| 
						($ext == "XLSX") 	|| 
						($ext == "PPT") 	|| 
						($ext == "PPTX") 	||
						($ext == "TXT") 	|| 
						($ext == "ZIP") 	|| 
						($ext == "KML") 	||
						($ext == "TAR")
					)
                	return true;
                else
					return false;
	}
	
	function isValidKMLFileType($filename) {
		$filename = strtolower($filename) ;
                $exts = split("[/\\.]", $filename) ;
                $n = count($exts)-1;
                $exts = $exts[$n];
                
                $ext = strtoupper($exts);
                if ($ext == "KML")
                	return true;
                else
			return false;
	}
	
	function isValidCSVFileType($filename) {
		$filename = strtolower($filename) ;
                $exts = split("[/\\.]", $filename) ;
                $n = count($exts)-1;
                $exts = $exts[$n];
                
                $ext = strtoupper($exts);
                if ($ext == "CSV")
                	return true;
                else
			return false;
	}
	
	function filename_safe($filename) {
		$temp = $filename;
		$temp = str_replace(" ", "_", $temp);
		$result = "";
		for ($i=0; $i<strlen($temp); $i++) {
			if (preg_match('([0-9]|[a-z]|[A-Z]|.|_)', $temp[$i])) {
				$result = $result . $temp[$i];
			}
		}

		return trim($result);
	}
	
	function limit_string ( $str, $n ) {
		if ( strlen ( $str ) <= $n )
		{
			return $str;
		}
		else {
			return substr ( $str, 0, $n ) . '...';
		}
	}
	
	class thumbnail
	{
		var $sourceFile; // We use this file to create the thumbnail
		var $originalFilename; // We use this to get the extension of the filename
		var $destinationDirectory; // The Directory in question
		var $destinationDirectoryFilename; // The destination filename
	
		var $createImageFunction = '';
		var $outputImageFunction = '';
	
		function generate($sourceFile = "", $originalFilename = "", $destinationDirectory = "", $destinationDirectoryFilename = "", $width = -1, $height = -1)
		{
			if (!empty($sourceFile))
			$this->sourceFile = $sourceFile;
	
			if (!empty($originalFilename))
			$this->originalFilename = $originalFilename;
	
			if (!empty($destinationDirectory))
			$this->destinationDirectory = $destinationDirectory;
	
			if (!empty($destinationDirectoryFilename))
			$this->destinationDirectoryFilename = $destinationDirectoryFilename;
	
			if (!empty($width))
			$this->width = $width;
	
			if (!empty($height))
			$this->height = $height;
	
			list(, $this->extension) = explode('.', $this->originalFilename);
	
			switch ($this->extension)
			{
			case 'gif' :
			$createImageFunction = 'imagecreatefromgif';
			$outputImageFunction = 'imagegif';
			break;
	
			case 'png' :
			$createImageFunction = 'imagecreatefrompng';
			$outputImageFunction = 'imagepng';
			break;
	
			case 'bmp' :
			$createImageFunction = 'imagecreatefromwbmp';
			$outputImageFunction = 'imagewbmp';
			break;
	
			case 'JPG': case 'JPEG':
			$createImageFunction = 'imagecreatefromjpeg';
			$outputImageFunction = 'imagejpeg';
			break;
	
			case 'PNG':
			$createImageFunction = 'imagecreatefromjpeg';
			$outputImageFunction = 'imagejpeg';
			break;
	
			case 'GIF':
			$createImageFunction = 'imagecreatefromjpeg';
			$outputImageFunction = 'imagejpeg';
			break;
	
			case 'BMP':
			$createImageFunction = 'imagecreatefromjpeg';
			$outputImageFunction = 'imagejpeg';
			break;
	
			case 'jpg': case 'jpeg':
			$createImageFunction = 'imagecreatefromjpeg';
			$outputImageFunction = 'imagejpeg';
			break;
	
			default :
			exit("Sorry: The format is not supported");
			break;
			}
	
			$this->img = $createImageFunction($this->sourceFile);
	
			list($this->org_width, $this->org_height) = getimagesize($this->sourceFile);
	
			if ($this->height == -1)
			{
			$this->height = round($this->org_height * $this->width / $this->org_width);
			}
	
			if ($this->width == -1)
			{
			$this->width = round($this->org_width * $this->height / $this->org_height);
			}
	
			$this->xoffset = 0;
			$this->yoffset = 0;
	
			$this->img_new = imagecreatetruecolor($this->width, $this->height);
	
			if ($this->img_new)
			{
			imagecopyresampled($this->img_new, $this->img, 0, 0, $this->xoffset, $this->yoffset, $this->width, $this->height, $this->org_width, $this->org_height);
	
			list($this->newFilename) = explode('.', $this->destinationDirectoryFilename);
	
			$this->fullDestination = ($this->destinationDirectory.'/'.$this->newFilename.'.'.$this->extension);
	
			$outputImageFunction($this->img_new, $this->fullDestination);
			}
			else
			{
			$this->failed = true;
			}
	
			if ($this->failed == false)
			{
				return $this->fullDestination;
			}
		}
	}

		//function repository 
	function isValidEmail($email){
		return eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$", $email);
	}
	
	function genRandomString() 
	{
		$length = 10;
		$characters = "0123456789abcdefghijklmnopqrstuvwxyz";
		$string = "";    
	
		for ($p = 0; $p < $length; $p++) 
		{
			$string .= $characters[mt_rand(0, strlen($characters))];
		}
		return $string;
	}
	

?>