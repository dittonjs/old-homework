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
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
            
        }
        private string username = "Joseph";
        private string password = "cs2412";

        public string Password {
            get {
                return password;
            }
        }

        public string UserName {
            get {
                return username;
            }
        }
        
        private void loginButton_Click(object sender, EventArgs e)
        {
            if (CheckLogin(userNameTextBox.Text, passwordTextBox.Text)) {
                mainForm m = (mainForm)this.MdiParent;
                m.LoggedIn();
            }
            
        }

        public bool CheckLogin(string username, string password)
        {
            if (UserName == this.username && Password == this.password)
                return true;

            errorLabel.Text = "Invalid Info";
            return false;
        }
    }
}
