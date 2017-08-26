using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    public class Cube : ThreeDimensionalShape
    {
        public double getArea() 
        {

            return SideOne * SideTwo * 6;
        }

        public Cube(double s1, double s2, double s3) 
        {
            SideOne = s1;
            SideTwo = s2;
            SideThree = s3;
        }
        public double getVolume() 
        {
            return SideOne * SideTwo * SideThree;
        }

        public override string ToString()
        {
            string myValue = "CUBE: Side one is " + SideOne + ". Side two is " + SideTwo + ". Side three is " + SideThree;
            return myValue;
        }
    }
}
