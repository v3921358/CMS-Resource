/*
	Mady By Coffee
	Powered By XXMS
	Warp NPC
*/

var bossmaps = Array(
										Array(100000005,0,"������԰III"), 																	Array(105070002,0,"Ģ����֮Ĺ"), 
										Array(105090900,0,"���������Ժ"), 
										Array(889210600,0,"С�����"), 
										Array(889212500,0,"�ִ�����"), 
										Array(889211800,0,"�ӽ�����"), 
										Array(889212400,0,"����ʿ"), 
										Array(889212300,0,"������ʿ"), 
										Array(889212200,0,"��ɫ����ħ"), 
										Array(889212000,0,"��צ����"), 
										Array(889212100,0,"ʯ����"), 
										Array(889211900,0,"������"), 
										Array(889211700,0,"��ߴ���"), 
										Array(889211600,0,"����"), 
										Array(889211200,0,"��ʨ��"), 
										Array(889211500,0,"������ɮ"), 
										Array(889211300,0,"����ͭ�޺�"), 
										Array(889211400,0,"���ֽ��޺�"), 
										Array(889211000,0,"���С����"), 
										Array(541020800,0,"ǧ������"), 
										Array(889211100,0,"�ڰ�֮��"), 
										Array(889210900,0,"������"), 
										Array(889210800,0,"Ģ���齱��"), 
										Array(889210700,0,"������"), 
										Array(889210500,0,"�����"), 
										Array(889210200,0,"��������"), 
										Array(889210400,0,"�綯����"), 
										Array(889210300,0,"������"), 
										Array(889210100,0,"��Ģ����"), 
										Array(230040420,0,"Ƥ��ū˹��Ѩ"), 
										Array(211042300,0,"�������"), 
										Array(220080001,0,"ʱ�����ı�Դ"), 
										Array(240020402,0,"�������Ϣ��"), 
										Array(240020101,0,"����Ҷ�ɭ��"), 
										Array(801040100,0,"�����ι���"), 
										Array(240060200,0,"����������Ѩ"), 
										Array(610010005,0,"����ɭ��:��ʬI"), 
										Array(610010012,0,"����ɭ��:а�������"), 
										Array(610010013,0,"����ɭ��:��ʬII"), 
										Array(270050000,0,"��Ļƻ�:��PB��"), 
										Array(610010100,0,"����ɭ��:Ť��·��I"), 
										Array(610010101,0,"����ɭ��:Ť��·��II"), 
										Array(610010102,0,"����ɭ��:Ť��·��III"), 
										Array(610010103,0,"����ɭ��:Ť��·��IV"), 
										Array(610010104,0,"����ɭ��:Ť��·��V")
										);
var monstermaps = Array(
										Array(100040001,0,"�ϲ�ɭ��ѵ������8��-15��"), 
										Array(101010100,0,"��ľ�֢�8��-15��"), 
										Array(104040000,0,"����ѵ���� 1��-15��"), 
										Array(103000101,0,"����һ����<��1����> 20��-30��"), 
										Array(103000105,0,"����һ����<��4����> 50��-70��"), 
										Array(101030110,0,"��1��Ӫ"), 
										Array(106000002,0,"Σ�յ�Ͽ�Ȣ�"), 
										Array(101030103,0,"�ż�����آ�"), 
										Array(101040001,0,"Ұ������� 20��-35��"), 
										Array(101040003,0,"��֮�ڹ�֮��"), 
										Array(101030001,0,"Ұ���������"), 
										Array(104010001,0,"��ĺ��� 10��-20��"), 
										Array(930000100,0,"ɭ�ֳ���"),
										Array(930000200,0,"���ʵ�ɭ��"),
										Array(105070001,0,"���Ϲ㳡 20��-40��"), 
										Array(105090300,0,"��Ѩ"), 
										Array(105040306,0,"����֮�� 60��-80��"), 
										Array(230020000,0,"������·"), 
										Array(230010400,0,"������·"), 
										Array(211041400,0,"����֮�֢�"), 
										Array(222010000,0,"��ɽ���"),
										Array(220070301,0,"ʱ��ֹ֮ͣ��"), 
										Array(220070201,0,"��ʧ��ʱ��"), 
										Array(220050300,0,"ʱ��ͨ��"), 
										Array(220010500,0,"¶̨���� 40��-70��"), 
										Array(250020000,0,"���������� 50��-60��"), 
										Array(251010000,0,"ʮ��ҩ�ݵ�"), 
										Array(200040000,0,"�Ʋʹ�԰��"), 
										Array(200010301,0,"�ڰ�ͥԺ��"), 
										Array(240020100,0,"��������ս�� 100��-120��"), 
										Array(240040500,0,"��֮��Ѩ���"), 
										Array(240040000,0,"����Ͽ��"), 
										Array(600020300,0,"���붴Ѩ"), 
										Array(801040004,0,"������"), 
										Array(802000200,0,"δ��������̨����"),
										Array(802000300,0,"δ��������������������"),
										Array(802000400,0,"δ�����������棩"),
										Array(802000500,0,"δ�������������о�����"),
										Array(802000600,0,"δ��������̫�ս��ӣ�"),
										Array(800020130,0,"��������"),
	
	Array(749020000,0,"���쵰���ͼ")
										); 
