<?php
ob_start();
include ("mean/config.php");
$Wormdb = @mysql_connect($db_host, $db_user, $db_pass) or die ('�������������Ƿ���ȷ~��λ�ã�mean/config.php');
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
<title>ðð��-�ʺ�ע��</title>
<div align="center"><b>ðð��-�ʺ�ע��</b><br />
  <?php
    //error handling
    if (isset($_GET['error'])){
    	   if (($_GET['error']) == "xey"){
        echo ("<font color=red>Error:You do not agree with the registration agreement, to terminate the registration!</br>������ͬ��ע��</font><br />");}
        if (($_GET['error']) == "nu"){
        echo ("<font color=red>Error:You did not enter a username.</br>������û������ע���û���.</font><br />");}
        if (($_GET['error']) == "np"){
        echo ("<font color=red>Error:You did not enter a password.</br>������û�������û�����.</font><br />");}
        if (($_GET['error']) == "pdm"){
        echo ("<font color=red>Error:Passwords don't match.</br>����ȷ�����벻ƥ��.</font><br />");}
        if (($_GET['error']) == "emer"){
        echo ("<font color=red>Error:E-Mail Incorrect.</br>����E-Mail ����ȷ.</font><br />");}
        if (($_GET['error']) == "qqer"){
        echo ("<font color=red>Error:QQ Incorrect.</br>����QQ���� ����ȷ.</font><br />");}
        if (($_GET['error']) == "nanu"){
        echo ("<font color=red>Error:You used non alphanumeric/numeric characters in your username.</br>�����벻Ҫ�������û�����ʹ���������.</font><br />");}
        if (($_GET['error']) == "nanp"){
        echo ("<font color=red>Error:You used non alphanumeric/numeric characters in your password.</br>�����벻Ҫ�������û�������ʹ���������.</font><br />");}
        if (($_GET['error']) == "nanc"){
        echo ("<font color=red>Error:You used non numeric characters in your pin.</font><br />");}
        if (($_GET['error']) == "lu"){
        echo ("<font color=red>Error:Your username is too long. 12 characters max!</br>���������û�����̫���ˡ� ���12λ��</font><br />");}
        if (($_GET['error']) == "lp"){
        echo ("<font color=red>Error:Your password is too long. 12 characters max!</br>���������û�������̫���ˡ� ���12λ��</font><br />");}
        if (($_GET['error']) == "su"){
        echo ("<font color=red>Error:Your username is too long. 12 characters max!</br>���������û�����̫���ˡ� С��6λ!</font><br />");}
        if (($_GET['error']) == "sp"){
        echo ("<font color=red>Error:Your password is too long. 12 characters max!</br>���������û�������̫���ˡ� С��6��λ��</font><br />");}
        if (($_GET['error']) == "lc"){
        echo ("<font color=red>Error:Your PIN is too long. 4 numeric digits!</font><br />");}
        if (($_GET['error']) == "ue"){
        echo ("<font color=red>Sorry:The username you chose exists. Choose another one.</br>�Բ�����������û����ѱ�������ע�ᡣ����������û�����</font><br />");}
    }
    if (!isset($_POST['reg'])){
?>
    <script type="text/javascript" src="Day.js"></script>
</div>
<form action="<?php echo $_SERVER['PHP_SELF']; ?>?page=register" method="post">
  <p align="center">�û�����:
    <input type="text" name="username" maxlength="12" value="" />
    <br />
    [����6λ����]<br />
��������:
  <input type="text" id="getday" name="birthday" onClick="javascript:ShowCalendar('getday')" maxlength="10" >
  <br />
    [��ʽ:xxxx-xx-xx]<br />
    ��������:
    <input type="password" name="password" maxlength="12" value="">
    <br />
    [����6λ����]<br />
�ٴ�����:
    <input type="password" name="cpassword" maxlength="12" value="">
    <br />
    [����6λ����]<br />
��������:
    <input type="text" name="mail"  value="">
    <br />
    [��д�������]<br />
����Q Q:
    <input type="text" name="QQ"  >
    <br />
    [����ȷ��д]<br />
    <br />
�û�Э��:
    <select name="gender">
      <option value="0">�� ѡ ��</option>
      <option value="1" selected="selected">�ܾ�ע��</option>
      <option value="2">ͬ��ע��</option>
    </select>
    <br />
    <br />
    <input type="submit" value="ע��" name="reg">
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
    ��ӭ����ע��, <?php echo $_POST['username']; ?>!<br />
    ��ϲ:�����˺��Ѿ��������!<br />
    <br />
  ���ס���� ע��ʱ�������Ա�ɾ����ɫ֮��!<br />
    <br />
    <br />
    [�ʺż����������ҳ�·����ر���ר�õ�½�� ������Ϸ,��ʼ���ð������!]<br />
    <br />
    <br />
    [������ ��½�� ������Ϸ,��ʼ���ð������!]
    <?php
    }
    }
?>
  </p>
</div>
