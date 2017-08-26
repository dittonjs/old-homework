using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BillCalculator
{
    public partial class mainForm : Form
    {

        private LoginForm loginForm;
        private BillCalcForm billCalcForm;
        public mainForm()
        {
            InitializeComponent();
            loginForm = new LoginForm();
            loginForm.MdiParent = this;
            billCalcForm = new BillCalcForm();
            billCalcForm.MdiParent = this;
            loginForm.Show();

        }

        public void LoggedIn() {
            loginForm.Hide();
            billCalcForm.Show();
        }
        
    }
}
