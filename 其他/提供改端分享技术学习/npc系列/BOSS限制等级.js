var map1 = Array(100000005, 105070002, 800010100, 105090900, 682000001, 240020101, 240020401);
var map1name = Array("铁甲猪公园Ⅲ(蘑菇王)", "蘑菇王之墓(僵尸蘑菇王)", "天皇殿堂(蓝蘑菇王)", "被诅咒的寺院(蝙蝠怪)", "幻影森林(魔马)", "格瑞芬多森林(天鹰)", "喷火龙栖息地(肥龙)"); 
var map2 = Array(230040420, 990000900, 801040003, 220080000, 211042300, 910000001);
var map2name = Array("皮亚奴斯洞穴(鱼王)", "艾里斯王座", "日本御姐", "时间塔的本源(闹钟)", "扎昆祭台(扎昆)", "黑龙，!"); 
var chosenMap = -1;
var monsters = 0;
var bosses = 0;



importPackage(net.sf.odinms.client);

function start() {
	status = -1;
	
	action(1, 0, 0);
}

function action(mode, type, selection) {
            if (mode == -1) {
                cm.dispose();
            }
            else {
                if (status >= -1 && mode == 0) {
                
			cm.sendOk("好的,如果你想好了要做什么,我会很乐意的为你服务的..");
			cm.dispose();
			return;                    
                }
                if (mode == 1) {
			status++;
		}
		else {
			status--;
		}
               
               if (status == 0) {
                       cm.sendSimple("你好，我是BOSS级怪物便捷传送员。\r\n现在你想把谁痛扁一顿呢：\r\n#b#L0#Boss地图1#r(50级)#l #b#L1#Boss地图2#r(120级)#l");
                   }
               else if (status == 1) {
                   if (selection == 0) {
                   if (cm.getLevel() < 50){
                   cm.sendOk("美女，你等级太低了！！");
                   cm.dispose();
                   }else {
                       var selStr = "选择你的目的地.#b";
                       for (var i = 0; i < map1.length; i++) {
				selStr += "\r\n#L" + i + "#" + map1name[ i ]+"";
                       }
                       cm.sendSimple(selStr);
                       monsters = 1;
                   }
                   }
                   else if ((selection == 1)&& (cm.getLevel() >= 1)) {
                   if (cm.getLevel() < 120){
                   cm.sendOk("帅哥，你等级太低了！！");
                   cm.dispose();
                   }else {
                       var selStr = "选择你的目的地.#b";
                       for (var i = 0; i < map2.length; i++) {
                selStr += "\r\n#L" + i + "#" + map2name[ i ]+""; 
                       }
                       cm.sendSimple(selStr);
                       bosses = 1;
                   }
                   }
               }
            else if (status == 2) {
                if (monsters == 1) {
                cm.sendYesNo("你想去 #b" + map1name[selection] + "#k 吗?");
                chosenMap = selection;
                monsters = 2;
                }
                else if (bosses == 1) {
                cm.sendYesNo("你想去 #b" + map2name[selection] + "#k 吗?");
                chosenMap = selection;
                bosses = 2;
                }
                
            }
            else if (status == 3) {
                if (monsters == 2) {
                    cm.warp(map1[chosenMap], 0);
                    cm.dispose();
                }
                else if (bosses == 2) {
                    cm.warp(map2[chosenMap], 0);
                    cm.dispose();
                }

            }
         }
}