#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include"draw.h"
#include"mouse.h"
#include"menu.h"
void main()
{
	//clrmous(MouseX, MouseY);
	cleardevice();
	draw_mcmap();
	//draw_menu();
	//draw_button(100,380,280,430,"MAIN CITY");
	//draw_button(400, 380, 570, 430, "SUB CITY");
	/*while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 0 && MouseX<640 && MouseY>0 && MouseY < 480)
		{
			if (mouse_press(100, 380, 280, 430) == 1)
			{
				exit(1);
				//maincity();
			}
			else if (mouse_press(400, 380, 570, 430) == 1)
			{
				clrmous(MouseX, MouseY);
				cleardevice();
				//subcity();
			}
			else continue;
		}
	}
	//if (mouse_press(165, 275, 275, 305)==1)
	getchar();  */
}

/*******************************
function: draw_mcmap
description:draw main city map of the MARS HOME
input:void
return:void
designer:lyn
********************************/
void draw_mcmap()
{
	setfillstyle(SOLID_FILL, RED);//1
	bar(32 - 8, 256 - 16, 32 + 8, 256 - 1);
	bar(411 - 8, 256 - 16, 411 + 8, 256 - 1);
	setfillstyle(SOLID_FILL, LIGHTBLUE);//7
	bar(480 - 8, 320 - 16, 480 + 8, 320 - 1);
	bar(230 - 8, 320 - 16, 230 + 8, 320 - 1);
	bar(174 - 8, 320 - 16, 174 + 8, 320 - 1);
	setfillstyle(SOLID_FILL, RED);//3
	bar(48 - 8, 384 - 16, 48 + 8, 384 - 1);
	bar(171 - 8, 384 - 16, 171 + 8, 384 - 1);
	bar(219 - 8, 384 - 16, 219 + 8, 384 - 1);
	bar(298 - 8, 384 - 16, 298 + 8, 384 - 1);
	bar(344 - 8, 384 - 16, 344 + 8, 384 - 1);
	bar(512 - 8, 384 - 16, 512 + 8, 384 - 1);
	setfillstyle(SOLID_FILL, LIGHTBLUE);//5
	bar(580 - 8, 448 - 16, 580 + 8, 448 - 1);
	bar(531 - 8, 448 - 16, 531 + 8, 448 - 1);
	bar(396 - 8, 448 - 16, 396 + 8, 448 - 1);
	bar(191 - 8, 448 - 16, 191 + 8, 448 - 1);
	bar(32 - 8, 448 - 16, 32 + 8, 448 - 1);
	setfillstyle(SOLID_FILL, LIGHTBLUE);//8
	bar(32 - 8, 256 + 1, 32 + 8, 256 + 16);
	bar(411 - 8, 256 + 1, 411 + 8, 256 + 16);
	setfillstyle(SOLID_FILL, RED);//2
	bar(480 - 8, 320 + 1, 480 + 8, 320 + 16);
	bar(230 - 8, 320 + 1, 230 + 8, 320 + 16);
	bar(174 - 8, 320 + 1, 174 + 8, 320 + 16);
	setfillstyle(SOLID_FILL, LIGHTBLUE);//6
	bar(48 - 8, 384 + 1, 48 + 8, 384 + 16);
	bar(171 - 8, 384 + 1, 171 + 8, 384 + 16);
	bar(219 - 8, 384 + 1, 219 + 8, 384 + 16);
	bar(298 - 8, 384 + 1, 298 + 8, 384 + 16);
	bar(344 - 8, 384 + 1, 344 + 8, 384 + 16);
	bar(512 - 8, 384 + 1, 512 + 8, 384 + 16);
	setfillstyle(SOLID_FILL, RED);//4
	bar(580 - 8, 448 + 1, 580 + 8, 448 + 16);
	bar(531 - 8, 448 + 1, 531 + 8, 448 + 16);
	bar(396 - 8, 448 + 1, 396 + 8, 448 + 16);
	bar(191 - 8, 448 + 1, 191 + 8, 448 + 16);
	bar(32 - 8, 448 + 1, 32 + 8, 448 + 16);

	puthz(4 + 2, 224 + 2, "天河机场", 12, 16, DARKGRAY);
	puthz(387 + 2, 224 + 2, "宋家岗", 12, 16, DARKGRAY);
	puthz(448 + 2, 288 + 2, "宏图大道", 12, 16, DARKGRAY);
	puthz(206 + 2, 288 + 2, "金银潭", 12, 16, DARKGRAY);
	puthz(128 + 2, 288 + 2, "常青花园", 12, 16, DARKGRAY);
	puthz(40 + 2, 352 + 2, "范湖", 12, 16, DARKGRAY);
	puthz(144 + 2, 352 + 2, "青年路", 12, 16, DARKGRAY);
	puthz(200 + 2, 352 + 2, "中山公园", 12, 16, DARKGRAY);
	puthz(272 + 2, 352 + 2, "循礼门", 12, 16, DARKGRAY);
	puthz(328 + 2, 352 + 2, "江汉路", 12, 16, DARKGRAY);
	puthz(488 + 2, 352 + 2, "积玉桥", 12, 16, DARKGRAY);
	puthz(560 + 2, 416 + 2, "洪山广场", 12, 16, DARKGRAY);
	puthz(504 + 2, 416 + 2, "中南路", 12, 16, DARKGRAY);
	puthz(372 + 2, 416 + 2, "街道口", 12, 16, DARKGRAY);
	puthz(167 + 2, 416 + 2, "杨家湾", 12, 16, DARKGRAY);
	puthz(8 + 2, 416 + 2, "佛祖岭", 12, 16, DARKGRAY);
}
