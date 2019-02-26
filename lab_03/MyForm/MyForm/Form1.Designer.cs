namespace MyForm
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.axActiveXCPP21 = new AxActiveXCPP2Lib.AxActiveXCPP2();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.axActiveXCPP21)).BeginInit();
            this.SuspendLayout();
            // 
            // axActiveXCPP21
            // 
            this.axActiveXCPP21.Enabled = true;
            this.axActiveXCPP21.Location = new System.Drawing.Point(0, 0);
            this.axActiveXCPP21.Name = "axActiveXCPP21";
            this.axActiveXCPP21.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axActiveXCPP21.OcxState")));
            this.axActiveXCPP21.Size = new System.Drawing.Size(100, 50);
            this.axActiveXCPP21.TabIndex = 0;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(209, 263);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(406, 43);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.axActiveXCPP21);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.axActiveXCPP21)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private AxActiveXCPP2Lib.AxActiveXCPP2 axActiveXCPP21;
        private System.Windows.Forms.Button button1;
    }
}

