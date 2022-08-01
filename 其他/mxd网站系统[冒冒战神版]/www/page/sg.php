<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<?php
ob_start();
include ("Mean/config.php");
$Wormdb = @mysql_connect($db_host, $db_user, $db_pass) or die ('请检查所填数据是否正确~！位置：mean/config.php');
mysql_select_db ($db_name);
session_start();
?>
<html>
<head>
<title><?php echo $site_title; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">

<style type="text/css">
<!--
#apDiv1 {
	position:absolute;
	width:962px;
	height:285px;
	z-index:1;
	left: 120px;
}
body {
	background-image: url(images/bg.jpg);
	background-position:center;
	background-position:top
	background-repeat: repeat-x;
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
	background-repeat: repeat-x;
}
#apDiv2 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:2;
}
#apDiv3 {
	position:absolute;
	width:200px;
	height:38px;
	z-index:2;
	top: 369px;
}
#apDiv4 {
	position:absolute;
	width:629px;
	height:225px;
	z-index:2;
}
#__01 table {
	font-size: 12px;
	font-style: normal;
	line-height: normal;
	border-bottom-style: dashed;
	border-top-color: #BD35C3;
	border-right-color: #BD35C3;
	border-bottom-color: #BD35C3;
	border-left-color: #BD35C3;
}
-->
</style>
<script type="text/javascript">
<!--
function alertWin() {
      var iWidth = document.documentElement.clientWidth;
      var iHeight = document.documentElement.clientHeight;
      var w=435;h=450;
      background.style.cssText="position:absolute;left:0px;top:0px;width:100%;height:100%;filter:Alpha(Opacity=90);opacity:0.9;background-color:#333;z-index:101;";
      wincontent.style.cssText="width:540px; height:340px; left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102;";
      sl.style.overflow="hidden";
    }
	
	
function MM_swapImgRestore() { //v3.0
  var i,x,a=document.MM_sr; for(i=0;a&&i<a.length&&(x=a[i])&&x.oSrc;i++) x.src=x.oSrc;
}
function MM_preloadImages() { //v3.0
  var d=document; if(d.images){ if(!d.MM_p) d.MM_p=new Array();
    var i,j=d.MM_p.length,a=MM_preloadImages.arguments; for(i=0; i<a.length; i++)
    if (a[i].indexOf("#")!=0){ d.MM_p[j]=new Image; d.MM_p[j++].src=a[i];}}
}

function MM_findObj(n, d) { //v4.01
  var p,i,x;  if(!d) d=document; if((p=n.indexOf("?"))>0&&parent.frames.length) {
    d=parent.frames[n.substring(p+1)].document; n=n.substring(0,p);}
  if(!(x=d[n])&&d.all) x=d.all[n]; for (i=0;!x&&i<d.forms.length;i++) x=d.forms[i][n];
  for(i=0;!x&&d.layers&&i<d.layers.length;i++) x=MM_findObj(n,d.layers[i].document);
  if(!x && d.getElementById) x=d.getElementById(n); return x;
}

