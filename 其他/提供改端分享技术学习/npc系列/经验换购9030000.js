/*
*   �����̵꣬��ǿ��  NPC
*   By: ZreHy_MS               �����Ҫ�Ķ����������޸ģ����˿����õ�~
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
        if (mode == 0) {
            cm.dispose();
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendSimple ("��ã��𾴵� #b#h ##k, ���ǻ�������ֵ��NPC����Ȩ��ʵϰGM���椡��޸ģ�����Ŀǰ�У� #e#r" + cm.getMeso() + "#k#n ð�ս��~.\r\n#r#L0##e5,000 ���� - 5,000,000 ð�ձ�#n#l\r\n#k#L1##e1,000,000 ���� - 10,000,000 ð�ձ�#n#l#k\r\n#b#L2##e5,000,000 ���� - 50,000,000 ð�ձ�#n#l#k\r\n#g#L3##e50,000,000 ���� - 100,000,000 ð�ձ�#n#l#k\r\n#d#L4##e100,000,000 ���� - 200,000,000 ð�ձ�#n#l#k\r\n#k#L5##e200,000,000 ���� - 300,000,000 ð�ձ�#n#l#k\r\n#r#L6##e300,000,000 ���� - 400,000,000 ð�ձ�#n#l#k\r\n#b#L7##e400,000,000 ���� - 500,000,000 ð�ձ�#n#l#k\r\n#g#L8##e500,000,000 ���� - 600,000,000 ð�ձ�#n#l#k\r\n#d#L9##e600,000,000 ���� - 700,000,000 ð�ձ�#n#l#k\r\n#r#L10##e700,000,000 ���� - 800,000,000 ð�ձ�#n#l#k\r\n#d#L11##e800,000,000 ��� - 900,000,000 ð�ձ�#n#l#k\r\n#k#L12##e900,000,000 ��� - 1,000,000,000 ð�ձ�#n#l#k\r\n#b#L13##e1,000,000,000 ��� - 1,100,000,000 ð�ձ�#n#l#k\r\n#g#L14##e2,000,000,000 ��� - 2,000,000,000 ð�ձ�#n#l");
        } else if (status == 1) {
            switch(selection) {
        case 0:
            if(cm.getMeso() >= 10000000){
                cm.sendOk("��ϲ�㣬������ 1,000,000 ����ֵ! .");
                cm.gainMeso(-10000000);
                cm.gainExp(1000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 10,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
        case 1: 
            if(cm.getMeso() >= 50000000){
                cm.sendOk("��ϲ�㣬������ 5,000,000 ����ֵ! .");
                cm.gainMeso(-50000000);
                cm.gainExp(5000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 50,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 2: 
            if(cm.getMeso() >= 100000000){
                cm.sendOk("��ϲ�㣬������ 10,000,000 ����ֵ! .");
                cm.gainMeso(-100000000);
                cm.gainExp(10000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 100,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 3: 
            if(cm.getMeso() >= 150000000){
                cm.sendOk("��ϲ�㣬������ 50,000,000 ����ֵ! .");
                cm.gainMeso(-150000000);
                cm.gainExp(50000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 150,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 4: 
            if(cm.getMeso() >= 200000000){
                cm.sendOk("��ϲ�㣬������ 100,000,000 ����ֵ! .");
                cm.gainMeso(-200000000);
                cm.gainNX(100000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 200,000,000 ����Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 5: 
            if(cm.getMeso() >= 300000000){
                cm.sendOk("��ϲ�㣬������ 200,000,000 ����ֵ! .");
                cm.gainMeso(-300000000);
                cm.gainExp(200000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 300,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 6: 
            if(cm.getMeso() >= 400000000){
                cm.sendOk("��ϲ�㣬������ 300,000,000 ����ֵ! .");
                cm.gainMeso(-400000000);
                cm.gainExp(300000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 400,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 7: 
            if(cm.getMeso() >= 500000000){
                 cm.sendOk("��ϲ�㣬������ 400,000,000 ����ֵ! .");
                cm.gainMeso(-500000000);
                cm.gainExp(400000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 500,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 8: 
            if(cm.getMeso() >= 600000000){
                 cm.sendOk("��ϲ�㣬������ 500,000,000 ����ֵ! .");
                cm.gainMeso(-600000000);
                cm.gainExp(500000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 600,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 9: 
            if(cm.getMeso() >= 700000000){
                 cm.sendOk("��ϲ�㣬������ 600,000,000 ����ֵ! .");
                cm.gainMeso(-700000000);
                cm.gainExp(600000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 700,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 10: 
            if(cm.getMeso() >= 800000000){
                cm.sendOk("��ϲ�㣬������ 700,000,000 ����ֵ! .");
                cm.gainMeso(-800000000);
                cm.gainExp(700000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 800,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 11: 
            if(cm.getMeso() >= 900000000){
                cm.sendOk("��ϲ�㣬������ 800,000,000 ����ֵ! .");
                cm.gainMeso(-900000000);
                cm.gainExp(800000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 900,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 12: 
            if(cm.getMeso() >= 1000000000){
                cm.sendOk("��ϲ�㣬������ 900,000,000 ����ֵ! .");
                cm.gainMeso(-1000000000);
                cm.gainExp(900000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 1,000,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 13: 
            if(cm.getMeso() >= 1100000000){
                cm.sendOk("��ϲ�㣬������ 1,000,000,000 ����ֵ! .");
                cm.gainMeso(-1100000000);
                cm.gainExp(1000000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 1,100,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
         case 14: 
            if(cm.getMeso() >= 2000000000){
                cm.sendOk("��ϲ�㣬������ 2,000,000,000 ����ֵ! .");
                cm.gainMeso(-2000000000);
                cm.gainExp(2000000000);
                cm.dispose();
            }else{
                cm.sendOk("��û�� 2,000,000,000 ð�ձң��Ҳ��ܸ��㻻��~.");
                cm.dispose();
            }
            break;
            }
        }
    }
}