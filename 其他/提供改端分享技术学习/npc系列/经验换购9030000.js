/*
*   交换商店，增强版  NPC
*   By: ZreHy_MS               如果需要改动，请自行修改，本人开服用的~
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
            cm.sendSimple ("你好，尊敬的 #b#h ##k, 我是换购经验值的NPC，版权（实习GM【妞妞】修改），你目前有： #e#r" + cm.getMeso() + "#k#n 冒险金币~.\r\n#r#L0##e5,000 经验 - 5,000,000 冒险币#n#l\r\n#k#L1##e1,000,000 经验 - 10,000,000 冒险币#n#l#k\r\n#b#L2##e5,000,000 经验 - 50,000,000 冒险币#n#l#k\r\n#g#L3##e50,000,000 经验 - 100,000,000 冒险币#n#l#k\r\n#d#L4##e100,000,000 经验 - 200,000,000 冒险币#n#l#k\r\n#k#L5##e200,000,000 经验 - 300,000,000 冒险币#n#l#k\r\n#r#L6##e300,000,000 经验 - 400,000,000 冒险币#n#l#k\r\n#b#L7##e400,000,000 经验 - 500,000,000 冒险币#n#l#k\r\n#g#L8##e500,000,000 经验 - 600,000,000 冒险币#n#l#k\r\n#d#L9##e600,000,000 经验 - 700,000,000 冒险币#n#l#k\r\n#r#L10##e700,000,000 经验 - 800,000,000 冒险币#n#l#k\r\n#d#L11##e800,000,000 点卷 - 900,000,000 冒险币#n#l#k\r\n#k#L12##e900,000,000 点卷 - 1,000,000,000 冒险币#n#l#k\r\n#b#L13##e1,000,000,000 点卷 - 1,100,000,000 冒险币#n#l#k\r\n#g#L14##e2,000,000,000 点卷 - 2,000,000,000 冒险币#n#l");
        } else if (status == 1) {
            switch(selection) {
        case 0:
            if(cm.getMeso() >= 10000000){
                cm.sendOk("恭喜你，你获得了 1,000,000 经验值! .");
                cm.gainMeso(-10000000);
                cm.gainExp(1000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 10,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
        case 1: 
            if(cm.getMeso() >= 50000000){
                cm.sendOk("恭喜你，你获得了 5,000,000 经验值! .");
                cm.gainMeso(-50000000);
                cm.gainExp(5000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 50,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 2: 
            if(cm.getMeso() >= 100000000){
                cm.sendOk("恭喜你，你获得了 10,000,000 经验值! .");
                cm.gainMeso(-100000000);
                cm.gainExp(10000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 100,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 3: 
            if(cm.getMeso() >= 150000000){
                cm.sendOk("恭喜你，你获得了 50,000,000 经验值! .");
                cm.gainMeso(-150000000);
                cm.gainExp(50000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 150,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 4: 
            if(cm.getMeso() >= 200000000){
                cm.sendOk("恭喜你，你获得了 100,000,000 经验值! .");
                cm.gainMeso(-200000000);
                cm.gainNX(100000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 200,000,000 点卷，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 5: 
            if(cm.getMeso() >= 300000000){
                cm.sendOk("恭喜你，你获得了 200,000,000 经验值! .");
                cm.gainMeso(-300000000);
                cm.gainExp(200000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 300,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 6: 
            if(cm.getMeso() >= 400000000){
                cm.sendOk("恭喜你，你获得了 300,000,000 经验值! .");
                cm.gainMeso(-400000000);
                cm.gainExp(300000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 400,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 7: 
            if(cm.getMeso() >= 500000000){
                 cm.sendOk("恭喜你，你获得了 400,000,000 经验值! .");
                cm.gainMeso(-500000000);
                cm.gainExp(400000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 500,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 8: 
            if(cm.getMeso() >= 600000000){
                 cm.sendOk("恭喜你，你获得了 500,000,000 经验值! .");
                cm.gainMeso(-600000000);
                cm.gainExp(500000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 600,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 9: 
            if(cm.getMeso() >= 700000000){
                 cm.sendOk("恭喜你，你获得了 600,000,000 经验值! .");
                cm.gainMeso(-700000000);
                cm.gainExp(600000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 700,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 10: 
            if(cm.getMeso() >= 800000000){
                cm.sendOk("恭喜你，你获得了 700,000,000 经验值! .");
                cm.gainMeso(-800000000);
                cm.gainExp(700000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 800,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 11: 
            if(cm.getMeso() >= 900000000){
                cm.sendOk("恭喜你，你获得了 800,000,000 经验值! .");
                cm.gainMeso(-900000000);
                cm.gainExp(800000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 900,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 12: 
            if(cm.getMeso() >= 1000000000){
                cm.sendOk("恭喜你，你获得了 900,000,000 经验值! .");
                cm.gainMeso(-1000000000);
                cm.gainExp(900000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 1,000,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 13: 
            if(cm.getMeso() >= 1100000000){
                cm.sendOk("恭喜你，你获得了 1,000,000,000 经验值! .");
                cm.gainMeso(-1100000000);
                cm.gainExp(1000000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 1,100,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
         case 14: 
            if(cm.getMeso() >= 2000000000){
                cm.sendOk("恭喜你，你获得了 2,000,000,000 经验值! .");
                cm.gainMeso(-2000000000);
                cm.gainExp(2000000000);
                cm.dispose();
            }else{
                cm.sendOk("你没有 2,000,000,000 冒险币，我不能给你换购~.");
                cm.dispose();
            }
            break;
            }
        }
    }
}