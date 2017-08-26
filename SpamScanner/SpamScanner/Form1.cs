using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SpamScanner
{
    public partial class Form1 : Form
    {
        string Words = "$$$,Affordable,Bargain,Beneficiary,Best price,Big bucks,Cash,Cash bonus,Cashcashcash,Cents on the dollar,Cheap,CheckClaims,CollectCompare,rates,Cost,Credit,Credit bureaus,Discount,Earn,Easy terms,F r e e,Fast cash,For just $,Hidden assets,hidden charges,Income,Incredible deal,Insurance,Investment,Loans,Lowest price,Million dollars,Money,Money back,Mortgage,Mortgage rates,No cost,No fees,One hundred percent free,Only $,Pennies a day,Price,Profits,Pure profit,Quote,Refinance,Save,$Save big money,Save up to,Serious cash,Subject to credit,They keep your money – no refund,Unsecured credit,Unsecured debt,US dollars,Why pay more";
        string[] WordsCollection; 
        
        public Form1()
        {
            //WordListText2 = new RichTextBox();
            
            InitializeComponent();
            UpdateWordList();  
            //UpdateText()
        }
        
        private void UpdateWordList(){
            WordsCollection = null;
            string[] temp = Words.Split(',');
            WordsCollection = new string[temp.Length];
            for (int i = 0; i < temp.Length; i++) {
                //Console.Write(temp[i]);
                WordsCollection[i] = temp[i];
            }
            WordListText.Text = " ";
            for (int i = 0; i < WordsCollection.Length; i++)
            {
                WordListText.Text += WordsCollection[i] + " ";
            }
        }

        private void UpdateText() {
            
        }

        private void AddWord(string word){
            Words += ","+word;
        }

        private string FormatString(string email){
            string temp = email.Replace(",", "");
            temp = temp.Replace(".", "");
            temp = temp.Replace(":", "");
            temp = temp.Replace("?", "");
            temp = temp.Replace("!", "");
            
            return temp;
        }

        private double CheckScore(string[] email){
            double score =0;
            for(int i=0; i< email.Length; i++){
                for(int j = 0; j< WordsCollection.Length; j++){
                    if(email[i] == WordsCollection[j])
                        score++;
                }
            }
            return ((score/email.Length)*100);
        }

        private string GetVerdict(double score){
            if(score>10)
                return "SPAM!";
            else return "NOT SPAM";
        }

        private void CheckButton_Click(object sender, EventArgs e)
        {
            string temp = FormatString(EmailEntry.Text);
            string[] emailWords = temp.Split(' ');
            double score = CheckScore(emailWords);
            
            ScoreLabel.Text = "Score: " + score;
            string verdict = GetVerdict(score);
            VerdictLabel.Text = "Verdict: " + verdict;
        }

        private void AddWordButton_Click(object sender, EventArgs e)
        {
            AddWord(AddWorkText.Text);
            UpdateWordList();
        }
    }
}
