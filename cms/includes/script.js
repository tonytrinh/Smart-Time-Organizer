
function file_name_only(str) { 
	var slash = '/' 
	if (str.match(/\\/)) { 
		slash = '\\' 
	} 
	return str.substring(str.lastIndexOf(slash) + 1, str.lastIndexOf('.')) 
} 

function isValidPasswdLength(passStr) {
	if ((passStr.length <=3) || (passStr.length >12)) 
		return false;
	else
		return true;
}

function isValidLoginLength(loginStr) {
	if ((loginStr.length <=3) || (loginStr.length >20)) 
		return false;
	else
		return true;
}

function isValidPasswdChar(passStr) {
	temp = passStr.toUpperCase();
	var ValidChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_*";
	var IsValid=true;
	var Char;
	
	for (i = 0; i < temp.length && IsValid == true; i++) 
	{ 
		Char = temp.charAt(i); 
		if (ValidChars.indexOf(Char) == -1) {
			IsValid = false;
		}
	}
	return IsValid;
}

function LTrim(str)
{
   var whitespace = new String(" \t\n\r");

   var s = new String(str);

   if (whitespace.indexOf(s.charAt(0)) != -1) {
      // We have a string with leading blank(s)...

      var j=0, i = s.length;

      // Iterate from the far left of string until we
      // don't have any more whitespace...
      while (j < i && whitespace.indexOf(s.charAt(j)) != -1)
         j++;

      // Get the substring from the first non-whitespace
      // character to the end of the string...
      s = s.substring(j, i);
   }
   return s;
}

function RTrim(str)
{
    var whitespace = new String(" \t\n\r");

   var s = new String(str);

   if (whitespace.indexOf(s.charAt(s.length-1)) != -1) {

      var i = s.length - 1;       // Get length of string

       while (i >= 0 && whitespace.indexOf(s.charAt(i)) != -1)
         i--;
      s = s.substring(0, i+1);
   }

   return s;
}

function Trim(str)
{
   return RTrim(LTrim(str));
}

function IsNumericCord(sText)
{
   var ValidChars = "0123456789., ";
   var IsNumber=true;
   var Char;
 
   for (i = 0; i < sText.length && IsNumber == true; i++) 
      { 
      Char = sText.charAt(i); 
	  if (Char != "\n") {
		  if (ValidChars.indexOf(Char) == -1) 
			 {
			 IsNumber = false;
			 }
		  }
	   }
   return IsNumber;
}

function IsNumeric(sText)
{
   var ValidChars = "0123456789.";
   var IsNumber=true;
   var Char;
 
   for (i = 0; i < sText.length && IsNumber == true; i++) 
      { 
      Char = sText.charAt(i); 
      if (ValidChars.indexOf(Char) == -1) 
         {
         IsNumber = false;
         }
      }
   return IsNumber;
}

function testIsValidObject(objToTest) {
	if (null == objToTest) {
		return false;
	}
	if ("undefined" == typeof(objToTest) ) {
		return false;
	}
	return true;
}

function isValidEmail(strEmail){
  validRegExp = /^[^@]+@[^@]+.[a-z]{2,}$/i;

   // search email text for regular exp matches
    if (strEmail.search(validRegExp) == -1) 
   {
      return false;
    } 
    return true; 
}

function MM_findObj(n, d) { //v4.01
		var p,i,x;  
		if(!d) d=document; 
		if((p=n.indexOf("?"))>0&&parent.frames.length) {
			d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);
		}
		if(!(x=d[n])&&d.all) x=d.all[n]; 
		for (i=0;!x&&i<d.forms.length;i++) 
			x=d.forms[i][n];
		for(i=0;!x&&d.layers&&i<d.layers.length;i++) 
			x=MM_findObj(n,d.layers[i].document);
		if(!x && d.getElementById) 
			x=d.getElementById(n); 

		return x;
	}

	function flevToggleCheckboxes() { // v1.1
		// Copyright 2002, Marja Ribbers-de Vroed, FlevOOware (www.flevooware.nl/dreamweaver/)
	
		var sF = arguments[0], bT = arguments[1], bC = arguments[2], oF = MM_findObj(sF);
		var insert_update = arguments[3];
		
		if ((insert_update == "insert") || (insert_update == "update")) {
			for (var i=0; i<oF.length; i++) {
				if (oF[i].type == "checkbox") {
					if (oF[i].name.indexOf(insert_update) >= 1) {
						if (bT) {
							oF[i].checked = !oF[i].checked;
						} else {
							oF[i].checked = bC;
						}
					}
				}
			} 
		} else
		{
			for (var i=0; i<oF.length; i++) {
				if (oF[i].type == "checkbox") {
					if (bT) {
						oF[i].checked = !oF[i].checked;
					} else {
						oF[i].checked = bC;
					}
				}
			} 
		}
	}

	function ToggleCounter() {
		var counter = 0;
		var sF = arguments[0], bT = arguments[1], bC = arguments[2], oF = MM_findObj(sF);

                for (var i=0; i<oF.length; i++) {
                        if (oF[i].type == "checkbox") {
                        	if (oF[i].checked)
					counter++; 
                        }
                }
				
		return counter;
	}
