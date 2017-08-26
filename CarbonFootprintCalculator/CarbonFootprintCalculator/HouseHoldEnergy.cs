using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarbonFootprintCalculator
{
    class HouseHoldEnergy : Consumption
    {
        public double Modifier { get; set; }
        public double PricePerUnit { get; set; }
        public HouseHoldEnergy(double amount, double cost, double mod) : base(amount) 
        {
            PricePerUnit = cost;
            Modifier = mod;
        }

        public override double getCarbonAmount()
        {
            return (DollarsSpent / PricePerUnit) * Modifier * 12;
        }
    }
}
