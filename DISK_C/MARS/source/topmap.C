#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include"draw.h"
#include"mouse.h"
#include"menu.h"
#include<stdlib.h>
void draw_cubic(int a,int b,int c,int d,int e);
void draw_Tmap();
void Tmap()
{
	clrmous(MouseX, MouseY);
	draw_Tmap();
	draw_menu();
	draw_button(100,380,280,430,"MAIN CITY");
	draw_button(400, 380, 570, 430, "SUB CITY");
	mouseinit();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 0 && MouseX<640 && MouseY>0 && MouseY < 480)
		{
			menu_ctr();
			if (mouse_press(100, 380, 280, 430) == 1)
			{
				exit(1);
				//maincity();
			}
			else if (mouse_press(400, 380, 570, 430) == 1)
			{
				clrmous(MouseX, MouseY);
				cleardevice();
				subcity();
			}
			else continue;
		}
	}
	//if (mouse_press(165, 275, 275, 305)==1)
	//getchar();
}

/*******************************
function: draw_Tmap
description:draw 3Dmap of the MARS HOME
input:void
return:void
designer:lyn
********************************/
void draw_Tmap()
{
	//int gd = VGA, gm = VGAHI;
	int i, j;
	//initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	cleardevice();
	setbkcolor(BLACK);
	bar(220, 270, 440, 290);
	fillellipse(200, 260, 170, 85);
	fillellipse(490, 280, 90, 45);
	setlinestyle(0, 0, 6);
	for (i = 0; i<10; i++)//draw roads
	{
		setcolor(BLACK);
		line(0 + 30 * i, 400, 130 + 30 * i, 150);
		for (j = 0; j<10; j++)
		{
			line(80- 10 * j, 180 + 20 * j, 380 - 10 * j, 180 + 20 * j);
		}
	}
	draw_cubic(210, 210, 80, 20, 30);
	draw_cubic(250, 250, 40, 80, 30);
	draw_cubic(320, 235, 20, 30, 20);
	draw_cubic(110, 210, 30, 40, 20);
	draw_cubic(60, 250, 30, 50, 20);

	draw_cubic(150, 150, 60, 150, 40);
	
	setfillstyle(1, BLUE);
	floodfill(230, 140, DARKGRAY);
	floodfill(240, 200, DARKGRAY);
	floodfill(235, 225, DARKGRAY);
	draw_cubic(95, 300, 30, 30, 20);
	draw_cubic(430, 280, 80, 20, 40);
}
