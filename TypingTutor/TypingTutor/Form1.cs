using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TypingTutor
{
    public partial class mainForm : Form
    {
        //NECESSARY VARIABLES
        
        string message = "";
        int stringNumber = 0;
        string charsMissed = "";
        string[] instructions = new string[11];

        string inst1 = "A typed word is counted as any five keystrokes.";
        string inst2 = "Do not stop to correct your errors in these first tests but check them out.";
        string inst3 = "The beautiful scenic country of New Zealand is situated in the South Pacific to the east of Australia";
        string inst4 = "The ferry crosses Cook Strait and cruises beautiful Queen Charlotte Sounds between Wellington, NZ's Capital City, and Picton";
        string inst5 = "NZ's East Coast has many stretches of white sand and rolling surf which attract NZ and overseas surfers. They are popular NZ family holiday places";
        string inst6 = "New Zealand is a land of contrasts, which attract thousands of overseas tourists every year to climb, ski or snowboard our mountains, swim, fish or cruise on our lakes and rivers.";
        string inst7 = "Between The Southern Alps and the West Coast is a fantastic scenic drive taking the Haast Pass road. Here is our great rain forest. Most overseas and local tours include this route in their Itinerary.";
        string inst8 = "New Zealand is a very sport oriented country and sometimes hosts world events. Sports include tennis, golf, yachting, canoeing, cruising, cricket, soccer, rugby, basketball, netball, swimming, surf lifesaving, athletics, and riding.";
        string inst9 = "Watching events where they take place is fine but many can only watch at home as the event is screened on our TVs. New Zealand is proud too of our sporting participants who have entered and gained medals in many sporting events including Olympic Games.";
        string inst10 = "Masters' Games are very popular in New Zealand as in many other countries and NZ swimmers were really proud in the year 2002 to host the FINA World Masters Swimming Champs at Christchurch in the South Island, at which I gained 10th place medals for 100 m and 200 m backstroke.";
        string inst11 = "Some challenging events which draw overseas sports people include the annual Coast to Coast involving running, cycling and kayaking from the West Coast, through mountain passes to the East Coast, and the Iron Man including running, cycling, and swimming. I am proud one of my sons twice took part in the Ironman.";
        
        
        public mainForm()
        {
            this.KeyPreview = true;
            
            InitializeComponent();
            userType.Focus();
            instructions[0] = inst1;
            instructions[1] = inst2;
            instructions[2] = inst3;
            instructions[3] = inst4;
            instructions[4] = inst5;
            instructions[5] = inst6;
            instructions[6] = inst7;
            instructions[7] = inst8;
            instructions[8] = inst9;
            instructions[9] = inst10;
            instructions[10] = inst11;
            instructionText.Text = instructions[stringNumber];
             numErrors.Text = "";
             correctLabel.Text = "";
            charsDifLabel.Text = "";

            
        }


        int StringCompare(string a, string b)
        {
            if (a == b) //Same string, no iteration needed.
                return a.Length;
            if ((a.Length == 0) || (b.Length == 0)) //One is empty, second is not
            {
                return 0;
            }
            double maxLen = a.Length > b.Length ? a.Length : b.Length;
            int minLen = a.Length < b.Length ? a.Length : b.Length;
            int sameCharAtIndex = 0;
            int offsetA = 0;
            int offsetB = 0;
            for (int i = 0; i < minLen; i++) //Compare char by char
            {
                if (a[i+offsetA] == b[i+offsetB])
                {
                    sameCharAtIndex++;
                    //Console.WriteLine(a[i]);
                }
                else {
                    try
                    {
                        if (a.Length < b.Length)
                        {
                            if (a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2])
                            {
                                // do nothing
                            }
                            else if ( a[i] == b[i + 1] && a[i + 1] == b[i + 2])
                            {
                                offsetB++;
                            }
                        }
                        else if (a.Length > b.Length)
                        {
                            if (a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2])
                            {
                                // do nothing
                            }
                            else if (a[i + 1] == b[i] && a[i + 2] == b[i + 1])
                            {
                                offsetA++;
                            }
                        }
                    } catch(Exception e){}
                    charsMissed += b[i];
                }
            }
            return sameCharAtIndex;
        }

        private void enterButton_Push(ref Button sender, EventArgs e)
        {
            // GET THE TEXT FROM THE TEXT FIELD, COMPARE IT TO TEST TEXT COUNT THE ERRORS
            instructionText.Focus();
            int correct = StringCompare(userType.Text, instructions[stringNumber]);
            correctLabel.Text = " " + correct;
            numErrors.Text = " " + (Math.Abs(instructions[stringNumber].Length - correct));
            
            charsDifLabel.Text = charsMissed;
            userType.Text = "";
            userType.Focus();
            stringNumber++;
            if(stringNumber > 10) stringNumber = 0;
            instructionText.Text = instructions[stringNumber];
            charsMissed = "";
            
        }



        private void type(ref Button sender, KeyEventArgs e)
        {
            // MAKE THE BUTTON HIGHLIGHT
            //MessageBox.Show("This works");
            sender.BackColor = Color.LightSlateGray;
            //if (e.KeyCode != Keys.Enter && e.KeyCode != Keys.LShiftKey && e.KeyCode != Keys.RShiftKey) {
            //    if (isShiftPressed) message += (char)e.KeyValue;
            //    else  {
            //        message += Char.ToLower((char)e.KeyValue);
            //        userType.Text = message;
            //    }
                
            //}
            //else if (e.KeyCode == Keys.Shift || e.KeyCode == Keys.RShiftKey) {
            //    isShiftPressed = true;
            //    MessageBox.Show("shift pressed");
            //}
            
            
        }

        private void untype(ref Button sender, KeyEventArgs e) { 
            // MAKE THE BUTTON UNHIGLIGHT
            sender.BackColor = mainForm.DefaultBackColor;
            

        }

        private void mainForm_KeyDown(object sender, KeyEventArgs e)
        {
            //MessageBox.Show("Button Pressed");
            if (e.KeyCode == Keys.Q) {
                type(ref qButton, e);
            }
            if (e.KeyCode == Keys.W)
            {
                type(ref wButton, e);
            }
            if (e.KeyCode == Keys.E)
            {
                type(ref eButton, e);
            }
            if (e.KeyCode == Keys.R)
            {
                type(ref rButton, e);
            }
            if (e.KeyCode == Keys.T)
            {
                type(ref tButton, e);
            }
            if (e.KeyCode == Keys.Y)
            {
                type(ref yButton, e);
            }
            if (e.KeyCode == Keys.U)
            {
                type(ref uButton, e);
            }
            if (e.KeyCode == Keys.I)
            {
                type(ref iButton, e);
            }
            if (e.KeyCode == Keys.O)
            {
                type(ref oButton, e);
            }
            if (e.KeyCode == Keys.P)
            {
                type(ref pButton, e);
            }
            if (e.KeyCode == Keys.A)
            {
                type(ref aButton, e);
            }
            if (e.KeyCode == Keys.S)
            {
                type(ref sButton, e);
            }
            if (e.KeyCode == Keys.D)
            {
                type(ref dButton, e);
            }
            if (e.KeyCode == Keys.F)
            {
                type(ref fButton, e);
            }
            if (e.KeyCode == Keys.G)
            {
                type(ref gButton, e);
            }
            if (e.KeyCode == Keys.H)
            {
                type(ref hButton, e);
            }
            if (e.KeyCode == Keys.J)
            {
                type(ref jButton, e);
            }
            if (e.KeyCode == Keys.K)
            {
                type(ref kButton, e);
            }
            if (e.KeyCode == Keys.L)
            {
                type(ref lButton, e);
            }
            if (e.KeyCode == Keys.OemSemicolon)
            {
                type(ref semiButton, e);
            }
            if (e.KeyCode == Keys.Z)
            {
                type(ref zButton, e);
            }
            if (e.KeyCode == Keys.X)
            {
                type(ref xButton, e);
            }
            if (e.KeyCode == Keys.C)
            {
                type(ref cButton, e);
            }
            if (e.KeyCode == Keys.V)
            {
                type(ref vButton, e);
            }
            if (e.KeyCode == Keys.B)
            {
                type(ref bButton, e);
            }
            if (e.KeyCode == Keys.N)
            {
                type(ref nButton, e);
            }
            if (e.KeyCode == Keys.M)
            {
                type(ref mButton, e);
            }
            if (e.KeyCode == Keys.Oemcomma)
            {
                type(ref commaButton, e);
            }
            if (e.KeyCode == Keys.OemPeriod)
            {
                type(ref periodButton, e);
            }
            if (e.KeyCode == Keys.Enter) {

                type(ref enterButton, e);
                enterButton_Push(ref enterButton, e);
            }
            if (e.KeyCode == Keys.Space)
            {
                type(ref spaceButton, e);
            }
            if (e.KeyData == Keys.LShiftKey)
            {
                MessageBox.Show("shift");
                type(ref leftShift, e);
            }
            if (e.KeyData == Keys.RShiftKey)
            {
                type(ref rightShift, e);
            }
            
        }

        private void mainForm_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Q)
            {
                untype(ref qButton, e);
            }
            if (e.KeyCode == Keys.W)
            {
                untype(ref wButton, e);
            }
            if (e.KeyCode == Keys.E)
            {
                untype(ref eButton, e);
            }
            if (e.KeyCode == Keys.R)
            {
                untype(ref rButton, e);
            }
            if (e.KeyCode == Keys.T)
            {
                untype(ref tButton, e);
            }
            if (e.KeyCode == Keys.Y)
            {
                untype(ref yButton, e);
            }
            if (e.KeyCode == Keys.U)
            {
                untype(ref uButton, e);
            }
            if (e.KeyCode == Keys.I)
            {
                untype(ref iButton, e);
            }
            if (e.KeyCode == Keys.O)
            {
                untype(ref oButton, e);
            }
            if (e.KeyCode == Keys.P)
            {
                untype(ref pButton, e);
            }
            if (e.KeyCode == Keys.A)
            {
                untype(ref aButton, e);
            }
            if (e.KeyCode == Keys.S)
            {
                untype(ref sButton, e);
            }
            if (e.KeyCode == Keys.D)
            {
                untype(ref dButton, e);
            }
            if (e.KeyCode == Keys.F)
            {
                untype(ref fButton, e);
            }
            if (e.KeyCode == Keys.G)
            {
                untype(ref gButton, e);
            }
            if (e.KeyCode == Keys.H)
            {
                untype(ref hButton, e);
            }
            if (e.KeyCode == Keys.J)
            {
                untype(ref jButton, e);
            }
            if (e.KeyCode == Keys.K)
            {
                untype(ref kButton, e);
            }
            if (e.KeyCode == Keys.L)
            {
                untype(ref lButton, e);
            }
            if (e.KeyCode == Keys.OemSemicolon)
            {
                untype(ref semiButton, e);
            }
            if (e.KeyCode == Keys.Z)
            {
                untype(ref zButton, e);
            }
            if (e.KeyCode == Keys.X)
            {
                untype(ref xButton, e);
            }
            if (e.KeyCode == Keys.C)
            {
                untype(ref cButton, e);
            }
            if (e.KeyCode == Keys.V)
            {
                untype(ref vButton, e);
            }
            if (e.KeyCode == Keys.B)
            {
                untype(ref bButton, e);
            }
            if (e.KeyCode == Keys.N)
            {
                untype(ref nButton, e);
            }
            if (e.KeyCode == Keys.M)
            {
                untype(ref mButton, e);
            }
            if (e.KeyCode == Keys.Oemcomma)
            {
                untype(ref commaButton, e);
            }
            if (e.KeyCode == Keys.OemPeriod)
            {
                untype(ref periodButton, e);
            }
            if (e.KeyCode == Keys.Space)
            {
                untype(ref spaceButton, e);
            }
            if (e.KeyCode == Keys.Enter) {
                untype(ref enterButton, e);
            }

            if (e.KeyCode == Keys.Shift)
            {
                untype(ref leftShift, e);
            }
            if (e.KeyCode == Keys.RShiftKey)
            {
                untype(ref rightShift, e);
            }
        }

        private void mainForm_Load(object sender, EventArgs e)
        {

        }
    }
}
