//Kippieeej for the base of the script, Mikethemak for editing it for this function.
var status = 0;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == -1) {
        cm.dispose();
    } else {
        if (mode == 0 && status == 0) {
            cm.dispose();
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
                cm.sendSimple("Hello #h #, ��ӭ���� #r����ð�յ�#k\r\n�ƽ𼶴�����У���������ϵĽ�ҹ�����Զһ��ɵȼ���ƷŶ\r\n �������ϵĽ�Ҷһ��ɵȼۻƽ�������Ҫ��ʱ���ҿ��Ը��һ��ɽ�ң����������Ҫ��ȡ������ã������Ѿ��Ǻܱ��˵�������Ҫ��Ҫ�һ�\r\n \r\n����ѡ����Ҫ�һ��Ļƽ�Ʒ�֣���ͬƷ�ֵĻƽ���Ի�����ͬ�����Ľ�ң�ѡ�����ǰ��ע�⣬���������Ǯ�ܹ����ܳ���21E�������ɸ������ٶһ�֮ǰ������������Ǯ�᲻�����21E�������Ϊ�����ҿɲ�����Ŷ������ ! ! �һ���ǧ��Ҫ˫������������ʧ! \r\n#L1##bʹ��15E�һ����1�� #v5200002##k#l \r\n \r\n#L2##bʹ��1�� #v5200002#�һ�14.5El#k#l \r\n \r\n#L3#10Eð�ձҶһ�1�� #v5200001##l \r\n#L4#ʹ��1�� #v5200001# �һ�9.5Eð�ձ�.#l \r\n#L5#5Eð�ձҶһ�1�� #v5200000##l \r\n#L6#ʹ��1�� #v5200000# �һ�4.5Eð�ձ�.#l");
        //cm.dispose();
            } else if (status == 1) {
            if (selection == 1) {
    if (cm.itemQuantity(5200002) >= 50) {
    cm.sendOk(" �㴢�����㹻�� #v5200002# ��, �㲻���ڴ�Ÿ���� #v5200002# ��");
    cm.dispose();
        }  else if (cm.getMeso() >= 1500000000) {
                    cm.gainMeso(-1500000000);                
                    cm.gainItem(5200002, 1); 
                    cm.dispose();
                } else {
                    cm.sendOk("You don't have enough #bMesos#k, are you trying to #eScam#k me!?");
                    cm.dispose();
                }                                
            } else if (selection == 2) {
        if (cm.getMeso() >= 647000000) {
        cm.sendOk("�뻨�������ϵ�Ǯ�ɣ�ǿ�жһ���ʹ���Ǯ��ɸ���Ŷ���Ǻ�");
                cm.dispose();
        } else if (cm.itemQuantity(5200002) >= 1) {
                    cm.gainMeso(1450000000);                
                    cm.gainItem(5200002, -1); 
                    cm.dispose();
                } else {
                    cm.sendOk("��û�� #v5200002#. ��Ҫ������������ƭ���κζ���!");
                    cm.dispose();
                }    
            } else if (selection == 3) {
    if (cm.itemQuantity(5200000) >= 50) {
    cm.sendOk(" �����㹻��� #v5200001# ��, ���Ŷһ�һ���� #v5200001# �������Ҷһ�����.");
    cm.dispose();
    } else if (cm.getMeso() >= 1000000000) {
                    cm.gainMeso(-1000000000);                
                    cm.gainItem(5200001, 1); 
                    cm.dispose();
                } else {
                    cm.sendOk("You don't have enough #bMesos#k, are you trying to #eScam#k me!?");
                    cm.dispose();
                  }
        } else if (selection == 4) {
        if (cm.getMeso() >= 1147000000) {
        cm.sendOk("�뻨�������ϵ�Ǯ�ɣ�ǿ�жһ���ʹ���Ǯ��ɸ���Ŷ���Ǻ�");
                cm.dispose();
                } else if (cm.itemQuantity(5200001) >= 1) {
                    cm.gainMeso(950000000);                
                    cm.gainItem(5200001, -1); 
                    cm.dispose();
                } else {
                    cm.sendOk("�������û�� #v5200001#. ����Ǯ����������,��ɲ�����ѷ���!");
                    cm.dispose();
              }    
            } else if (selection == 5) {
    if (cm.itemQuantity(5200000) >= 50) {
    cm.sendOk(" �����㹻��� #v5200000# ��, �ȶһ�һ���� #v5200000# �������������һ�ͭ�Ұ�����");
    cm.dispose();
    } else if (cm.getMeso() >= 500000000) {
                    cm.gainMeso(-500000000);                
                    cm.gainItem(5200000, 1); 
                    cm.dispose();
                } else {
                    cm.sendOk("You don't have enough #bMesos#k, are you trying to #eScam#k me!?");
                    cm.dispose();
            }
                } else if (selection == 6) {
        if (cm.getMeso() >= 1647000000) {
        cm.sendOk("�뻨�������ϵ�Ǯ�ɣ�ǿ�жһ���ʹ���Ǯ��ɸ���Ŷ���Ǻ�");
                cm.dispose();
                } else if (cm.itemQuantity(5200000) >= 1) {
                    cm.gainMeso(450000000);                
                    cm.gainItem(5200000, -1); 
                    cm.dispose();
                } else {
                    cm.sendOk("�������û�� #v5200000#. ����Ǯ�������Ҷһ���!.");
                    cm.dispose();
                    }    
                }
            }
        }
    }
