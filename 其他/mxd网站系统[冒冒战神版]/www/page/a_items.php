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
<style type="text/css">
<!--
#apDiv1 {
	position:absolute;
	width:220px;
	height:99px;
	z-index:1;
}
body,td,th {
	font-size: 12px;
	color: #BC2EC0;
}
body {
	background-color: #FFFFFF;
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
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
<table width="558" border="0" cellpadding="10">
  <tr>
    <td width="76" bgcolor="#FFFFFF"><div align="center"><strong><a href="index.php?page=a_item">其他物品</a></strong></div></td>
    <td width="217" bgcolor="#FFFFFF"><div align="left"><del>武器装备</del></div></td>
    <td width="217" bgcolor="#FFFFFF"><div align="right"><a href="index.php?page=a_login"><strong>Goto登陆网页商城</strong></a></div></td>
  </tr>
  
  
  <tr>
    <td colspan="3" align="left" valign="middle" bgcolor="#F0F1E0"><a href="index.php?page=a_items&amp;shop=1">BT武器</a> | <a href="index.php?page=a_items&amp;shop=2">BT衣服</a> | <a href="index.php?page=a_items&amp;shop=3">BT点装</a> | <a href="index.php?page=a_items&amp;shop=4">BT鞋子手套</a> | <a href="index.php?page=a_items&amp;shop=5"><strong>BT装备</strong></a> |<a href="index.php?page=a_items&amp;shop=6"><span class="r"><strong>每日特卖</strong></a> | <a href="index.php?page=a_items&amp;shop=7">BT披风 | </a><a href="index.php?page=a_items&amp;shop=8">BT项链 </a><a href="index.php?page=a_items&amp;shop=9">| 玩具坐骑</a> </td>
  </tr>
</table>
<p>
  <? if ($_SESSION["userid"]=="" or $_SESSION["charid"]=="") { ?>
</p>
<p>&nbsp; </p>
<table width="601" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
  <tr>
    <td height="38" bgcolor="#FFFFFF">&nbsp;&nbsp;<strong>
      <style type="text/css">
<!--
.STYLE1 {
	color: #FF0000;
	font-weight: bold;
}
-->
</style>
      <span class="STYLE1">请先登陆</span></strong></td>
  </tr>
  <tr>
    <td height="50" align="center" bgcolor="#FFFFFF">进行该页面的所有操作，都需要先登陆到角色之中，登陆角色必须从游戏中下线!</td>
  </tr>
</table>
<? }else{ ?>
<table width="601" border="0" align="center" cellpadding="0" cellspacing="1" bgcolor="#CCCCCC">
  <tr>
    <td height="38" colspan="6" bgcolor="#FFFFFF">&nbsp;&nbsp;<strong>属性物品</strong></td>
  </tr>
  <?
if ($_GET["shop"]==""){
	$i="1";
}else{
	$i=$_GET["shop"];
}

$sql = mysql_query("select * from shop_items where itemtype='$i'",$conn);
$total_items = mysql_affected_rows();
if ($total_items<=0){
  echo ("<tr><td height=\"50\" align=\"center\" bgcolor=\"#FFFFFF\">Sorry,无该类产品出售!</td></tr>");
}else{
  while ($item = mysql_fetch_array($sql)){
?>
  <form action="index.php?page=server&amp;act=items" method="post" name="form" id="form" onsubmit="return confirm('购买物品:<? echo $item[itemname]; ?>\n\n购买后不能退款和兑换!是否购买?');">
    <input name="id" type="hidden" id="id" value="<? echo $item[id]; ?>" />
    <tr>
      <td width="51" height="100" align="center" bgcolor="#FFFFFF"><img src="http://www.mapletip.com/images/maplestory-monsters/0<? echo $item[itemid]; ?>.png"/></td>
      <td width="132" bgcolor="#FFFFFF">物品名称:<span class="r"><? echo $item[itemname]; ?></span><br />
        [<span class="r"><? echo $item[iteminfo]; ?></span>]</td>
      <td width="282" align="left" valign="top" bgcolor="#FFFFFF"><div id="apDiv1">可砸次数:<? echo $item[upgradeslots]; ?> 已砸次数:<? echo $item[level]; ?><br />
        力:<? echo $item[str]; ?> 敏:<? echo $item[dex]; ?> 智:<? echo $item[int]; ?> 运:<? echo $item[luk]; ?> 血:<? echo $item[hp]; ?> 魔:<? echo $item[mp]; ?><br />
        物攻:<? echo $item[watk]; ?> 魔攻:<? echo $item[matk]; ?> 物防:<? echo $item[wdef]; ?> 魔防:<? echo $item[mdef]; ?><br />
        命中:<? echo $item[acc]; ?> 躲避:<? echo $item[avoid]; ?> 手技:<? echo $item[hands]; ?> 速度:<? echo $item[speed]; ?> 跳跃:<? echo $item[jump]; ?></div></td>
      <td width="103" bgcolor="#FFFFFF">物品存货:<span class="r"><? echo $item[itemhave]; ?></span></td>
      <td width="103" bgcolor="#FFFFFF">物品价格:<span class="r"><? echo $item[itemmoney]; ?></span></td>
      <td width="56" align="center" bgcolor="#FFFFFF"><input name="sub" type="submit" id="sub" value="购买" /></td>
    </tr>
  </form>
  <? }} ?>
</table>
<? } ?>

</body>
</html>