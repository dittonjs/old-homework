using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    public class ThreeDimensionalShape : Shape
    {
        protected double sideOne;
        protected double sideTwo;
        protected double sideThree;


        public double SideOne
        {
            get
            {
                return sideOne;

            }

            protected set
            {
                sideOne = value;
            }
        }

        public double SideTwo
        {
            get
            {
                return sideTwo;
            }

            protected set
            {
                sideTwo = value;
            }
        }


        public double SideThree 
        {
            get 
            { 
                return sideThree; 
            }
            protected set 
            {
                sideThree = value; 
            }
        }

        public override string ToString()
        {
            return base.ToString() + " Three dimentional Object";
        }

        public override double getArea()
        {
            return SideOne * SideTwo * 6;
        }

        public override double getVolume()
        {
            return SideOne * SideTwo * SideThree;
        }
       
    }
}
