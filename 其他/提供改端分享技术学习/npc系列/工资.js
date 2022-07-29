/*
======================================
 囧囧改端技术  囧囧收集正式发布
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
            cm.sendOk("请需要领取工资再来找我吧！");
            status = 4;
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendNext("亲爱的#h #你好，再次见到你真是太荣幸了，我负责给VIP玩家每天派送工资的，如果确认你是VIP玩家请到我这里来领取工资，否则不要来打扰我！");
        } else if (status == 1) {            
            cm.sendYesNo("初级VIP每天可以领取3千万猪猪币\r\n中级VIP每天可以领取6千万猪猪币\r\n高级VIP每天可以领取1亿猪猪币\r\n你确定领取今天的工资吗？");
        } else if (status == 2) {
            if(cm.getChar().getVip() == 0) {
            cm.sendOk("对不起！你不是VIP会员无法领取工资。\r\n如需要请联系管理员#bQQ：22899960#k购买VIP会员！");
            } else if (cm.getBossLog('VIPGZ') >= 1) {
            cm.sendOk("抱歉，尊敬VIP玩家你今天己经领取工资，请明天再来找我吧！");
            } else if(cm.getChar().getVip() == 1) {
            cm.gainMeso(20000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("恭喜你领取今天的工资3千万猪猪币，您真是幸运的玩家");
            } else if(cm.getChar().getVip() == 2) {
            cm.gainMeso(50000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("恭喜你领取今天的工资6千万猪猪币，您真是幸运的玩家");
            } else if(cm.getChar().getVip() == 3) {
            cm.gainMeso(100000000);
            cm.setBossLog('VIPGZ');
            cm.sendOk("恭喜你领取今天的工资1亿猪猪币，您真是幸运的玩家");
            }
            cm.dispose();
        }
    }    } 