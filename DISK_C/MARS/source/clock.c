#include <math.h>
#include <graphics.h>
#include <time.h>

#define pi 3.1415926

void main()
{
    int i,l;
    int x1,x2;
    int y1,y2;

    int gd = VGA, gm = VGAHI;
    initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");


    setbkcolor(BLACK); 
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(WHITE);
	circle(320, 160, 120); 
	setcolor(RED);
	circle(320, 160, 105);
	setcolor(WHITE);
	circle(320, 160, 5);

    for (i = 0; i < 60; i++)
	{
		if (i % 5 == 0) l = 15;
		else l = 5;
		x1 = 120 * cos(i * 6 * pi / 180) + 320;
		y1 = 120 * sin(i * 6 * pi / 180) + 160;
		x2 = (120 - l) * cos(i * 6 * pi / 180) + 320;
		y2 = (120 - l) * sin(i * 6 * pi / 180) + 160;
		line(x1, y1, x2, y2);
	}
}
