using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    public class TwoDimensionalShape : Shape
    {
        protected double sideA;
        protected double sideB;

        public double SideA 
        {
            get { return sideA; }
            set { sideA = value; }
        }

        public double SideB
        {
            get { return sideB; }
            set { sideB = value; }
        }

        public TwoDimensionalShape(double a, double b) 
        {
            SideA = a;
            sideB = b;
        }

        public override double getArea()
        {
            return SideA * SideB;
        }

        public override double getVolume()
        {
            return 0;
        }
    }
}