function MM_swapImage() { //v3.0
  var i,j=0,x,a=MM_swapImage.arguments; document.MM_sr=new Array; for(i=0;i<(a.length-2);i+=3)
   if ((x=MM_findObj(a[i]))!=null){document.MM_sr[j++]=x; if(!x.oSrc) x.oSrc=x.src; x.src=a[i+2];}
}
function MM_popupMsg(msg) { //v1.0
  alert(msg);
}
//-->
</script>
</style>
<link rel="stylesheet" rev="stylesheet" href="template/sweetTitles.css" type="text/css" media="all" />
<LINK href="images/js/chromestyle.css" type=text/css rel=stylesheet>
<SCRIPT src="images/js/chrome.js" type=text/javascript>
</SCRIPT>
<script type="text/javascript" src="images/js/ts.js"></script>
<style type="text/css">
<!--
#apDiv5 {
	position:absolute;
	width:654px;
	height:272px;
	z-index:2;
}
body,td,th {
	font-size: 12px;
	color: #BC2EC0;
}
#apDiv6 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:3;
	left: 129px;
	top: 412px;
}
#apDiv7 {
	position:absolute;
	width:234px;
	height:224px;
	z-index:3;
}
#apDiv8 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv9 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv10 {
	position:absolute;
	width:1218px;
	height:115px;
	z-index:4;
}
#apDiv11 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv12 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv13 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv14 {
	position:absolute;
	width:979px;
	height:115px;
	z-index:4;
	background-image: url(images/bg3.gif);
}
#apDiv15 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:4;
}
#apDiv16 {
	position:absolute;
	width:1031px;
	height:104px;
	z-index:4;
}
.STYLE3 {
	color: #006600;
	font-weight: bold;
}
.STYLE4 {color: #006600}
#apDiv17 {
	position:absolute;
	width:687px;
	height:277px;
	z-index:4;
}
.STYLE5 {color: #000000}
#apDiv18 {
	position:absolute;
	width:696px;
	height:600px;
	z-index:4;
}
#apDiv {
	position:absolute;
	width:687px;
	height:278px;
	z-index:4;
}
#apDiv19 {	position:absolute;
	width:687px;
	height:278px;
	z-index:4;
}
#apDiv20 {
	position:absolute;
	width:696px;
	height:276px;
	z-index:5;
}
#apDiv21 {
	position:absolute;
	width:243px;
	height:115px;
	z-index:6;
}
a:link {
	color: #BD35C3;
	text-decoration: none;
}
a:visited {
	text-decoration: none;
	color: #BD35C3;
}
a:hover {
	text-decoration: underline;
	color: #BD35C3;
}
a:active {
	text-decoration: none;
	color: #BD35C3;
}
#apDiv22 {
	position:absolute;
	width:649px;
	height:181px;
	z-index:6;
}
#apDiv23 {
	position:absolute;
	width:695px;
	height:798px;
	z-index:6;
	background-image: url(../images/%E6%8E%92%E8%A1%8C_02.gif);
}
#apDiv24 {
	position:absolute;
	width:200px;
	height:115px;
	z-index:7;
}
#apDiv25 {
	position:absolute;
	width:672px;
	height:79px;
	z-index:7;
}
#apDiv26 {
	position:absolute;
	width:657px;
	height:787px;
	z-index:8;
}
#apDiv27 {
	position:absolute;
	width:633px;
	height:784px;
	z-index:8;
}
-->
</style>
</head>
<script language="javascript">
    function alertWin() {
      var iWidth = document.documentElement.clientWidth;
      var iHeight = document.documentElement.clientHeight;
      var w=435;h=450;
      background.style.cssText="position:absolute;left:0px;top:0px;width:100%;height:100%;filter:Alpha(Opacity=90);opacity:0.9;background-color:#333;z-index:101;";
      wincontent.style.cssText="width:540px; height:340px; left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102;";
      sl.style.overflow="hidden";
    }
    function closeWin() {
      location.reload();
    }
  </script>
  <head> 
<script LANGUAGE="JavaScript"> 
<!------------------------------------------------------------------------------------------------------------------------------------------- 
function openwin() { 
window.open ("index.php?page=zhuce", "newwindow", "height=280, width=340, left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102; toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no")  
} 
//--> ------------------------------------------------------------------------------------------------------------------------------------------- 


<!------------------------------------------------------------------------------------------------------------------------------------------- 
function openwin2() { 
window.open ("index.php?page=pass", "newwindow", "height=261, width=278, left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102; toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no")  
} 
//--> ------------------------------------------------------------------------------------------------------------------------------------------- 
<!------------------------------------------------------------------------------------------------------------------------------------------- 
function openwin3() { 
window.open ("index.php?page=maps", "newwindow", "height=261, width=278, left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102; toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no")  
} 
//--> ------------------------------------------------------------------------------------------------------------------------------------------- 
<!------------------------------------------------------------------------------------------------------------------------------------------- 
function openwin4() { 
window.open ("index.php?page=password", "newwindow", "height=270, width=278, left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102; toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no")  
} 
//--> ------------------------------------------------------------------------------------------------------------------------------------------- 
<!------------------------------------------------------------------------------------------------------------------------------------------- 
function openwin5() { 
window.open ("index.php?page=xiazai", "newwindow", "height=240, width=278, left:50%; margin:-181px 0 0 -170px; position:absolute; top:50%;z-index:102; toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no")  
} 
//--> ------------------------------------------------------------------------------------------------------------------------------------------- 
</script> 
</head> 

