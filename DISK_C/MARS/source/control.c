//#include <graphics.h>
//#include <bios.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include "mouse.h"
#include "control.h"
#include "environ.h"
#include "energy.h"

#define win_w 320
#define win_h 400
#define subwin_w 300
#define subwin_h 240
#define rate 0.5

typedef struct PANEL
{
	char type ;

}panel;

void draw_control();
void draw_jumpmenu(int fillcolor);
void draw_window(short int type);
void item_ctr(ITEM *item);
void withdraw(short int type_r);
void menu(ITEM *);
void control();
//void environment(FILE *envi);



void draw_jumpmenu(int fillcolor)
{
	setfillstyle(1,fillcolor);
	setcolor(WHITE);
	bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
	rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);
}

void control()
{
	int gd = VGA, gm = VGAHI;
	ITEM item = {0, 0};
	cleardevice();
	//initgraph( &gd, &gm, "C:\\BORLANDC\\BGI");

	draw_control();
   //	draw_menu();
	item_ctr(&item);
}

void draw_control()
{
	panel page;

	setbkcolor(BLACK);

	//draw the main window  [15,50]-[335,450]
	setfillstyle(1,DARKGRAY);
	bar(20, 53, 20 + win_w, 53 + win_h);//[20,53]-[340,453]
	setfillstyle(1,LIGHTBLUE);
	bar(15, 50, 15 + win_w, 50 + win_h);//[15,50]-[335,450]

	//draw MARS [20,55]-[330,270]
	setfillstyle(0,0);
	bar(20, 55, 20 + 210, 55 + 210);
	setfillstyle(1,LIGHTRED);
	fillellipse(20 + 105, 55 + 105, 90, 90);//[20,55]-[230,265]

	//draw buttons_group 1
	setfillstyle(0,0);
	bar(235, 65 , 330, 65  + 30); //[235, 65]-[330, 95]
	bar(235, 100, 330, 100 + 30); //[235, 100]-[330,130]
	bar(235, 135, 330, 135 + 30); //[235,135]-[330,165]
	bar(235, 170, 330, 170 + 30); //[235,170]-[330,200]
	bar(235, 205, 330, 205 + 30); //[235,205]-[330,235]
	setcolor(WHITE);
	settextstyle(0, 0, 1);
	outtextxy(235 + 5, 65  + 10, "ENVIRONMENT");
	outtextxy(235 + 5, 100 + 10, "ENERGY" );
	outtextxy(235 + 5, 135 + 10, "RESOURCE");
	outtextxy(235 + 5, 170 + 10, "SECURITY");
	outtextxy(235 + 5, 205 + 10, "RESEARCH");


	//draw connect picture
	//setfillstyle(0,0);
	//bar(20, 280, 20 + 210, 280 + 100);//[20,280]-[230,380]


	//draw the subwin1 [340,50]-[620,290]
	setfillstyle(1,DARKGRAY);
	bar(20 + win_w + 5, 53, win_w + 5 + subwin_w, 53 + subwin_h + 3);
	setfillstyle(1,LIGHTBLUE);
	bar(20 + win_w    , 50, win_w + subwin_w    , 50 + subwin_h);
	setfillstyle(1,DARKGRAY);
	bar(20 + win_w + 10, 60, win_w + subwin_w/3 - 10 , 80 );


	//draw the subwin2 [340,295]-[640,450]
	setfillstyle(1,DARKGRAY);
	bar(20 + win_w, 53 + subwin_h + 3, win_w + 5 + subwin_w, 53 + subwin_h + 160);
	setfillstyle(1,LIGHTBLUE);
	bar(20 + win_w, 55 + subwin_h    , win_w + subwin_w    , 50 + subwin_h + 160);

	//draw the subcity map
	setfillstyle(0,DARKGRAY);
	bar(340, 300, 340 + 160, 300 + 120);
	//setcolor(WHITE);
	//rectangle(340, 300, 340 + 160, 300 + 120); //[340,300]-[500,420]
	setcolor(LIGHTRED);
	circle(420, 300 + 60, 55);
	setcolor(RED);
	circle(420, 300 + 60, 50);
	setfillstyle(7, WHITE);
	fillellipse(420, 300 + 60, 50, 50);
	setcolor(WHITE);
	/*for(i = 0; i < N; i++)
	{
		circle(120 + pos[i][0] / 3 , 30 + 60 + pos[i][1] / 3, pixel_rad / 1.5);
	}*/
	//setcolor

}

/*void item_menu(ITEM *item)
{


}*/

