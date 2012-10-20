<form name="myform" method="post" action="checklogin.php" onSubmit="return checkForm();" align="center">
	<?php if ($msgCode != "") echo "<br>Login Failed, Please try again!"; ?>

	<p>
		<label for="admin_login_name">Username<br />
		<input type="text" name="admin_login_name" id="admin_login_name" class="input" value="" size="20" tabindex="10" /></label>
	</p>
	<p>
		<label for="admin_login_password">Password<br />
		<input type="password" name="admin_login_password" id="admin_login_password" class="input" value="" size="20" tabindex="20" /></label>
	</p>
	<p class="submit">
		<input type="submit" name="Submit" id="Submit" class="button-primary" value="Log In" tabindex="100" />
	</p>
</form>