var townmaps = Array(
										Array(910000000,0,"�����г�"), 
										Array(1010000,0,"�ʺ�� �ʺ絺���ִ�"), 
										Array(60000,0,"�ϸ� �ʺ絺���ִ�"), 
										Array(104000000,0,"�����"), 
										Array(100000000,0,"���ִ�"), 
										Array(101000000,0,"ħ������"), 
										Array(180000001,0,"�ڰ�С��"), 
										Array(102000000,0,"��ʿ����"), 
										Array(103000000,0,"��������"), 
										Array(120000000,0,"ŵ����˹����ͷ"),
										Array(105040300,0,"����֮��"), 
										Array(200000000,0,"���֮��"),
										Array(211000000,0,"����ѩ��"), 
										Array(230000000,0,"ˮ������"),  
										Array(222000000,0,"ͯ����"), 
										Array(220000000,0,"��߳�"),
										Array(701000000,0,"��������"),
										Array(250000000,0,"����"), 
										Array(702000000,0,"������"), 
										Array(500000000,0,"̩��"),
										Array(260000000,0,"ɳĮ֮��"), 
										Array(741000000,0,"��ҹ��"), 
										Array(600000000,0,"��Ҷ��"), 
										Array(240000000,0,"��ľ��"), 
										Array(742000000,0,"̨��101���"), 
										Array(261000000,0,"�������"), 
										Array(800040000,0,"���"),  
										Array(221000000,0,"�����������"), 
										Array(251000000,0,"�ٲ���"),
										Array(701000200,0,"�Ϻ�ԥ԰"),
										Array(550000000,0,"��¡����"),
										Array(130000000,0,"ʥ�쵺"),
										Array(219000000,0,"�ɿڿ��ֳ�"), 
										Array(551000000,0,"�ʰ��"),
										Array(740000000,0,"�����"), 
										Array(801000000,0,"�Ѻʹ�"), 
										Array(540010000,0,"�¼��»���"),
										Array(541000000,0,"�¼�����ͷ"),
										Array(300000000,0,"����ɭ��"), 
										Array(501000000,0,"̩���µ�ͼ"),
										Array(270000100,0,"ʱ�����"), 
										Array(702100000,0,"�ؾ���"), 
										Array(970000000,0,"�����������"), 
										Array(800000000,0,"�Ŵ�����"), 
										Array(709000101,0,"���վ���"), 
										Array(130000200,0,"ʥ���֮��"),
										Array(741000208,0,"���㳡"),
										Array(925020000,0,"����������"),
										Array(930000000,0,"����ɭ��"),
										Array(802000100,0,"�Ŵ�ɭ��"),
										Array(800040500,0,"��Ծ��GMװ����ͼ"),
										Array(930000010,0,"ɭ�����"), 
										Array(193000000,0,"���� ����װ��ר��"),
										Array(702090101,0,"Ӣ���"), 
										Array(680000000,0,"�Ҹ�����"), 
										Array(700000000,0,"��𽹬")
							);
