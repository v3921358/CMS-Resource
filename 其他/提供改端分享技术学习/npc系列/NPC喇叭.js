/*
======================================
 囧囧改端技术  囧囧收集正式发布
======================================
*/
var status = 0; 
var shout = Array(1, 2, 3, 4); 
var shoutname = Array("来恋爱吧", "去旅游吧", "想死是吧", "动真格了"); 
var cose = Array(30, 20, 40, 100); 
var selectedShout = -1; 
var text;

function start() { 
    status = -1; 
    action(1, 0, 0); 
} 

function action(mode, type, selection) { 
    if (mode == -1) { 
        cm.dispose(); 
    } else { 
        if (status >= -1 && mode == 0) { 
            cm.sendOk("感谢您的光临！"); 
            cm.dispose(); 
            return; 
        } 
        if (mode == 1) 
            status++; 
        else { 
            cm.sendOk("感谢您的光临！"); 
            cm.dispose(); 
            return; 
        } if (status == 0) { 
            cm.sendYesNo("你好，我是系统喇叭服务员，在这里可以使用系统喇叭"); 
        } else if (status == 1) { 
            var selStr = "请选择喇叭类型.#b"; 
                for (var i = 0; i < shout.length; i++) { 
                selStr += "\r\n#L" + i + "#" + shoutname[ i ]+""; 
                } 
            cm.sendSimple(selStr);   
        } else if (status == 2) {
            selectedShout = selection; 
            cm.sendGetText("请输入喇叭内容");
        } else if (status == 3) { 
            text = cm.getText();
            cm.sendYesNo("你真的要使用#r" + shoutname[selectedShout] + "#k吗?\r\n#b(需要:#r "  +cose[selectedShout] + "#b金币)#k");
        } else if (status == 4) { 
        if(cm.getMeso() < cose[selectedShout]) {
        cm.sendOk("你的金币不够啊!");
        cm.dispose(); 
        }else{
        cm.gainMeso(-cose[selectedShout]);
            switch(shout[selectedShout]) {
                case 1: case 2: case 3: 
                cm.shout(shout[selectedShout],text);
                break;
                case 4: 
                cm.serverNotice(cm.getChar().getName() + " : " + text);
                cm.serverTop(cm.getChar().getName() + " : " + text);
                break;
            }
        }
        cm.dispose();     
      }
    }
}