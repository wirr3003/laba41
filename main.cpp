#include "graphics.h"
#include "control.h"
#include "task.h"

int main() {
   initwindow(1000, 800);
   
   create_control(PAINT, SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "circle.bmp");
   create_control(CIRCLE, 3*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "paint.bmp");
   create_control(SAVE, 11*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "SAVE.bmp");
   create_control(EXIT, 13*SIZEBUTTON, SIZEWINDOW-SIZEBUTTON, "EXIT.bmp");


   while (true) 
   {
      while (mousebuttons() != 1);
      switch (select_control()) 
      {
      case NONE:
         break;
      case PAINT:
         build();
         break;
      case CIRCLE:
         newpaint();
      break;
      case SAVE:
         save();
      break;
      case EXIT:
         closegraph();
         return 0;
      }
   }
}