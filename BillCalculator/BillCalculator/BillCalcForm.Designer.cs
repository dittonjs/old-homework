namespace BillCalculator
{
    partial class BillCalcForm
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
            this.bevCombo = new System.Windows.Forms.ComboBox();
            this.appCombo = new System.Windows.Forms.ComboBox();
            this.mainCombo = new System.Windows.Forms.ComboBox();
            this.desCombo = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.bevCost = new System.Windows.Forms.Label();
            this.appCost = new System.Windows.Forms.Label();
            this.mainCost = new System.Windows.Forms.Label();
            this.desCost = new System.Windows.Forms.Label();
            this.costText = new System.Windows.Forms.TextBox();
            this.taxText = new System.Windows.Forms.TextBox();
            this.totalText = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.clearButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // bevCombo
            // 
            this.bevCombo.FormattingEnabled = true;
            this.bevCombo.Items.AddRange(new object[] {
            "Soda",
            "Tea",
            "Coffee",
            "Mineral Water",
            "Juice",
            "Milk"});
            this.bevCombo.Location = new System.Drawing.Point(13, 13);
            this.bevCombo.Name = "bevCombo";
            this.bevCombo.Size = new System.Drawing.Size(121, 21);
            this.bevCombo.TabIndex = 0;
            this.bevCombo.SelectedIndexChanged += new System.EventHandler(this.bevCombo_SelectedIndexChanged);
            // 
            // appCombo
            // 
            this.appCombo.FormattingEnabled = true;
            this.appCombo.Items.AddRange(new object[] {
            "Buffalo Wings",
            "Buffalo Fingers",
            "Potato Skins",
            "Nachos",
            "Mushroom Caps",
            "Shrimp Cocktail",
            "CHips and Salsa"});
            this.appCombo.Location = new System.Drawing.Point(13, 41);
            this.appCombo.Name = "appCombo";
            this.appCombo.Size = new System.Drawing.Size(121, 21);
            this.appCombo.TabIndex = 1;
            this.appCombo.SelectedIndexChanged += new System.EventHandler(this.appCombo_SelectedIndexChanged);
            // 
            // mainCombo
            // 
            this.mainCombo.FormattingEnabled = true;
            this.mainCombo.Items.AddRange(new object[] {
            "Seafood Alfredo",
            "Chicken Alfredo",
            "Chicken Picatta",
            "Turkey Club",
            "Lobster Pie",
            "Prime Rib",
            "Shrimp Scampi",
            "Turkey Dinner",
            "Stuffed Chicken"});
            this.mainCombo.Location = new System.Drawing.Point(13, 69);
            this.mainCombo.Name = "mainCombo";
            this.mainCombo.Size = new System.Drawing.Size(121, 21);
            this.mainCombo.TabIndex = 2;
            this.mainCombo.SelectedIndexChanged += new System.EventHandler(this.mainCombo_SelectedIndexChanged);
            // 
            // desCombo
            // 
            this.desCombo.FormattingEnabled = true;
            this.desCombo.Items.AddRange(new object[] {
            "Apple Pie",
            "Sundae",
            "Carrot Cake",
            "Mud Oie",
            "Apple Crisp"});
            this.desCombo.Location = new System.Drawing.Point(13, 97);
            this.desCombo.Name = "desCombo";
            this.desCombo.Size = new System.Drawing.Size(121, 21);
            this.desCombo.TabIndex = 3;
            this.desCombo.SelectedIndexChanged += new System.EventHandler(this.desCombo_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(141, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Beverages";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(141, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Appetizers";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(141, 72);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(66, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Main Course";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(141, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Dessert";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // bevCost
            // 
            this.bevCost.AutoSize = true;
            this.bevCost.Location = new System.Drawing.Point(363, 20);
            this.bevCost.Name = "bevCost";
            this.bevCost.Size = new System.Drawing.Size(28, 13);
            this.bevCost.TabIndex = 8;
            this.bevCost.Text = "0.00";
            // 
            // appCost
            // 
            this.appCost.AutoSize = true;
            this.appCost.Location = new System.Drawing.Point(363, 44);
            this.appCost.Name = "appCost";
            this.appCost.Size = new System.Drawing.Size(28, 13);
            this.appCost.TabIndex = 9;
            this.appCost.Text = "0.00";
            // 
            // mainCost
            // 
            this.mainCost.AutoSize = true;
            this.mainCost.Location = new System.Drawing.Point(363, 72);
            this.mainCost.Name = "mainCost";
            this.mainCost.Size = new System.Drawing.Size(28, 13);
            this.mainCost.TabIndex = 10;
            this.mainCost.Text = "0.00";
            // 
            // desCost
            // 
            this.desCost.AutoSize = true;
            this.desCost.Location = new System.Drawing.Point(363, 100);
            this.desCost.Name = "desCost";
            this.desCost.Size = new System.Drawing.Size(28, 13);
            this.desCost.TabIndex = 11;
            this.desCost.Text = "0.00";
            // 
            // costText
            // 
            this.costText.Location = new System.Drawing.Point(13, 190);
            this.costText.Name = "costText";
            this.costText.Size = new System.Drawing.Size(100, 20);
            this.costText.TabIndex = 12;
            // 
            // taxText
            // 
            this.taxText.Location = new System.Drawing.Point(189, 190);
            this.taxText.Name = "taxText";
            this.taxText.Size = new System.Drawing.Size(100, 20);
            this.taxText.TabIndex = 13;
            // 
            // totalText
            // 
            this.totalText.Location = new System.Drawing.Point(357, 190);
            this.totalText.Name = "totalText";
            this.totalText.Size = new System.Drawing.Size(100, 20);
            this.totalText.TabIndex = 14;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(13, 171);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(28, 13);
            this.label5.TabIndex = 15;
            this.label5.Text = "Cost";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(186, 171);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(25, 13);
            this.label6.TabIndex = 16;
            this.label6.Text = "Tax";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(357, 171);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(31, 13);
            this.label7.TabIndex = 17;
            this.label7.Text = "Total";
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(202, 232);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(75, 23);
            this.clearButton.TabIndex = 18;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // BillCalcForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(469, 267);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.totalText);
            this.Controls.Add(this.taxText);
            this.Controls.Add(this.costText);
            this.Controls.Add(this.desCost);
            this.Controls.Add(this.mainCost);
            this.Controls.Add(this.appCost);
            this.Controls.Add(this.bevCost);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.desCombo);
            this.Controls.Add(this.mainCombo);
            this.Controls.Add(this.appCombo);
            this.Controls.Add(this.bevCombo);
            this.Name = "BillCalcForm";
            this.Text = "BillCalcForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox bevCombo;
        private System.Windows.Forms.ComboBox appCombo;
        private System.Windows.Forms.ComboBox mainCombo;
        private System.Windows.Forms.ComboBox desCombo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label bevCost;
        private System.Windows.Forms.Label appCost;
        private System.Windows.Forms.Label mainCost;
        private System.Windows.Forms.Label desCost;
        private System.Windows.Forms.TextBox costText;
        private System.Windows.Forms.TextBox taxText;
        private System.Windows.Forms.TextBox totalText;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button clearButton;
    }
}