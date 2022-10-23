#include <cmath>
#include "graphics.h"
#include <cstdlib>
#include "task.h"
#include "ctime"
#define _USE_MATH_DEFINES

using namespace std;

bool design=false;//можно ли сделать true и там где !=, заменить на false

void circles( int x_0, int y_0, int R)
{
   int color = COLOR_MAX;
   int x_1 = 0, y_1 = R, p = 3-2*R;
   
   while(x_1<=y_1)
      {
         putpixel(x_0 + x_1, y_0 + y_1, color);
         putpixel(x_0 + x_1, y_0 - y_1, color);
         putpixel(x_0 - x_1, y_0 + y_1, color);
         putpixel(x_0 - x_1, y_0 - y_1, color);
         putpixel(x_0 + y_1, y_0 + x_1, color);
         putpixel(x_0 + y_1, y_0 - x_1, color);
         putpixel(x_0 - y_1, y_0 + x_1, color);
         putpixel(x_0 - y_1, y_0 - x_1, color);
         
         if(p > 0)
            {
               p += 4 * (x_1-y_1) + 10;
               y_1--;
            }
         else//можно ли написать elif
         {
            p += 4 * x_1 + 6;
         }
         x_1++;
      }
}
void paint(int x_0,int y_0, int basic) //seed color = basic
{
   int x_1, y_1;
   double df=M_PI/6, da=df/2;//как можно заменить df

   int color[7];
   int R1[3]= {30, 180, 280};
   int R2[4]= {30, 110, 160, 250};
   for (int i = 0; i < 7; i++)//можно ли делать с пробелами?
      {
         color[i] = rand() % WHITE;
      }
   for (int i = 0; i < 3; i++) 
      {
      setfillstyle(SOLID_FILL, color[i]);
      for (int j=0; j<12; j++)
      {
         x_1 = x_0 + R1[i] * cos(j * df);
         y_1 = y_0 + R1[i]  *sin(j * df);
         floodfill(x_1, y_1, COLOR_MAX);
      }
   }
   for (int i = 0; i < 4; i++) 
   {
      setfillstyle(SOLID_FILL, color[3+i]);
      for (int j = 0; j < 12; j++) 
      {
         x_1 = x_0 + R2[i] * cos(j * df+da);//чем заменить da
         y_1 = y_0 + R2[i] * sin(j * df+da);
         floodfill(x_1, y_1, COLOR_MAX);
      }
   }
}
void circle_1(int x_0, int y_0, int R) 
{
   circles(x_0,y_0,R);
   for (int i = 1; i <= 12; i++)
   {
      circles(x_0+R * cos((M_PI/6)*i), y_0+R * sin((M_PI/6) * i),  R);
   }
}

void build() 
{
   circle_1(WIDTH/2,(WIDTH-FRAMELOWER)/2,FRAMELOWER+50);//что такое FRAMELOWER, куда писать
   design=true;
}
void newpaint() {

   if (!design) return;

   while (mousebuttons()!=0);
   int basic=rand()%WHITE;
   setfillstyle(SOLID_FILL, basic);

   paint(WIDTH/2,(WIDTH-FRAMELOWER)/2, basic);
   circles(3*WIDTH/5+INDENT, HIEGHT-INDENT-3*FRAMESIDE/2,INDENT+1);   // 3*FRAMELOWER-FRAMESIDE ,5*FRAMELOWER-FRAMESIDE ,INDENT-1
   floodfill(3*WIDTH/5+INDENT, HIEGHT-INDENT-3*FRAMESIDE/2,COLOR_MAX);
}

void save()
{
   int w, h;
   IMAGE *output;
   
   w = getmaxx() + 1;
   h = getmaxy() + 1;
   output = createimage(w, h);
   
   getimage(0, 0, w - 1, h - 1, output);
   saveBMP("output1.bmp", output);
   freeimage(output);
}