<body onLoad="MM_preloadImages('images/index2_07.gif','images/index2_08.gif','images/index2_09.gif','images/index2_16.gif','images/index2_11.gif','images/index2_18.gif','images/index2_23.gif','images/index2_20.gif','images/index1_22.gif','images/index2_22.gif')">
<table width="1251" height="1601" border="0" align="center" cellpadding="0" cellspacing="0" id="__01">
<tr>
		<td height="285" colspan="16" align="left" valign="top"><div id="apDiv1"></div></td>
<td>
			<img src="images/分隔符.gif" width="1" height="285" alt=""></td>
	</tr>
	<tr>
		<td rowspan="10">&nbsp;</td>
  <td rowspan="6">&nbsp;</td>
  <td rowspan="6">&nbsp;</td>
  <td>
			<img src="images/index1_05.gif" width="3" height="1" alt=""></td>
		<td rowspan="6" background="images/index1_06.gif">&nbsp;</td>
	  <td rowspan="2"><a href="#" onClick="openwin()" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image52','','images/index2_07.gif',1)"><img src="images/index1_07.gif" alt="创建你的游戏账号" name="Image52" width="91" height="37" border="0"></a></td>
<td rowspan="2"><a href="index.php" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image53','','images/index2_08.gif',1)"><img src="images/index1_08.gif" alt="返回网站首页" name="Image53" width="91" height="37" border="0"></a></td>
<td rowspan="2"><a href="#"onClick="openwin2()" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image54','','images/index2_09.gif',1)"><img src="images/index1_09.gif" alt="修改您的游戏密码" name="Image54" width="91" height="37" border="0"></a></td>
<td colspan="2">
			<img src="images/index1_10.gif" width="92" height="1" alt=""></td>
		<td colspan="3" rowspan="2"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image56','','images/index2_11.gif',1)"><img src="images/index1_11.gif" alt="充值元宝" name="Image56" width="105" height="37" border="0"></a></td>
<td rowspan="6" background="images/index1_12.gif">&nbsp;</td>
		<td rowspan="6" background="images/index1_13.gif">&nbsp;</td>
	  <td rowspan="10" align="left" valign="top">&nbsp;</td>
<td>
			<img src="images/分隔符.gif" width="1" height="1" alt=""></td>
	</tr>
	<tr>
		<td rowspan="5">
			<img src="images/index1_15.gif" width="3" height="79" alt=""></td>
		<td><a href="#" onClick="openwin3()"onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image55','','images/index2_16.gif',1)"><img src="images/index1_16.gif" alt="解封激活" name="Image55" width="91" height="36" border="0"></a></td>
<td rowspan="5">
			<img src="images/index1_17.gif" width="1" height="79" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="1" height="36" alt=""></td>
	</tr>
	<tr>
		<td rowspan="2"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image57','','images/index2_18.gif',1)"><img src="images/index1_18.gif" name="Image57" width="91" height="37" border="0"></a></td>
<td>
			<img src="images/index1_19.gif" width="91" height="1" alt=""></td>
		<td rowspan="2"><a href="#" onClick="openwin4()"onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image59','','images/index2_20.gif',1)"><img src="images/index1_20.gif" name="Image59" width="91" height="37" border="0"></a></td>
