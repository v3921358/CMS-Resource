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
            cm.sendOk("很好下次再见");
            cm.dispose();
            return;
        }
        if (mode == 1)
            status++;
        else
            status--;
        if (status == 0) {
            cm.sendNext("嗨。！ #h #! 我是 #bXX冒险岛赌博NPC#k!想参与金钱娱乐的游戏吗？哈哈 你先下注吧 ");
        } else if (status == 1) {
            cm.sendGetText("你想下注多少金额呢?如果赢了的话可以获得双倍的收益,哈哈快输入金额吧");
        } else if (status == 2) {
            fee = cm.getText();
            cm.sendYesNo("你确定要下注 #r" + fee + "#k 冒险币吗?请先检查你有没有那么多钱哦");
        } else if (status == 3) {
            if (cm.getMeso() < fee) {
                cm.sendOk("哦呵，不好意思你没那么多钱了，去赚点钱再来吧，这可不是免费的");
                cm.dispose();
            } else if (cm.getMeso() >= 1050000000) {
                cm.sendOk("哦不好意思哦这里最大赌注不能超过1050000000");
                cm.dispose();
            } else if (cm.getText() < 0) {
                cm.sendOk("亏你想得出来，居然输入负数，一边去!");
                cm.dispose();
            } else {
                if (chance <= 1) {
                    cm.gainMeso(-fee);
                    cm.sendNext("哦··你的运气不怎么好哦··哈哈 再来一把嘛");
                    cm.dispose();
                }
                else if (chance == 2) {
                    cm.gainMeso(-fee);
                    cm.sendNext("哦··你的运气不怎么好哦··哈哈 再来一把嘛");
                    cm.dispose();
                }
                else if (chance == 3) {
                    cm.gainMeso(-fee);
                    cm.sendNext("哦··你的运气不怎么好哦··哈哈 再来一把嘛");
                    cm.dispose();
                }
                else if (chance >= 4) {
                    cm.gainMeso(fee * 2);
                    cm.sendNext("#r哈哈，恭喜你#k! 你赢了! 看来你手气不错再来一把哈");
                                        cm.serverNotice(恭喜玩家" + getName() + "在这一轮的博彩中获胜");
                    cm.dispose();
                }
            }
        }
    }
}