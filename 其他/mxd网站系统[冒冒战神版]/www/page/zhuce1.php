<?php
ob_start();
include ("mean/config.php");
$Wormdb = @mysql_connect($db_host, $db_user, $db_pass) or die ('请检查所填数据是否正确~！位置：mean/config.php');
mysql_select_db ($db_name);
session_start();
?><style type="text/css">
<!--
body,td,th {
	font-size: 12px;
	color: #000000;
	border: thin dotted #666666;
}
.STYLE1 {color: #FF0000}
body {
	background-image: url(images/bg002.jpg);
	background-repeat: no-repeat;
}
-->
</style>
<title>冒冒岛-帐号注册</title>
<div align="center"><b>冒冒岛-帐号注册</b><br />
  <?php
    //error handling
    if (isset($_GET['error'])){
    	   if (($_GET['error']) == "xey"){
        echo ("<font color=red>Error:You do not agree with the registration agreement, to terminate the registration!</br>出错：不同意注册</font><br />");}
        if (($_GET['error']) == "nu"){
        echo ("<font color=red>Error:You did not enter a username.</br>出错：您没有输入注册用户名.</font><br />");}
        if (($_GET['error']) == "np"){
        echo ("<font color=red>Error:You did not enter a password.</br>出错：您没有输入用户密码.</font><br />");}
        if (($_GET['error']) == "pdm"){
        echo ("<font color=red>Error:Passwords don't match.</br>出错：确认密码不匹配.</font><br />");}
        if (($_GET['error']) == "emer"){
        echo ("<font color=red>Error:E-Mail Incorrect.</br>出错：E-Mail 不正确.</font><br />");}
        if (($_GET['error']) == "qqer"){
        echo ("<font color=red>Error:QQ Incorrect.</br>出错：QQ号码 不正确.</font><br />");}
        if (($_GET['error']) == "nanu"){
        echo ("<font color=red>Error:You used non alphanumeric/numeric characters in your username.</br>出错：请不要在您的用户名里使用特殊符号.</font><br />");}
        if (($_GET['error']) == "nanp"){
        echo ("<font color=red>Error:You used non alphanumeric/numeric characters in your password.</br>出错：请不要在您的用户密码里使用特殊符号.</font><br />");}
        if (($_GET['error']) == "nanc"){
        echo ("<font color=red>Error:You used non numeric characters in your pin.</font><br />");}
        if (($_GET['error']) == "lu"){
        echo ("<font color=red>Error:Your username is too long. 12 characters max!</br>出错：您的用户名是太长了。 最大12位！</font><br />");}
        if (($_GET['error']) == "lp"){
        echo ("<font color=red>Error:Your password is too long. 12 characters max!</br>出错：您的用户密码是太长了。 最大12位！</font><br />");}
        if (($_GET['error']) == "su"){
        echo ("<font color=red>Error:Your username is too long. 12 characters max!</br>出错：您的用户名是太短了。 小于6位!</font><br />");}
        if (($_GET['error']) == "sp"){
        echo ("<font color=red>Error:Your password is too long. 12 characters max!</br>出错：您的用户密码是太短了。 小于6个位！</font><br />");}
        if (($_GET['error']) == "lc"){
        echo ("<font color=red>Error:Your PIN is too long. 4 numeric digits!</font><br />");}
        if (($_GET['error']) == "ue"){
        echo ("<font color=red>Sorry:The username you chose exists. Choose another one.</br>对不起：您输入的用户名已被其他人注册。请更换其它用户名。</font><br />");}
    }
    if (!isset($_POST['reg'])){
?>
    <script type="text/javascript" src="Day.js"></script>
</div>
<form action="<?php echo $_SERVER['PHP_SELF']; ?>?page=register" method="post">
  <p align="center">用户名称:
    <input type="text" name="username" maxlength="12" value="" />
    <br />
    [输入6位以上]<br />
出生日期:
  <input type="text" id="getday" name="birthday" onClick="javascript:ShowCalendar('getday')" maxlength="10" >
  <br />
    [格式:xxxx-xx-xx]<br />
    输入密码:
    <input type="password" name="password" maxlength="12" value="">
    <br />
    [输入6位以上]<br />
再次输入:
    <input type="password" name="cpassword" maxlength="12" value="">
    <br />
    [输入6位以上]<br />
电子邮箱:
    <input type="text" name="mail"  value="">
    <br />
    [填写你的邮箱]<br />
您的Q Q:
    <input type="text" name="QQ"  >
    <br />
    [请正确填写]<br />
    <br />
用户协议:
    <select name="gender">
      <option value="0">请 选 择</option>
      <option value="1" selected="selected">拒绝注册</option>
      <option value="2">同意注册</option>
    </select>
    <br />
    <br />
    <input type="submit" value="注册" name="reg">
  </p>
</form>
<div align="center">
  <p>
    <?php
    }else{
    //check XieYi
    if (($_POST['gender'] != "2")){header("Location:zhuce&error=xey"); die();}	
    	
  	//check to see if the variables were set
  	if (($_POST['username'] == "")){header("Location:zhuce&error=nu"); die();}
  	if (($_POST['password'] == "")){header("Location:zhuce&error=np"); die();}
	
    //check for alpha numeric characters
    $username = ereg_replace("[^A-Za-z0-9]", "", $_POST['username']);
    if ($username != $_POST['username']){header("Location: zhuce&error=nanu"); die();}

    $password = ereg_replace("[^A-Za-z0-9]", "", $_POST['password']);
    if ($password != $_POST['password']){header("Location: zhuce&error=nanp"); die();}
    
    if (($_POST['password']) != ($_POST['cpassword'])){header("Location: zhuce&error=pdm"); die();}

    
    //check lengths
    if (strlen($_POST['username']) > 12 or strlen($_POST['username']) < 6){header("Location: zhuce&error=su"); die();}

    if (strlen($_POST['password']) > 12 or strlen($_POST['password']) < 6){header("Location: zhuce&error=sp"); die();}


    //check Email
    if (!eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$", $_POST['mail'])){header("Location: zhuce&error=emer"); die();}  

    //check QQ
    if ((ereg_replace("[^0-9]", "", $_POST['QQ']))!=$_POST['QQ']){header("Location: zhuce&error=qqer"); die();}
    
    if (strlen($_POST['QQ']) > 11 or strlen($_POST['QQ']) < 5){header("Location: zhuce&error=qqer"); die();}

    //check for duplicate username
    $user_query = mysql_query("SELECT COUNT(*) FROM `accounts` WHERE `name` = '". $_POST['username'] ."'") or die (mysql_error());
    $check_user = mysql_fetch_array($user_query);
    if ($check_user['0'] != "0"){header("Location: zhuce&error=ue"); die();}
    else{
    //prepare sql
    $add_user = ("INSERT INTO `accounts`
        (`ID`, `name`,`md5pass`, `password`,`banned`,`macs`,`birthday`,`email`,`QQ`)
        VALUES (NULL ,'". $_POST['username'] ."', '". sha1($_POST['password']) ."', '". sha1($_POST['password']) ."',0,'00-00-00-00-00-00','". $_POST['birthday'] ."','". $_POST['mail'] ."','". $_POST['QQ'] ."')");
    mysql_query ($add_user) or die (mysql_error());

	//escape php mode and output some kind of welcome message to the user
	?>
    <br />
    <br />
    欢迎您的注册, <?php echo $_POST['username']; ?>!<br />
    恭喜:您的账号已经创建完毕!<br />
    <br />
  请记住您的 注册时的生日以便删除角色之用!<br />
    <br />
    <br />
    [帐号激活后请在主页下方下载本服专用登陆器 进入游戏,开始你的冒险世界!]<br />
    <br />
    <br />
    [请下载 登陆器 进入游戏,开始你的冒险世界!]
    <?php
    }
    }
?>
  </p>
</div>