var chosenMap = -1;
var monsters = 0;
var towns = 0;
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
                if (status >= 3 && mode == 0) {
			cm.sendOk("�´��ټ�!.");
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
                        cm.sendNext("Hi,�������紫��Ա!");                  
                }
               if (status == 1) {
                   cm.sendSimple("#fUI/UIWindow.img/QuestIcon/3/0#\r\n#L0#���紫��#l\r\n#L1#��Ǹ,���ߴ���#l");
               }
               else if (status == 2) {
                   if (selection == 0) {
                       cm.sendSimple("#fUI/UIWindow.img/QuestIcon/3/0#\r\n#L0#�����ͼ#l\r\n#L1#������ͼ#l\r\n#L2#BOSS��ͼ#l");
                   }
                   else if (selection == 1) {
                       cm.dispose();
                   }
               }
               else if (status == 3) {
                   if (selection == 0) {
                        var selStr = "ѡ�����Ŀ�ĵذ�.#b";
			for (var i = 0; i < townmaps.length; i++) {
				selStr += "\r\n#L" + i + "#" + townmaps[i][2] + "";
			}
                        cm.sendSimple(selStr);
                        towns = 1;
                   }
                   if (selection == 1) {
                       var selStr = "ѡ�����Ŀ�ĵذ�.#b";
                       for (var i = 0; i < monstermaps.length; i++) {
				selStr += "\r\n#L" + i + "#" + monstermaps[i][2] + "";
                       }
                       cm.sendSimple(selStr);
                       monsters = 1;
                   }
                   if (selection == 2) {
                       var selStr = "ѡ�����Ŀ�ĵذ�.#b";
                       for (var i = 0; i < bossmaps.length; i++) {
				selStr += "\r\n#L" + i + "#" + bossmaps[i][2] + "";
                       }
                       cm.sendSimple(selStr);
                       bosses = 1;
                   }
               }
            else if (status == 4) {
                if (towns == 1) {
                cm.sendYesNo("��ȷ��Ҫȥ " + townmaps[selection][2] + "? �۸�:#r"+townmaps[selection][1]+"#k���");
		chosenMap = selection;
                towns = 2;
                }
                else if (monsters == 1) {
                cm.sendYesNo("��ȷ��Ҫȥ " + monstermaps[selection][2] + "? �۸�:#r"+monstermaps[selection][1]+"#k���");
                chosenMap = selection;
                monsters = 2;
                }
                else if (bosses == 1) {
                cm.sendYesNo("��ȷ��Ҫȥ " + bossmaps[selection][2] + "? �۸�:#r"+bossmaps[selection][1]+"#k���");
                chosenMap = selection;
                bosses = 2;
                }
            }
            else if (status == 5) {
                if (towns == 2) {
                	if(cm.getMeso()>=townmaps[chosenMap][1]){
                		cm.warp(townmaps[chosenMap][0], 0);
                		cm.gainMeso(-townmaps[chosenMap][1]);
                	}else{
                		cm.sendOk("��û���㹻�Ľ��Ŷ!");
                	}
                    cm.dispose();
                }
                else if (monsters == 2) {
                    if(cm.getMeso()>=monstermaps[chosenMap][1]){
                		cm.warp(monstermaps[chosenMap][0], 0);
                		cm.gainMeso(-monstermaps[chosenMap][1]);
                	}else{
                		cm.sendOk("��û���㹻�Ľ��Ŷ!");
                	}
                    cm.dispose();
                }
                else if (bosses == 2) {
                    if(cm.getMeso()>=bossmaps[chosenMap][1]){
                		cm.warp(bossmaps[chosenMap][0], 0);
                		cm.gainMeso(-bossmaps[chosenMap][1]);
                	}else{
                		cm.sendOk("��û���㹻�Ľ��Ŷ!");
                	}
                    cm.dispose();
                }
            }
              
            }
}
