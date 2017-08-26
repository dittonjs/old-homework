namespace LinkLabelTest
{
    partial class Form1
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
            this.cLink = new System.Windows.Forms.LinkLabel();
            this.webLabel = new System.Windows.Forms.LinkLabel();
            this.notepadLabel = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // cLink
            // 
            this.cLink.AutoSize = true;
            this.cLink.Location = new System.Drawing.Point(13, 13);
            this.cLink.Name = "cLink";
            this.cLink.Size = new System.Drawing.Size(105, 13);
            this.cLink.TabIndex = 0;
            this.cLink.TabStop = true;
            this.cLink.Text = "Click to open C drive";
            this.cLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // webLabel
            // 
            this.webLabel.AutoSize = true;
            this.webLabel.Location = new System.Drawing.Point(12, 44);
            this.webLabel.Name = "webLabel";
            this.webLabel.Size = new System.Drawing.Size(84, 13);
            this.webLabel.TabIndex = 1;
            this.webLabel.TabStop = true;
            this.webLabel.Text = "Visit google.com";
            this.webLabel.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.webLabel_LinkClicked);
            // 
            // notepadLabel
            // 
            this.notepadLabel.AutoSize = true;
            this.notepadLabel.Location = new System.Drawing.Point(13, 77);
            this.notepadLabel.Name = "notepadLabel";
            this.notepadLabel.Size = new System.Drawing.Size(73, 13);
            this.notepadLabel.TabIndex = 2;
            this.notepadLabel.TabStop = true;
            this.notepadLabel.Text = "open notepad";
            this.notepadLabel.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.notepadLabel_LinkClicked);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.notepadLabel);
            this.Controls.Add(this.webLabel);
            this.Controls.Add(this.cLink);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.LinkLabel cLink;
        private System.Windows.Forms.LinkLabel webLabel;
        private System.Windows.Forms.LinkLabel notepadLabel;
    }
}

