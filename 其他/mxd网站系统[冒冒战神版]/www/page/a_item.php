<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title><? echo $Site_name; ?></title>

<script language="javascript">
function correctPNG() 
   {
   for(var i=0; i<document.images.length; i++)
      {
   var img = document.images[i]
   var imgName = img.src.toUpperCase()
   if (imgName.substring(imgName.length-3, imgName.length) == "PNG")
      {
   var imgID = (img.id) ? "id='" + img.id + "' " : ""
   var imgClass = (img.className) ? "class='" + img.className + "' " : ""
   var imgTitle = (img.title) ? "title='" + img.title + "' " : "title='" + img.alt + "' "
   var imgStyle = "display:inline-block;" + img.style.cssText 
   if (img.align == "left") imgStyle = "float:left;" + imgStyle
   if (img.align == "right") imgStyle = "float:right;" + imgStyle
   if (img.parentElement.href) imgStyle = "cursor:hand;" + imgStyle  
   var strNewHTML = "<span " + imgID + imgClass + imgTitle
   + " style=\"" + "width:" + img.width + "px; height:" + img.height + "px;" + imgStyle + ";"
      + "filter:progid:DXImageTransform.Microsoft.AlphaImageLoader"
   + "(src=\'" + img.src + "\', sizingMethod='scale');\"></span>" 
   img.outerHTML = strNewHTML
   i = i-1
      }
      }
   }
window.attachEvent("onload", correctPNG);
</script>
<style clear:botn type="text/css">
<!--
#apDiv1 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:1;
}
#apDiv2 {
	position:absolute;
	width:227px;
	height:50px;
	z-index:1;
}
body {
	margin-left: 0px;
	background-color: #FFFFFF;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
body,td,th {
	font-size: 12px;
	color: #BC2EC0;
}
a:link {
	color: #BC2EC0;
	text-decoration: none;
}
a:visited {
	text-decoration: none;
	color: #BC2EC0;
}
a:hover {
	text-decoration: underline;
	color: #BC2EC0;
}
a:active {
	text-decoration: none;
	color: #BC2EC0;
}
-->
</style>
</head>

<body>
<table width="601" border="0" align="center" cellpadding="10">
  <tr>
    <td width="63" bgcolor="#FFFFFF"><del>
      <div align="center">其他物品</div>
    </del></td>
    <td width="245" bgcolor="#FFFFFF"><div align="left"><strong><a href="index.php?page=a_items">武器装备</a></strong> </div></td>
    <td width="246" bgcolor="#FFFFFF"><div align="right"><a href="index.php?page=a_login"><strong>Goto登陆网页商城</strong></a></div></td>
  </tr>
  <tr>
    <td colspan="3" bgcolor="#F0F1E0"><tt>请选择你要进入的列：<a href="index.php?page=a_item&amp;shop=2"><strong>诅咒卷轴 </strong></a><strong>|</strong> <a href="index.php?page=a_item&amp;shop=3"><strong>稀有椅子</strong></a> <strong>|</strong><a href="index.php?page=a_item&amp;shop=4"><strong> 消耗专卖</strong></a></tt></td>
  </tr>
</table>
<p><tt>
  <? if ($_SESSION["userid"]=="" or $_SESSION["charid"]=="") { ?>
</tt></p>
<table width="601" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
  <tr>
    <td width="527" height="38" bgcolor="#FFFFFF">&nbsp;&nbsp;<strong>
      <style type="text/css">
<!--
.STYLE1 {
	color: #FF0000;
	font-weight: bold;
}
-->
</style>
    </strong></td>
  </tr>
  <tr>
    <td height="50"  bgcolor="#FFFFFF">进行该页面的所有操作，都需要先登陆到角色之中，登陆角色必须从游戏中下线!</td>
  </tr>
</table>
<? }else{ ?>
<table width="601" border="0" align="center" cellpadding="0" cellspacing="1" bordercolor="#BC2EC0" bgcolor="#CCCCCC">
  <tr>
    <td height="38" colspan="6" bgcolor="#FFFFFF">&nbsp;&nbsp;<strong>普通物品</strong></td>
  </tr>
  <?
if ($_GET["shop"]==""){
	$i="2";
}else{
	$i=$_GET["shop"];
}

$sql = mysql_query("select * from shop_item where itemtype='$i'",$conn);
$total_items = mysql_affected_rows();
if ($total_items<=0){
  echo ("<tr><td height=\"50\" align=\"lift\" bgcolor=\"#FFFFFF\">Sorry,无该类产品出售!</td></tr>");
}else{
  while ($item = mysql_fetch_array($sql)){
?>
  <form action="index.php?page=server&amp;act=item" method="post" name="form" id="form" onsubmit="return confirm('购买物品:<? echo $item[itemname]; ?>\n\n购买后不能退款和兑换!是否购买?');">
    <input name="id" type="hidden" id="id" value="<? echo $item[id]; ?>" />
    <tr>
      <td width="50" height="50" align="lift" bgcolor="#FFFFFF"><img src="http://www.mapletip.com/images/maplestory-monsters/0<? echo $item[itemid]; ?>.png"/></td>
      <td width="227" align="left" valign="top" bgcolor="#FFFFFF"><div id="apDiv2">物品名称:<? echo $item[itemname]; ?><br />
        物品说明:<? echo $item[iteminfo]; ?></div></td>
      <td width="84" bgcolor="#FFFFFF">物品数量:<? echo $item[quantity]; ?></td>
      <td width="90" bgcolor="#FFFFFF">物品存货:<? echo $item[itemhave]; ?></td>
      <td width="96" bgcolor="#FFFFFF">物品价格:<? echo $item[itemmoney]; ?></td>
      <td width="50" align="lift" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="购买" /></td>
    </tr>
  </form>
  <? }} ?>
</table>
<? } ?>
</body>
</html>