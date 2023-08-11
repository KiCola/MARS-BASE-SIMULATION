#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include"draw.h"
/*******************************
function: draw_cubic
description:draw cubics of certain pattern
input:integers a,b,c,d,e.(coordinates(a,b),length c,height d,depth e)
return:void
designer:lyn
********************************/
void draw_cubic(int a, int b, int c, int d, int e)   
{
	setcolor(DARKGRAY);
	bar3d(a, b, a + c, b + d, e, 1);
	setfillstyle(1, LIGHTBLUE);
	floodfill(a + 5, b - 1, DARKGRAY);
	setfillstyle(1, BLUE);
	floodfill(a + c + 5, b + d - 5, DARKGRAY);
	setfillstyle(1, YELLOW);
	floodfill(a + 5, b + 5, DARKGRAY);
}
/*******************************
function: draw_button
description:draw buttons of certain pattern
input:a,b,c,d,s(LEFT,TOP,RIGHT,BOTTOM,CONTENT)
designer:lyn
********************************/
void draw_button(int a, int b, int c, int d,char s[])
{
	setfillstyle(1, DARKGRAY);
	bar(a,b,c,d);
	setfillstyle(1, WHITE);
	bar(a-5, b-5, c-5, d-5);
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	rectangle(a-5, b-5, c-5, d-5);
	settextstyle(1, 0, 2);
	outtextxy(a+(c-a)/10, b+(d-b)/10, s);
}
