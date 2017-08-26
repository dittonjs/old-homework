using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccount 
{
    public class SavingsAccount : Account
    {
        private decimal interestRate;
        public decimal InterestRate 
        {
            get 
            {
                return interestRate;
            }
            private set 
            {
                if (value >= 0){
                    interestRate = value;
                }
                else{
                    throw new IndexOutOfRangeException();
                }
            }
        }

        public SavingsAccount(decimal bal, decimal inter):base(bal) 
        {
            InterestRate = inter;
        }

        public decimal CalculateInterest() 
        {
            return InterestRate * Balance;
        }

    }
}
