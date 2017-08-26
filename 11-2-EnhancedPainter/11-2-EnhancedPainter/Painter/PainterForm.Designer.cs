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
            this.colorGroupBox = new System.Windows.Forms.GroupBox();
            this.blackRadioButton = new System.Windows.Forms.RadioButton();
            this.greenRadioButton = new System.Windows.Forms.RadioButton();
            this.blueRadioButton = new System.Windows.Forms.RadioButton();
            this.redRadioButton = new System.Windows.Forms.RadioButton();
            this.sizeGroupBox = new System.Windows.Forms.GroupBox();
            this.LargeRadioButton = new System.Windows.Forms.RadioButton();
            this.mediumRadioButton = new System.Windows.Forms.RadioButton();
            this.smallRadioButton = new System.Windows.Forms.RadioButton();
            this.paintingPanel = new System.Windows.Forms.Panel();
            this.colorGroupBox.SuspendLayout();
            this.sizeGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // colorGroupBox
            // 
            this.colorGroupBox.Controls.Add(this.blackRadioButton);
            this.colorGroupBox.Controls.Add(this.greenRadioButton);
            this.colorGroupBox.Controls.Add(this.blueRadioButton);
            this.colorGroupBox.Controls.Add(this.redRadioButton);
            this.colorGroupBox.Location = new System.Drawing.Point(29, 24);
            this.colorGroupBox.Name = "colorGroupBox";
            this.colorGroupBox.Size = new System.Drawing.Size(132, 126);
            this.colorGroupBox.TabIndex = 0;
            this.colorGroupBox.TabStop = false;
            this.colorGroupBox.Text = "Color";
            // 
            // blackRadioButton
            // 
            this.blackRadioButton.AutoSize = true;
            this.blackRadioButton.Location = new System.Drawing.Point(20, 101);
            this.blackRadioButton.Name = "blackRadioButton";
            this.blackRadioButton.Size = new System.Drawing.Size(53, 19);
            this.blackRadioButton.TabIndex = 3;
            this.blackRadioButton.Text = "Black";
            this.blackRadioButton.UseVisualStyleBackColor = true;
            // 
            // greenRadioButton
            // 
            this.greenRadioButton.AutoSize = true;
            this.greenRadioButton.Location = new System.Drawing.Point(20, 75);
            this.greenRadioButton.Name = "greenRadioButton";
            this.greenRadioButton.Size = new System.Drawing.Size(56, 19);
            this.greenRadioButton.TabIndex = 2;
            this.greenRadioButton.Text = "Green";
            this.greenRadioButton.UseVisualStyleBackColor = true;
            // 
            // blueRadioButton
            // 
            this.blueRadioButton.AutoSize = true;
            this.blueRadioButton.Location = new System.Drawing.Point(20, 49);
            this.blueRadioButton.Name = "blueRadioButton";
            this.blueRadioButton.Size = new System.Drawing.Size(48, 19);
            this.blueRadioButton.TabIndex = 1;
            this.blueRadioButton.Text = "Blue";
            this.blueRadioButton.UseVisualStyleBackColor = true;
            // 
            // redRadioButton
            // 
            this.redRadioButton.AutoSize = true;
            this.redRadioButton.Checked = true;
            this.redRadioButton.Location = new System.Drawing.Point(20, 23);
            this.redRadioButton.Name = "redRadioButton";
            this.redRadioButton.Size = new System.Drawing.Size(45, 19);
            this.redRadioButton.TabIndex = 0;
            this.redRadioButton.TabStop = true;
            this.redRadioButton.Text = "Red";
            this.redRadioButton.UseVisualStyleBackColor = true;
            // 
            // sizeGroupBox
            // 
            this.sizeGroupBox.Controls.Add(this.LargeRadioButton);
            this.sizeGroupBox.Controls.Add(this.mediumRadioButton);
            this.sizeGroupBox.Controls.Add(this.smallRadioButton);
            this.sizeGroupBox.Location = new System.Drawing.Point(29, 172);
            this.sizeGroupBox.Name = "sizeGroupBox";
            this.sizeGroupBox.Size = new System.Drawing.Size(132, 100);
            this.sizeGroupBox.TabIndex = 1;
            this.sizeGroupBox.TabStop = false;
            this.sizeGroupBox.Text = "Size";
            // 
            // LargeRadioButton
            // 
            this.LargeRadioButton.AutoSize = true;
            this.LargeRadioButton.Location = new System.Drawing.Point(20, 75);
            this.LargeRadioButton.Name = "LargeRadioButton";
            this.LargeRadioButton.Size = new System.Drawing.Size(54, 19);
            this.LargeRadioButton.TabIndex = 2;
            this.LargeRadioButton.Text = "Large";
            this.LargeRadioButton.UseVisualStyleBackColor = true;
            // 
            // mediumRadioButton
            // 
            this.mediumRadioButton.AutoSize = true;
            this.mediumRadioButton.Location = new System.Drawing.Point(20, 49);
            this.mediumRadioButton.Name = "mediumRadioButton";
            this.mediumRadioButton.Size = new System.Drawing.Size(70, 19);
            this.mediumRadioButton.TabIndex = 1;
            this.mediumRadioButton.Text = "Medium";
            this.mediumRadioButton.UseVisualStyleBackColor = true;
            // 
            // smallRadioButton
            // 
            this.smallRadioButton.AutoSize = true;
            this.smallRadioButton.Checked = true;
            this.smallRadioButton.Location = new System.Drawing.Point(20, 23);
            this.smallRadioButton.Name = "smallRadioButton";
            this.smallRadioButton.Size = new System.Drawing.Size(54, 19);
            this.smallRadioButton.TabIndex = 0;
            this.smallRadioButton.TabStop = true;
            this.smallRadioButton.Text = "Small";
            this.smallRadioButton.UseVisualStyleBackColor = true;
            // 
            // paintingPanel
            // 
            this.paintingPanel.BackColor = System.Drawing.SystemColors.Window;
            this.paintingPanel.Location = new System.Drawing.Point(193, 33);
            this.paintingPanel.Name = "paintingPanel";
            this.paintingPanel.Size = new System.Drawing.Size(280, 239);
            this.paintingPanel.TabIndex = 2;
            this.paintingPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.paintingPanel_MouseDown);
            this.paintingPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.paintingPanel_MouseMove);
            this.paintingPanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.paintingPanel_MouseUp);
            // 
            // PainterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(501, 302);
            this.Controls.Add(this.paintingPanel);
            this.Controls.Add(this.sizeGroupBox);
            this.Controls.Add(this.colorGroupBox);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PainterForm";
            this.Text = "Painter";
            this.colorGroupBox.ResumeLayout(false);
            this.colorGroupBox.PerformLayout();
            this.sizeGroupBox.ResumeLayout(false);
            this.sizeGroupBox.PerformLayout();
            this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.GroupBox colorGroupBox;
      private System.Windows.Forms.RadioButton blackRadioButton;
      private System.Windows.Forms.RadioButton greenRadioButton;
      private System.Windows.Forms.RadioButton blueRadioButton;
      private System.Windows.Forms.RadioButton redRadioButton;
      private System.Windows.Forms.GroupBox sizeGroupBox;
      private System.Windows.Forms.RadioButton LargeRadioButton;
      private System.Windows.Forms.RadioButton mediumRadioButton;
      private System.Windows.Forms.RadioButton smallRadioButton;
      private System.Windows.Forms.Panel paintingPanel;
   }
}

