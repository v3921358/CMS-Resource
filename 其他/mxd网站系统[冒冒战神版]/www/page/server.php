<? !defined("phppage") && die("<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>"); ?>
<?



//ע���ʺ�
if ($_GET[act]=="user") {
  if ($_POST[pass]!=$_POST[password]){
    error ("ȷ���������,���������!");
  }
  $user=$_POST[user];
  $pass=$_POST[pass];
  $code=$_POST[codepass];
  $email=$_POST[email];
  $bay = $_POST[bay];
  if (empty($user) or empty($pass) or empty($code) or empty($email) or empty($bay)) {
    error ("���������������,���������!");
  }
  if (!eregi("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$", $email)){
    error("���ĵ����ʼ������Ϲ��,���������!");
  }
  if (!ereg("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})",$bay)) {
    error("�����������ڲ����Ϲ��,���������!");
  } 
  if (strlen($user) > 12 or strlen($user) < 6) {
    error("�ʺŲ��ܴ���12λ,С��6λ,���������!");
  }
  if (strlen($code) > 8 or strlen($code) < 6) {
    error("��ȫ�벻�ܴ���8λ��С��6λ����������룡");
  }
  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("���벻�ܴ���12λ,С��6λ,���������!");
  }
  if (!isAlNum($user)) {
    error("�ʺ�ֻ�������ֻ�Ӣ��,���������!");
  }
  if (!isAlNum($pass)) {
    error ("����ֻ�������ֻ�Ӣ��,���������!");
  }
  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count>=1) {
    error("���ʺ��Ѿ�����,���������!");
  }
  $shapass="".$pass."".$code."";
  $mypass = hash('SHA512',$shapass);
  $mysql="insert into accounts (name,password,salt,birthday,banned,email) values ('$user','$mypass','$code','$bay','".$aced_user."','$email')";
  $reg = mysql_query($mysql);
  if ($reg) {
    error("ע���ʺųɹ�!");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}

//�޸�����
if ($_GET[act]=="pass") {
  if ($_POST[pass]!=$_POST[newpass]){
    error("ȷ�����������������룡");
  }
  $user=$_POST[user];
  $oldpass=$_POST[oldpass];
  $pass=$_POST[pass];
  $email=$_POST[email];
  $bay = $_POST[bay];

  if (!isAlNum($pass)) {
    error("����ֻ�������ֻ�Ӣ�ģ���������룡");
  }

  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("���벻�ܴ���12λ��С��6λ����������룡");
  }

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("���ʺŲ����ڣ����������!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$oldpass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("�ɵ�����������������!");
  }
  
  if ($email!=$ur[email]) {
    error("��������������������!");
  }
  
  if ($bay!=$ur[birthday]) {
    error("�������ڴ������������!");
  }

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `password`='".$mepass."' where name='$user'");

  if ($uppass) {
    error("�޸�����ɹ���");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}

//�һ�����
if ($_GET[act]=="password") {
  if ($_POST[pass]!=$_POST[newpass]){
    error("ȷ�����������������룡");
  }
  $user=$_POST[user];
  $codepass=$_POST[codepass];
  $pass=$_POST[pass];
  $email=$_POST[email];
  $bay = $_POST[bay];

  if (!isAlNum($pass)) {
    error("����ֻ�������ֻ�Ӣ�ģ���������룡");
  }

  if (strlen($pass) > 12 or strlen($pass) < 6) {
    error("���벻�ܴ���12λ��С��6λ����������룡");
  }

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("���ʺŲ����ڣ����������!");
  }
  $ur = mysql_fetch_array(mysql_query($sql));

  if ($email!=$ur[email]) {
    error("��������������������!");
  }

  if ($bay!=$ur[birthday]) {
    error("�������ڴ������������!");
  }

  $shapass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$shapass);
  
  $uppass = mysql_query("update accounts set `password`='".$mepass."' where name='$user'");

  if ($uppass) {
    error("�һ�����ɹ���");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}

//��⼤��
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
    error("���ʺŲ����ڣ����������!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$pass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("����������������!");
  }
  
  if ($email!=$ur[email]) {
    error("��������������������!");
  }
  
  if ($bay!=$ur[birthday]) {
    error("�������ڴ������������!");
  }
  
  if ($ur[banned]==0) {
    error("�˺��Ѿ���������ٴμ��");
  }
  
  $money = $ur[money]-$aced_money;
  if ($money<0) {
    error("����㣬���ȳ�ֵ��");
  }

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `banned`=0,`money`='$money' where name='$user'");

  if ($uppass) {
    error("��⼤��ɹ���");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}

