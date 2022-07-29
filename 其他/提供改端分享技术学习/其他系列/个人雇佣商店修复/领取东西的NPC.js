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
		cm.sendNext("您好，我是存储银行家(By:杰修复).");
	else if (status == 1)
		cm.sendSimple("你好,我是个人商店助理.你想回收:\r\n#b#L0#冒险币#l    #L1#物品#l");
	else if (status == 2) {
		cm.sendNext("让我查查你的物品...");
		choice = selection;
	} else {
		if (choice == 0) {
			if (status == 3) {
				var mesoEarnt = cm.getHiredMerchantMesos();
				if (mesoEarnt > 0)
					cm.sendYesNo("你的个人商店.当前共有 "+mesoEarnt+" 冒险币.你是否要收下??");
				else {
					cm.sendNext("你的破商店.没人买.");
					cm.dispose();
				}
			} else if (status == 4) {
				cm.sendNext("感谢你使用.钱收到了.小费就免了.我看你很顺眼");
				cm.gainMeso(cm.getHiredMerchantMesos());
				cm.zeroMerchantMesos();
				cm.dispose();
			}
		} else {
			if (status == 3) {
				var items = cm.getHiredMerchantItems();
				if (items.size() > 0) {
					var text = "请选择一个项目\r\n";
					for (var i = 0; i < items.size(); i++)
						text += "#L"+i+"##i"+items.get(i).getRight().getItemId()+"##l ";
					cm.sendSimple(text);
				} else {
					cm.sendNext("您没有任何物品，您的店铺");
					cm.dispose();
				}
			} else if (status == 4) {
				var items = cm.getHiredMerchantItems();
				if (cm.getC() == null)
					cm.getPlayer().dropMessage("RAWR");
				MapleInventoryManipulator.addFromDrop(cm.getC(), items.get(selection).getRight());
				cm.sendNext("感谢您使用我的服务，您的项目已收到");
				cm.removeHiredMerchantItem(items.get(selection).getLeft());
				cm.dispose();
			}
		}
	}
}