<td rowspan="2"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('231232','','images/inde2_21.gif',1)"><img src="images/index1_21.gif" alt="装备截图" name="231232" width="91" height="37" border="0" onClick="MM_popupMsg('功能制作ing~~~~~')"></a></td>
<td colspan="3" rowspan="2"><a href="#" onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image60','','images/index2_22.gif',1)"><img src="images/index1_22.gif" alt="装备购买" name="Image60" width="105" height="37" border="0" onClick="MM_popupMsg('购买装备请联系GMQQ:191118032找 gm定制')"></a></td>
<td>
			<img src="images/分隔符.gif" width="1" height="1" alt=""></td>
	</tr>
	<tr>
		<td rowspan="2"><a href="#" onClick="openwin5()"onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('Image58','','images/index2_23.gif',1)"><img src="images/index1_23.gif" alt="下载游戏" name="Image58" width="91" height="37" border="0"></a></td>
      <td>
			<img src="images/分隔符.gif" width="1" height="36" alt=""></td>
	</tr>
	<tr>
		<td rowspan="2">
			<img src="images/index1_24.gif" width="91" height="6" alt=""></td>
		<td colspan="2" rowspan="2">
			<img src="images/index1_25.gif" width="182" height="6" alt=""></td>
		<td colspan="3" rowspan="2">
			<img src="images/index1_26.gif" width="105" height="6" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="1" height="1" alt=""></td>
	</tr>
	<tr>
		<td>
			<img src="images/index1_27.gif" width="91" height="5" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="1" height="5" alt=""></td>
	</tr>
	<tr>
		<td background="images/index1_28.gif">&nbsp;</td>
	  <td colspan="13" rowspan="4" align="left" valign="top" bgcolor="#FFFFFF">
	  <img src="images/index1_32.gif" width="1" height="1" alt="">
	  <table id="__2" width="695" height="278" border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td height="82" align="left" valign="top" background="../images/sg.gif"><div id="apDiv25">
            <table width="100%" border="0" cellspacing="5" cellpadding="5">
              <tr>
                <td height="38" colspan="2">&nbsp;</td>
              </tr>
              <tr>
                <td width="4%" height="22">&nbsp;</td>
                <td width="96%"> <div align="left" onfocus="MM_popupMsg('暂时无法使用，维护中。')">网页商城系统给你提供一个离线购买的平台！</div></td>
              </tr>
            </table>
          </div></td>
        </tr>
        <tr>
          <td height="194" align="left" valign="top" background="../images/排行_02.gif"><div id="apDiv23">
            <table width="100%" border="0" cellspacing="0" cellpadding="00">
              <tr>
                <td height="784" align="left" valign="top"><table width="100%" height="784" border="0" cellpadding="00" cellspacing="0">
                  <tr>
                    <td width="3%">&nbsp;</td>
                    <td width="97%" align="left" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="00">
                      <tr>
                        <td width="94%" height="427" align="left" valign="top"><div id="apDiv27">
                          <iframe frameborder="0" name="frame" id="frame" src="index.php?page=a_item" height="100%" width="100%" scrolling="auto"></iframe>
                        </div></td>
                        <td width="6%">&nbsp;</td>
                      </tr>
                    </table></td>
                  </tr>
                </table></td>
              </tr>
              <tr>
                <td background="../images/排行_03.gif">&nbsp;</td>
              </tr>
            </table>
          </div></td>
        </tr>
      </table></td>
<td>
			<img src="images/分隔符.gif" width="1" height="43" alt=""></td>
	</tr>
	<tr>
		<td rowspan="3" align="left" valign="top" background="images/index1_30.gif" background-position:center;><div id="apDiv7">
		  <table width="100%" height="222" border="0" cellpadding="00" cellspacing="0">
            <tr>
              <td width="25%" height="81">&nbsp;</td>
              <td width="75%">&nbsp;</td>
            </tr>
            <tr>
              <td height="35">&nbsp;</td>
              <td align="left" valign="bottom"><img src="images/lift1.gif" width="150" height="40" onClick="MM_popupMsg('功能建设中')"></td>
            </tr>
            <tr>
              <td rowspan="2" align="right" valign="bottom"><img src="images/2.gif" width="46" height="69"></td>
              <td height="47" align="left" valign="bottom"><img src="images/lift2.gif" width="150" height="40" onClick="MM_popupMsg('已在该页面.')"></td>
            </tr>
            <tr>
              <td align="left" valign="bottom"><img src="images/lift3.gif" width="150" height="40" onClick="MM_popupMsg('功能建设中')"></td>
            </tr>
          </table>
		</div></td>
