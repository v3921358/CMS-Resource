/*
*
* ���а�ϵͳ NPC    By: ZreHy_MapleStory    ��վ��www.zrehymxd.cn
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
                
			cm.sendOk("�õ�,����������Ҫ��ʲô,�һ�������Ϊ������..");
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
			cm.sendSimple("ӭ���꣬�����Ķ����󽵼�!�������絼��С��(�������޸�)��Ϊ���ṩ�����ʵķ���\r\n #d#L1#��Ա�ȼ�1��԰#l #L2#��Ա�ȼ�2̽��#l #g#L3#��Ա�ȼ�3ʥ��#l \r\n\r\n#d#e#L9#��ת�����а�#l #L10#�����������а�#l #g#L16#�Ƹ�����#k\r\n\r\n#r#L15#������������а�#k #L12#��PK���а�#l\r\n\r\n#L13#���ȼ����а�(By:�������޸�)#l#n #e#b#L6#��ɱ�����а�#k#l\r\n\r\n#L14#����������#l#r #L11#��Ϸ˵��(����GM�ֲ�)#l  #b");
			} else if (status == 1) {
			if (selection == 1) {
				   if(cm.getChar().getVip() >= 1) {
                   cm.warp(209000000, 0);
                   cm.sendOk("�𾴵�VIP1��Ա�����Ѿ����㴫����#r��Ա�ȼ�1��ͼ-�Ҹ���#n#k��.��ӭ�ٴι���!"); 
				   cm.dispose();
				   }else{
                   cm.sendOk("#b�㲻�ǻ�Ա1��������ϵGM�������߿�ͨ!");
                   cm.dispose();   }  
			} else if  (selection == 2) {
				   if(cm.getChar().getVip() >= 2) {
                   cm.warp(922020300, 0);
cm.sendOk("�𾴵�VIP2��Ա�����Ѿ����㴫����#r��Ա�ȼ�2��ͼ-����֮��#n#k��.��ӭ�ٴι���!"); 
				   cm.dispose();
				   }else{
                   cm.sendOk("#b�㲻�ǻ�Ա2��������ϵGM�������߿�ͨ!");
                   cm.dispose();   }     
            } else if (selection == 3) {
            if(cm.getChar().getVip() >= 3) {
                   cm.warp(920010000, 0);
cm.sendOk("�𾴵�VIP3��Ա�����Ѿ����㴫����#r��Ա�ȼ�3��ͼ-���֮��ɫ�����#n#k��.��ӭ�ٴι���!"); 
                   cm.dispose(); 
                   }else{
                   cm.sendOk("#b�㲻�ǻ�Ա3��������ϵGM�������߿�ͨ!");
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
                   cm.sendOk("#b(01)������������@help���Դ���Ұ��� \r\n(02)��TRADE����ֱ�Ӵ��͵������г���#l \r\n(03)�����е�NaNa˵�������кö�����Ŷ!  \r\n(04)�������纣��ѧϰ�����Ҿ��ܣ����׷��ߵ�����衣 \r\n(05)���ִ�ĳ������ԱCloy�ܸ�������ڳ����һ�� \r\n(06)�˶��ɵ�����ȫ���ṩ����֧��!\r\n(07).GM����������Ϸ������ϣ�����˵����Ϸ��ľ��飬����������Ϸ������ϣ���������˵�1�θ����洦��,��2�����Ͼ�ȡ��GMȨ��!\r\n(08).GM������������Լ���GM��ȥF���˵ĺţ�������Ϊ���Լ����˵�����ȥ�ͱ���GMñ�ӣ�������Υ����GM�ֲ���Ĺ涨����1�ξ��沢��û�����GMñ�Ӻ��͸����˵�ñ�ӣ�Ҳ����ȥ�����ȥ��������\r\n(09).GM�пյĻ���ȥ����Ҹ��������Ҫ��æ��ʱ��Ҫ���ĵ�ȥ������ң������ſ���������ҶԱ�F���Ȱ���\r\n(10).GM�пյ�ʱ�򵽴�ȥ����������û������G�ģ��о�F�����ĺţ����ܿ����˵�û�����������ľ�F����������һ���������ĵ�GM��\r\n(11).GM��������������г��й֣�Ҫ����ʱ���У����ٻ��ĵ�1�ξ���2������ְͣ1��2�췴�ѣ��úõ�ѧϰGM�ֲᡣ\r\n(12).GM���������Լ���װ���������ã�������ҾͲ�����VIP��������F������Ҳ���ã����趫������Һúù�F�����Լ��ı�ְ��������VIP����Ҳ���ˣ�Ҳ����F��ǿ��\r\n(13).GM������ȥ��GM��������F������ģ������Ժ��Ҷ������棬ϣ��GM�ǲ�Ҫ��ȥ��GM�����GM�����������Ϊ�˰�����ң���������Ϸ�������ǰ�������Ϸ�����Ը���GM�����ʱ����ã������õ�ʱ��Ͳ�Ҫ�ã�ϣ����λGM��ȥ���ء�\r\n(14).#rҪ����ʵҲ����ϣ�������ȥ���������ϵ������������Ը�����ģ����кܶ��������GM��ϣ������GM���˺ú����ù�������ϧGM��Ȩ��!#b\n");
                        cm.dispose();   
            } else if (selection == 13) {
                   cm.ZreHylvl(); 
                   cm.dispose();  
            } else if (selection == 14) {
                   cm.sendOk("�벻Ҫʹ���κ���ҳ���,�����Ų������κν���!��GM���ñ��ݹ���,���Ҽ���!һ����ZreHy����! ");

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