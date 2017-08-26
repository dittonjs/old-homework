using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PythagoreanTriangles
{
    class Triangle
    {
        private double maxLength;

        public double MaxLength { get; set; }

        public void PrintPossibleLengths()
        {
            //System.IO.StreamWriter fileWrite;
            //fileWrite = new System.IO.StreamWriter("output.txt");
            //fileWrite.WriteLine("SIDE A: SIDE B: SIDE C:");
            //fileWrite.WriteLine("-----------------------");
            Console.WriteLine("SIDE A: SIDE B: SIDE C:");
            Console.WriteLine("-----------------------");
            int total = 0;
            for (int i = 1; i <= MaxLength; i++) 
            {
                // side A values
                
                for (int j = 1; j <= MaxLength; j++)
                {
                    
                    for (int k = 1; k <= MaxLength; k++)
                    {
                        if (checkPyth(i, j, k)) 
                        {
                            //fileWrite.WriteLine(i + "    " + j + "    " + k);
                            Console.WriteLine(i + "    " + j + "    " + k);
                            total++;
                        }   
                        
                    }
                }
            }
            //fileWrite.Close();
            Console.WriteLine("THE TOTAL NUMBER OF TRIANGLE IS: " + total);
        }

        public bool checkPyth(double a, double b, double c) 
        {
            if (Math.Pow(a, 2) + Math.Pow(b, 2) == Math.Pow(c, 2))
                return true;
            return false;
        }
    
    }
}
