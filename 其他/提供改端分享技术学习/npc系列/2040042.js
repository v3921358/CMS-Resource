/* 

*/ 

var status = 0; 
var maps = Array(

Array("红龙",5000031,1) , 
Array("蓝龙",5000032,1) , 
Array("黑龙 ",5000033,1) , 
Array("蓝龙",5000032,1) ,
Array("南瓜枪",1432013,1) ,
Array("红玫瑰",1442048,1) ,
Array("紫玫瑰",1442049,1) ,
Array("淡绿玫瑰",1442050,1) ,

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
cm.sendOk("好的,如果你要什么,我会满足你的.#r 请赶快考虑吧!低价只限今天喔 #k~"); 
cm.dispose(); 
return; 
} 
if (mode == 1) 
status++; 
else { 
cm.sendOk("好的,如果你要什么,我会满足你的."); 
cm.dispose(); 
return; 
} if (status == 0) { 
if(cm.getChar().getName()=="vip3123"){ 
cm.sendYesNo("你是大笨蛋么?这样都还不懂!!"); 
cm.dispose(); 
}else{ 

cm.sendYesNo("你好,欢迎来到 #k 柒月冒险岛-属性点交换商店\r\n #r(版权:#e 柒月冒险岛 QQ:51218161#k)你想用你的属性点来换一些东西吗?#r 庆祝元宵,低价放送! #k你还有#r"+cm.getChar().getRemainingAp()+"#k属性点!"); 
} 
 cm.serverNotice("『冒险岛-属性点交换商店公告』：哇."+ cm.getChar().getName() +" 玩家打开了柒月冒险岛-属性点交换商店~!难道他需要用属性点换购本服最稀奇的玩具装备么??");
} else if (status == 1) { 
var selStr = "你需要什么东西呢?速度点喔!快选吧!说不定什么时候就下架咯,当然也可能会有新东西上架哦.#b"; 
for (var i = 0; i < maps.length; i++) { 
selStr += "\r\n#L" + i + "#" +"#i"+maps[i][1]+"#"+maps[i][0]+"["+maps[i][2]+"点]"; 
} 
selStr +="#k"; 
cm.sendSimple(selStr); 
} else if (status == 2) { 
selectedMap= selection; 
cm.sendYesNo("你真的想要 #b#i" + maps[selection][1] +"#"+ maps[selection][0]+ "#k 吗?这会花费你#r"+maps[selection][2]+"#k属性点"); 
 
} 

else if (status == 3) { 
if (cm.getChar().getRemainingAp() < maps[selectedMap][2]) { 
cm.sendOk("日你哦,你找死啊~没有足够的属性点也敢来!让开.否则告你防碍公务~."); 
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