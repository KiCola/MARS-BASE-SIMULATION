#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
//#include "hz.h"
#include <bios.h>

typedef struct resource
{
	int bd_material[2];
	char water[10];
	char food[10];
}RESO;

typedef struct RE_page
{
	short page;
	short page_r;
}re_page;

void draw_resource();


//void resource()
void resource()
{
	FILE *fp;
	RESO fe;
	int i,j;
	char ch;
	int key;
  //	int gd = VGA, gm = VGAHI;
  //	initgraph(&gd, &gm, "../../BORLANDC/BGI");
	draw_resource();


}

void draw_resource()
{
	int lx,ly;
	int i,j;

	//draw backwindow
	setfillstyle(1,BLUE);
	setcolor(WHITE);
	bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
	rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);
	setcolor(WHITE);
	rectangle(560 - 28, 60 + 6, 560 - 8 , 60 + 26);
	rectangle(560 - 48, 60 + 6, 560 - 28, 60 + 26);

	setlinestyle(0, 0, WHITE);
	line(560 - 28, 60 + 6, 560 - 8 , 60 + 26);
	line(560 - 8 , 60 + 6, 560 - 28, 60 + 26);
	line(560 - 48 + 3, 60 + 16, 560 - 28 - 3, 60 + 16);
	line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 - 6);
	line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 + 6);

   /*	for(i = 0; i< 640 ; i += 20)
	{
		for(j = 0; j < 480; j += 20)
		{
			setcolor(WHITE);
			setlinestyle(DOTTED_LINE, 0, 1);
			rectangle(i, j, i + 20, j + 20 );
		}
	}        */

	setlinestyle( DOTTED_LINE, 0, 1);
	line(320, 60 + 6, 320, 420 - 6);
	line(80 + 8, 240, 560 - 8, 240);

	//draw buttons

	setfillstyle(1,WHITE);

	//robo_group
	//bar(5*20, 5*20, 15*20, 7*20);
	settextstyle(1,0,3);
	setcolor(BLACK);
	
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,3);
	bar(5*20, 4*20,15*20,12*20-10);
	outtextxy(5*20+5, 4*20+3, "robo-group");
	rectangle(5*20, 4*20,15*20,12*20 - 10);
	line(5*20,6*20,15*20,6*20);

	settextstyle(1, 0 ,1);
	setcolor(BLACK);
	outtextxy(5*20,6*20," occupancy:    70%");//[5,4]-[6 + 9, 5 + 7]
	outtextxy(5*20,7*20," working  :    60%");
	outtextxy(5*20,8*20," availibility: 20%");
	outtextxy(5*20,9*20," maintance:    20%");

	//draw_bdmaterial
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,3);
	bar(17*20, 4*20,25*20,12*20-10);
	outtextxy(17*20+5, 4*20+3, "bd-material");
	rectangle(17*20, 4*20,25*20,12*20 - 10);
	line(17*20,6*20,25*20,6*20);

	settextstyle(1, 0 ,1);
	setcolor(BLACK);
	outtextxy(17*20,6*20,"    metal ");
	setfillstyle(1,RED);
	fillellipse(17*20+13,7*20+10,7,7);

	//outtextxy(17*20,7*20," working  :    60%");
	outtextxy(17*20,8*20,"    glass ");
	fillellipse(17*20+13,9*20+10,7,7);
	//outtextxy(17*20,9*20," maintance:    20%");

	outtextxy(17*20,10*20,"mars-material ");
	fillellipse(17*20+13,11*20+8,7,7);

	//draw food
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,3);
	bar(17*20, 13*20,25*20,20*20);
	outtextxy(17*20+5, 13*20+3, "food");
	rectangle(17*20, 13*20,25*20,20*20);
	line(17*20,15*20,25*20,15*20);

	setfillstyle(1,LIGHTGREEN);
	outtextxy(17*20,15*20,"Vegetables");
	outtextxy(17*20,17*20 - 5,"Protain");
	outtextxy(17*20,19*20 - 10,"Sugar");

	//draw electricity
	setfillstyle(1,LIGHTBLUE);
	setlinestyle(0,0,3);
	bar(5*20, 13*20,15*20,20*20);
	outtextxy(5*20+5, 13*20+3, "electricity");
	rectangle(5*20, 13*20,15*20,20*20);
	line(5*20,15*20,15*20,15*20);

	setlinestyle(0,0,1);
	settextstyle(1,0,1);

	setcolor(YELLOW);
	circle(160,350,40);
	setfillstyle(7,YELLOW);//taiyangneng
	pieslice(160,350,0,100,40);
	fillellipse(215,315,3,3);
	outtextxy(220, 300,"SolarE");

	setfillstyle(7,RED);//direneng
	pieslice(160,350,100,180,40);
	fillellipse(215,330,3,3);
	outtextxy(220, 315,"GeoTE");

	setfillstyle(7,BLUE);//heneng
	pieslice(160,350,180,290,40);
	fillellipse(215,345,3,3);
	outtextxy(220, 330,"NuclearE");

	setfillstyle(7,LIGHTGRAY);//fengneng
	pieslice(160,350,290,320,40);
	fillellipse(215,360,3,3);
	outtextxy(220, 345,"WindE");

	setfillstyle(7,BROWN);
	pieslice(160,350,320,360,40);
	fillellipse(215,375,3,3);
	outtextxy(220, 360,"Fossil");

	
	setcolor(WHITE);
	for(lx = 6*20 - 4; lx <= 14*20; lx ++ )
	{
		for(ly = 10*20 + 10; ly <= 11 * 20; ly ++)
		{
			moveto(lx, ly);
			lineto(lx+1, ly);
			lineto(lx+1, ly+1);
			lineto(lx, ly+1);
			lineto(lx, ly);
			//delay(3);
		}
	}


	//outtextxy()
	//bar(120,120, 340 + 20 * 9, 120 + 20);
	/*for(lx = 0, ly = 0;ly < 40 * 7 ; ly += 40 )
	{
		bar(120, 120 + ly, 340 + 20 * 9, 120 + 20 + ly);
	}*/



}

