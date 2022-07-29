/*
*
* 排行榜系统 NPC    By: ZreHy_MapleStory    网站：www.zrehymxd.cn
*
*/

importPackage(net.sf.odinms.client);

function start() {
	status = -1;
	
	action(1, 0, 0);
}

function action(mode, type, selection) {
            if (mode == -1) {
                cm.dispose();
            }
            else {
                if (status >= 0 && mode == 0) {
                
			cm.sendOk("好的,如果你想好了要做什么,我会很乐意的为你服务的..");
			cm.dispose();
			return;                    
                }
                if (mode == 1) {
			status++;
		}
		else {
			status--;
		}
		        if (status == 0) {
			cm.sendSimple("迎新年，本服的东西大降价!我是世界导游小姐(稻、香修复)，为你提供最优质的服务。\r\n #d#L1#会员等级1乐园#l #L2#会员等级2探秘#l #g#L3#会员等级3圣殿#l \r\n\r\n#d#e#L9#【转生排行榜】#l #L10#家族势力排行榜#l #g#L16#财富排行#k\r\n\r\n#r#L15#【玩家人气排行榜】#k #L12#〖PK排行榜〗#l\r\n\r\n#L13#【等级排行榜】(By:稻、香修复)#l#n #e#b#L6#被杀数排行榜#k#l\r\n\r\n#L14#〖本服守则〗#l#r #L11#游戏说明(加了GM手册)#l  #b");
			} else if (status == 1) {
			if (selection == 1) {
				   if(cm.getChar().getVip() >= 1) {
                   cm.warp(209000000, 0);
                   cm.sendOk("尊敬的VIP1会员，我已经将你传送至#r会员等级1地图-幸福村#n#k了.欢迎再次光临!"); 
				   cm.dispose();
				   }else{
                   cm.sendOk("#b你不是会员1级，请联系GM给你在线开通!");
                   cm.dispose();   }  
			} else if  (selection == 2) {
				   if(cm.getChar().getVip() >= 2) {
                   cm.warp(922020300, 0);
cm.sendOk("尊敬的VIP2会员，我已经将你传送至#r会员等级2地图-闹钟之家#n#k了.欢迎再次光临!"); 
				   cm.dispose();
				   }else{
                   cm.sendOk("#b你不是会员2级，请联系GM给你在线开通!");
                   cm.dispose();   }     
            } else if (selection == 3) {
            if(cm.getChar().getVip() >= 3) {
                   cm.warp(920010000, 0);
cm.sendOk("尊敬的VIP3会员，我已经将你传送至#r会员等级3地图-天空之蓝色的天空#n#k了.欢迎再次光临!"); 
                   cm.dispose(); 
                   }else{
                   cm.sendOk("#b你不是会员3级，请联系GM给你在线开通!");
                   cm.dispose();   }         
          } else if (selection == 6) {
                   cm.ZreHypvpdeaths();
                   cm.dispose();    
            } else if (selection == 9) {
                   cm.ZreHyzs();
                   cm.dispose();  
            } else if (selection == 10) {
                   cm.displayGuildRanks();
	               cm.dispose();  
            } else if (selection == 11) {
                   cm.sendOk("#b(01)聊天栏里输入@help可以打开玩家帮助 \r\n(02)点TRADE可以直接传送到自由市场。#l \r\n(03)各城市的NaNa说不定会有好东西卖哦!  \r\n(04)海底世界海豚学习骑宠和砸卷技能，海底防具店买骑宠。 \r\n(05)射手村的宠物管理员Cloy能告诉你关于宠物的一切 \r\n(06)此端由稻、香全部提供技术支持!\r\n(07).GM不能随便改游戏里的资料，不如说改游戏里的经验，或者其它游戏里的资料，如果发现了第1次给警告处分,第2次以上就取消GM权利!\r\n(08).GM不能随便丈着自己是GM乱去F别人的号，或者是为了自己个人的利益去送被人GM帽子，这样是违犯了GM手册里的规定发现1次警告并且没收你的GM帽子和送给被人的帽子，也不能去帮别人去砸武器。\r\n(09).GM有空的话就去给玩家搞活动，玩家需要帮忙的时候要热心的去帮助玩家，这样才可以增加玩家对本F的热爱。\r\n(10).GM有空的时候到处去看看，看有没有人用G的，有就F了他的号，不能看见了当没看见，看见的就F号着样才象一个有责任心的GM。\r\n(11).GM不能随便在自由市场招怪，要搞活动的时候招，乱召唤的第1次警告2次以上停职1到2天反醒，好好的学习GM手册。\r\n(12).GM不能随便把自己的装备借给玩家用，着样玩家就不想买VIP了这样都F的利益也不好，不借东西给玩家好好管F做好自己的本职工作，买VIP的人也多了，也会让F更强大。\r\n(13).GM不用乱去用GM命令这样F会崩溃的，崩溃以后大家都不能玩，希望GM们不要乱去用GM的命令，GM命令给你们是为了帮助玩家，玩好这个游戏，让他们爱上这游戏，所以该用GM命令的时候就用，不该用的时候就不要用，希望各位GM能去遵守。\r\n(14).#r要求其实也不多希望大家能去遵守着以上的条件。如果不愿意做的，还有很多玩家想做GM，希望做了GM的人好好做好工作，珍惜GM的权利!#b\n");
                        cm.dispose();   
            } else if (selection == 13) {
                   cm.ZreHylvl(); 
                   cm.dispose();  
            } else if (selection == 14) {
                   cm.sendOk("请不要使用任何外挂程序,否则封号不给予任何解释!请GM做好本份工作,见挂即封!一起发扬ZreHy精神! ");

				 cm.dispose();   
      } else if (selection == 15) {
                   cm.ZreHyfame(); 
                   cm.dispose(); 
     } else if (selection == 16) {
                   cm.ZreHymeso(); 
                   cm.dispose(); 
            } else if (selection == 12) {
                   cm.ZreHypvpkills();
                   cm.dispose();   
				
			}
		}
	}
}