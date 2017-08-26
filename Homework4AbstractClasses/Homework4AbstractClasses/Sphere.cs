using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    class Sphere : ThreeDimensionalShape
    {
        private double radius;
        public double Radius
        {
            get { return radius; }
            private set { radius = value; }
        }
        
        public override string ToString()
        {
            string myValue = "SPHERE: Radius is " + Radius;
            return myValue;
        }

        public Sphere(double radi) 
        {
            Radius = radi;
        }

        public override double getArea()
        {
            return 4 * 3.14159 * Radius * Radius;
        }

        public override double getVolume()
        {
            return (4/3) * 3.14159 * Radius * Radius * Radius;
        }

    }
}
