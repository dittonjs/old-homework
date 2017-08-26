using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    class Square : TwoDimensionalShape
    {
        public override double getArea()
        {
            return SideA * SideB;
        }

        public override string ToString()
        {
            string myValue = "SQUARE: Side one is " + SideB + ". Side two is " + SideB;
            return myValue;
        }

        public Square(double s1, double s2): base(s1, s2) 
        {
            
        }

        public override double getVolume()
        {
            return 0;
        }
    }
}
