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
            cm.sendNext("你好！我是专门为人拉红线的月老相信大家都认识我吧！你们是来结婚的吧！带上了结婚卡的吧！可以在外面的红线女处购买喔！要结婚就点击下面吧！");
        } else if (status == 1) {
            if(cm.getLevel() >= 1 ){  
                if (cm.getParty() == null) { 
                    cm.sendOk("#e你好像还没有带你老婆来，所以不能让你结婚！."); 
         } else if (status == 2) { 
   if (cm.haveItem(5251003)) { 
    cm.sendNext("很好, 你们有婚礼卡. 我将带你们进去.\r\n祝愿你们的婚礼圆满成功.可不要忘记和对方亲吻喔."); 
    cm.gainItem(5251003,-1); 
       
     } else { 
if (!cm.isLeader()) { 
                cm.sendSimple("如果要结婚就和你老婆组队来找我，手牵手喔！"); 
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
                    cm.sendOk("error！"); 
                } else {  
                em.startInstance(cm.getParty(),cm.getChar().getMap()); 
                party = cm.getChar().getEventInstance().getPlayers(); 
                cm.removeFromParty(4001008, party); 
                cm.removeFromParty(4001007, party);  
                } 
            cm.serverNotice("[月老]玩家:" + cm.c.getPlayer().getName() + " 带着老婆进入了红樱宫，大家来拿红包啊，语苍天在上,厚土在下,高堂其中。我,宣布你们俩人结为合法夫妇。小姐珠圆玉润旺夫之相、宜室宜家,先生才高八斗、学富五车。现福禄鸳鸯缘定三生，佳偶天成，珠联壁合。祝二人：永结同心，百年好合、百子千孙,无论富贵贫穷同德同心、琴瑟合鸣、相敬如宾。结此终身之盟,守此终身之誓,不离不弃、白头偕老！~~");
       cm.dispose(); 
                    } 
                } 
            }else{ 
                cm.sendOk("#e#r对不起,你还未成年， 还不能结婚！."); 
                cm.dispose(); 
            }
        }
    }
}