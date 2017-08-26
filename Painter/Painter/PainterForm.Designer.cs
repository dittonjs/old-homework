namespace Painter
{
    partial class PainterForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.RedRadio = new System.Windows.Forms.RadioButton();
            this.GreenRadio = new System.Windows.Forms.RadioButton();
            this.BlueRadio = new System.Windows.Forms.RadioButton();
            this.SmallRadio = new System.Windows.Forms.RadioButton();
            this.MediumRadio = new System.Windows.Forms.RadioButton();
            this.LargeRadio = new System.Windows.Forms.RadioButton();
            this.YellowRadio = new System.Windows.Forms.RadioButton();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.panel1.Location = new System.Drawing.Point(120, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(247, 299);
            this.panel1.TabIndex = 0;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseUp);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.YellowRadio);
            this.groupBox1.Controls.Add(this.BlueRadio);
            this.groupBox1.Controls.Add(this.GreenRadio);
            this.groupBox1.Controls.Add(this.RedRadio);
            this.groupBox1.Location = new System.Drawing.Point(13, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(101, 150);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Color";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.LargeRadio);
            this.groupBox2.Controls.Add(this.MediumRadio);
            this.groupBox2.Controls.Add(this.SmallRadio);
            this.groupBox2.Location = new System.Drawing.Point(13, 178);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(101, 133);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Size";
            // 
            // RedRadio
            // 
            this.RedRadio.AutoSize = true;
            this.RedRadio.Checked = true;
            this.RedRadio.Location = new System.Drawing.Point(7, 20);
            this.RedRadio.Name = "RedRadio";
            this.RedRadio.Size = new System.Drawing.Size(45, 17);
            this.RedRadio.TabIndex = 0;
            this.RedRadio.TabStop = true;
            this.RedRadio.Text = "Red";
            this.RedRadio.UseVisualStyleBackColor = true;
            this.RedRadio.CheckedChanged += new System.EventHandler(this.RedRadio_CheckedChanged);
            // 
            // GreenRadio
            // 
            this.GreenRadio.AutoSize = true;
            this.GreenRadio.Location = new System.Drawing.Point(7, 44);
            this.GreenRadio.Name = "GreenRadio";
            this.GreenRadio.Size = new System.Drawing.Size(54, 17);
            this.GreenRadio.TabIndex = 1;
            this.GreenRadio.TabStop = true;
            this.GreenRadio.Text = "Green";
            this.GreenRadio.UseVisualStyleBackColor = true;
            this.GreenRadio.CheckedChanged += new System.EventHandler(this.GreenRadio_CheckedChanged);
            // 
            // BlueRadio
            // 
            this.BlueRadio.AutoSize = true;
            this.BlueRadio.Location = new System.Drawing.Point(7, 68);
            this.BlueRadio.Name = "BlueRadio";
            this.BlueRadio.Size = new System.Drawing.Size(46, 17);
            this.BlueRadio.TabIndex = 2;
            this.BlueRadio.TabStop = true;
            this.BlueRadio.Text = "Blue";
            this.BlueRadio.UseVisualStyleBackColor = true;
            this.BlueRadio.CheckedChanged += new System.EventHandler(this.BlueRadio_CheckedChanged);
            // 
            // SmallRadio
            // 
            this.SmallRadio.AutoSize = true;
            this.SmallRadio.Checked = true;
            this.SmallRadio.Location = new System.Drawing.Point(7, 20);
            this.SmallRadio.Name = "SmallRadio";
            this.SmallRadio.Size = new System.Drawing.Size(50, 17);
            this.SmallRadio.TabIndex = 0;
            this.SmallRadio.TabStop = true;
            this.SmallRadio.Text = "Small";
            this.SmallRadio.UseVisualStyleBackColor = true;
            this.SmallRadio.CheckedChanged += new System.EventHandler(this.SmallRadio_CheckedChanged);
            // 
            // MediumRadio
            // 
            this.MediumRadio.AutoSize = true;
            this.MediumRadio.Location = new System.Drawing.Point(7, 44);
            this.MediumRadio.Name = "MediumRadio";
            this.MediumRadio.Size = new System.Drawing.Size(62, 17);
            this.MediumRadio.TabIndex = 1;
            this.MediumRadio.TabStop = true;
            this.MediumRadio.Text = "Medium";
            this.MediumRadio.UseVisualStyleBackColor = true;
            this.MediumRadio.CheckedChanged += new System.EventHandler(this.MediumRadio_CheckedChanged);
            // 
            // LargeRadio
            // 
            this.LargeRadio.AutoSize = true;
            this.LargeRadio.Location = new System.Drawing.Point(7, 68);
            this.LargeRadio.Name = "LargeRadio";
            this.LargeRadio.Size = new System.Drawing.Size(52, 17);
            this.LargeRadio.TabIndex = 2;
            this.LargeRadio.TabStop = true;
            this.LargeRadio.Text = "Large";
            this.LargeRadio.UseVisualStyleBackColor = true;
            this.LargeRadio.CheckedChanged += new System.EventHandler(this.LargeRadio_CheckedChanged);
            // 
            // YellowRadio
            // 
            this.YellowRadio.AutoSize = true;
            this.YellowRadio.Location = new System.Drawing.Point(7, 92);
            this.YellowRadio.Name = "YellowRadio";
            this.YellowRadio.Size = new System.Drawing.Size(56, 17);
            this.YellowRadio.TabIndex = 3;
            this.YellowRadio.TabStop = true;
            this.YellowRadio.Text = "Yellow";
            this.YellowRadio.UseVisualStyleBackColor = true;
            this.YellowRadio.CheckedChanged += new System.EventHandler(this.YellowRadio_CheckedChanged);
            // 
            // PainterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(379, 323);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.panel1);
            this.Name = "PainterForm";
            this.Text = "Painter";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton YellowRadio;
        private System.Windows.Forms.RadioButton BlueRadio;
        private System.Windows.Forms.RadioButton GreenRadio;
        private System.Windows.Forms.RadioButton RedRadio;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton LargeRadio;
        private System.Windows.Forms.RadioButton MediumRadio;
        private System.Windows.Forms.RadioButton SmallRadio;
    }
}

