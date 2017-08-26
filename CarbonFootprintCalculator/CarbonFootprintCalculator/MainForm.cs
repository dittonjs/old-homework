using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CarbonFootprintCalculator
{
    public partial class MainForm : Form
    {
        private AirTravel airTravel = new AirTravel(0);
        private CarTravel carTravel = new CarTravel(0, 0);
        private GoodsAndServices clothing = new GoodsAndServices(0, 436);
        private GoodsAndServices furnishings = new GoodsAndServices(0, 459);
        private GoodsAndServices otherGoods = new GoodsAndServices(0, 338);
        private GoodsAndServices services = new GoodsAndServices(0, 178);
        private HouseHoldEnergy electric = new HouseHoldEnergy(0, 0, 1.37);
        private HouseHoldEnergy gas = new HouseHoldEnergy(0, 0, 121.61);
        private HouseHoldEnergy oil = new HouseHoldEnergy(0, 0, 22.37);
        private HouseHoldEnergy propane = new HouseHoldEnergy(0, 0, 12.17);
        private DietAndEating meat = new DietAndEating(0, 1452);
        private DietAndEating cereals = new DietAndEating(0, 741);
        private DietAndEating dairy = new DietAndEating(0, 1911);
        private DietAndEating fruits = new DietAndEating(0, 1176);
        private DietAndEating eatingOut = new DietAndEating(0, 368);
        private DietAndEating otherFood = new DietAndEating(0, 467);
        

        //THIS IS NEEDED TO MOVE THE SCREEN


        private bool draggable = false;
        private Point lastLocation;
        public MainForm()
        {
            InitializeComponent();
            StartPanel.Enabled = true;
            StartPanel.Visible = true;
            StartPanel.Location = new Point(13,12);
            FirstStepPanel.Enabled = false;
            FirstStepPanel.Visible = false;
            Step2Panel.Visible = false;
            Step2Panel.Enabled = false;
            Step5Panel.Enabled = false;
            Step5Panel.Visible = false;
            Step5Panel.Location =  new Point(0,0);
            Step3Panel.Enabled = false;
            Step3Panel.Visible = false;
            FirstStepPanel.Location = new Point(0, 0);
            Step2Panel.Location = new Point(0, 0);
            Step3Panel.Location = new Point(0, 0);
            Step4Panel.Location = new Point(0, 0);
            Step4Panel.Visible = false;
            Step4Panel.Enabled = false;
            FinalPanel.Location = new Point(0, 0);
            FinalPanel.Visible = false;
            FinalPanel.Enabled = false;

        }

        private void StartLabel_MouseEnter(object sender, EventArgs e)
        {
            if (sender.Equals(StartLabel))
                StartLabel.Font = new Font(StartLabel.Font, FontStyle.Bold);
            if (sender.Equals(Step1Next))
                Step1Next.Font = new Font(Step1Next.Font, FontStyle.Bold);
            if (sender.Equals(Step1Back))
                Step1Back.Font = new Font(Step1Back.Font, FontStyle.Bold);
            if (sender.Equals(Step5Next))
                Step5Next.Font = new Font(Step5Next.Font, FontStyle.Bold);
            if (sender.Equals(Step5Back))
                Step5Back.Font = new Font(Step5Back.Font, FontStyle.Bold);
            if (sender.Equals(Step3Back))
                Step3Back.Font = new Font(Step3Back.Font, FontStyle.Bold);
            if (sender.Equals(Step3Next))
                Step3Next.Font = new Font(Step3Next.Font, FontStyle.Bold);
            if (sender.Equals(Step4Back))
                Step4Back.Font = new Font(Step4Back.Font, FontStyle.Bold);
            if (sender.Equals(Finish))
                Finish.Font = new Font(Finish.Font, FontStyle.Bold);
            if (sender.Equals(HomeButton))
                HomeButton.Font = new Font(HomeButton.Font, FontStyle.Bold);

            if (sender.Equals(QuitIcon))
                QuitIcon.Size = new Size(35, 35);
            if (sender.Equals(QuitIconStep1))
                QuitIconStep1.Size = new Size(35, 35);
            if (sender.Equals(Step5QuitIcon))
                Step2QuitIcon.Size = new Size(35, 35);
            if (sender.Equals(Step3QuitIcon))
                Step3QuitIcon.Size = new Size(35, 35);
            if (sender.Equals(Step4QuitIcon))
                Step4QuitIcon.Size = new Size(35, 35);
            if (sender.Equals(FinalQuitIcon))
                FinalQuitIcon.Size = new Size(35, 35);


        }

        private void StartLabel_MouseLeave(object sender, EventArgs e)
        {
            if (sender.Equals(StartLabel))
                StartLabel.Font = new Font(StartLabel.Font, FontStyle.Regular);
            if (sender.Equals(Step1Next))
                Step1Next.Font = new Font(Step1Next.Font, FontStyle.Regular);
            if (sender.Equals(Step1Back))
                Step1Back.Font = new Font(Step1Back.Font, FontStyle.Regular);
            if (sender.Equals(Step5Next))
                Step5Next.Font = new Font(Step5Next.Font, FontStyle.Regular);
            if (sender.Equals(Step2Back))
                Step2Back.Font = new Font(Step2Back.Font, FontStyle.Regular);
            if (sender.Equals(Step3Next))
                Step3Next.Font = new Font(Step3Next.Font, FontStyle.Regular);
            if (sender.Equals(Step3Back))
                Step3Back.Font = new Font(Step3Back.Font, FontStyle.Regular);
            if (sender.Equals(Finish))
                Finish.Font = new Font(Finish.Font, FontStyle.Regular);
            if (sender.Equals(Step4Back))
                Step4Back.Font = new Font(Step4Back.Font, FontStyle.Regular);
            if (sender.Equals(HomeButton))
                HomeButton.Font = new Font(HomeButton.Font, FontStyle.Regular);

            if (sender.Equals(QuitIcon))
                QuitIcon.Size = new Size(30, 30);
            if (sender.Equals(QuitIconStep1))
                QuitIconStep1.Size = new Size(30, 30);
            if (sender.Equals(Step5QuitIcon))
                Step2QuitIcon.Size = new Size(30, 30);
            if (sender.Equals(Step3QuitIcon))
                Step3QuitIcon.Size = new Size(30, 30);
            if (sender.Equals(Step4QuitIcon))
                Step4QuitIcon.Size = new Size(30, 30);
            if (sender.Equals(FinalQuitIcon))
                FinalQuitIcon.Size = new Size(30, 30);
        }

        private void ButtonClick(object sender, EventArgs e)
        {
            if (sender.Equals(StartLabel))
            {
                StartPanel.Visible = false;
                FirstStepPanel.Enabled = true;
                FirstStepPanel.Visible = true;
                FirstStepPanel.Location = new Point(13, 12);
                StartPanel.Location = new Point(0, 0);
                StartPanel.Enabled = false;

            }

            if (sender.Equals(Step1Next))
            {
                
                FirstStepPanel.Visible = false;
                Step5Panel.Enabled = true;
                Step5Panel.Visible = true;
                Step5Panel.Location = new Point(13, 12);
                FirstStepPanel.Location = new Point(0, 0);
                FirstStepPanel.Enabled = false;
                // WE NEED TO SAVE THE DATA HERE
                SaveDataTrans();
            }

            if (sender.Equals(Step5Next))
            {
                Step5Panel.Visible = false;
                Step3Panel.Enabled = true;
                Step3Panel.Visible = true;
                Step3Panel.Location = new Point(13, 12);
                Step5Panel.Location = new Point(0, 0);
                Step5Panel.Enabled = false;
                //SAVE DATA
                SaveDataFood();
            }

            if (sender.Equals(Step3Next))
            {
                Step3Panel.Visible = false;
                Step4Panel.Enabled = true;
                Step4Panel.Visible = true;
                Step4Panel.Location = new Point(13, 12);
                Step3Panel.Location = new Point(0, 0);
                Step3Panel.Enabled = false;
                //SAVE DATA
                SaveDataEnergy();

            }

            if (sender.Equals(Finish))
            {
                Step4Panel.Visible = false;
                FinalPanel.Enabled = true;
                FinalPanel.Visible = true;
                FinalPanel.Location = new Point(13, 12);
                Step4Panel.Location = new Point(0, 0);
                Step4Panel.Enabled = false;
                //SAVE DATA
                SaveDataGoods();
                CarbonFootPrint.Text = CalculateCarbonFootprint().ToString();

            }
            if (sender.Equals(Step1Back))
            {
                FirstStepPanel.Visible = false;
                StartPanel.Enabled = true;
                StartPanel.Visible = true;
                StartPanel.Location = new Point(13, 12);
                FirstStepPanel.Location = new Point(0, 0);
                FirstStepPanel.Enabled = false;
                //SAVE DATA
                //SaveDataTrans();
            }
            if (sender.Equals(Step5Back))
            {
                Step5Panel.Visible = false;
                FirstStepPanel.Enabled = true;
                FirstStepPanel.Visible = true;
                FirstStepPanel.Location = new Point(13, 12);
                Step5Panel.Location = new Point(0, 0);
                Step5Panel.Enabled = false;
                
               
            }

            if (sender.Equals(Step3Back))
            {
                Step3Panel.Visible = false;
                Step5Panel.Enabled = true;
                Step5Panel.Visible = true;
                Step5Panel.Location = new Point(13, 12);
                Step3Panel.Location = new Point(0, 0);
                Step3Panel.Enabled = false;
                //SAVE DATA
                //LOAD DATA
            }

            if (sender.Equals(Step4Back))
            {
                Step4Panel.Visible = false;
                Step3Panel.Enabled = true;
                Step3Panel.Visible = true;
                Step3Panel.Location = new Point(13, 12);
                Step4Panel.Location = new Point(0, 0);
                Step4Panel.Enabled = false;
                //SAVE DATA
                //SaveDataGoods();
            }

            if (sender.Equals(HomeButton))
            {
                FinalPanel.Visible = false;
                StartPanel.Enabled = true;
                StartPanel.Visible = true;
                StartPanel.Location = new Point(13, 12);
                FinalPanel.Location = new Point(0, 0);
                FinalPanel.Enabled = false;
                //SAVE DATA
                
            }



        }

        private void QuitIcon_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void SaveDataTrans()
        {
            airTravel.Miles = Convert.ToDouble(PlaneMilesValue.Text);
            carTravel.Miles = Convert.ToDouble(CarMilesValue.Text);
            carTravel.MPG = Convert.ToDouble(CarMPGValue.Text);
        }

        private void SaveDataFood()
        {
            meat.DollarsSpent = Convert.ToDouble(MeatValue5.Text);
            cereals.DollarsSpent = Convert.ToDouble(CerealsValue5.Text);
            fruits.DollarsSpent = Convert.ToDouble(FruitsValue5.Text);
            dairy.DollarsSpent = Convert.ToDouble(DairyValue5.Text);
            eatingOut.DollarsSpent = Convert.ToDouble(FastFoodValue5.Text);
            otherFood.DollarsSpent = Convert.ToDouble(OtherFoodValue5.Text);
        }

        private void SaveDataEnergy()
        {
            electric.DollarsSpent = Convert.ToDouble(ElecAverageValue.Text);
            electric.PricePerUnit = Convert.ToDouble(ElecPPUValue.Text);
            gas.DollarsSpent = Convert.ToDouble(GasAverageValue.Text);
            gas.PricePerUnit = Convert.ToDouble(GasPPUValue.Text);
            oil.DollarsSpent = Convert.ToDouble(OilAverageValue.Text);
            oil.PricePerUnit = Convert.ToDouble(OilPPUValue.Text);
            propane.DollarsSpent = Convert.ToDouble(PropaneAverageValue.Text);
            propane.PricePerUnit = Convert.ToDouble(PropanePPUValue.Text);
        }

        private void SaveDataGoods()
        {
            clothing.DollarsSpent = Convert.ToDouble(ElecAverageValue.Text);
            furnishings.DollarsSpent = Convert.ToDouble(ElecPPUValue.Text);
            services.DollarsSpent = Convert.ToDouble(GasAverageValue.Text);
            otherGoods.DollarsSpent = Convert.ToDouble(GasPPUValue.Text);

        }

        private double CalculateCarbonFootprint() 
        {
            double a, b, c, d, e, f, g, h, i, j, k, l,m,n,o,p,q;
            a = carTravel.getCarbonAmount();
            b = airTravel.getCarbonAmount();
            c = meat.getCarbonAmount();
            d = cereals.getCarbonAmount();
            e = fruits.getCarbonAmount();
            f = dairy.getCarbonAmount();
            g = eatingOut.getCarbonAmount();
            h = otherFood.getCarbonAmount();
            i = gas.getCarbonAmount();
            j = electric.getCarbonAmount();
            k = oil.getCarbonAmount();
            l = propane.getCarbonAmount();
            m = clothing.getCarbonAmount();
            n = furnishings.getCarbonAmount();
            o = services.getCarbonAmount();
            p = otherGoods.getCarbonAmount();
            q = a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p;
            return q;

        }
        private void DeleteData(object sender, EventArgs e)
        {

        }

        private void Grabscreen(object sender, MouseEventArgs e)
        {
            draggable = true;
            lastLocation = e.Location;
        }

        private void MoveScreen(object sender, MouseEventArgs e)
        {
            if (draggable)
            {
                this.Location = new Point(
                    (this.Location.X - lastLocation.X) + e.X, (this.Location.Y - lastLocation.Y) + e.Y);

                this.Update();
            }
        }

        private void ReleaseScreen(object sender, MouseEventArgs e)
        {
            draggable = false;
        }
    }
}