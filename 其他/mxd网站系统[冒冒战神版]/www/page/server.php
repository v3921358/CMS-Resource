<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<?



//注册帐号
if ($_GET[act]=="user") {
  if ($_POST[pass]!=$_POST[password]){
    error ("确认密码错误,请从新输入!");
  }
  $user=$_POST[user];
  $pass=$_POST[pass];
  $code=$_POST[codepass];
  $email=$_POST[email];
  $bay = $_POST[bay];
  if (empty($user) or empty($pass) or empty($code) or empty($email) or empty($bay)) {
    error ("请把内容输入完整,请从新输入!");
  }
  if (!eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$", $email)){
    error("您的电子邮件不符合规格,请从新输入!");
  }
  if (!ereg("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})",$bay)) {
    error("您的生日日期不符合规格,请从新输入!");
  } 
  if (strlen($user) > 12 or strlen($user) < 6) {
    error("帐号不能大于12位,小于6位,请从新输入!");
  }
  if (strlen($code) > 8 or strlen($code) < 6) {
    error("安全码不能大于8位，小于6位，请从新输入！");
  }
  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("密码不能大于12位,小于6位,请从新输入!");
  }
  if (!isAlNum($user)) {
    error("帐号只能是数字或英文,请从新输入!");
  }
  if (!isAlNum($pass)) {
    error ("密码只能是数字或英文,请从新输入!");
  }
  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count>=1) {
    error("该帐号已经存在,请从新输入!");
  }
  $shapass="".$pass."".$code."";
  $mypass = hash('SHA512',$shapass);
  $mysql="insert into accounts (name,password,salt,birthday,banned,email) values ('$user','$mypass','$code','$bay','".$aced_user."','$email')";
  $reg = mysql_query($mysql);
  if ($reg) {
    error("注册帐号成功!");
  }else{
    error("系统出错,请联系GM");
  }
}

//修改密码
if ($_GET[act]=="pass") {
  if ($_POST[pass]!=$_POST[newpass]){
    error("确认密码错误，请从新输入！");
  }
  $user=$_POST[user];
  $oldpass=$_POST[oldpass];
  $pass=$_POST[pass];
  $email=$_POST[email];
  $bay = $_POST[bay];

  if (!isAlNum($pass)) {
    error("密码只能是数字或英文，请从新输入！");
  }

  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("密码不能大于12位或小于6位，请从新输入！");
  }

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("该帐号不存在，请从新输入!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$oldpass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("旧的密码错误，请从新输入!");
  }
  
  if ($email!=$ur[email]) {
    error("电子邮箱错误，请从新输入!");
  }
  
  if ($bay!=$ur[birthday]) {
    error("生日日期错误，请从新输入!");
  }

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `password`='".$mepass."' where name='$user'");

  if ($uppass) {
    error("修改密码成功！");
  }else{
    error("系统出错,请联系GM");
  }
}

//找回密码
if ($_GET[act]=="password") {
  if ($_POST[pass]!=$_POST[newpass]){
    error("确认密码错误，请从新输入！");
  }
  $user=$_POST[user];
  $codepass=$_POST[codepass];
  $pass=$_POST[pass];
  $email=$_POST[email];
  $bay = $_POST[bay];

  if (!isAlNum($pass)) {
    error("密码只能是数字或英文，请从新输入！");
  }

  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("密码不能大于12位或小于6位，请从新输入！");
  }

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("该帐号不存在，请从新输入!");
  }
  $ur = mysql_fetch_array(mysql_query($sql));

  if ($email!=$ur[email]) {
    error("电子邮箱错误，请从新输入!");
  }

  if ($bay!=$ur[birthday]) {
    error("生日日期错误，请从新输入!");
  }

  $shapass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$shapass);
  
  $uppass = mysql_query("update accounts set `password`='".$mepass."' where name='$user'");

  if ($uppass) {
    error("找回密码成功！");
  }else{
    error("系统出错,请联系GM");
  }
}

