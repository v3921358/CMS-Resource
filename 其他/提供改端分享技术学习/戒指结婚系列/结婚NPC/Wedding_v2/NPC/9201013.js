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
        cm.sendYesNo("你好,我可以将你们送去大教堂. 一旦你们进去,那里将可以举行婚礼. 一旦你们准备好后,可以找牧师,他会带你们去照相.如果你不小心走错地方了,请不用担心, 在里面的 Debbie 可以将你传送出来! 祝你们玩得开心!");
} else if (status == 1) {
        cm.warp(680000210,0);
        cm.dispose();
        }            
    }
}