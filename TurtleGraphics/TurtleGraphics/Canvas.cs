using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TurtleGraphics
{
    class Canvas
    {
        public int[,] floor = new int[20,20];

        public void printFloor() 
        {
            for(int i = 0; i < floor.GetLength(0); i++)
            {
                for (int j = 0; j < floor.GetLength(1); j++ )
                {
                    switch(floor[i,j])
                    {
                        case 0:
                            Console.Write(" ");
                            break;
                        case 1:
                            Console.Write("*");
                            break;
                        default:
                            break;
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