//�㿨��ֵ
if ($_GET[act]=="card") {
  if ($_POST[user]!=$_POST[username]){
    error("�����ʺŲ�һ������������룡");
  }

  $user=$_POST[user];
  $carduser=$_POST[carduser];
  $cardpass=$_POST[cardpass];

  $usersql = mysql_query("select * from accounts where name='$user'",$conn);
  $user = mysql_fetch_array($usersql);
  $total_user = mysql_affected_rows();
  if($total_user!=1) {
    error ("���ʺŲ����ڣ����������!");
  }

  $cardsql = mysql_query("select * from shop_card where card_user='$carduser'",$conn);
  $card = mysql_fetch_array($cardsql);
  $total_card = mysql_affected_rows();
  if($total_card<=0) {
    error ("�ó�ֵ�������ڣ����������!");
  }
  if ($card[card_pass]!=$cardpass){
    error ("��ֵ���������,���������!");
  }
  if ($card[card_info]!=0) {
    error ("��ֵ���ѱ�ʹ��,����������!");
  }

  $money = $user[money]+$card[card_money];

  $upuser = mysql_query("update `accounts` set `money`='$money' where name='".$user[name]."'");
  $upcard = mysql_query("update `shop_card` set `card_info`='1' where card_user='$carduser'");

  if ($upuser and $upcard) {
    error("��ֵ�ɹ�!���ʺ�Ŀǰ���ý��: $money  Ԫ");
  }else{
    error("ϵͳ����,����ϵGM");
  }

}

//�����Ծ�
if ($_GET[act]=="khzj") {

  $user=$_POST[user];
  $pass=$_POST[pass];
  $codepass=$_POST[codepass];

  $sql="select * from accounts where name='$user'";
  $check = mysql_query($sql,$conn);
  $total_count = mysql_affected_rows();
  if($total_count!=1) {
    error("���ʺŲ�����,���������!");
  }
  
  $ur = mysql_fetch_array(mysql_query($sql));
  $shapass="".$pass."".$ur[salt]."";
  $mypass = hash('SHA512',$shapass);
  if ($mypass!=$ur[password]) {
    error("�������,���������!");
  }
  
  if ($ur[loggedin]==0) {
    error("�˺ſ���������½!����Ҫ�Ծ�!");
  }
  

  $codepass="".$pass."".$ur[salt]."";
  $mepass = hash('SHA512',$codepass);
  
  $uppass = mysql_query("update accounts set `loggedin`=0 where name='$user'");

  if ($uppass) {
    error("�Ծȳɹ�!");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}

//���һ�
if ($_GET["act"]=="money") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
  error("�һ�������ȵ�½��");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $webmoney=$_POST[webmoney];
}
if ($webmoney=="") {
  error("��������Ϊ��!");
}
if (!Num($webmoney)) {
  error("������ֻ��Ϊ����!");
}
$mysql_usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($mysql_usql);

$money=$user[money]-$webmoney;
if ($money<0) {
  error("���ʺŵ����,���ȳ�ֵ!");
}

$xnxCash = $webmoney*$user_money;
$nxCash=$user[nxCash]+$xnxCash;

$ups = mysql_query("update `accounts` set `money`='$money',`nxCash`='$nxCash' where id='$userid'");

if ($ups) {
  $_SESSION["money"]=$money;
  error("�һ��ɹ���");
}else{
  error("ϵͳ����,����ϵGM");
}

}
//��Ǯ����
if ($_GET["act"]=="mesos") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
  error("�����ң����ȵ�½��");
}else{
  $userid=$_SESSION[userid];
  $charid=$_SESSION[charid];
  $webmoney=$_POST[webmoney];
}
if ($webmoney=="") {
  error("��������Ϊ��!");
}
if (!Num($webmoney)) {
  error("������ֻ��Ϊ����!");
}
$mysql_usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($mysql_usql);

$money=$user[money]-$webmoney;
if ($money<0) {
  error("���ʺŵ����,���ȳ�ֵ!");
}

$mysql_csql = mysql_query("select * from characters where id='$charid'",$conn);
$char = mysql_fetch_array($mysql_csql);
$mesos=$webmoney*$user_mesos;
$meso=$char[meso]+$mesos;

$upa = mysql_query("update `accounts` set `money`='$money' where id='$userid'");
$upb = mysql_query("update `characters` set `meso`='$meso' where id='$charid'");

