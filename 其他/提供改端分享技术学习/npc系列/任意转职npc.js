/* [NPC]
    Job NPC ID 9010009
    Final  by aexr
    @RageZone
*/

importPackage(net.sf.odinms.client);


var status = 0;
var jobName;
var job;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == -1) {
        cm.sendOk("#d好的,如果你改变想法随时可以告诉我!\r\n#r祝你好运!");
        cm.dispose();
    } else {
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
cm.sendSimple("这里可以任意转职，你想成为：\r\n#r #L1#战士#l   #L11#魔法师#l   #L21#弓箭手#l   #L28#飞侠#l   #L35#海盗#l \r\n#b #L2#剑客#l   #L5#准骑士#l   #L8#枪战士#l \r\n#r #L12#火毒法师#l   #L15#冰雷法师#l   #L18#牧师#l \r\n#e #L22#猎人#l   #L25#弩弓手#l \r\n#d #L29#刺客#l   #L32#侠客#l \r\n#g #L36#拳手#l   #L39#火枪手#l \r\n#b #L3#勇士#l   #L6#骑士#l   #L9#龙骑士#l \r\n#r #L13#火毒巫师#l   #L16#冰雷巫师#l   #L19#祭司#l \r\n#e #L23#射手#l   #L26#游侠#l \r\n#d #L30#无影人#l   #L33#独行客#l \r\n#g #L37#斗士#l   #L40#大副#l \r\n#b #L4#英雄#l   #L7#圣骑士#l   #L10#黑骑士#l \r\n#r #L14#火毒魔导士#l   #L17#冰雷魔导士#l   #L20#主教#l \r\n#e #L24#神箭手#l   #L27#箭神#l \r\n#d #L31#隐士#l #L34#侠盗#l \r\n#g #L38#冲锋队长#l   #L41#船长#l \r\n#r #L0#新手#l   #L42#管理员#l   #L43#超级管理员#l");


        } else if (status == 1) {
            if (selection == 0) {
                jobName = "新手";
                job = net.sf.odinms.client.MapleJob.BEGINNER;
            }
            if (selection == 1) {
                jobName = "战士";
                job = net.sf.odinms.client.MapleJob.WARRIOR;
            }
            if (selection == 2) {
                jobName = "剑客";
                job = net.sf.odinms.client.MapleJob.FIGHTER;
            }
            if (selection == 3) {
                jobName = "勇士";
                job = net.sf.odinms.client.MapleJob.CRUSADER;
            }
            if (selection == 4) {
                jobName = "英雄";
                job = net.sf.odinms.client.MapleJob.HERO;
            }
            if (selection == 5) {
                jobName = "准骑士";
                job = net.sf.odinms.client.MapleJob.PAGE;
            }
            if (selection == 6) {
                jobName = "骑士";
                job = net.sf.odinms.client.MapleJob.WHITEKNIGHT;
            }
            if (selection == 7) {
                jobName = "圣骑士";
                job = net.sf.odinms.client.MapleJob.PALADIN;
            }
            if (selection == 8) {
                jobName = "枪战士";
                job = net.sf.odinms.client.MapleJob.SPEARMAN;
            }
            if (selection == 9) {
                jobName = "龙骑士";
                job = net.sf.odinms.client.MapleJob.DRAGONKNIGHT;
            }
            if (selection == 10) {
                jobName = "黑骑士";
                job = net.sf.odinms.client.MapleJob.DARKKNIGHT;
            }
            if (selection == 11) {
                jobName = "魔法师";
                job = net.sf.odinms.client.MapleJob.MAGICIAN;
            }
            if (selection == 12) {
                jobName = "火毒法师";
                job = net.sf.odinms.client.MapleJob.FP_WIZARD;
            }
            if (selection == 13) {
                jobName = "火毒巫师";
                job = net.sf.odinms.client.MapleJob.FP_MAGE;
            }
            if (selection == 14) {
                jobName = "火毒魔导士";
                job = net.sf.odinms.client.MapleJob.FP_ARCHMAGE;
            }
            if (selection == 15) {
                jobName = "冰雷法师";
                job = net.sf.odinms.client.MapleJob.IL_WIZARD;
            }
            if (selection == 16) {
                jobName = "冰雷巫师";
                job = net.sf.odinms.client.MapleJob.IL_MAGE;
            }
            if (selection == 17) {
                jobName = "冰雷魔导士";
                job = net.sf.odinms.client.MapleJob.IL_ARCHMAGE;
            }
            if (selection == 18) {
                jobName = "牧师";
                job = net.sf.odinms.client.MapleJob.CLERIC;
            }
            if (selection == 19) {
                jobName = "祭司";
                job = net.sf.odinms.client.MapleJob.PRIEST;
            }
            if (selection == 20) {
                jobName = "主教";
                job = net.sf.odinms.client.MapleJob.BISHOP;
            }
            if (selection == 21) {
                jobName = "弓箭手";
                job = net.sf.odinms.client.MapleJob.BOWMAN;
            }
            if (selection == 22) {
                jobName = "猎人";
                job = net.sf.odinms.client.MapleJob.HUNTER;
            }
            if (selection == 23) {
                jobName = "射手";
                job = net.sf.odinms.client.MapleJob.RANGER;
            }
            if (selection == 24) {
                jobName = "神箭手";
                job = net.sf.odinms.client.MapleJob.BOWMASTER;
            }
            if (selection == 25) {
                jobName = "弩弓手";
                job = net.sf.odinms.client.MapleJob.CROSSBOWMAN;
            }
            if (selection == 26) {
                jobName = "游侠";
                job = net.sf.odinms.client.MapleJob.SNIPER;
            }
            if (selection == 27) {
                jobName = "箭神";
                job = net.sf.odinms.client.MapleJob.MARKSMAN;
            }
            if (selection == 28) {
                jobName = "飞侠";
                job = net.sf.odinms.client.MapleJob.THIEF;
            }
            if (selection == 29) {
                jobName = "刺客";
                job = net.sf.odinms.client.MapleJob.ASSASSIN;
            }
            if (selection == 30) {
                jobName = "无影人";
                job = net.sf.odinms.client.MapleJob.HERMIT;
            }
            if (selection == 31) {
                jobName = "隐士";
                job = net.sf.odinms.client.MapleJob.NIGHTLORD;
            }
            if (selection == 32) {
                jobName = "侠客";
                job = net.sf.odinms.client.MapleJob.BANDIT;
            }
            if (selection == 33) {
                jobName = "独行客";
                job = net.sf.odinms.client.MapleJob.CHIEFBANDIT;
            }
            if (selection == 34) {
                jobName = "侠盗";
                job = net.sf.odinms.client.MapleJob.SHADOWER;
            }
            if (selection == 35) {
                jobName = "海盗";
                job = net.sf.odinms.client.MapleJob.PIRATE;
            }
            if (selection == 36) {
                jobName = "拳手";
                job = net.sf.odinms.client.MapleJob.BRAWLER;
            }
            if (selection == 37) {
                jobName = "斗士";
                job = net.sf.odinms.client.MapleJob.MARAUDER;
            }
            if (selection == 38) {
                jobName = "冲锋队长";
                job = net.sf.odinms.client.MapleJob.BUCCANEER;
            }
            if (selection == 39) {
                jobName = "火枪手";
                job = net.sf.odinms.client.MapleJob.GUNSLINGER;
            }
            if (selection == 40) {
                jobName = "大副";
                job = net.sf.odinms.client.MapleJob.OUTLAW;
            }
            if (selection == 41) {
                jobName = "船长";
                job = net.sf.odinms.client.MapleJob.CORSAIR;
            }
            if (selection == 42) {
                jobName = "管理员";
                job = net.sf.odinms.client.MapleJob.GM;
            }
            if (selection == 43) {
                jobName = "超级管理员";
                job = net.sf.odinms.client.MapleJob.SUPERGM;
            }
            cm.sendYesNo("#d你想成为: #r[" + jobName + "]#k #d吗?");
                        
                        
        } else if (status == 2) {
            if (job == net.sf.odinms.client.MapleJob.WARRIOR && cm.c.getPlayer().getStr() < 1) {
                cm.sendOk("#d你没有符合最小需求: #r[1 力量]#k #d!");
                cm.dispose();
            } else {
                cm.changeJob(job);

                cm.sendOk("#d你去吧,希望你能好好运用,也许不久的未来还能见到你!");
                cm.dispose();
            }
            
          } else {
            cm.dispose();
        }  

    }
}
