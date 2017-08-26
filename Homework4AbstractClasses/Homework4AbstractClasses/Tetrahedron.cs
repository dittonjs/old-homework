using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    class Tetrahedron : ThreeDimensionalShape
    {
        private double sideA;
        public double SideA
        {
            get { return sideA; }
            private set { sideA = value; }
        }
        
        public override double getArea() 
        {
            return Math.Sqrt(3) * SideA;
        }

        public override double getVolume() 
        {
            return Math.Pow(SideA, 3) / (6 * Math.Sqrt(2));
        }

        public override string ToString()
        {
            string myValue = "TETRAHEDRON: Side A is " + SideA;
            return myValue;
        }

        public Tetrahedron(double side) 
        {
            SideA = side;
        }
        
    }
}
