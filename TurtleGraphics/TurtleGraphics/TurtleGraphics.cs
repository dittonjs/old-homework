using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TurtleGraphics
{
    class TurtleGraphics
    {
        static void Main(string[] args)
        {
            int choice = 0;
            TurtleGraphics turtleGraphics = new TurtleGraphics();
            Canvas canvas = new Canvas();
            Turtle sandy = new Turtle();
            while (choice != 9) 
            {
                turtleGraphics.printOptions();
                choice = Convert.ToInt32 (Console.ReadLine());
                switch(choice)
                {
                    case 1:
                        sandy.UpOrDown = 0;
                        break;
                    case 2:
                        sandy.UpOrDown = 1;
                        break;
                    case 3:
                        sandy.ChangeDirection(1);
                        break;
                    case 4:
                        sandy.ChangeDirection(0);
                        break;
                    case 5:
                        Console.WriteLine("How many steps?");
                        int a = Convert.ToInt32(Console.ReadLine());
                        sandy.Walk(a, ref canvas.floor);
                        break;
                    case 6:
                        canvas.printFloor();
                        break;
                    case 9:
                        Console.WriteLine("THANKS!");
                        break;
                }
            }
        }
        
        public void printOptions()
        {
            Console.WriteLine("1: Lift Pen Up");
            Console.WriteLine("2: Put Pen Down");
            Console.WriteLine("3: Turn Right");
            Console.WriteLine("4: Turn Left");
            Console.WriteLine("5: Move");
            Console.WriteLine("6: Print The picture");
            Console.WriteLine("9: Finish");

        }
    }
}
