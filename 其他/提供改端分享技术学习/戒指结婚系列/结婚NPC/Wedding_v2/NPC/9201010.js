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
   cm.sendOk("呵呵,我猜你们是来这里照相的吧. 祝你们玩得开心,如果你们要离开这里,我将为你们准备了一份非常精美的礼物喔!"); 
   cm.dispose(); 
   return; 
  } 
        if (mode == 1)
            status++;
        else
            status--;
        
                 if (status == 0) {
        cm.sendYesNo("你们已经照完像了吧? 那么我送你们出去吧! 当你们离开这里以后就会收到我送给你们的小礼物了喔.");
    } else if (status == 1) {
        cm.warp(680000500,0);
        cm.dispose();
        }            
    }
}