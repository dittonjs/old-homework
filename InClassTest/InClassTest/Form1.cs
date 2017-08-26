using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace InClassTest
{
    public partial class BoxesForm : Form
    {
        
        public BoxesForm()
        {
            InitializeComponent();
        }

        private void hiButton_Click(object sender, EventArgs e)
        {
            displayText.Text = "Hello world!";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            displayText.Text = "Goodbye";
        }

        private void leftButton_Click(object sender, EventArgs e)
        {
            displayText.Text = "You clicked the left";
        }

        private void rightButton_Click(object sender, EventArgs e)
        {
            displayText.Text = "You clicked the right!";
        }

       

        private void boldBox_CheckedChanged(object sender, EventArgs e)
        {
            fontLable.Font = new Font(fontLable.Font, fontLable.Font.Style ^ FontStyle.Bold);
        }

        private void italicBox_CheckedChanged(object sender, EventArgs e)
        {
            fontLable.Font = new Font(fontLable.Font,fontLable.Font.Style ^ FontStyle.Italic);
        }
    }
}