//解封激活
if ($_GET[act]=="aced") {

  $user=$_POST[user];
  $pass=$_POST[pass];
  $codepass=$_POST[codepass];
  $email=$_POST[email];
  $bay = $_POST[bay];

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("该帐号不存在，请从新输入!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$pass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("密码错误，请从新输入!");
  }
  
  if ($email!=$ur[email]) {
    error("电子邮箱错误，请从新输入!");
  }
  
  if ($bay!=$ur[birthday]) {
    error("生日日期错误，请从新输入!");
  }
  
  if ($ur[banned]==0) {
    error("此号已经激活，无需再次激活！");
  }
  
  $money = $ur[money]-$aced_money;
  if ($money<0) {
    error("点卷不足，请先充值！");
  }

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `banned`=0,`money`='$money' where name='$user'");

  if ($uppass) {
    error("解封激活成功！");
  }else{
    error("系统出错,请联系GM");
  }
}

//点卡充值
if ($_GET[act]=="card") {
  if ($_POST[user]!=$_POST[username]){
    error("两次帐号不一样，请从新输入！");
  }

  $user=$_POST[user];
  $carduser=$_POST[carduser];
  $cardpass=$_POST[cardpass];

  $usersql = mysql_query("select * from accounts where name='$user'",$conn);
  $user = mysql_fetch_array($usersql);
  $total_user = mysql_affected_rows();
  if($total_user!=1) {
    error ("该帐号不存在，请从新输入!");
  }

  $cardsql = mysql_query("select * from shop_card where card_user='$carduser'",$conn);
  $card = mysql_fetch_array($cardsql);
  $total_card = mysql_affected_rows();
  if($total_card<=0) {
    error ("该充值卡不存在，请从新输入!");
  }
  if ($card[card_pass]!=$cardpass){
    error ("充值卡密码错误,请从新输入!");
  }
  if ($card[card_info]!=0) {
    error ("充值卡已被使用,请重新输入!");
  }

  $money = $user[money]+$card[card_money];

  $upuser = mysql_query("update `accounts` set `money`='$money' where name='".$user[name]."'");
  $upcard = mysql_query("update `shop_card` set `card_info`='1' where card_user='$carduser'");

  if ($upuser and $upcard) {
    error("充值成功!该帐号目前可用金额: $money  元");
  }else{
    error("系统出错,请联系GM");
  }

}

//卡号自救
if ($_GET[act]=="khzj") {

  $user=$_POST[user];
  $pass=$_POST[pass];
  $codepass=$_POST[codepass];

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("该帐号不存在,请从新输入!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$pass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("密码错误,请从新输入!");
  }
  
  if ($ur[loggedin]==0) {
    error("此号可以正常登陆!不需要自救!");
  }
  

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `loggedin`=0 where name='$user'");

  if ($uppass) {
    error("自救成功!");
  }else{
    error("系统出错,请联系GM");
  }
}

//点卷兑换
if ($_GET["act"]=="money") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
  error("兑换点卷，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $webmoney=$_POST[webmoney];
}
if ($webmoney=="") {
  error("输入点卷不能为空!");
}
if (!Num($webmoney)) {
  error("输入点卷只能为数字!");
}
$mysql_usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($mysql_usql);

$money=$user[money]-$webmoney;
if ($money<0) {
  error("该帐号点卷不足,请先充值!");
}

$xnxCash = $webmoney*$user_money;
$nxCash=$user[nxCash]+$xnxCash;

$ups = mysql_query("update `accounts` set `money`='$money',`nxCash`='$nxCash' where id='$userid'");

if ($ups) {
  $_SESSION["money"]=$money;
  error("兑换成功！");
}else{
  error("系统出错,请联系GM");
}

}
//金钱购买
if ($_GET["act"]=="mesos") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
  error("购买金币，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $webmoney=$_POST[webmoney];
}
if ($webmoney=="") {
  error("输入点卷不能为空!");
}
if (!Num($webmoney)) {
  error("输入点卷只能为数字!");
}
$mysql_usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($mysql_usql);

$money=$user[money]-$webmoney;
if ($money<0) {
  error("该帐号点卷不足,请先充值!");
}

