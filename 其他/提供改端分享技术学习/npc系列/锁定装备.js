/*
======================================
 ���Ķ˼���  ����ռ���ʽ����
======================================
*/
*
-- MrCoffee JavaScript --
        NPC�ű� 
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
            cm.sendOk("Ϊ�˰���������˹�����Լ���װ��,�ҷǳ���æ��");
            cm.dispose();
            return;
        }
    if (mode == 1)
            status++;
    else
            status--;
        if (status == 0) {
            cm.sendGetNumber("������װ����˳������, �ҽ�Ϊ��������. \r\n װ��������װ���޷�����,�޷����� �����ʺ����뱻����֪��Ҳ���¡�\r\n #b[ע�⣺�˹���ֻ��ʹ����װ������]#k",1,1,100);
        } else if (status == 1) {
            slot = selection;
            item = cm.getChar().itemid(slot);
            if (item==0){
                cm.sendOk("���������Ʒλ��û��װ��!")
                cm.dispose();
            }
            else
                cm.sendYesNo("��ȷ��Ҫ�����������װ����\r\n#i"+item+"# #b#t"+item+"#")
        } else if (status == 2) {
            cm.getChar().lockitem(slot,true)
            cm.sendOk("װ����#i"+item+"##b#t"+item+"##k �����ɹ�!");
            cm.dispose();
        }
    }
}  
