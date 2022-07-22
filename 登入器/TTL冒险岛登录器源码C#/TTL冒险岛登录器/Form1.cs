using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TTL冒险岛登录器
{
    public partial class 主窗体 : Form
    {
        public 主窗体()
        {
            InitializeComponent();
        }

        private void 按钮_开始_Click(object sender, EventArgs e)
        {
            try
            {
                // 启动外部程序
                Process proc = Process.Start("MapleStory.exe", "124.71.108.141 8484");
                if (proc != null)
                {
                    // 监视进程退出
                    proc.EnableRaisingEvents = true;
                    // 指定退出事件方法
                    proc.Exited += new EventHandler(OnExited);
                }
                Process[] 进程数组 = null;
                while (进程数组==null||进程数组.Length==0) {
                    进程数组= Process.GetProcessesByName("MapleStory");
                   
                }
              

                for (int i = 0; i < 进程数组.Length; i++)
                {
                    while (true) {
                        Thread.Sleep(2000);
                        PerformanceCounter pf1 = new PerformanceCounter("Process", "Working Set - Private", "MapleStory");
                        if ((pf1.NextValue() / 1024 / 1024) > 33)
                        {
                          
                            进程数组[i].Close();
                            Process[] s=  Process.GetProcessesByName("MapleStory");
                            for (int n = 0; n < s.Length; n++) {
                                if (s[n] != proc) {
                                 
                                    s[n].CloseMainWindow();
                                    MessageBox.Show("关闭进程成功");
                                }
                               
                            
                            }
                                
                            return;
                        }
                    }
                 
                       
                    
        
                   


                }
            }
            catch (ArgumentException ex)
            {
                MessageBox.Show(ex.Message, this.Text,
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public static void OnExited(object sender, EventArgs e)
        {
            Process[] ps = Process.GetProcessesByName("ad.");
            if (ps.Length != 0)
            {
                for (int i = 0; i < ps.Length; i++) {
                    ps[i].Kill();
                }
                return;
            }
            else {
                OnExited(sender, e);
            }
            
            /// exited event handle
        }
    }
}
