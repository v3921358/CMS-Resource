var map1 = Array(100000005, 105070002, 800010100, 105090900, 682000001, 240020101, 240020401);
var map1name = Array("������԰��(Ģ����)", "Ģ����֮Ĺ(��ʬĢ����)", "��ʵ���(��Ģ����)", "���������Ժ(�����)", "��Ӱɭ��(ħ��)", "����Ҷ�ɭ��(��ӥ)", "�������Ϣ��(����)"); 
var map2 = Array(230040420, 990000900, 801040003, 220080000, 211042300, 910000001);
var map2name = Array("Ƥ��ū˹��Ѩ(����)", "����˹����", "�ձ�����", "ʱ�����ı�Դ(����)", "������̨(����)", "������!"); 
var chosenMap = -1;
var monsters = 0;
var bosses = 0;



importPackage(net.sf.odinms.client);

function start() {
	status = -1;
	
	action(1, 0, 0);
}

function action(mode, type, selection) {
            if (mode == -1) {
                cm.dispose();
            }
            else {
                if (status >= -1 && mode == 0) {
                
			cm.sendOk("�õ�,����������Ҫ��ʲô,�һ�������Ϊ������..");
			cm.dispose();
			return;                    
                }
                if (mode == 1) {
			status++;
		}
		else {
			status--;
		}
               
               if (status == 0) {
                       cm.sendSimple("��ã�����BOSS�������ݴ���Ա��\r\n���������˭ʹ��һ���أ�\r\n#b#L0#Boss��ͼ1#r(50��)#l #b#L1#Boss��ͼ2#r(120��)#l");
                   }
               else if (status == 1) {
                   if (selection == 0) {
                   if (cm.getLevel() < 50){
                   cm.sendOk("��Ů����ȼ�̫���ˣ���");
                   cm.dispose();
                   }else {
                       var selStr = "ѡ�����Ŀ�ĵ�.#b";
                       for (var i = 0; i < map1.length; i++) {
				selStr += "\r\n#L" + i + "#" + map1name[ i ]+"";
                       }
                       cm.sendSimple(selStr);
                       monsters = 1;
                   }
                   }
                   else if ((selection == 1)&& (cm.getLevel() >= 1)) {
                   if (cm.getLevel() < 120){
                   cm.sendOk("˧�磬��ȼ�̫���ˣ���");
                   cm.dispose();
                   }else {
                       var selStr = "ѡ�����Ŀ�ĵ�.#b";
                       for (var i = 0; i < map2.length; i++) {
                selStr += "\r\n#L" + i + "#" + map2name[ i ]+""; 
                       }
                       cm.sendSimple(selStr);
                       bosses = 1;
                   }
                   }
               }
            else if (status == 2) {
                if (monsters == 1) {
                cm.sendYesNo("����ȥ #b" + map1name[selection] + "#k ��?");
                chosenMap = selection;
                monsters = 2;
                }
                else if (bosses == 1) {
                cm.sendYesNo("����ȥ #b" + map2name[selection] + "#k ��?");
                chosenMap = selection;
                bosses = 2;
                }
                
            }
            else if (status == 3) {
                if (monsters == 2) {
                    cm.warp(map1[chosenMap], 0);
                    cm.dispose();
                }
                else if (bosses == 2) {
                    cm.warp(map2[chosenMap], 0);
                    cm.dispose();
                }

            }
         }
}