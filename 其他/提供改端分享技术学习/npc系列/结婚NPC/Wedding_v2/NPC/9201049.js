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
   cm.sendOk("�õ�,ϣ������ݾ����ĸ����������ϲ��!"); 
   cm.dispose(); 
   return; 
  } 
        if (mode == 1)
            status++;
        else
            status--;
        
                 if (status == 0) {
        cm.sendYesNo("�����Ѿ���ӽ�β����, ���,���ǽ���������͵�һ��СС������:����220��ħ������������100��,����140���������İ�צ10��!ϣ����Щ��Ʒ�����ǽ���ս�����ܷ�������,�ټ�!");
   cm.gainItem(2022273,100); 
   cm.gainItem(2022282,10); 
    } else if (status == 1) {
        cm.warp(680000000,0);
        cm.dispose();
        }            
    }
}