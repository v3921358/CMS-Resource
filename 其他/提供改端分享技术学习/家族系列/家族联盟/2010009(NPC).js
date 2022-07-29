importPackage(net.sf.odinms.net.world.guild);

var status;
var choice;
var guildName;
var partymembers;

function start() {
	partymembers = cm.getPartyMembers();
	status = -1;
	action(1,0,0);
}

function action(mode, type, selection) {
	if (mode == 1)
		status++;
	else {
		cm.dispose();
		return;
	}
	
	 
	if (status == 0)
	    cm.sendSimple("��ã�  ����!  #b�������˵Ĺ���Ա#k\r\n#b#L0#����֪������������ʲô��?#l\r\n#L1#���ʹ�ü����Ϊ����������?#l\r\n#L2#�����ü����Ϊ��������.#l\r\n#L3#����ҪΪ�����������ӽ϶�ļ���.#l\r\n#L4#����Ҫ��ɢ��������.#l");
	else if (status == 1) {
		choice = selection;
	    if (selection == 0) {
		    cm.sendNext("����������, һ��һЩ����������γɵ�һ������С�顣 �����ƹ���Щ�������˵���.");
			cm.dispose();
		} else if (selection == 1) {
			cm.sendNext("Ҫ����һ���������ˣ� ��Ҫ2������������Ҫ��һ������С� ��һ����ӵĶӳ����ᱻ���䵱���������˵�����.");
			cm.dispose();
		} else if(selection == 2) {
			if (cm.getPlayer().getParty() == null) {
				cm.sendNext("��Ķ�����û��2��������峤�����Բ��ܴ����������ˡ�"); //Not real text
				cm.dispose();
			} else if (partymembers.get(0).getGuild() == null) {
				cm.sendNext("�㲻��ֱ���ü������˴������Լ��ļ��塣");
				cm.dispose();
			} else if (partymembers.get(1).getGuild() == null) {
				cm.sendNext("������Ǽ�����峤.");
				cm.dispose();
			} else if (partymembers.get(0).getGuild().getAllianceId() > 0) {
				cm.sendNext("������������˵��ˣ����Բ����ڼ����������.");
				cm.dispose();
			} else if (partymembers.get(1).getGuild().getAllianceId() > 0) {
				cm.sendNext("��ļ����Ա�Ѿ�����������˵��ˡ�");
				cm.dispose();
			} else if (partymembers.size() != 2) {
				cm.sendNext("��ȷ����ֻ�� 2��������峤�������ӵ���.");
				cm.dispose();
			} else if (cm.partyMembersInMap() != 2) {
				cm.sendNext("��ȷ����������������峤�ڴ˵�ͼ��.");
				cm.dispose();
			} else
                cm.sendYesNo("Ŷ, ��Լ������˸���Ȥ?");
		} else if (selection == 3) {
		    var rank = cm.getPlayer().getMGC().getAllianceRank();
			if (rank == 1)
				cm.sendOk("Not done yet"); //ExpandGuild Text
			else {
			    cm.sendNext("ֻ�м�������������������˵ļ������Ŀ.");
				cm.dispose();
			}
		} else if(selection == 4) {
		    var rank = cm.getPlayer().getMGC().getAllianceRank();
			if (rank == 1)
				cm.sendYesNo("��ȷ������Ҫ��ɢ��ļ�������?");
			else {
				cm.sendNext("ֻ�м����������˿��ܽ�ɢ��������.");
				cm.dispose();
			}
		}
	} else if(status == 2) {
	    if (choice == 2) {
		    cm.sendGetText("��������������¼������˵�����. (max. 12 letters)");
		} else if (choice == 4) {
			if (cm.getPlayer().getGuild() == null) {
				cm.sendNext("�㲻�ܹ���ɢ��������ĵļ�������.");
				cm.dispose();
			} else if (cm.getPlayer().getGuild().getAllianceId() <= 0) {
				cm.sendNext("�㲻�ܹ���ɢ��������ĵļ�������.");
				cm.dispose();
			} else {
				MapleAlliance.disbandAlliance(cm.getC(), cm.getPlayer().getGuild().getAllianceId());
				cm.sendOk("��ļ��������Ѿ���ɢ");
				cm.dispose();
			}
		}
	} else if (status == 3) {
		guildName = cm.getText();
	    cm.sendYesNo("Will "+ guildName + " be the name of your Guild Union?");
	} else if (status == 4) {
	    if (!MapleAlliance.canBeUsedAllianceName(guildName)) {
			cm.sendNext("������ֲ���ʹ�ã����㻻��ģ�"); //Not real text
			status = 1;
			choice = 2;
		} else {
			if (MapleAlliance.createAlliance(partymembers.get(0), partymembers.get(1), guildName) == null)
				cm.sendOk("����δ֪����");
			else
				cm.sendOk("��ɹ��ش����˼�������.");
			cm.dispose();
		}
	}
}