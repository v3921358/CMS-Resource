/*
	This file is part of the OdinMS Maple Story Server
    Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc> 
                       Matthias Butz <matze@odinms.de>
                       Jan Christian Meyer <vimes@odinms.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License version 3
    as published by the Free Software Foundation. You may not use, modify
    or distribute this program under any other version of the
    GNU Affero General Public License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Pison
	Warp NPC to Lith Harbor (104000000)
	located in Florina Beach (110000000)
*/

var status = 0;

function start() {
    status = -1;
    action(1, 0, 0);
}

function action(mode, type, selection) {
    if (mode == -1) {
        cm.dispose();
    } else {
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendNext("��ã�����ר��Ϊ�������ߵ��������Ŵ�Ҷ���ʶ�Ұɣ������������İɣ������˽�鿨�İɣ�����������ĺ���Ů������ร�Ҫ���͵������ɣ�");
        } else if (status == 1) {
            if(cm.getLevel() >= 1 ){  
                if (cm.getParty() == null) { 
                    cm.sendOk("#e�����û�д��������������Բ��������飡."); 
         } else if (status == 2) { 
   if (cm.haveItem(5251003)) { 
    cm.sendNext("�ܺ�, �����л���. �ҽ������ǽ�ȥ.\r\nףԸ���ǵĻ���Բ���ɹ�.�ɲ�Ҫ���ǺͶԷ������."); 
    cm.gainItem(5251003,-1); 
       
     } else { 
if (!cm.isLeader()) { 
                cm.sendSimple("���Ҫ���ͺ���������������ң���ǣ��ร�"); 
                cm.dispose(); 
                    }else { 
            var party = cm.getParty().getMembers(); 
            var next = true; 
                if (party.size() > 6){  
                    next = false; 
                    } 
                if (next) { 
            var em = cm.getEventManager("PB1");  
                if (em == null) { 
                    cm.sendOk("error��"); 
                } else {  
                em.startInstance(cm.getParty(),cm.getChar().getMap()); 
                party = cm.getChar().getEventInstance().getPlayers(); 
                cm.removeFromParty(4001008, party); 
                cm.removeFromParty(4001007, party);  
                } 
            cm.serverNotice("[����]���:" + cm.c.getPlayer().getName() + " �������Ž����˺�ӣ����������ú���������������,��������,�������С���,�����������˽�Ϊ�Ϸ��򸾡�С����Բ��������֮�ࡢ�����˼�,�����Ÿ߰˶���ѧ���峵���ָ�»ԧ��Ե����������ż��ɣ������ںϡ�ף���ˣ�����ͬ�ģ�����úϡ�����ǧ��,���۸���ƶ��ͬ��ͬ�ġ���ɪ�������ྴ������������֮��,�ش�����֮��,���벻������ͷ���ϣ�~~");
       cm.dispose(); 
                    } 
                } 
            }else{ 
                cm.sendOk("#e#r�Բ���,�㻹δ���꣬ �����ܽ�飡."); 
                cm.dispose(); 
            }
        }
    }
}