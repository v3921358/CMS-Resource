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
  error("����½���ʺŲ�����,����µ�½!");
}
$sqlpass = "".$password."".$user[salt]."";
$mypass = hash('sha512',$sqlpass);
if ($user[password]!=$mypass) {
  error("���ĵ�½�������,����µ�½!");
}
if ($user[loggedin]<>0){
 error("�����ʺ�����ʹ����,�����ߺ���!");
}
$mysql_nsql = mysql_query("select * from characters where name='$charname' and accountid='".$user[id]."'",$conn);
$name = mysql_fetch_array($mysql_nsql);
$total_acter = mysql_affected_rows();
if($total_acter!=1) {
  error("���ʺŲ����ڴ˽�ɫ,����µ�½!");
}

if ($maps<>"910000000") {
  error("�õ�ͼ������");
}

$sql=mysql_query("update `characters` set `map`='$maps' where name='$charname'");

 if ($sql) {
  error("���ͳɹ���");
 }else{
  error("����ʧ�ܣ�");
 }

}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title><? echo $Site_name; ?>-��ͼ����</title>
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
      <td height="32" colspan="3" bgcolor="#FFFFFF"><div align="center"><strong>��ͼ����</strong></div></td>
    </tr>
    <tr>
      <td width="130" height="30" align="center" bgcolor="#FFFFFF">��Ϸ�ʺ�:</td>
      <td width="170" height="30" colspan="2" bgcolor="#FFFFFF"><input name="username" type="text" class="box" id="username" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��Ϸ����:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="password" type="password" class="box" id="password" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��ɫ����:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="charname" type="text" class="box" id="charname"/></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��ͼѡ��:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><span class="STYLE1"><input name="maps" type="text" class="boxs" id="maps" value="910000000" readonly="true" /></span></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">&nbsp;</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="�ύ" /></td>
    </tr>
    <tr>
      <td height="30" colspan="3" bgcolor="#FFFFFF"><div align="center">����˵��:ֻ�ܴ��͵������г�.</div></td>
    </tr>
   </form>
  </table>
  <div id="footer"></div>
</div>
</body>
</html>"