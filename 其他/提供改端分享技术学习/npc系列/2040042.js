/* 

*/ 

var status = 0; 
var maps = Array(

Array("����",5000031,1) , 
Array("����",5000032,1) , 
Array("���� ",5000033,1) , 
Array("����",5000032,1) ,
Array("�Ϲ�ǹ",1432013,1) ,
Array("��õ��",1442048,1) ,
Array("��õ��",1442049,1) ,
Array("����õ��",1442050,1) ,

); 
var selectedMap = -1; 
function start() { 
status = -1; 
action(1, 0, 0); 
} 
function action(mode, type, selection) { 

if (mode == -1) { 
cm.dispose(); 
} else { 
if (status >= 3 && mode == 0) { 
cm.sendOk("�õ�,�����Ҫʲô,�һ��������.#r ��Ͽ쿼�ǰ�!�ͼ�ֻ�޽���� #k~"); 
cm.dispose(); 
return; 
} 
if (mode == 1) 
status++; 
else { 
cm.sendOk("�õ�,�����Ҫʲô,�һ��������."); 
cm.dispose(); 
return; 
} if (status == 0) { 
if(cm.getChar().getName()=="vip3123"){ 
cm.sendYesNo("���Ǵ󱿵�ô?������������!!"); 
cm.dispose(); 
}else{ 

cm.sendYesNo("���,��ӭ���� #k ����ð�յ�-���Ե㽻���̵�\r\n #r(��Ȩ:#e ����ð�յ� QQ:51218161#k)������������Ե�����һЩ������?#r ��ףԪ��,�ͼ۷���! #k�㻹��#r"+cm.getChar().getRemainingAp()+"#k���Ե�!"); 
} 
 cm.serverNotice("��ð�յ�-���Ե㽻���̵깫�桻����."+ cm.getChar().getName() +" ��Ҵ�������ð�յ�-���Ե㽻���̵�~!�ѵ�����Ҫ�����Ե㻻��������ϡ������װ��ô??");
} else if (status == 1) { 
var selStr = "����Ҫʲô������?�ٶȵ��!��ѡ��!˵����ʲôʱ����¼ܿ�,��ȻҲ���ܻ����¶����ϼ�Ŷ.#b"; 
for (var i = 0; i < maps.length; i++) { 
selStr += "\r\n#L" + i + "#" +"#i"+maps[i][1]+"#"+maps[i][0]+"["+maps[i][2]+"��]"; 
} 
selStr +="#k"; 
cm.sendSimple(selStr); 
} else if (status == 2) { 
selectedMap= selection; 
cm.sendYesNo("�������Ҫ #b#i" + maps[selection][1] +"#"+ maps[selection][0]+ "#k ��?��Ứ����#r"+maps[selection][2]+"#k���Ե�"); 
 
} 

else if (status == 3) { 
if (cm.getChar().getRemainingAp() < maps[selectedMap][2]) { 
cm.sendOk("����Ŷ,��������~û���㹻�����Ե�Ҳ����!�ÿ�.��������������~."); 
cm.dispose(); 
} else { 
cm.getChar().setRemainingAp (cm.getChar().getRemainingAp() - maps[selectedMap][2]); 
cm.gainItem(maps[selectedMap][1],1); 
var statup = new java.util.ArrayList(); 

statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(cm.getChar().getRemainingAp()))); 
cm.getChar().getClient().getSession().write(net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup)); 

cm.dispose(); 
} 

} 
} 
}