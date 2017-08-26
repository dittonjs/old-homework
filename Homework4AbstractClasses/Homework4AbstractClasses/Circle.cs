using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    class Circle : TwoDimensionalShape
    {
        private double radius;
        public double Radius 
        {
            get { return radius; }
            private set { radius = value; }
        }

        public override double getArea()
        {
            return 2 * 3.14159 * Radius;
        }

        public override string ToString()
        {
            string myValue = "CIRCLE: Radius is " + Radius;
            return myValue;
        }

        public Circle(double s1, double s2, double radi) : base(s1,s2) 
        {
            Radius = radi;   
        }

        public override double getVolume()
        {
            return 0;
        }
    }
}
