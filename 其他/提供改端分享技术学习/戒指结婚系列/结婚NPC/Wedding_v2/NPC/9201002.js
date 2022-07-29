/*
@    Author : Snow
@
@    NPC = NAME
@    Map =  MAP
@    NPC MapId = MAPID
@    Function = Rebirth Player
@
*/

var status = 0;

function start() {
    status = -1;
    action(1, 0, 0);
}
function action(mode, type, selection) {
         if (mode == -1) {//ExitChat
        cm.dispose();
 } else { 
  if (status >= 2 && mode == 0) { 
   cm.sendOk("欢迎你们!我看你们是天上龙凤.想要得到结婚戒指,你们必须要在装备栏里空出空格.你们这对,准备好 #b结婚#k 了吗?"); 
   cm.dispose(); 
   return; 
  } 
        if (mode == 1)
            status++;
        else
            status--;
        
                 if (status == 0) {
        cm.sendYesNo("我将带你们进入结婚的礼堂,那里有许多婚礼用的盒子! 打开那些盒子将获得一生的幸福! 如果你想离开请告诉Robin即可!");
    } else if (status == 1) {
        cm.warp(680000401,0);
        cm.dispose();
        }            
    }
}