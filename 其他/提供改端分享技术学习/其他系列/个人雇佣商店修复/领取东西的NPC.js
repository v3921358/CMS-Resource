/*Fredrick NPC (9030000)
*By Moogra (Fixed by Ronald)
*/
importPackage(net.sf.odinms.server);

var status;
var choice;

function start() {
	status = -1;
	action(1, 0, 0);
} 

function action(mode, type, selection) {
	if (mode == 1)
		status++;
	else {
		cm.dispose();
		return;
	}
	
	if (status == 0)
		cm.sendNext("���ã����Ǵ洢���м�(By:���޸�).");
	else if (status == 1)
		cm.sendSimple("���,���Ǹ����̵�����.�������:\r\n#b#L0#ð�ձ�#l    #L1#��Ʒ#l");
	else if (status == 2) {
		cm.sendNext("���Ҳ�������Ʒ...");
		choice = selection;
	} else {
		if (choice == 0) {
			if (status == 3) {
				var mesoEarnt = cm.getHiredMerchantMesos();
				if (mesoEarnt > 0)
					cm.sendYesNo("��ĸ����̵�.��ǰ���� "+mesoEarnt+" ð�ձ�.���Ƿ�Ҫ����??");
				else {
					cm.sendNext("������̵�.û����.");
					cm.dispose();
				}
			} else if (status == 4) {
				cm.sendNext("��л��ʹ��.Ǯ�յ���.С�Ѿ�����.�ҿ����˳��");
				cm.gainMeso(cm.getHiredMerchantMesos());
				cm.zeroMerchantMesos();
				cm.dispose();
			}
		} else {
			if (status == 3) {
				var items = cm.getHiredMerchantItems();
				if (items.size() > 0) {
					var text = "��ѡ��һ����Ŀ\r\n";
					for (var i = 0; i < items.size(); i++)
						text += "#L"+i+"##i"+items.get(i).getRight().getItemId()+"##l ";
					cm.sendSimple(text);
				} else {
					cm.sendNext("��û���κ���Ʒ�����ĵ���");
					cm.dispose();
				}
			} else if (status == 4) {
				var items = cm.getHiredMerchantItems();
				if (cm.getC() == null)
					cm.getPlayer().dropMessage("RAWR");
				MapleInventoryManipulator.addFromDrop(cm.getC(), items.get(selection).getRight());
				cm.sendNext("��л��ʹ���ҵķ���������Ŀ���յ�");
				cm.removeHiredMerchantItem(items.get(selection).getLeft());
				cm.dispose();
			}
		}
	}
}