<td>
			<img src="images/分隔符.gif" width="1" height="187" alt=""></td>
	</tr>
	<tr>
	  <td>
		  <img src="images/分隔符.gif" width="1" height="1" alt=""></td>
	</tr>
	<tr>
	  <td height="49">
		  <img src="images/分隔符.gif" width="1" height="49" alt=""></td>
  </tr>
	<tr>
		<td background="images/index1_35.gif"  background-position:right >&nbsp;</td>
  <td colspan="14" align="left" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="00">
    
    <tr>
      <td width="26%" height="290" align="left" valign="top" background="images/02.gif"><table width="98%" border="0" cellspacing="0" cellpadding="00">
        <tr>
          <td width="9%" rowspan="2">&nbsp;</td>
            <td width="91%" height="127">&nbsp;</td>
          </tr>
        <tr>
          <td height="161" align="left" valign="top"><table width="100%" border="0" cellspacing="3" cellpadding="5">
            <tr>
              <td colspan="2" align="right">运行状况：</td>
                <td width="53%"><span class="STYLE3">正常开启</span></td>
              </tr>
            <tr>
              <td height="28" colspan="2" align="right">注册人数：</td>
                <td><span class="STYLE3">
                  <?php
$query = mysql_query("SELECT COUNT(*) FROM `accounts`") or die (mysql_error());
$user_count = mysql_fetch_array($query);
?>
                  <?php
//output the number of users
echo $user_count['0'];
?>
                  人</span></td>
              </tr>
            <tr>
              <td colspan="2" align="right">角色人数：</td>
                <td><span class="STYLE3">
                  <?php
//count how many users we have
$query = mysql_query("SELECT COUNT(*) FROM `characters`") or die (mysql_error());
$char_count = mysql_fetch_array($query);
?>
                  <?php
//output the number of users
echo $char_count['0'];
?>
                  人</span></td>
              </tr>
            <tr>
              <td colspan="2" align="right">在线人数：</td>
                <td><span class="STYLE27 STYLE4"><strong><?php echo mysql_result(mysql_query('SELECT COUNT(*) FROM accounts WHERE loggedin > 0'), 0);?>人</strong></span></td>
              </tr>
            <tr>
              <td width="14%" height="16" align="right">&nbsp;</td>
                <td height="16" colspan="2" align="left"><div align="left">各位玩家们：
                  <SCRIPT>
