using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Picture_Viewer_Test
{
    public partial class Form1 : Form
    {
        public int index = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string imageSrc = "image_" + index;
            picBox.Image = (Image)Properties.Resources.ResourceManager.GetObject(imageSrc);
            
        }

        

        private void NextButton_Click(object sender, EventArgs e)
        {
            index++;
            if (index > 7) index = 7;
            string imageSrc = "image_" + index;
            picBox.Image = (Image)Properties.Resources.ResourceManager.GetObject(imageSrc);

        }

        private void PrevButton_Click(object sender, EventArgs e)
        {

            index--;
            if (index < 0) index = 0;
            string imageSrc = "image_" + index;
            picBox.Image = (Image)Properties.Resources.ResourceManager.GetObject(imageSrc);

        }

        private void picBox_MouseHover(object sender, EventArgs e)
        {
            string imageSrc = "image_" + index;
            toolTip1.Show(imageSrc, picBox);
        }

        
    }
}