if ($upa and $upb) {
  $_SESSION["money"]=$money;
  error("����ɹ���");
}else{
  error("ϵͳ����,����ϵGM");
}

}
//����ת��
if ($_GET[act]=="zhun") {
  if ($_SESSION[userid]=="" or $_SESSION[charid]=="") {
    error("����ת�������ȵ�½��");
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
    error ("�Ѿ��ﵽ���ת�����������ת��!");
  }
  if ($char[level]<$zhun[lv]) {
    error("�ȼ����㣬��δ��ת����");
  }
  $zmesos = $char[meso]-$zhun[mesos];
  if ($zmesos<0) {
    error("��Ǯ���㣬��δ��ת����");
  }
  $zmoney = $user[money]-$zhun[money];
  if ($zmoney<0) {
    error("����㣬��δ��ת����");
  }
$dskill = mysql_query("DELETE FROM skills WHERE characterid='$charid'");
$uprmbs = mysql_query("update `accounts` set `money`='$zmoney' where id='$userid'");
$update = mysql_query("update `characters` set `meso`='$zmesos',`level`='".$zhun[level]."',`exp`='0',`str`='".$zhun[str]."',`dex`='".$zhun[dex]."',`luk`='".$zhun[luk]."',`int`='".$zhun[int]."',`hp`='".$zhun[hp]."',`mp`='".$zhun[mp]."',`maxhp`='".$zhun[hp]."',`maxmp`='".$zhun[mp]."',`job`='0',`ap`='0',sp='0',`zhun`='".$zhun[id]."' where id='$charid'");
  if ($dskill and $uprmbs and $update) {
    $_SESSION[zhun]=$zhunid;
	$_SESSION[money]=$zmoney;
    error("ת���ɹ���");
  }else{
    error("ϵͳ����,����ϵGM");
  }
}
//��ͨ��Ʒ
if ($_GET[act]=="item") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("������Ʒ�����ȵ�½��");
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
  error("����Ҫ�������Ʒ������,�����ѡ��!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("�ʺ�����ʹ��,������������!");
}

$money = $user[mmb]-$item[itemmoney];
if ($money<0) {
  error("���ʺŵ����,���ȳ�ֵ!");
}


$lsql = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("�ô��ڵı�������,������λ�ã�");
}


$have = $item[itemhave]-$item[quantity];
if ($have<0) {
  error("����Ʒ�����꣡");
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
        error("����ɹ�,����ʣ����ȯ:".$_SESSION["money"]."��!");
      }else{
        error("ϵͳ����,����ϵGM");
      }
	}
  }
}
//����װ��
if ($_GET[act]=="items") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("������Ʒ�����ȵ�½��");
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
  error("����Ҫ�������Ʒ������,�����ѡ��!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("�ʺ�����ʹ��,������������!");
}

$money = $user[mmb]-$item[itemmoney];
if ($money<0) {
  error("���ʺŹ���ȯ����,���ȳ�ֵ!");
}

$lsql = mysql_query("select * from inventoryitems where inventorytype='1' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("�ô��ڵı�������,������λ�ã�");
}

$have = $item[itemhave]-1;
if ($have<0) {
  error("����Ʒ�����꣡");
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
        error("����ɹ�,����ʣ����ȯ:".$_SESSION["money"]."��!");
      }else{
        error("ϵͳ����,����ϵGM");
      }
	}
  }
}

//���ֹ�����

//��ͨ��Ʒ
if ($_GET[act]=="jfitem") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("������Ʒ�����ȵ�½��");
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
  error("����Ҫ�������Ʒ������,�����ѡ��!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("�ʺ�����ʹ��,������������!");
}

$jfmoney = $user[jfmoney]-$item[itemmoney];
if ($jfmoney<0) {
  error("���ʺŻ��ֲ���,�ù���ȯ����������Ʒ�ſ��Եõ�����!");
}


$lsql = mysql_query("select * from inventoryitems where inventorytype='".$item[itemtype]."' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("�ô��ڵı�������,������λ�ã�");
}


$have = $item[itemhave]-$item[quantity];
if ($have<0) {
  error("����Ʒ�����꣡");
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
        error("����ɹ�,����ʣ:".$_SESSION["jfmoney"]."����!");
      }else{
        error("ϵͳ����,����ϵGM");
      }
	}
  }
}
//����װ��
if ($_GET[act]=="jfitems") {

if ($_SESSION[userid]=="" or $_SESSION[charid]=="" or $_POST[id]=="" or $_SESSION[name]=="") {
  error("������Ʒ�����ȵ�½��");
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
  error("����Ҫ�������Ʒ������,�����ѡ��!");
}

$usql = mysql_query("select * from accounts where id='$userid'",$conn);
$user = mysql_fetch_array($usql);

if ($user['loggedin'] != "0") {
  error("�ʺ�����ʹ��,������������!");
}

$jfmoney = $user[jfmoney]-$item[itemmoney];
if ($jfmoney<0) {
  error("���ʺŻ��ֲ���,�ù���ȯ����������Ʒ�ſ��Եõ�����!");
}

$lsql = mysql_query("select * from inventoryitems where inventorytype='1' and characterid='$charid'");
$total_lion = mysql_affected_rows();
if ($total_lion>=100) {
  error("�ô��ڵı�������,������λ�ã�");
}

$have = $item[itemhave]-1;
if ($have<0) {
  error("����Ʒ�����꣡");
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
        error("����ɹ�,����ʣ:".$_SESSION["jfmoney"]."����!");
      }else{
        error("ϵͳ����,����ϵGM");
      }
	}
  }
}

echo "<script>window.location.href=\"http://".$HTTP_SERVER_VARS['HTTP_HOST']."\";</script>";

?>