$mysql_csql = mysql_query("select * from characters where id='$charid'",$conn);
$char = mysql_fetch_array($mysql_csql);
$mesos=$webmoney*$user_mesos;
$meso=$char[meso]+$mesos;

$upa = mysql_query("update `accounts` set `money`='$money' where id='$userid'");
$upb = mysql_query("update `characters` set `meso`='$meso' where id='$charid'");

if ($upa and $upb) {
  $_SESSION["money"]=$money;
  error("购买成功！");
}else{
  error("系统出错,请联系GM");
}

}
//人物转生
if ($_GET[act]=="zhun") {
  if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
    error("人物转生，请先登陆！");
  }else{
    $userid=$_SESSION[userid];
    $charid=$_SESSION[charid];
  }
  $csql = mysql_query("select * from characters where id='$charid'");
  $char = mysql_fetch_array($csql);
  $usql = mysql_query("select * from accounts where id='$userid'");
  $user = mysql_fetch_array($usql);
  $zhunid=$char[zhun]+1;
  $zsql = mysql_query("select * from shop_zhun where id='$zhunid'");
  $zhun = mysql_fetch_array($zsql);
  $total_zhun = mysql_affected_rows();
  if($total_zhun<=0) {
    error ("已经达到最高转生，无需继续转生!");
  }
  if ($char[level]<$zhun[lv]) {
    error("等级不足，尚未能转生！");
  }
  $zmesos = $char[meso]-$zhun[mesos];
  if ($zmesos<0) {
    error("金钱不足，尚未能转生！");
  }
  $zmoney = $user[money]-$zhun[money];
  if ($zmoney<0) {
    error("点卷不足，尚未能转生！");
  }
$dskill = mysql_query("DELETE FROM skills WHERE characterid='$charid'");
$uprmbs = mysql_query("update `accounts` set `money`='$zmoney' where id='$userid'");
$update = mysql_query("update `characters` set `meso`='$zmesos',`level`='".$zhun[level]."',`exp`='0',`str`='".$zhun[str]."',`dex`='".$zhun[dex]."',`luk`='".$zhun[luk]."',`int`='".$zhun[int]."',`hp`='".$zhun[hp]."',`mp`='".$zhun[mp]."',`maxhp`='".$zhun[hp]."',`maxmp`='".$zhun[mp]."',`job`='0',`ap`='0',sp='0',`zhun`='".$zhun[id]."' where id='$charid'");
  if ($dskill and $uprmbs and $update) {
    $_SESSION[zhun]=$zhunid;
	$_SESSION[money]=$zmoney;
    error("转生成功！");
  }else{
    error("系统出错,请联系GM");
  }
}
//普通物品
if ($_GET[act]=="item") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("购买物品，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $itemid=$_POST[id];
}

$isql="select * from shop_item where id='$itemid'";
$mysql_isql = mysql_query($isql,$conn);
$item = mysql_fetch_array($mysql_isql);

$total_item = mysql_affected_rows();
if($total_item!=1) {
  error("您所要购买的物品不存在,请从新选择!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("帐号正在使用,购买请先下线!");
}

$money = $user[mmb]-$item[itemmoney];
if ($money<0) {
  error("该帐号点卷不足,请先充值!");
}


$lsql = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("该窗口的背包已满,请先留位置！");
}


$have = $item[itemhave]-$item[quantity];
if ($have<0) {
  error("该物品已卖完！");
}
$uphave = mysql_query("update `shop_item` set `itemhave`='$have' where itemid='".$item[itemid]."'");

