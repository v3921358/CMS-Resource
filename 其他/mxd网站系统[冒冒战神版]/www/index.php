<?

//��������=================================

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
//�������=================================

$Data_host = ("localhost");	//���ݿ�����

$Data_user = ("root");	//���ݿ��ʺ�

$Data_pass = ("root");	//���ݿ�����

$Data_name = ("odinms");	//���ݿ���

$Site_name = ("ðð��");	//����������

$Site_host = ("http://127.0.0.1/");	//����������

$Site_port = ("80");	//�������˿�

$aced_user = ("0");	

$name_money = ("0");    //

//���������ļ������\page\Mean\config.php ��������

$conn = @mysql_connect ($Data_host, $Data_user, $Data_pass) or die ("ϵͳ����ά���С�����");
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