// Fig 14.38: PainterForm.cs
// Using the mouse to draw on a Form.
using System;
using System.Drawing;
using System.Windows.Forms;
using ColorLibrary;

namespace Painter
{
   // creates a Form that is a drawing surface
   public partial class PainterForm : Form
   {
      bool shouldPaint = false; // determines whether to paint
      enum BrushSize
      {
          SMALL = 4,
          MEDIUM = 8,
          LARGE = 16
      };
      BrushSize size;
      Color color;
      SortedColors sortedColors = new SortedColors();


      // default constructor
      public PainterForm()
      {
         InitializeComponent();
      }

       // should paint when mouse button is pressed down
      private void paintingPanel_MouseDown( 
         object sender, MouseEventArgs e )
      {
         // indicate that user is dragging the mouse
         shouldPaint = true;
      }

      // stop painting when mouse button is released
      private void paintingPanel_MouseUp( object sender, MouseEventArgs e )
      {
         // indicate that user released the mouse button
         shouldPaint = false;
      }

      // draw circle whenever mouse moves with its button held down        
      private void paintingPanel_MouseMove( 
         object sender, MouseEventArgs e )
      {
         if ( shouldPaint ) // check if mouse button is being pressed
         {
             if (redRadioButton.Checked)
                 color = sortedColors.getColor("Red");
             else if (blueRadioButton.Checked)
                 color = sortedColors.getColor("Blue");
             else if (greenRadioButton.Checked)
                 color = sortedColors.getColor("Green");
             else
                 color = sortedColors.getColor("Black");

             if (smallRadioButton.Checked)
                 size = BrushSize.SMALL;
             else if (mediumRadioButton.Checked)
                 size = BrushSize.MEDIUM;
             else
                 size = BrushSize.LARGE;


            // draw a circle where the mouse pointer is present
            using ( Graphics graphics = paintingPanel.CreateGraphics() )
            {
               graphics.FillEllipse(
                  new SolidBrush( color ), e.X, e.Y, (int)size, (int)size );
            }
         }
      }
   }
}