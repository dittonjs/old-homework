namespace SpamScanner
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
            this.WordListTab = new System.Windows.Forms.TabPage();
            this.AddWordButton = new System.Windows.Forms.Button();
            this.AddWorkText = new System.Windows.Forms.TextBox();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.VerdictLabel = new System.Windows.Forms.Label();
            this.ScoreLabel = new System.Windows.Forms.Label();
            this.CheckButton = new System.Windows.Forms.Button();
            this.EntryLabel = new System.Windows.Forms.Label();
            this.EmailEntry = new System.Windows.Forms.RichTextBox();
            this.TextEntryTab = new System.Windows.Forms.TabControl();
            this.label1 = new System.Windows.Forms.Label();
            this.WordListText = new System.Windows.Forms.RichTextBox();
            this.WordListTab.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.TextEntryTab.SuspendLayout();
            this.SuspendLayout();
            // 
            // WordListTab
            // 
            this.WordListTab.Controls.Add(this.WordListText);
            this.WordListTab.Controls.Add(this.AddWordButton);
            this.WordListTab.Controls.Add(this.AddWorkText);
            this.WordListTab.Location = new System.Drawing.Point(4, 22);
            this.WordListTab.Name = "WordListTab";
            this.WordListTab.Padding = new System.Windows.Forms.Padding(3);
            this.WordListTab.Size = new System.Drawing.Size(599, 355);
            this.WordListTab.TabIndex = 1;
            this.WordListTab.Text = "Word List";
            this.WordListTab.UseVisualStyleBackColor = true;
            // 
            // AddWordButton
            // 
            this.AddWordButton.Location = new System.Drawing.Point(114, 6);
            this.AddWordButton.Name = "AddWordButton";
            this.AddWordButton.Size = new System.Drawing.Size(75, 23);
            this.AddWordButton.TabIndex = 2;
            this.AddWordButton.Text = "Add Word";
            this.AddWordButton.UseVisualStyleBackColor = true;
            this.AddWordButton.Click += new System.EventHandler(this.AddWordButton_Click);
            // 
            // AddWorkText
            // 
            this.AddWorkText.Location = new System.Drawing.Point(8, 6);
            this.AddWorkText.Name = "AddWorkText";
            this.AddWorkText.Size = new System.Drawing.Size(100, 20);
            this.AddWorkText.TabIndex = 1;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.VerdictLabel);
            this.tabPage1.Controls.Add(this.ScoreLabel);
            this.tabPage1.Controls.Add(this.CheckButton);
            this.tabPage1.Controls.Add(this.EntryLabel);
            this.tabPage1.Controls.Add(this.EmailEntry);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(599, 355);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "TextEntry";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // VerdictLabel
            // 
            this.VerdictLabel.AutoSize = true;
            this.VerdictLabel.Location = new System.Drawing.Point(257, 293);
            this.VerdictLabel.Name = "VerdictLabel";
            this.VerdictLabel.Size = new System.Drawing.Size(40, 13);
            this.VerdictLabel.TabIndex = 4;
            this.VerdictLabel.Text = "Verdict";
            // 
            // ScoreLabel
            // 
            this.ScoreLabel.AutoSize = true;
            this.ScoreLabel.Location = new System.Drawing.Point(130, 293);
            this.ScoreLabel.Name = "ScoreLabel";
            this.ScoreLabel.Size = new System.Drawing.Size(38, 13);
            this.ScoreLabel.TabIndex = 3;
            this.ScoreLabel.Text = "Score:";
            // 
            // CheckButton
            // 
            this.CheckButton.Location = new System.Drawing.Point(12, 288);
            this.CheckButton.Name = "CheckButton";
            this.CheckButton.Size = new System.Drawing.Size(75, 23);
            this.CheckButton.TabIndex = 2;
            this.CheckButton.Text = "Check";
            this.CheckButton.UseVisualStyleBackColor = true;
            this.CheckButton.Click += new System.EventHandler(this.CheckButton_Click);
            // 
            // EntryLabel
            // 
            this.EntryLabel.AutoSize = true;
            this.EntryLabel.Location = new System.Drawing.Point(9, 21);
            this.EntryLabel.Name = "EntryLabel";
            this.EntryLabel.Size = new System.Drawing.Size(114, 13);
            this.EntryLabel.TabIndex = 1;
            this.EntryLabel.Text = "Enter Your Email Here:";
            // 
            // EmailEntry
            // 
            this.EmailEntry.Location = new System.Drawing.Point(8, 40);
            this.EmailEntry.Name = "EmailEntry";
            this.EmailEntry.Size = new System.Drawing.Size(580, 95);
            this.EmailEntry.TabIndex = 0;
            this.EmailEntry.Text = "";
            // 
            // TextEntryTab
            // 
            this.TextEntryTab.Controls.Add(this.tabPage1);
            this.TextEntryTab.Controls.Add(this.WordListTab);
            this.TextEntryTab.Location = new System.Drawing.Point(0, 0);
            this.TextEntryTab.Name = "TextEntryTab";
            this.TextEntryTab.SelectedIndex = 0;
            this.TextEntryTab.Size = new System.Drawing.Size(607, 381);
            this.TextEntryTab.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 142);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(52, 13);
            this.label1.TabIndex = 6;
            this.label1.Text = "Word List";
            // 
            // WordListText
            // 
            this.WordListText.Location = new System.Drawing.Point(6, 35);
            this.WordListText.Name = "WordListText";
            this.WordListText.Size = new System.Drawing.Size(581, 240);
            this.WordListText.TabIndex = 6;
            this.WordListText.Text = "";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(605, 381);
            this.Controls.Add(this.TextEntryTab);
            this.Name = "Form1";
            this.Text = "Form1";
            this.WordListTab.ResumeLayout(false);
            this.WordListTab.PerformLayout();
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.TextEntryTab.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage WordListTab;
        private System.Windows.Forms.Button AddWordButton;
        private System.Windows.Forms.TextBox AddWorkText;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.Label VerdictLabel;
        private System.Windows.Forms.Label ScoreLabel;
        private System.Windows.Forms.Button CheckButton;
        private System.Windows.Forms.Label EntryLabel;
        private System.Windows.Forms.RichTextBox EmailEntry;
        private System.Windows.Forms.TabControl TextEntryTab;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox WordListText;

    }
}