today=new Date();
var day; var date; var hello; var wel;
hour=new Date().getHours()
if(hour < 6)hello='凌晨好'
else if(hour < 9)hello='早上好'
else if(hour < 12)hello='上午好'
else if(hour < 14)hello='中午好'
else if(hour < 17)hello='下午好'
else if(hour < 19)hello='傍晚好'
else if(hour < 22)hello='晚上好'
else {hello='夜里好!'}
if(today.getDay()==0)day='星期日'
else if(today.getDay()==1)day='星期一'
else if(today.getDay()==2)day='星期二'
else if(today.getDay()==3)day='星期三'
else if(today.getDay()==4)day='星期四'
else if(today.getDay()==5)day='星期五'
else if(today.getDay()==6)day='星期六'
date=(today.getYear())+'年'+(today.getMonth() + 1 )+'月'+today.getDate()+'日';
if(hour<1)wel='子时';
else if(hour<3)wel='丑时';
else if(hour<5)wel='寅时';
else if(hour<7)wel='卯时';
else if(hour<9)wel='辰时';
else if(hour<11)wel='巳时';
else if(hour<13)wel='午时';
else if(hour<15)wel='未时';
else if(hour<17)wel='申时';
else if(hour<19)wel='酉时';
else if(hour<21)wel='戌时';
else if(hour<23)wel='亥时';
else {wel='子时';}
document.write(hello);
                  </SCRIPT>
                  <span class="STYLE3">&nbsp;</span></div></td>
                </tr>
            </table></td>
          </tr>
      </table></td>
      <td height="284" align="left" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="00">
        <tr>
          <td height="280" align="left" valign="top" bgcolor="#FFFFFF">&nbsp;</td>
        </tr>
        <tr>
          <td height="12">&nbsp;</td>
        </tr>
      </table></td>
    </tr>
    
    <tr>
      <td align="left" valign="top" background="images/03.gif" ><table width="100%" border="0" cellspacing="0" cellpadding="00">
        <tr>
          <td width="9%" rowspan="2">&nbsp;</td>
          <td width="91%" height="127">&nbsp;</td>
        </tr>
        <tr>
          <td height="161" align="left" valign="top"><table width="100%" border="0" cellspacing="3" cellpadding="5">
              <tr>
                <td height="22" align="right">客服QQ1号：</td>
                <td width="54%"><span class="STYLE3">
                  <?=($kf1)?></span></td>
              </tr>
              <tr>
                <td height="28" align="right">客服QQ2号：</td>
                <td><span class="STYLE3">
                  <?=($kf2)?></span></td>
              </tr>
              <tr>
                <td align="right">玩家交流群1：</td>
                <td><span class="STYLE3">
                  <?=($Q1)?>
                </span></td>
              </tr>
              <tr>
                <td align="right">玩家交流群2：</td>
                <td><span class="STYLE3">
                  <?=($Q2)?></span></td>
              </tr>
              <tr>
                <td height="16" align="right">玩家交流群3：</td>
                <td><span class="STYLE3">
                  <?=($Q3)?></span></td>
              </tr>
          </table></td>
        </tr>
      </table></td>
      <td width="74%" align="left" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="00">
        <tr>
          <td height="280" align="left" valign="top" background="images/down.gif">&nbsp;</td>
        </tr>
        <tr>
          <td>&nbsp;</td>
        </tr>
      </table></td>
    </tr>
    
  </table>  </td>
  <td align="left" valign="top" background="images/indexzzz.gif">&nbsp;</td>
<td rowspan="2">
			<img src="images/分隔符.gif" width="1" height="155" alt=""></td>
	</tr>
	<tr>
	  <td height="18" colspan="16" align="center" valign="top"  background-position:center ><table width="100%" border="0" cellspacing="0" cellpadding="00">
        <tr>
          <td width="8%" height="355">&nbsp;</td>
          <td width="92%" align="left" valign="top"><table id="__" width="1031" height="354" border="0" cellpadding="0" cellspacing="0">
            <tr>
              <td height="80"><img src="images/index2_01.gif" width="1031" height="80" alt=""></td>
            </tr>
            <tr>
              <td height="72"><img src="images/index2_02.gif" width="1031" height="72" alt=""></td>
            </tr>
            <tr>
              <td height="80"><img src="images/index2_03.gif" width="1031" height="80" alt=""></td>
            </tr>
            <tr>
              <td height="104" background="images/index2_04.gif"><table width="100%" border="0" cellspacing="5" cellpadding="5">
                <tr>
                  <td width="13%">&nbsp;</td>
                  <td colspan="2">&nbsp;</td>
                </tr>
                <tr>
                  <td>&nbsp;</td>
                  <td width="72%"><div align="center"><span class="STYLE5">
                    <?=($bq)?>
                  </span></div></td>
                  <td width="15%">&nbsp;</td>
                </tr>
                <tr>
                  <td>&nbsp;</td>
                  <td><div align="center"><span class="STYLE5">
                    <?=($ba)?>
                  </span></div></td>
                  <td>&nbsp;</td>
                </tr>
              </table></td>
            </tr>
            <tr>
              <td align="left" valign="top"><img src="images/index2_05.gif" width="1031" height="14" alt=""></td>
            </tr>
          </table></td>
        </tr>
      </table></td>
  </tr>
	
	<tr>
		<td>
			<img src="images/分隔符.gif" width="128" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="246" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="72" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="3" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="35" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="91" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="91" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="91" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="91" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="1" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="30" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="1" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="74" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="56" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="59" height="1" alt=""></td>
		<td>
			<img src="images/分隔符.gif" width="181" height="1" alt=""></td>
		<td></td>
	</tr>
</table>
<!-- End ImageReady Slices -->
</body>
</html>