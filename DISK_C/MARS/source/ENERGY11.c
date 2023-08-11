#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>

typedef struct energy
{
    int sun_e;
    int nuclear_e;
    int wind_e;
    int geothermal_e;
}ENERGY;

//void energy()
void energy()
{
    FILE *fp;
    int pos = 0;
    int value;
    ENERGY fe;
    char buffer[20];
    int i,j;

  /*  int gd = VGA, gm = VGAHI;
    initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");   */

	//draw backwindow
    setfillstyle(1,LIGHTBLUE);
    setcolor(WHITE);
    bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
    rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);
    setcolor(WHITE);
    rectangle(560 - 28, 60 + 6, 560 - 8, 60 + 26);
    rectangle(560 - 48, 60 + 6, 560 - 28, 60 + 26);
    
    setlinestyle(0, 0, WHITE);
    line(560 - 28, 60 + 6, 560 - 8 , 60 + 26);
    line(560 - 8 , 60 + 6, 560 - 28, 60 + 26);
    line(560 - 48 + 3, 60 + 16, 560 - 28 - 3, 60 + 16);
    line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 - 6);
    line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 + 6);

    //draw 4 subwindow
    setlinestyle( DOTTED_LINE, 0, 1);
    line(320, 60 + 6, 320, 420 - 6);
    line(80 + 8, 240, 560 - 8, 240);

}