//draw subwindow point [320,240] square[480,360]
void draw_window(short int type)
{
	switch (type)
	{
		case 0 :
		{
			draw_control();
			break;
		}
		case 1 : //ENVIRONMENT panel
		{
			environ_0();
			break;
		}

		case 2 : //ENERGY panel
		{
			energy();
			//draw energy illustration

			break;
		}

		case 3 : //RESOURCE panel
		{

			resource();
			break;
		}

		case 4 : //SECURITY panel
		{
			setfillstyle(1,BROWN);
			setcolor(WHITE);
			bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
			rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);

			break;
		}

		case 5 : //RESEARCH panel
		{
			setfillstyle(1,BLUE);
			setcolor(WHITE);
			bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
			rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);

			break;
		}
	}
}

void item_ctr(ITEM* item)
{
	mouseinit();
	while(1)
	{
		item->key = bioskey(1);
		if(item->key == 0x011b)
		{
			exit(1);
		}
		newmouse(&MouseX, &MouseY,&press);
		if(item->type_n == 0)
			if(MouseX>0 && MouseX<640 && MouseY>0 && MouseY<480)
			{
			   //	menu_ctr();
				if(mouse_press(235, 65, 330,  95) == 1) //click "ENVIRON"
				{
					item->type_r = item->type_n;
					item->type_n = 1;
					clrmous(MouseX, MouseY);
					draw_window(item->type_n);
				}

				if(mouse_press(235, 100, 330, 130) == 1)//click "ENERGY"
				{
					item->type_r = item->type_n;
					item->type_n = 2;
					clrmous(MouseX, MouseY);
					draw_window(item->type_n);
				}

				if(mouse_press(235, 135, 330, 165) == 1)//click "RESOURCE"
				{
					item->type_r = item->type_n;
					item->type_n = 3;
					clrmous(MouseX, MouseY);
					draw_window(item->type_n);

				}

				if(mouse_press(235, 170, 330, 200) == 1)//click "SECURITY"
				{
					item->type_r = item->type_n;
					item->type_n = 4;
					clrmous(MouseX, MouseY);
					draw_window(item->type_n);

				}

				if(mouse_press(235, 205, 330, 235) == 1)//click "RESEARCH"
				{
					item->type_r = item->type_n;
					item->type_n = 5;
					clrmous(MouseX, MouseY);
					draw_window(item->type_n);

				}
			}
		if(item->type_n != 0)
		{
			if(MouseX>0 && MouseX<640 && MouseY>0 && MouseY<480)
			{
				if(mouse_press(560-28, 66, 560-8, 86) == 1)//560 - 28, 60 + 6, 560 - 8 , 60 + 26
				{
					item->type_r = item->type_n;
					item->type_n = 0;
					clrmous(MouseX,MouseY);
					cleardevice();
					draw_window(item->type_n);
				}
			}
		}


	}



}


/*void environment()
{
	FILE *p_e;
	int pos = 0;
	int value;
	envi fe;

	p_e = fopen ("envi_Data", "rb+");

	//draw backwindow
	setfillstyle(1,DARKGRAY);
	setcolor(WHITE);
	bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
	rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);

	//draw mars
	setfillstyle(0,0);
	bar(90, 70, 90 + 180, 70 + 180);//[90,70]-[270,250]
	setfillstyle(1,RED);
	fillellipse(90 + 90, 70 + 90, 80, 80);

	//read envi_Data
	p_e = fopen ("environ_Data","rt+");
	fe.TEMPERATURE = fscanf(p_e, "%d", pos * sizeof(int));
	fe.HUMIDITY    = fscanf(p_e, "%d", (pos + 1) * sizeof(int));
	fe.OXYGEN      = fscanf(p_e, "%d", (pos + 2) * sizeof(int));
	fe.NITROGEN    = fscanf(p_e, "%d", (pos + 3) * sizeof(int));


	//show mars panel
	setfillstyle(1,DARKGRAY);
	bar(90 - 4, 270 - 3, 90 - 4, 290 - 3 );
	setcolor(RED);
	settextstyle(0,0,1);
	outtextxy(90, 270, "TEMPERATURE(CEL):25");
	outtextxy(90, 290, "HUMIDITY(RH): 50");
	outtextxy(90, 310, "GAS ENVIRONMENT:");
	outtextxy(90, 330, "OXYGEON:78  NITROGEN:21");
	outtextxy(90, 350, "RADIATION: NORMAL");

	fclose(p_e);
}*/