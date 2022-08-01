<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<?
if ($_GET["act"]=="maps") {

$username=$_POST[username];
$password=$_POST[password];
$charname=$_POST[charname];
$maps=$_POST[maps];

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
if ($user[loggedin]<>0){
 error("您的帐号正在使用中,请下线后传送!");
}
$mysql_nsql = mysql_query("select * from characters where name='$charname' and accountid='".$user[id]."'",$conn);
$name = mysql_fetch_array($mysql_nsql);
$total_acter = mysql_affected_rows();
if($total_acter!=1) {
  error("该帐号不存在此角色,请从新登陆!");
}

if ($maps<>"910000000") {
  error("该地图不存在");
}

$sql=mysql_query("update `characters` set `map`='$maps' where name='$charname'");

 if ($sql) {
  error("传送成功！");
 }else{
  error("传送失败！");
 }

}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title><? echo $Site_name; ?>-地图传送</title>
<style type="text/css">
<!--
.boxs {
	color: #999999;
	font-size: 12px;
	height: 13px;
	width: auto;
}
.STYLE1 {color: #999999}
body,td,th {
	font-size: 12px;
	color: #000000;
}
body {
	margin-left: 00px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
-->
</style>
</head>

<body>
<div id="main">
  <table border="0" align="center" cellpadding="0" cellspacing="0">
   <form action="index.php?page=maps&act=maps" method="post" name="form" id="form">
    <tr>
      <td height="32" colspan="3" bgcolor="#FFFFFF"><div align="center"><strong>地图传送</strong></div></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">游戏帐号:</td>
      <td width="170" height="30" colspan="2" bgcolor="#FFFFFF"><input name="username" type="text" class="box" id="username" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">游戏密码:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="password" type="password" class="box" id="password" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">角色名称:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="charname" type="text" class="box" id="charname"/></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">地图选择:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><span class="STYLE1"><input name="maps" type="text" class="boxs" id="maps" value="910000000" readonly="true" /></span></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">&nbsp;</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="提交" /></td>
    </tr>
    <tr>
      <td height="30" colspan="3" bgcolor="#FFFFFF"><div align="center">传送说明:只能传送到自由市场.</div></td>
    </tr>
   </form>
  </table>
  <div id="footer"></div>
</div>
</body>
</html>"