$jfmoney = $user[jfmoney]+$item[itemmoney];
$upmoney = mysql_query("update `accounts` set `mmb`='$money' where id='".$user[id]."'");
$upjfmoney = mysql_query("update `accounts` set `jfmoney`='$jfmoney' where id='".$user[id]."'");
$_SESSION["jfmoney"]=$jfmoney;
$_SESSION["money"]=$money;

  for ($j=1;$j<=100;$j++) { 
    $lion = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and position='$j' and characterid='$charid'");
    $total_lion = mysql_affected_rows();
    if ($total_lion<=0) {
      $itemsql = mysql_query("INSERT INTO inventoryitems (`characterid`,`itemid`,`inventorytype`,`position`,`quantity`,`owner`) VALUES ('".$charid."','".$item[itemid]."','".$item[itemtype]."', '".$j."','".$item[quantity]."','".$_SESSION["name"]."')", $conn);
      if ($itemsql) {
        error("购买成功,您所剩购物券:".$_SESSION["money"]."点!");
      }else{
        error("系统出错,请联系GM");
      }
	}
  }
}
//属性装备
if ($_GET[act]=="items") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("购买物品，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $itemid=$_POST[id];
}

$isql="select * from shop_items where id='$itemid'";
$mysql_isql = mysql_query($isql,$conn);
$item = mysql_fetch_array($mysql_isql);

$total_item = mysql_affected_rows();
if($total_item!=1) {
  error("您所要购买的物品不存在,请从新选择!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("帐号正在使用,购买请先下线!");
}

$money = $user[mmb]-$item[itemmoney];
if ($money<0) {
  error("该帐号购物券不足,请先充值!");
}

$lsql = mysql_query("select * from inventoryitems where inventorytype='1' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("该窗口的背包已满,请先留位置！");
}

$have = $item[itemhave]-1;
if ($have<0) {
  error("该物品已卖完！");
}
$uphave = mysql_query("update `shop_items` set `itemhave`='$have' where itemid='".$item[itemid]."'");
$jfmoney = $user[jfmoney]+$item[itemmoney];
$upmoney = mysql_query("update `accounts` set `mmb`='$money' where id='".$user[id]."'");
$upjfmoney = mysql_query("update `accounts` set `jfmoney`='$jfmoney' where id='".$user[id]."'");
$_SESSION["jfmoney"]=$jfmoney;
$_SESSION["money"]=$money;
  for ($j=1;$j<=100;$j++) {
  
    $lion = mysql_query("select * from inventoryitems where inventorytype='1' and position='$j' and characterid='$charid'");
    $total_lion = mysql_affected_rows();
    if ($total_lion<=0) {
      $itemsql = mysql_query("INSERT INTO inventoryitems (`characterid`,`itemid`,`inventorytype`,`position`,`quantity`,`owner`) VALUES ('".$charid."','".$item[itemid]."','1', '".$j."','1','".$_SESSION["name"]."')", $conn);
	  
	  $itemids = mysql_insert_id();
	  
	  $itemssql = mysql_query("insert into inventoryequipment (`inventoryitemid`,`upgradeslots`,`level`,`str`,`dex`,`int`,`luk`,`hp`,`mp`,`watk`,`matk`,`wdef`,`mdef`,`acc`,`avoid`,`hands`,`speed`,`jump`) values ('".$itemids."','".$item["upgradeslots"]."','".$item["level"]."','".$item["str"]."','".$item["dex"]."','".$item["int"]."','".$item["luk"]."','".$item["hp"]."','".$item["mp"]."','".$item["watk"]."','".$item["matk"]."','".$item["wdef"]."','".$item["mdef"]."','".$item["acc"]."','".$item["avoid"]."','".$item["hands"]."','".$item["speed"]."','".$item["jump"]."')", $conn);
      if ($itemsql and $itemssql) {
        error("购买成功,您所剩购物券:".$_SESSION["money"]."点!");
      }else{
        error("系统出错,请联系GM");
      }
	}
  }
}

//积分购买处理

//普通物品
if ($_GET[act]=="jfitem") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("购买物品，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $itemid=$_POST[id];
}

$isql="select * from shop_jfitem where id='$itemid'";
$mysql_isql = mysql_query($isql,$conn);
$item = mysql_fetch_array($mysql_isql);

$total_item = mysql_affected_rows();
if($total_item!=1) {
  error("您所要购买的物品不存在,请从新选择!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("帐号正在使用,购买请先下线!");
}

$jfmoney = $user[jfmoney]-$item[itemmoney];
if ($jfmoney<0) {
  error("该帐号积分不足,用购物券购买其他物品才可以得到积分!");
}


$lsql = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("该窗口的背包已满,请先留位置！");
}


