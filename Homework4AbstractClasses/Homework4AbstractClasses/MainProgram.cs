using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homework4AbstractClasses
{
    class MainProgram
    {
        static void Main(string[] args)
        {
            Shape cir = new Circle(0, 0, 3);
            Shape square = new Square(2, 2);
            Shape tri = new Triangle(2,3);
            Shape sphere = new Sphere(3);
            Shape tetra = new Tetrahedron(3);
            Shape cube = new Cube(3, 4, 4);

            Shape[] myShapes = { cir, square, tri, sphere, tetra, cube };

            for (int i = 0; i < myShapes.Length; i++) 
            {
                if (myShapes[i] is ThreeDimensionalShape) 
                {
                    Console.WriteLine(myShapes[i].ToString());
                    Console.WriteLine("AREA: " + myShapes[i].getArea());
                    Console.WriteLine("VOLUME: " + myShapes[i].getVolume());

                }
                else if (myShapes[i] is TwoDimensionalShape)
                {
                    Console.WriteLine(myShapes[i].ToString());
                    Console.WriteLine("AREA: " + myShapes[i].getArea());
                    
                }
            }
        }
    }
}
