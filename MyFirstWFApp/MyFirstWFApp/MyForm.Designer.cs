namespace MyFirstWFApp
{
    partial class MyForm
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
            this.MyButton = new System.Windows.Forms.Button();
            this.NameLable = new System.Windows.Forms.Label();
            this.NameTextBox = new System.Windows.Forms.TextBox();
            this.DisplayLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // MyButton
            // 
            this.MyButton.BackColor = System.Drawing.SystemColors.ControlDark;
            this.MyButton.Location = new System.Drawing.Point(207, 43);
            this.MyButton.Name = "MyButton";
            this.MyButton.Size = new System.Drawing.Size(100, 50);
            this.MyButton.TabIndex = 0;
            this.MyButton.Text = "Click Me";
            this.MyButton.UseVisualStyleBackColor = false;
            this.MyButton.Click += new System.EventHandler(this.MyButton_Click);
            // 
            // NameLable
            // 
            this.NameLable.AutoSize = true;
            this.NameLable.Location = new System.Drawing.Point(45, 62);
            this.NameLable.Name = "NameLable";
            this.NameLable.Size = new System.Drawing.Size(38, 13);
            this.NameLable.TabIndex = 1;
            this.NameLable.Text = "Name:";
            // 
            // NameTextBox
            // 
            this.NameTextBox.Location = new System.Drawing.Point(89, 59);
            this.NameTextBox.Name = "NameTextBox";
            this.NameTextBox.Size = new System.Drawing.Size(112, 20);
            this.NameTextBox.TabIndex = 2;
            this.NameTextBox.TextChanged += new System.EventHandler(this.CheckIfValid);
            // 
            // DisplayLabel
            // 
            this.DisplayLabel.AutoSize = true;
            this.DisplayLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DisplayLabel.ForeColor = System.Drawing.Color.Red;
            this.DisplayLabel.Location = new System.Drawing.Point(16, 104);
            this.DisplayLabel.Name = "DisplayLabel";
            this.DisplayLabel.Size = new System.Drawing.Size(86, 31);
            this.DisplayLabel.TabIndex = 3;
            this.DisplayLabel.Text = "label1";
            this.DisplayLabel.Visible = false;
            // 
            // MyForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(319, 161);
            this.Controls.Add(this.DisplayLabel);
            this.Controls.Add(this.NameTextBox);
            this.Controls.Add(this.NameLable);
            this.Controls.Add(this.MyButton);
            this.Name = "MyForm";
            this.Text = "Greeting";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button MyButton;
        private System.Windows.Forms.Label NameLable;
        private System.Windows.Forms.TextBox NameTextBox;
        private System.Windows.Forms.Label DisplayLabel;
    }
}

