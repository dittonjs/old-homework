using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarbonFootprintCalculator
{
    abstract class Consumption : ICarbonFootprint
    {
        public double DollarsSpent{get; set;}
        public Consumption(double dollars) 
        {
            DollarsSpent = dollars;
        }

        public abstract double getCarbonAmount();
    }
}
