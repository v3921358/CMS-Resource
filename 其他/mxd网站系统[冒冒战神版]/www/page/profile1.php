<?php
ob_start();
include ("mean/config.php");
$Wormdb = @mysql_connect($db_host, $db_user, $db_pass) or die ('请检查所填数据是否正确~！位置：mean/config.php');
mysql_select_db ($db_name);
session_start();
?>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>修改密码</title>
<style type="text/css">
<!--
body {
	background-repeat: no-repeat;
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
-->
</style></head>

<body>
<div id="main">
  <table border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
   <form action="index4.php" method="post" name="form" id="form">
    <tr>
      <td height="38" colspan="3" bgcolor="#FFFFCC">&nbsp;&nbsp;<strong>修改密码</strong></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">游戏帐号:</td>
      <td width="182" height="30" colspan="2" bgcolor="#FFFFFF"><input name="user" type="text" class="box" id="user" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">旧的密码:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="oldpass" type="password" class="box" id="oldpass" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">新的密码:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="newpass" type="password" class="box" id="newpass" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">确认密码:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="pass" type="password" class="box" id="pass" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">电子邮箱:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="email" type="text" class="box" id="email" maxlength="28" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">生日日期:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="bay" type="text" class="box" id="bay" value="0000-00-00" maxlength="10" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">&nbsp;</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="提交" /></td>
    </tr>
    <tr>
      <td height="30" colspan="3" bgcolor="#FFFFFF">&nbsp;</td>
    </tr>
   </form>
  </table>
  </div>
</body>
</html>