<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title><? echo $Site_name; ?>-�˺�ע��</title>

<style type="text/css">
<!--
body,td,th {
	font-size: 12px;
	color: #000000;
}
body {
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
-->
</style></head>

<body>
<div id="main">
  <table border="0" align="center" cellpadding="0" cellspacing="0" bgcolor="#CCCCCC">
   <form action="index.php?page=server&amp;act=user" method="post" name="form" id="form">
    <tr>
      <td height="38" colspan="3" bgcolor="#FFFFFF">&nbsp;&nbsp;<strong>ע���ʺ�</strong></td>
    </tr>
    <tr>
      <td width="84" height="30" align="center" bgcolor="#FFFFFF">��Ϸ�ʺ�:</td>
      <td width="220" height="30" colspan="2" bgcolor="#FFFFFF"><input name="user" type="text" class="box" id="user" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��Ϸ����:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="pass" type="password" class="box" id="pass" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">ȷ������:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="password" type="password" class="box" id="password" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��ȫ����:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="codepass" type="password" class="box" id="codepass" maxlength="12" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��������:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="email" type="text" class="box" id="email" maxlength="28" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">��������:</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="bay" type="text" class="box" id="bay" value="0000-00-00" maxlength="10" /></td>
    </tr>
    <tr>
      <td height="30" align="center" bgcolor="#FFFFFF">&nbsp;</td>
      <td height="30" colspan="2" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="�ύ" /></td>
    </tr>
    <tr>
      <td height="30" colspan="3" bgcolor="#FFFFFF">���ס���պ͵���������Ϣ!�Ա��һ�����!</td>
    </tr>
   </form>
  </table>
  <div id="footer"></div>
</div>
</body>
</html>