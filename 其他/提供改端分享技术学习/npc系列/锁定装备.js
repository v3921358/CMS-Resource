/*
======================================
 囧囧改端技术  囧囧收集正式发布
======================================
*/
*
-- MrCoffee JavaScript --
        NPC脚本 
-------------------------
   MrCoffee MapleStory
----- Version Info ------
     Version - 1.0.0 
-------------------------
*/
importPackage(net.sf.odinms.client);
var slot;
var item;
var qty;
function start() {
    status = -1;
    action(1, 0, 0);
}
function action(mode, type, selection) {
    if (mode == -1) {
        cm.dispose();
    } else {
        if (status <= 0 && mode == 0) {
            cm.dispose();
            return;
        } else if (status >= 1 && mode == 0) {
            cm.sendOk("为了帮助更多的人管理好自己的装备,我非常的忙！");
            cm.dispose();
            return;
        }
    if (mode == 1)
            status++;
    else
            status--;
        if (status == 0) {
            cm.sendGetNumber("请输入装备的顺序数字, 我将为你锁定它. \r\n 装备锁定后装备无法交易,无法丢弃 就算帐号密码被别人知道也不怕。\r\n #b[注意：此功能只可使用与装备栏！]#k",1,1,100);
        } else if (status == 1) {
            slot = selection;
            item = cm.getChar().itemid(slot);
            if (item==0){
                cm.sendOk("你输入的物品位置没有装备!")
                cm.dispose();
            }
            else
                cm.sendYesNo("你确定要锁定下面这件装备吗？\r\n#i"+item+"# #b#t"+item+"#")
        } else if (status == 2) {
            cm.getChar().lockitem(slot,true)
            cm.sendOk("装备：#i"+item+"##b#t"+item+"##k 锁定成功!");
            cm.dispose();
        }
    }
}  
