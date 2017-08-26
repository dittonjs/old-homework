using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstWFApp
{
    public partial class MyForm : Form
    {
        public MyForm()
        {
            InitializeComponent();
        }

        // WHEN MY BUTTON GETS CLICKED
        private void MyButton_Click(object sender, EventArgs e)
        {
            if (NameTextBox.Text.Length > 0)
            {
                DisplayLabel.Text = "Welcome " + NameTextBox.Text;
                DisplayLabel.Visible = true;
            }
            else 
            {
                MessageBox.Show("Please enter a name");
            }
        }

        private void CheckIfValid(object sender, EventArgs e)
        {
            if (!NameTextBox.Text.Contains("!")) 
            {
                
                DisplayLabel.Text = "Not valid";
                DisplayLabel.Visible = true;
            }
            else 
            {
                DisplayLabel.Visible = false;
            }
        }
    }
}
