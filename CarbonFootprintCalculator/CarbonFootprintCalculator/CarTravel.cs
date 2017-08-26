using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarbonFootprintCalculator
{
    class CarTravel : Transportation
    {
        private const double POCEPG = 19.4;
        private const double EOGGOTC = 100/95;
        public double MPG { get; set; }
        public CarTravel(double miles, double mpg) : base(miles)
        {
            MPG = mpg;
        }

        public override double getCarbonAmount()
        {
            return (Miles/MPG) * 12 * POCEPG * EOGGOTC;
        }

    }
}
