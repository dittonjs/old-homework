using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CarbonFootprintCalculator
{
    class AirTravel : Transportation
    {
        private const double AEPM = 223;
        private const double IWTPF = 1.2;
        private const double IARFF = 1.9;
        private const double GTPC = .0022;

        public AirTravel(double miles) : base(miles) { }

        public override double getCarbonAmount()
        {
            return Miles * AEPM * IWTPF * IARFF * GTPC;
        }
    }
}
