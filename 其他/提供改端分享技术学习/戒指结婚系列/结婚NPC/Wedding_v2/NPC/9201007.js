/* 
 This file is part of the OdinMS Maple Story Server 
    Copyright (C) 2008 Patrick Huy <patrick.huy@frz.cc>  
        Matthias Butz <matze@odinms.de> 
        Jan Christian Meyer <vimes@odinms.de> 
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU Affero General Public License as 
    published by the Free Software Foundation version 3 as published by 
    the Free Software Foundation. You may not use, modify or distribute 
    this program under any other version of the GNU Affero General Public 
    License. 
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU Affero General Public License for more details. 
    You should have received a copy of the GNU Affero General Public License 
    along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/ 
/* Assistant Nancy 
 Warp to bottom (680000210) 
 located in Amoria (680000000) 
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
  if (status >= 2 && mode == 0) { 
   cm.sendOk("�ټ�,�װ��ı���!"); 
   cm.dispose(); 
   return; 
  } 
  if (mode == 1) 
   status++; 
  else 
   status--; 
  if (status == 0) { 
   cm.sendNext("��ӭ����!�Ҳ�����������������İ�. ��ô��ϣ�������г�ԣ��׼��,��Ϊ���Ļ��ѿɲ�����ô���˵�Ӵ!"); 
  } else if (status == 1) { 
   cm.sendNextPrev("�Ǻ�,�Ҳ������Ǵ���Ѿ���������С������׼���˰�? ��ô��������ֻ��Ҫ����һ�Ž������ҾͿ��������ǽ�ȥ���."); 
  } else if (status == 2) { 
   if (cm.haveItem(5251003)) { 
    cm.sendNext("�ܺ�, �����л���. �ҽ������ǽ�ȥ.\r\nףԸ���ǵĻ���Բ���ɹ�.�ɲ�Ҫ���ǺͶԷ������."); 
    cm.gainItem(5251003,-1); 
     
   } else { 
    cm.sendOk("����û�л���,���ܾ��л���!�´�����ϻ�����������!"); 
    status = 9; 
   } 
  } else if (status == 3) { 
   cm.warp(680000210, 2); 
    cm.playMusic("BgmGL/cathedral"); 
   cm.mapMessage(5,"��������,��������,�������С���,�����������˽�Ϊ�Ϸ��򸾡�С����Բ��������֮�ࡢ�����˼�,�����Ÿ߰˶���ѧ���峵���ָ�»ԧ��Ե����������ż��ɣ������ںϡ�ף���ˣ�����ͬ�ģ�����úϡ�����ǧ��,���۸���ƶ��ͬ��ͬ�ġ���ɪ�������ྴ������������֮��,�ش�����֮��,���벻������ͷ���ϣ�"); 
   cm.gainItem(1112803,1); 
   cm.gainItem(1050113,1); 
   cm.gainItem(1050114,1); 
   cm.gainItem(1000029,1); 
   cm.gainItem(1081002,1); 
   cm.dispose(); 
  } 
 } 
}  
