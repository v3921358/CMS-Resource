<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<?
if ($_GET["user"]=="login") {

$username=$_POST[username];
$password=$_POST[password];
$charname=$_POST[charname];
$codepass=$_POST[codepass];

$mysql_usql = mysql_query("select * from accounts where name='$username'",$conn);
$user = mysql_fetch_array($mysql_usql);
$total_count = mysql_affected_rows();
if($total_count!=1) {
	error("您登陆的帐号不存在,请从新登陆!");
}

$sqlpass = "".$password."".$user[salt]."";
$mypass = hash('sha512',$sqlpass);
if ($user[password]!=$mypass) {
	error("您的登陆密码错误,请从新登陆!");
}
if ($codepass!=$user[salt]) {
	error("安全密码不正确,请从新登陆!");
}

$mysql_nsql = mysql_query("select * from characters where name='$charname' and accountid='".$user[id]."'",$conn);
$name = mysql_fetch_array($mysql_nsql);
$total_acter = mysql_affected_rows();
if($total_acter!=1) {
	error("该帐号不存在此角色,请从新登陆!");
}

  $_SESSION["money"]=$user["mmb"];
  $_SESSION["vip"]=$name["vip"];
  $_SESSION["reborns"]=$name["reborns"];
  $_SESSION["user"]=$user["name"];//用户帐号
  $_SESSION["name"]=$name["name"];//角色名字
  $_SESSION["userid"]=$user["id"];//帐号ID
  $_SESSION["charid"]=$name["id"];//角色ID

}

if ($_GET["user"]=="close") {
  session_destroy();
  echo ("<script>alert('注销成功!');window.location='index.php?page=a_login';</script>");
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title><? echo $Site_name; ?></title>
<style type="text/css">
<!--
body {
	margin-left: 0px;
	margin-right: 0px;
	margin-top: 0px;
	margin-bottom: 0px;
}
body,td,th {
	font-size: 12px;
	color: #000000;
}
a:link {
	color: #000000;
	text-decoration: none;
}
a:visited {
	text-decoration: none;
	color: #000000;
}
a:hover {
	text-decoration: underline;
	color: #000000;
}
a:active {
	text-decoration: none;
	color: #000000;
}
-->
</style></head>

<body>
<div id="main">
  <div align="left">
    <? if ($_SESSION["userid"]=="" or $_SESSION["charid"]=="") { ?>
  </div>
  <table width="351" border="0" align="left" cellpadding="0" cellspacing="0" bordercolor="#9900FF" bgcolor="#CCCCCC">
  <form action="index.php?page=a_login&amp;user=login" method="post" name="form" id="form">
    <tr>
      <td height="24" colspan="2" bgcolor="#FFFFFF">&nbsp;&nbsp;
        <div align="center"><strong>登陆页面</strong></div></td>
    </tr>
    <tr>
      <td width="132" height="30" align="center" bgcolor="#FFFFFF">游戏帐号:</td>
      <td width="216" height="30" bgcolor="#FFFFFF"><input name="username" type="text" id="username" maxlength="12" class="box" /></td>
    </tr>
    <tr>
      <td width="132" height="30" align="center" bgcolor="#FFFFFF">游戏密码:</td>
      <td width="216" height="30" bgcolor="#FFFFFF"><input name="password" type="password" id="password" maxlength="12" class="box" /></td>
    </tr>
    <tr>
      <td width="132" height="30" align="center" bgcolor="#FFFFFF">安全密码:</td>
      <td width="216" height="30" bgcolor="#FFFFFF"><input name="codepass" type="password" id="codepass" maxlength="12" class="box" /></td>
    </tr>
    <tr>
      <td width="132" height="30" align="center" bgcolor="#FFFFFF">角色名称:</td>
      <td width="216" height="30" bgcolor="#FFFFFF"><input name="charname" type="text" id="charname" class="box" /></td>
    </tr>
    <tr>
      <td width="132" height="30" bgcolor="#FFFFFF">&nbsp;</td>
      <td width="216" height="30" bgcolor="#FFFFFF"><input type="submit" name="submit" value="提交" /></td>
    </tr>
    <tr>
      <td height="30" colspan="2" align="center" bgcolor="#FFFFFF">登陆时请先中游戏中下线，不下线不负责。</td>
    </tr>
  </form>
  </table>
  <p>
    <? }else{ ?>
  </p>
  <table border="0" align="left" cellpadding="0" cellspacing="0" bordercolor="#9900FF" bgcolor="#CCCCCC">
    <tr>
      <td height="14" colspan="2" bgcolor="#FFFFFF">&nbsp;&nbsp;
      <div align="center"><strong>登陆页面</strong></div></td>
    </tr>
    <tr>
      <td height="30" colspan="2" align="center" bgcolor="#FFFFFF"><a href="index.php?page=a_items">前往装备页面&gt;&gt;</a></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">游戏帐号:</td>
      <td width="215" height="30" bgcolor="#FFFFFF"><? echo $_SESSION["user"]; ?></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">角色名称:</td>
      <td width="215" height="30" bgcolor="#FFFFFF"><? echo $_SESSION["name"]; ?></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">冒冒网币:</td>
      <td width="215" height="30" bgcolor="#FFFFFF"><? echo $_SESSION["money"]; ?></td>
    </tr>
    <tr>
      <td width="130" height="15" align="center" bgcolor="#FFFFFF">注销退出:</td>
      <td width="215" height="15" bgcolor="#FFFFFF"><input name="button" type="button" onclick="window.location='index.php?page=a_login&amp;user=close'" value="退出登陆" /></td>
    </tr>
    <tr>
      <td height="27" colspan="2" align="center" bgcolor="#FFFFFF">请选择上面的功能进行购买。</td>
    </tr>
  </table>
  <div align="left">
    <? } ?>
  </div>
  </div>
</body>
</html>