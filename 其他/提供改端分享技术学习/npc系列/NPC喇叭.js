/*
======================================
 ���Ķ˼���  ����ռ���ʽ����
======================================
*/
var status = 0; 
var shout = Array(1, 2, 3, 4); 
var shoutname = Array("��������", "ȥ���ΰ�", "�����ǰ�", "�������"); 
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
            cm.sendOk("��л���Ĺ��٣�"); 
            cm.dispose(); 
            return; 
        } 
        if (mode == 1) 
            status++; 
        else { 
            cm.sendOk("��л���Ĺ��٣�"); 
            cm.dispose(); 
            return; 
        } if (status == 0) { 
            cm.sendYesNo("��ã�����ϵͳ���ȷ���Ա�����������ʹ��ϵͳ����"); 
        } else if (status == 1) { 
            var selStr = "��ѡ����������.#b"; 
                for (var i = 0; i < shout.length; i++) { 
                selStr += "\r\n#L" + i + "#" + shoutname[ i ]+""; 
                } 
            cm.sendSimple(selStr);   
        } else if (status == 2) {
            selectedShout = selection; 
            cm.sendGetText("��������������");
        } else if (status == 3) { 
            text = cm.getText();
            cm.sendYesNo("�����Ҫʹ��#r" + shoutname[selectedShout] + "#k��?\r\n#b(��Ҫ:#r "  +cose[selectedShout] + "#b���)#k");
        } else if (status == 4) { 
        if(cm.getMeso() < cose[selectedShout]) {
        cm.sendOk("��Ľ�Ҳ�����!");
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