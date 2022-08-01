<?

//基本设置=================================

session_start();

define("phppage", true);

function error($msg) {
  echo ("<style>html {display:none}</style><script>window.alert(\"$msg\");history.go(-1)</script>");
  exit;
}
function isAlNum($str) {
	if(eregi("[^0-9a-zA-Z]",$str))
	return 0;return 1;
}
function Num($str) {
  if(eregi("[^0-9]",$str))
  return 0;return 1;
}
//相关设置=================================

$Data_host = ("localhost");	//数据库主机

$Data_user = ("root");	//数据库帐号

$Data_pass = ("root");	//数据库密码

$Data_name = ("odinms");	//数据库名

$Site_name = ("冒冒岛");	//服务器名称

$Site_host = ("http://127.0.0.1/");	//服务器主机

$Site_port = ("80");	//服务器端口

$aced_user = ("0");	

$name_money = ("0");    //

//其他设置文件请进入\page\Mean\config.php 进行设置

$conn = @mysql_connect ($Data_host, $Data_user, $Data_pass) or die ("系统正在维护中。。。");
mysql_query("set names 'gbk'");
mysql_select_db ($Data_name);

if(!isset($_GET['page'])){
  include ("page/index.php");
}else{
  $file = ("page/".$_GET['page'].".php");
  if (file_exists($file)){
    include ($file);
  }else{
    include ("page/index.php");
  }
}

mysql_close();
?>