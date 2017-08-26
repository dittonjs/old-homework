using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccount
{
    public class AccountProgram
    {
        static void Main(string[] args)
        {
            SavingsAccount savings = new SavingsAccount(5.00m, .005m);
            CheckingAccount checking = new CheckingAccount(5.00m, 2.50m);
            decimal ammount;
            Console.WriteLine("How much would you like to deposit to the savings account?");
            ammount = Convert.ToDecimal(Console.ReadLine());
            savings.Credit(ammount);
            Console.WriteLine("The new balance is: " + savings.Balance);
            Console.WriteLine("How much would you like to deposit to checking?");
            ammount = Convert.ToDecimal(Console.ReadLine());
            checking.Credit(ammount);
            Console.WriteLine("The new balance is: " + checking.Balance);

            Console.WriteLine("How much would you like to withdraw the savings account?");
            ammount = Convert.ToDecimal(Console.ReadLine());
            savings.Debit(ammount);
            Console.WriteLine("The new balance is: " + savings.Balance);
            Console.WriteLine("How much would you like to withdraw from checking?");
            ammount = Convert.ToDecimal(Console.ReadLine());
            checking.Debit(ammount);
            Console.WriteLine("The new balance is: " + checking.Balance);
            
            Console.WriteLine("The ammount of interest earned from savings is: " + savings.CalculateInterest());



            

        }
    }
}
