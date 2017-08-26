using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BankAccount 
{
    public class CheckingAccount : Account
    {
        private decimal transactionFee;
        public decimal TransactionFee 
        {
            get {
                return transactionFee;
            }
            set 
            {
                if (value >=0)
                {
                    transactionFee = value;
                }
                else
                {
                    throw new IndexOutOfRangeException();
                }
            }
        }

        public CheckingAccount(decimal bal, decimal trans) : base(bal)
        {
            TransactionFee = trans;
        }

        public override void Credit(decimal ammount)
        {
            if (ammount >= TransactionFee) 
            {
                Balance += (ammount-TransactionFee);

            }
            else
            {
                Console.WriteLine("You can't deposit an ammount smaller than the transaction fee.");

            }
        }

        public override void Debit(decimal ammount)
        {
            if ((ammount + TransactionFee) <= Balance && ammount >0)
            {
                Balance -= (ammount + TransactionFee);

            }
            else
            {
                Console.WriteLine("WithDrawl Exeeds Limit, or you choose to withdrawl $0.00 ");

            }
        }
        
    }
}
