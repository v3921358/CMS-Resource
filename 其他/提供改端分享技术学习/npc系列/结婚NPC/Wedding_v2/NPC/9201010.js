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
   cm.sendOk("�Ǻ�,�Ҳ�����������������İ�. ף������ÿ���,�������Ҫ�뿪����,�ҽ�Ϊ����׼����һ�ݷǳ������������!"); 
   cm.dispose(); 
   return; 
  } 
        if (mode == 1)
            status++;
        else
            status--;
        
                 if (status == 0) {
        cm.sendYesNo("�����Ѿ��������˰�? ��ô�������ǳ�ȥ��! �������뿪�����Ժ�ͻ��յ����͸����ǵ�С�������.");
    } else if (status == 1) {
        cm.warp(680000500,0);
        cm.dispose();
        }            
    }
}