/*
======================================
 ���Ķ˼���  ����ռ���ʽ����
======================================
*/
var status = 0;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == -1 || status == 4) {
        cm.dispose();
    } else {
        if (status == 2 && mode == 0) {
            cm.sendOk("����Ҫ��ȡ�����������Ұɣ�");
            status = 4;
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendNext("�װ���#h #��ã��ٴμ���������̫�����ˣ��Ҹ����VIP���ÿ�����͹��ʵģ����ȷ������VIP����뵽����������ȡ���ʣ�����Ҫ�������ң�");
        } else if (status == 1) {            
            cm.sendYesNo("����VIPÿ�������ȡ3ǧ�������\r\n�м�VIPÿ�������ȡ6ǧ�������\r\n�߼�VIPÿ�������ȡ1�������\r\n��ȷ����ȡ����Ĺ�����");
        } else if (status == 2) {
            if(cm.getChar().getVip() == 0) {
            cm.sendOk("�Բ����㲻��VIP��Ա�޷���ȡ���ʡ�\r\n����Ҫ����ϵ����Ա#bQQ��22899960#k����VIP��Ա��");
            } else if (cm.getBossLog('VIPGZ') >= 1) {
            cm.sendOk("��Ǹ����VIP�������켺����ȡ���ʣ��������������Ұɣ�");
            } else if(cm.getChar().getVip() == 1) {
            cm.gainMeso(20000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("��ϲ����ȡ����Ĺ���3ǧ������ң����������˵����");
            } else if(cm.getChar().getVip() == 2) {
            cm.gainMeso(50000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("��ϲ����ȡ����Ĺ���6ǧ������ң����������˵����");
            } else if(cm.getChar().getVip() == 3) {
            cm.gainMeso(100000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("��ϲ����ȡ����Ĺ���1������ң����������˵����");
            }
            cm.dispose();
        }
    }    } 