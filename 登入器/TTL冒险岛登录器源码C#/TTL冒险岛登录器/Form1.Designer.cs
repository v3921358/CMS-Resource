
namespace TTL冒险岛登录器
{
    partial class 主窗体
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(主窗体));
            this.按钮_开始 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // 按钮_开始
            // 
            this.按钮_开始.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.按钮_开始.Location = new System.Drawing.Point(102, 110);
            this.按钮_开始.Name = "按钮_开始";
            this.按钮_开始.Size = new System.Drawing.Size(105, 28);
            this.按钮_开始.TabIndex = 0;
            this.按钮_开始.Text = "开始";
            this.按钮_开始.UseVisualStyleBackColor = true;
            this.按钮_开始.Click += new System.EventHandler(this.按钮_开始_Click);
            // 
            // 主窗体
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Clock;
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Inherit;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(322, 332);
            this.Controls.Add(this.按钮_开始);
            this.Cursor = System.Windows.Forms.Cursors.Hand;
            this.Font = new System.Drawing.Font("幼圆", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "主窗体";
            this.Text = "愉悦冒险岛";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button 按钮_开始;
    }
}

