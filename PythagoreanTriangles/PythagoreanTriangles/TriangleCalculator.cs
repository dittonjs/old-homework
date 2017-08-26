using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PythagoreanTriangles
{
    class TriangleCalculator
    {

        
        static void Main(string[] args)
        {
            Triangle myTri = new Triangle();
           
            
            myTri.MaxLength = 500;
            myTri.PrintPossibleLengths();
            
           
        }
    }
}