$have = $item[itemhave]-$item[quantity];
if ($have<0) {
  error("该物品已卖完！");
}
$uphave = mysql_query("update `shop_jfitem` set `itemhave`='$have' where itemid='".$item[itemid]."'");

$upjfmoney = mysql_query("update `accounts` set `jfmoney`='$jfmoney' where id='".$user[id]."'");
$_SESSION["jfmoney"]=$jfmoney;

  for ($j=1;$j<=100;$j++) { 
    $lion = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and position='$j' and characterid='$charid'");
    $total_lion = mysql_affected_rows();
    if ($total_lion<=0) {
      $itemsql = mysql_query("INSERT INTO inventoryitems (`characterid`,`itemid`,`inventorytype`,`position`,`quantity`,`owner`) VALUES ('".$charid."','".$item[itemid]."','".$item[itemtype]."', '".$j."','".$item[quantity]."','".$_SESSION["name"]."')", $conn);
      if ($itemsql) {
        error("购买成功,您所剩:".$_SESSION["jfmoney"]."积分!");
      }else{
        error("系统出错,请联系GM");
      }
	}
  }
}
//属性装备
if ($_GET[act]=="jfitems") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("购买物品，请先登陆！");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $itemid=$_POST[id];
}

$isql="select * from shop_jfitems where id='$itemid'";
$mysql_isql = mysql_query($isql,$conn);
$item = mysql_fetch_array($mysql_isql);

$total_item = mysql_affected_rows();
if($total_item!=1) {
  error("您所要购买的物品不存在,请从新选择!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("帐号正在使用,购买请先下线!");
}

$jfmoney = $user[jfmoney]-$item[itemmoney];
if ($jfmoney<0) {
  error("该帐号积分不足,用购物券购买其他物品才可以得到积分!");
}

$lsql = mysql_query("select * from inventoryitems where inventorytype='1' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("该窗口的背包已满,请先留位置！");
}

$have = $item[itemhave]-1;
if ($have<0) {
  error("该物品已卖完！");
}
$uphave = mysql_query("update `shop_jfitems` set `itemhave`='$have' where itemid='".$item[itemid]."'");

$upjfmoney = mysql_query("update `accounts` set `jfmoney`='$jfmoney' where id='".$user[id]."'");
$_SESSION["jfmoney"]=$jfmoney;
  for ($j=1;$j<=100;$j++) {
  
    $lion = mysql_query("select * from inventoryitems where inventorytype='1' and position='$j' and characterid='$charid'");
    $total_lion = mysql_affected_rows();
    if ($total_lion<=0) {
      $itemsql = mysql_query("INSERT INTO inventoryitems (`characterid`,`itemid`,`inventorytype`,`position`,`quantity`,`owner`) VALUES ('".$charid."','".$item[itemid]."','1', '".$j."','1','".$_SESSION["name"]."')", $conn);
	  
	  $itemids = mysql_insert_id();
	  
	  $itemssql = mysql_query("insert into inventoryequipment (`inventoryitemid`,`upgradeslots`,`level`,`str`,`dex`,`int`,`luk`,`hp`,`mp`,`watk`,`matk`,`wdef`,`mdef`,`acc`,`avoid`,`hands`,`speed`,`jump`) values ('".$itemids."','".$item["upgradeslots"]."','".$item["level"]."','".$item["str"]."','".$item["dex"]."','".$item["int"]."','".$item["luk"]."','".$item["hp"]."','".$item["mp"]."','".$item["watk"]."','".$item["matk"]."','".$item["wdef"]."','".$item["mdef"]."','".$item["acc"]."','".$item["avoid"]."','".$item["hands"]."','".$item["speed"]."','".$item["jump"]."')", $conn);
      if ($itemsql and $itemssql) {
        error("购买成功,您所剩:".$_SESSION["jfmoney"]."积分!");
      }else{
        error("系统出错,请联系GM");
      }
	}
  }
}

echo "<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>";

?>