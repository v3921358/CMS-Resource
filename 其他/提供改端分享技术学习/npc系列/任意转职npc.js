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
        cm.sendOk("#d�õ�,�����ı��뷨��ʱ���Ը�����!\r\n#rף�����!");
        cm.dispose();
    } else {
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
cm.sendSimple("�����������תְ�������Ϊ��\r\n#r #L1#սʿ#l   #L11#ħ��ʦ#l   #L21#������#l   #L28#����#l   #L35#����#l \r\n#b #L2#����#l   #L5#׼��ʿ#l   #L8#ǹսʿ#l \r\n#r #L12#�𶾷�ʦ#l   #L15#���׷�ʦ#l   #L18#��ʦ#l \r\n#e #L22#����#l   #L25#����#l \r\n#d #L29#�̿�#l   #L32#����#l \r\n#g #L36#ȭ��#l   #L39#��ǹ��#l \r\n#b #L3#��ʿ#l   #L6#��ʿ#l   #L9#����ʿ#l \r\n#r #L13#����ʦ#l   #L16#������ʦ#l   #L19#��˾#l \r\n#e #L23#����#l   #L26#����#l \r\n#d #L30#��Ӱ��#l   #L33#���п�#l \r\n#g #L37#��ʿ#l   #L40#��#l \r\n#b #L4#Ӣ��#l   #L7#ʥ��ʿ#l   #L10#����ʿ#l \r\n#r #L14#��ħ��ʿ#l   #L17#����ħ��ʿ#l   #L20#����#l \r\n#e #L24#�����#l   #L27#����#l \r\n#d #L31#��ʿ#l #L34#����#l \r\n#g #L38#���ӳ�#l   #L41#����#l \r\n#r #L0#����#l   #L42#����Ա#l   #L43#��������Ա#l");


        } else if (status == 1) {
            if (selection == 0) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.BEGINNER;
            }
            if (selection == 1) {
                jobName = "սʿ";
                job = net.sf.odinms.client.MapleJob.WARRIOR;
            }
            if (selection == 2) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.FIGHTER;
            }
            if (selection == 3) {
                jobName = "��ʿ";
                job = net.sf.odinms.client.MapleJob.CRUSADER;
            }
            if (selection == 4) {
                jobName = "Ӣ��";
                job = net.sf.odinms.client.MapleJob.HERO;
            }
            if (selection == 5) {
                jobName = "׼��ʿ";
                job = net.sf.odinms.client.MapleJob.PAGE;
            }
            if (selection == 6) {
                jobName = "��ʿ";
                job = net.sf.odinms.client.MapleJob.WHITEKNIGHT;
            }
            if (selection == 7) {
                jobName = "ʥ��ʿ";
                job = net.sf.odinms.client.MapleJob.PALADIN;
            }
            if (selection == 8) {
                jobName = "ǹսʿ";
                job = net.sf.odinms.client.MapleJob.SPEARMAN;
            }
            if (selection == 9) {
                jobName = "����ʿ";
                job = net.sf.odinms.client.MapleJob.DRAGONKNIGHT;
            }
            if (selection == 10) {
                jobName = "����ʿ";
                job = net.sf.odinms.client.MapleJob.DARKKNIGHT;
            }
            if (selection == 11) {
                jobName = "ħ��ʦ";
                job = net.sf.odinms.client.MapleJob.MAGICIAN;
            }
            if (selection == 12) {
                jobName = "�𶾷�ʦ";
                job = net.sf.odinms.client.MapleJob.FP_WIZARD;
            }
            if (selection == 13) {
                jobName = "����ʦ";
                job = net.sf.odinms.client.MapleJob.FP_MAGE;
            }
            if (selection == 14) {
                jobName = "��ħ��ʿ";
                job = net.sf.odinms.client.MapleJob.FP_ARCHMAGE;
            }
            if (selection == 15) {
                jobName = "���׷�ʦ";
                job = net.sf.odinms.client.MapleJob.IL_WIZARD;
            }
            if (selection == 16) {
                jobName = "������ʦ";
                job = net.sf.odinms.client.MapleJob.IL_MAGE;
            }
            if (selection == 17) {
                jobName = "����ħ��ʿ";
                job = net.sf.odinms.client.MapleJob.IL_ARCHMAGE;
            }
            if (selection == 18) {
                jobName = "��ʦ";
                job = net.sf.odinms.client.MapleJob.CLERIC;
            }
            if (selection == 19) {
                jobName = "��˾";
                job = net.sf.odinms.client.MapleJob.PRIEST;
            }
            if (selection == 20) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.BISHOP;
            }
            if (selection == 21) {
                jobName = "������";
                job = net.sf.odinms.client.MapleJob.BOWMAN;
            }
            if (selection == 22) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.HUNTER;
            }
            if (selection == 23) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.RANGER;
            }
            if (selection == 24) {
                jobName = "�����";
                job = net.sf.odinms.client.MapleJob.BOWMASTER;
            }
            if (selection == 25) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.CROSSBOWMAN;
            }
            if (selection == 26) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.SNIPER;
            }
            if (selection == 27) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.MARKSMAN;
            }
            if (selection == 28) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.THIEF;
            }
            if (selection == 29) {
                jobName = "�̿�";
                job = net.sf.odinms.client.MapleJob.ASSASSIN;
            }
            if (selection == 30) {
                jobName = "��Ӱ��";
                job = net.sf.odinms.client.MapleJob.HERMIT;
            }
            if (selection == 31) {
                jobName = "��ʿ";
                job = net.sf.odinms.client.MapleJob.NIGHTLORD;
            }
            if (selection == 32) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.BANDIT;
            }
            if (selection == 33) {
                jobName = "���п�";
                job = net.sf.odinms.client.MapleJob.CHIEFBANDIT;
            }
            if (selection == 34) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.SHADOWER;
            }
            if (selection == 35) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.PIRATE;
            }
            if (selection == 36) {
                jobName = "ȭ��";
                job = net.sf.odinms.client.MapleJob.BRAWLER;
            }
            if (selection == 37) {
                jobName = "��ʿ";
                job = net.sf.odinms.client.MapleJob.MARAUDER;
            }
            if (selection == 38) {
                jobName = "���ӳ�";
                job = net.sf.odinms.client.MapleJob.BUCCANEER;
            }
            if (selection == 39) {
                jobName = "��ǹ��";
                job = net.sf.odinms.client.MapleJob.GUNSLINGER;
            }
            if (selection == 40) {
                jobName = "��";
                job = net.sf.odinms.client.MapleJob.OUTLAW;
            }
            if (selection == 41) {
                jobName = "����";
                job = net.sf.odinms.client.MapleJob.CORSAIR;
            }
            if (selection == 42) {
                jobName = "����Ա";
                job = net.sf.odinms.client.MapleJob.GM;
            }
            if (selection == 43) {
                jobName = "��������Ա";
                job = net.sf.odinms.client.MapleJob.SUPERGM;
            }
            cm.sendYesNo("#d�����Ϊ: #r[" + jobName + "]#k #d��?");
                        
                        
        } else if (status == 2) {
            if (job == net.sf.odinms.client.MapleJob.WARRIOR && cm.c.getPlayer().getStr() < 1) {
                cm.sendOk("#d��û�з�����С����: #r[1 ����]#k #d!");
                cm.dispose();
            } else {
                cm.changeJob(job);

                cm.sendOk("#d��ȥ��,ϣ�����ܺú�����,Ҳ���õ�δ�����ܼ�����!");
                cm.dispose();
            }
            
          } else {
            cm.dispose();
        }  

    }
}
