��һ��NPC~�Ӻͼ���~����ֱ~js�ű�~��ʹ���������ˣ�
ID��2100���Լ�ѡ�񣡱��磺2100.JS
------------------------------------------------------------------------------------------------------------------------------
/*

Multi-purpose:
AP adding NPC
AP reset NPC

Made by Kedano

*/
var status = 0;
var wui = 0;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {

    if (mode == -1) {
        cm.dispose();
    } else {
        if (status >= 0 && mode == 0) {
            cm.dispose();
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendSimple ("ι�� ��Ҫ��Ҫ������������������ֱ ��  \b\r\n#L0#����������������ֱ #l\r\n#L1#������������#l\r\n#L2#������������ #l\r\n#L3#������������#l\r\n#L4#������������#l\r\n#L5#�������е�����#l\r\n#L6#�������е����� #l\r\n#L7#�������е����� #l\r\n#L8#�������е����� ");
        } else if (status == 1) {
            if (selection == 0) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var totAp = p.getRemainingAp() + p.getStr() + p.getDex() + p.getInt() + p.getLuk();
                if (totAp < 30016) {
                p.setStr(4);
                p.setDex(4);
                p.setInt(4);
                p.setLuk(4);
                p.setRemainingAp (totAp - 16);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.STR, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.DEX, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.LUK, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.INT, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ������������������ֱ !");
                cm.dispose();
                } else if (totAp >= 30016) {
                    cm.sendOk ("������AP�ǳ���30000�� ��ֿ��������� .");
                    cm.dispose(); }
                }
            else if (selection == 1) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var totAp = p.getRemainingAp() + p.getStr();
                if (totAp < 30004) {
                p.setStr(4);
                p.setRemainingAp (totAp - 4);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.STR, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ������������������ֱ !");
                cm.dispose();
                } else if (totAp  >= 30004) {
                    cm.sendOk ("������֮ǰ��������AP��Ӧ���������� .");
                    cm.dispose(); }
                }
            else if (selection == 2) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var totAp = p.getRemainingAp() + p.getDex();
                if (totAp < 30004) {
                p.setDex(4);
                p.setRemainingAp (totAp - 4);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.DEX, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ������������������ֱ !");
                cm.dispose();
                } else if (totAp  >= 30004) {
                    cm.sendOk ("������֮ǰ��������AP��Ӧ����������.");
                    cm.dispose(); }
                }
            else if (selection == 3) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var totAp = p.getRemainingAp() + p.getInt();
                if (totAp < 30004) {
                p.setInt(4);
                p.setRemainingAp (totAp - 4);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.INT, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ������������������ֱ! ");
                cm.dispose();
                } else if (totAp  >= 30004) {
                    cm.sendOk ("������֮ǰ��������AP��Ӧ���������� .");
                    cm.dispose(); }
                }
            else if (selection == 4) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var totAp = p.getRemainingAp() + p.getLuk();
                if (totAp < 30004) {
                p.setLuk(4);
                p.setRemainingAp (totAp - 4);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.LUK, java.lang.Integer.valueOf(4)));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ������������������ֱ!");
                cm.dispose();
                } else if (totAp  >= 30004) {
                    cm.sendOk ("������֮ǰ��������AP��Ӧ���������� .");
                    cm.dispose(); }
                }
            else if (selection == 5) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var newStr = p.getRemainingAp() + p.getStr();
                if (newStr < 30000) {
                p.setStr(newStr);
                p.setRemainingAp (0);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.STR, java.lang.Integer.valueOf(p.getStr())));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(0)));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ��������ֱ������! ");
                cm.dispose();
                } else if (newStr >= 30000) {
                    p.setStr(29999);
                    p.setRemainingAp (newStr - 29999);
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.STR, java.lang.Integer.valueOf(p.getStr())));
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                    p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                    cm.sendOk ("���ˡ� ��������ֱ������! ");
                    cm.dispose(); }
                }
            else if (selection == 6) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var newDex = p.getRemainingAp() + p.getDex();
                if (newDex < 30000) {
                p.setDex(newDex);
                p.setRemainingAp (0);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.DEX, java.lang.Integer.valueOf(p.getDex())));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(0)));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("���ˡ� ��������ֱ������! ");
                cm.dispose();
                } else if (newDex >= 30000) {
                    p.setDex(29999);
                    p.setRemainingAp (newDex - 29999);
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.DEX, java.lang.Integer.valueOf(p.getDex())));
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                    p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                    cm.sendOk ("�á� ��������ֱ������! ");
                    cm.dispose(); }
                }
            else if (selection == 7) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var newInt = p.getRemainingAp() + p.getInt();
                if (newInt < 30000) {
                p.setInt(newInt);
                p.setRemainingAp (0);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.INT, java.lang.Integer.valueOf(p.getInt())));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(0)));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("�á� ��������ֱ������! ");
                cm.dispose();
                } else if (newInt >= 30000) {
                    p.setInt(29999);
                    p.setRemainingAp (newInt - 29999);
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.INT, java.lang.Integer.valueOf(p.getInt())));
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                    p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                    cm.sendOk ("�á� ��������ֱ������! ");
                    cm.dispose(); }
                }
            else if (selection == 8) {
                var statup = new java.util.ArrayList();
                var p = cm.c.getPlayer();
                var newLuk = p.getRemainingAp() + p.getLuk();
                if (newLuk < 30000) {
                p.setLuk(newLuk);
                p.setRemainingAp (0);
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.LUK, java.lang.Integer.valueOf(p.getLuk())));
                statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(0)));
        
                p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                cm.sendOk ("�á� ��������ֱ������! ");
                cm.dispose();
                } else if (newLuk >= 30000) {
                    p.setLuk(29999);
                    p.setRemainingAp (newLuk - 29999);
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.LUK, java.lang.Integer.valueOf(p.getLuk())));
                    statup.add (new net.sf.odinms.tools.Pair(net.sf.odinms.client.MapleStat.AVAILABLEAP, java.lang.Integer.valueOf(p.getRemainingAp())));
        
                    p.getClient().getSession().write (net.sf.odinms.tools.MaplePacketCreator.updatePlayerStats(statup));
                    cm.sendOk ("�á� ��������ֱ������! !");
                    cm.dispose(); }
                }
            }
        }
    }
=======================================================================
���ٵ�ֱ��һ�¼ӵ�����ӵ�����ȥ�ˣ��Ӵ��ˣ����ܴ����������Ǻǣ