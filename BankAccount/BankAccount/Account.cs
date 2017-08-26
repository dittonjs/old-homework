using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccount
{
    public class Account
    {
        private decimal balance;
        public decimal Balance 
        {
            get { return balance; }
            protected set {
                if (value >= 0.0m)
                    balance = value;
                else 
                    throw new IndexOutOfRangeException();
            }
        }

        public Account(decimal bal) 
        {
            Balance = bal;
        }

        public virtual void Credit(decimal ammount) 
        {
            Balance += ammount;
        }

        public virtual void Debit(decimal ammount) 
        {
            if (Balance - ammount >= 0)
            {
                Balance -= ammount;
            }
            else
            {
                Console.WriteLine("Withdrawl exceeds balance.");
            }
        }
    }
}
