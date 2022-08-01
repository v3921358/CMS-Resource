<style type="text/css">
<!--
body,td,th {
	font-size: 12px;
	color: #FFFFFF;
}
body {
	background-image: url(images/bg002.jpg);
	background-repeat: no-repeat;
}
-->
</style>
<title>家族排行</title><p align="center">冒冒岛家族排名</p>
<table width="293" border="0" align="center" cellpadding="00" cellspacing="0" bordercolor="#FFFFFF">
  <? $sql = mysql_query("SELECT * FROM guilds ORDER BY GP DESC LIMIT 0,20"); while ($data = mysql_fetch_array($sql)){ ?>
  <? echo $data["rmbs"]; ?>
 
  <tr>
    <td width="182"><strong><strong>家族名字:<? echo $data[name]; ?></td>
    <td width="111" height="20"><strong><strong>所有GP：<? echo $data[GP]; ?></td>
  </tr>
  <? }?>
</table>
