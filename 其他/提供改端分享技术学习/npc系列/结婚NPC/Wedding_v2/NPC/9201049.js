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
   cm.sendOk("好的,希望我这份精美的告别礼能让你喜欢!"); 
   cm.dispose(); 
   return; 
  } 
        if (mode == 1)
            status++;
        else
            status--;
        
                 if (status == 0) {
        cm.sendYesNo("婚礼已经快接近尾声了, 最后,你们将获得我赠送的一点小小的礼物:增加220点魔法攻击的奶酪100个,增加140点物理攻击的八爪10个!希望这些物品对你们今后的战斗中能发挥作用,再见!");
   cm.gainItem(2022273,100); 
   cm.gainItem(2022282,10); 
    } else if (status == 1) {
        cm.warp(680000000,0);
        cm.dispose();
        }            
    }
}