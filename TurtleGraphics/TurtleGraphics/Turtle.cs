using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TurtleGraphics
{
    class Turtle
    {
        enum Direction { up, dwn, lft, rt };
        private int xLoc;
        private int yLoc;
        private int upOrDown; // 0 for up 1 for down;
        private Direction myDir;
        // ==================
        // PROPERTIES
        // ==================
        public Turtle() 
        {
            myDir = Direction.dwn;
            XLoc = 0;
            YLoc = 0;
            upOrDown = 0;
        }
        public int XLoc
        {
            get { return xLoc; }
            set { xLoc = value; }
        }

        public int YLoc
        {
            get { return yLoc; }
            set { yLoc = value; }
        }

        public int UpOrDown
        {
            get { return upOrDown; }
            set { upOrDown = value; }
        }

        
        // =======================
        // METHODS
        // =======================
        public void Walk(int dist, ref int[,] gameBoard) 
        {
            switch (myDir) 
            {
                case Direction.up:
                    for (int i = 0; i < dist && XLoc >=0 && XLoc < 20; i++ )
                    {
                        if (upOrDown == 1) gameBoard[YLoc, XLoc] = 1;
                        if (i != dist - 1) YLoc = YLoc - 1;
                        if (YLoc < 0) YLoc = 0;
                    }
                    break;
                case Direction.dwn:
                    for (int i = 0; i < dist && XLoc >= 0 && XLoc < 20; i++)
                    {
                        if (upOrDown == 1) gameBoard[YLoc, XLoc] = 1;
                        if (i != dist - 1) YLoc = YLoc + 1;
                        if (YLoc > 19) YLoc = 19;
                    }
                    break;
                case Direction.lft:
                    for (int i = 0; i < dist && YLoc >= 0 && YLoc < 20; i++)
                    {
                        if (upOrDown == 1) gameBoard[YLoc, XLoc] = 1;
                        if (i != dist - 1) XLoc = XLoc - 1;
                        if (XLoc < 0) XLoc = 0;
                    }
                    break;
                case Direction.rt:
                    for (int i = 0; i < dist && XLoc >= 0 && XLoc < 20; i++)
                    {
                        if (upOrDown == 1) gameBoard[YLoc, XLoc] = 1;
                        if (i != dist - 1) XLoc = XLoc + 1;
                        if (XLoc > 19) XLoc = 19;
                    }
                    break;
            }
        }
       public void ChangeDirection(int rtOrLt) 
        {
            if (rtOrLt == 1) // TURN RIGHT
            {
                switch (myDir)
                {
                    case Direction.up:
                        myDir = Direction.rt;
                        break;
                    case Direction.dwn:
                        myDir = Direction.lft;
                        break;
                    case Direction.lft:
                        myDir = Direction.up;
                        break;
                    case Direction.rt: myDir = Direction.dwn;
                        break;
                }
            }
            else // TURN LEFT 
            {
                switch (myDir)
                {
                    case Direction.up:
                        myDir = Direction.lft;
                        break;
                    case Direction.dwn:
                        myDir = Direction.rt;
                        break;
                    case Direction.lft:
                        myDir = Direction.dwn;
                        break;
                    case Direction.rt: myDir = Direction.up;
                        break;
                }
            }
        }
    }
}
