using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    public abstract class Shape : IAreaAndVol
    {
        protected double sideOne;
        protected double sideTwo;

        public abstract double getVolume();
        public abstract double getArea();

        public override string ToString()
        {
            return "I am a ";
        }
    }
}
