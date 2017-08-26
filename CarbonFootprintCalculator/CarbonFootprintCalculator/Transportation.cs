using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarbonFootprintCalculator
{
    abstract class Transportation : ICarbonFootprint
    {
        public double Miles { get; set; }
        public Transportation(double miles) 
        {
            Miles = miles;
        }

        public abstract double getCarbonAmount();
    }
}
