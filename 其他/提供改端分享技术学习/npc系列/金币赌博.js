importPackage(net.sf.odinms.client);

var status = 0;
var fee;
var chance = Math.floor(Math.random()*4+1);

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == -1) {
        cm.dispose();
    } else {
        if (mode == 0) {
            cm.sendOk("�ܺ��´��ټ�");
            cm.dispose();
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendNext("�ˡ��� #h #! ���� #bXXð�յ��Ĳ�NPC#k!������Ǯ���ֵ���Ϸ�𣿹��� ������ע�� ");
        } else if (status == 1) {
            cm.sendGetText("������ע���ٽ����?���Ӯ�˵Ļ����Ի��˫��������,�������������");
        } else if (status == 2) {
            fee = cm.getText();
            cm.sendYesNo("��ȷ��Ҫ��ע #r" + fee + "#k ð�ձ���?���ȼ������û����ô��ǮŶ");
        } else if (status == 3) {
            if (cm.getMeso() < fee) {
                cm.sendOk("Ŷ�ǣ�������˼��û��ô��Ǯ�ˣ�ȥ׬��Ǯ�����ɣ���ɲ�����ѵ�");
                cm.dispose();
            } else if (cm.getMeso() >= 1050000000) {
                cm.sendOk("Ŷ������˼Ŷ��������ע���ܳ���1050000000");
                cm.dispose();
            } else if (cm.getText() < 0) {
                cm.sendOk("������ó�������Ȼ���븺����һ��ȥ!");
                cm.dispose();
            } else {
                if (chance <= 1) {
                    cm.gainMeso(-fee);
                    cm.sendNext("Ŷ���������������ô��Ŷ�������� ����һ����");
                    cm.dispose();
                }
                else if (chance == 2) {
                    cm.gainMeso(-fee);
                    cm.sendNext("Ŷ���������������ô��Ŷ�������� ����һ����");
                    cm.dispose();
                }
                else if (chance == 3) {
                    cm.gainMeso(-fee);
                    cm.sendNext("Ŷ���������������ô��Ŷ�������� ����һ����");
                    cm.dispose();
                }
                else if (chance >= 4) {
                    cm.gainMeso(fee * 2);
                    cm.sendNext("#r��������ϲ��#k! ��Ӯ��! ������������������һ�ѹ�");
                                        cm.serverNotice(��ϲ���" + getName() + "����һ�ֵĲ����л�ʤ");
                    cm.dispose();
                }
            }
        }
    }
}