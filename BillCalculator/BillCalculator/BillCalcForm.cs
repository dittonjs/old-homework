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
    public partial class BillCalcForm : Form
    {
        public BillCalcForm()
        {
            InitializeComponent();
        }

        private double[] bevPrices = { 1.95, 1.50, 1.25, 2.95, 2.50, 1.50 };
        private double[] appPrices = { 5.95, 6.95, 8.95, 8.95, 10.95, 12.95, 6.95 };
        private double[] mainPrices = { 15.95, 13.95, 13.95, 11.95, 19.95, 20.95, 18.95, 13.95, 14.95};
        private double[] desPrices = { 5.95, 3.95, 5.95, 4.95, 5.95};

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            costText.Text = "";
            totalText.Text = "";
            taxText.Text = "";
            bevCost.Text = "0.00";
            appCost.Text = "0.00";
            mainCost.Text = "0.00";
            desCost.Text = "0.00";
        }

        private void bevCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            bevCost.Text = "" + bevPrices[bevCombo.SelectedIndex];
            UpdateTotal();
        }

        private void appCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            appCost.Text = "" + appPrices[appCombo.SelectedIndex];
            UpdateTotal();
        }

        private void mainCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            mainCost.Text = "" + mainPrices[mainCombo.SelectedIndex];
            UpdateTotal();
        }

        private void desCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            desCost.Text = "" + desPrices[desCombo.SelectedIndex];
            UpdateTotal();
        }

        private void UpdateTotal(){
            double total = 0;
            total += Convert.ToDouble(desCost.Text);
            total += Convert.ToDouble(appCost.Text);
            total += Convert.ToDouble(mainCost.Text);
            total += Convert.ToDouble(bevCost.Text);
            costText.Text = "" + total;
            taxText.Text = "" + Math.Round((total * .07),2);
            totalText.Text = "" + (total + Math.Round((total * .07),2));
        }
    }
}
