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
	if (mode == -1) {
		cm.dispose();
	} else {
		if (mode == 0 && status == 0) {
			cm.dispose();
			return;
		}
		if (mode == 1)
			status++;
		else
			status--;
		if (status == 0) {
        cm.sendYesNo("���,�ҿ��Խ�������ȥ�����. һ�����ǽ�ȥ,���ｫ���Ծ��л���. һ������׼���ú�,��������ʦ,���������ȥ����.����㲻С���ߴ�ط���,�벻�õ���, ������� Debbie ���Խ��㴫�ͳ���! ף������ÿ���!");
} else if (status == 1) {
        cm.warp(680000210,0);
        cm.dispose();
        }            
    }
}