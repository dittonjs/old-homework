using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ColorLibrary
{
    public class SortedColors
    {
        private string[] colorNames = { "Blue", "Green", "Black", "White", "Red", "Yellow", "Purple", "Pink", "Gray", "Orange", "Teal", "Gold", "Silver", "Aqua" };
        private SortedDictionary<string, Color> colors = new SortedDictionary<string, Color>();
        public SortedColors()
        { 
            for(int i= 0; i<colorNames.Length; i++){
                colors.Add(colorNames[i], Color.FromName(colorNames[i]));
            }
        }

        public Color getColor(string name) {
            Color c;
            colors.TryGetValue(name, out c);
            return c;
        }
        
        
    }
}
