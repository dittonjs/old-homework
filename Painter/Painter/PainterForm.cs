using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Painter
{
    public partial class PainterForm : Form
    {
        
        private bool shouldPaint = false;
        private Color myColor = Color.Red;
        private int mySize = 4;
        public PainterForm()
        {
            InitializeComponent();
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            shouldPaint = true;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (shouldPaint) 
            {
                using (Graphics graphics = panel1.CreateGraphics()) 
                {
                    graphics.FillEllipse(new SolidBrush(myColor) , e.X, e.Y, mySize, mySize);
                }
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            shouldPaint = false;
        }

        private void SmallRadio_CheckedChanged(object sender, EventArgs e)
        {
            mySize = 4;
        }

        private void MediumRadio_CheckedChanged(object sender, EventArgs e)
        {
            mySize = 8;
        }

        private void LargeRadio_CheckedChanged(object sender, EventArgs e)
        {
            mySize = 16;
        }

        private void RedRadio_CheckedChanged(object sender, EventArgs e)
        {
            myColor = Color.Red;
        }

        private void GreenRadio_CheckedChanged(object sender, EventArgs e)
        {
            myColor = Color.Green;
        }

        private void BlueRadio_CheckedChanged(object sender, EventArgs e)
        {
            myColor = Color.Blue;
        }

        private void YellowRadio_CheckedChanged(object sender, EventArgs e)
        {
            myColor = Color.Yellow;
        }

        
    }
}
