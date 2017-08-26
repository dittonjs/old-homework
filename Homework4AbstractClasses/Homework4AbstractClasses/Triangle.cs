using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    public class Triangle : TwoDimensionalShape
    {
        public double getArea()
        {
            return SideA * SideB * 0.5;
        }

        public override string ToString()
        {
            string myValue = "TRIANGE: Base is " + SideA + ". The height is " + SideB;
            return myValue;
        }

        public Triangle(double baseLength, double heigth) : base (baseLength, heigth)
        {
            
        }
        public override double getVolume()
        {
            return 0;
        }
    }
}
