#ifndef CONTROL_H
#define CONTROL_H

//#define SIZEBUTTONS 90(НАДО ЛИ)
//#define SIZEBUTTONB 85(НАДО ЛИ)

enum control_values { NONE = -1, SAVE, EXIT, 
                     CIRCLE, PAINT, N_CONTROLS };//CIRCLE - построить, PAINT - закраска

struct Control{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int);//почему здесь пишет ошибку
//void create_control_1(int, int, int);
int select_control();

#endif