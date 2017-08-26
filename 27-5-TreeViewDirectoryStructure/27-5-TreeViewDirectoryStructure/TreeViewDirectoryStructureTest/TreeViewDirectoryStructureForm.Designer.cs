namespace TreeViewDirectoryStructure
{
   partial class TreeViewDirectoryStructureForm
   {
      /// <summary>
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose( bool disposing )
      {
         if ( disposing && ( components != null ) )
         {
            components.Dispose();
         }
         base.Dispose( disposing );
      }

      #region Windows Form Designer generated code

      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
            this.enterButton = new System.Windows.Forms.Button();
            this.inputTextBox = new System.Windows.Forms.TextBox();
            this.promptLabel = new System.Windows.Forms.Label();
            this.directoryTreeView = new System.Windows.Forms.TreeView();
            this.FileListView = new System.Windows.Forms.ListView();
            this.SearchBox = new System.Windows.Forms.TextBox();
            this.SearchButton = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // enterButton
            // 
            this.enterButton.Location = new System.Drawing.Point(504, 27);
            this.enterButton.Name = "enterButton";
            this.enterButton.Size = new System.Drawing.Size(100, 23);
            this.enterButton.TabIndex = 15;
            this.enterButton.Text = "Enter";
            this.enterButton.Click += new System.EventHandler(this.enterButton_Click);
            // 
            // inputTextBox
            // 
            this.inputTextBox.Location = new System.Drawing.Point(12, 27);
            this.inputTextBox.Name = "inputTextBox";
            this.inputTextBox.Size = new System.Drawing.Size(486, 23);
            this.inputTextBox.TabIndex = 14;
            // 
            // promptLabel
            // 
            this.promptLabel.AutoSize = true;
            this.promptLabel.Location = new System.Drawing.Point(9, 9);
            this.promptLabel.Name = "promptLabel";
            this.promptLabel.Size = new System.Drawing.Size(309, 15);
            this.promptLabel.TabIndex = 13;
            this.promptLabel.Text = "Enter the full path to the directory you would like to view:";
            // 
            // directoryTreeView
            // 
            this.directoryTreeView.Location = new System.Drawing.Point(12, 56);
            this.directoryTreeView.Name = "directoryTreeView";
            this.directoryTreeView.Size = new System.Drawing.Size(389, 605);
            this.directoryTreeView.TabIndex = 12;
            this.directoryTreeView.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.directoryTreeView_NodeMouseClick);
            // 
            // FileListView
            // 
            this.FileListView.CheckBoxes = true;
            this.FileListView.GridLines = true;
            this.FileListView.Location = new System.Drawing.Point(407, 56);
            this.FileListView.Name = "FileListView";
            this.FileListView.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.FileListView.Size = new System.Drawing.Size(626, 568);
            this.FileListView.TabIndex = 16;
            this.FileListView.UseCompatibleStateImageBehavior = false;
            this.FileListView.View = System.Windows.Forms.View.List;
            // 
            // SearchBox
            // 
            this.SearchBox.Location = new System.Drawing.Point(621, 28);
            this.SearchBox.Name = "SearchBox";
            this.SearchBox.Size = new System.Drawing.Size(123, 23);
            this.SearchBox.TabIndex = 17;
            // 
            // SearchButton
            // 
            this.SearchButton.Location = new System.Drawing.Point(750, 28);
            this.SearchButton.Name = "SearchButton";
            this.SearchButton.Size = new System.Drawing.Size(75, 23);
            this.SearchButton.TabIndex = 18;
            this.SearchButton.Text = "Search";
            this.SearchButton.UseVisualStyleBackColor = true;
            this.SearchButton.Click += new System.EventHandler(this.SearchButton_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(621, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(170, 15);
            this.label1.TabIndex = 19;
            this.label1.Text = "Enter File Name (Not Full Path)";
            // 
            // DeleteButton
            // 
            this.DeleteButton.Location = new System.Drawing.Point(488, 630);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(75, 23);
            this.DeleteButton.TabIndex = 20;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.DeleteButton_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(407, 630);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 21;
            this.button1.Text = "Open";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // TreeViewDirectoryStructureForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1045, 669);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.DeleteButton);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SearchButton);
            this.Controls.Add(this.SearchBox);
            this.Controls.Add(this.FileListView);
            this.Controls.Add(this.enterButton);
            this.Controls.Add(this.inputTextBox);
            this.Controls.Add(this.promptLabel);
            this.Controls.Add(this.directoryTreeView);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "TreeViewDirectoryStructureForm";
            this.Text = "TreeViewDirectoryStructure";
            this.ResumeLayout(false);
            this.PerformLayout();

      }

      #endregion

      internal System.Windows.Forms.Button enterButton;
      internal System.Windows.Forms.TextBox inputTextBox;
      internal System.Windows.Forms.Label promptLabel;
      internal System.Windows.Forms.TreeView directoryTreeView;
      private System.Windows.Forms.ListView FileListView;
      private System.Windows.Forms.TextBox SearchBox;
      private System.Windows.Forms.Button SearchButton;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.Button DeleteButton;
      private System.Windows.Forms.Button button1;

   }
}

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
