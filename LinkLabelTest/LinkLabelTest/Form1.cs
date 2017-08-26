using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LinkLabelTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            cLink.LinkVisited = true;
            System.Diagnostics.Process.Start("C:\\");

        }

        private void webLabel_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            webLabel.LinkVisited = true;
            System.Diagnostics.Process.Start("http://www.google.com");
        }

        private void notepadLabel_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            notepadLabel.LinkVisited = true;
            System.Diagnostics.Process.Start("notepad");

        }
    }
}
