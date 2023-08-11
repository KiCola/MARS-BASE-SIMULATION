#include "menu.h"
#include <graphics.h>
#include "mouse.h"
#include <stdlib.h>
#include "environ.h"
#include "energy.h"
#include "control.h"

/*******************************
designer:zzr
upgrade date: 2023.3.13
input:void
return :
********************************/
#define LOGIN 0
#define MAIN 1
#define BUILD 2
#define CONTROL 3
#define SCIENCE 4



/*******************************
data:struct menuinfo
description:control the menu line
designer:zzr
********************************/
typedef struct menuinfo
{
	short int page;     //父菜单号
	short int page_r;//防止重复刷新
	short int func;        //功能函数号
	int keybroad;//键盘
}m_info;

void menu()
{
	draw_menu();
	menu_ctr();
}



/*******************************
function: draw_menu
description:draw the menuline
input:void 
return:void
********************************/
void draw_menu(void)//画出页面上方菜单栏
{
    setfillstyle(1,LIGHTGRAY);
    setcolor(BLUE);
    setlinestyle(0,0,2);
    bar(0,0,640,24);
    rectangle(0,0,639,479);
	settextstyle(1,0,1);

	outtextxy(10,5,"exit");
	line(90,1,90,24);

	outtextxy(100,5,"login");
	line(180,1,180,24);

	outtextxy(190,5,"main");
	line(270,1,270,24);

	outtextxy(280,5,"build");
	line(360,1,360,24);

	outtextxy(370,5,"control");
	line(450,1,450,24);

	outtextxy(460,5,"subcity");
	line(540,1,540,24);
}


/*******************************
function: swit_page
description:jump to page
input:short int page_num
return:void
********************************/
/*void swit_page(short int page)
{
	cleardevice();
	switch(page)
	{
	case 0:
	  LOGIN_P();
	case 1:
	  MAIN_P();
	case 2:
	  BUILD_P();
	case 3:
	  CONTROL_P();
	case 4:
	  SCIENCE_P();
	}
}

/*******************************
function: menu_ctr
description:menu info control
input:m_info *menu
return:void
********************************/
void menu_ctr(void)
{
	if(MouseX>0 && MouseX<640 && MouseY>0 && MouseY<480)
	{
		if(mouse_press(0,0,90,24)==1)
		{
			exit(1);
		}
		else if(mouse_press(90,0,180,24)==1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			func_login1();
		}
		else if(mouse_press(180,0,270,24)==1)
		{
			clrmous(MouseX,MouseY) ;
			cleardevice();
			Tmap();
		}
		else if(mouse_press(360,0,450,24)==1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			control();
		}
		else if(mouse_press(450, 0, 540, 24) == 1)
		{
			clrmous(MouseX,MouseY);
			cleardevice();
			subcity();

		}
	}

	//else if(mouse_press(90,0,180,24)==1)
	//{
	//	menu->page = LOGIN;
	//	swit_page(menu->page);
	//	//menu->page_r=0;
	//}

	//else if(mouse_press(180,0,270,24)==1)
	//{
	//	menu->page = MAIN;
	//	swit_page(menu->page);
	//}

	//else if(mouse_press(270,0,360,24)==1)
	//{
	//	menu->page = BUILD;
	//	swit_page(menu->page);
	//}

	//else if(mouse_press(360,0,450,24)==1)
	//{
	//	menu->page = CONTROL;
	//	swit_page(menu->page);
	//}

	//else if(mouse_press(450,540)==1)
	//{
	//	menu->page = SCIENCE;
	//	swit_page(menu->page);
	//}
}


/*void submenu()
void lightbutton_menu(short int ord)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(1,LIGHTBLUE);
	switch(ord)
	{
		case 1:
			bar(0,24,60,48);
			puthz(10,29,"登陆",16,24,WHITE);
			break;
		case 2:
			bar(0,48,60,72);
			puthz(10,53,"退出",16,24,WHITE);
			break;
		case 3:
			bar(0,72,60,96);
			puthz(10,77,"注销",16,24,WHITE);
			break;
		case 4:
			bar(0,96,60,120);
			puthz(10,101,"关于",16,24,WHITE);
			break;}*/
//void initmenu(int* page);//初始化菜单栏
/*void lightbutton_menu(short int so_num)//点亮菜单按钮
{
	clrmous(MouseX,MouseY);
	delay(10);
	setfillstyle(1,LIGHTBLUE);
	switch(so_num)
	{
		case 1:
		    bar()
	}

}*/
//void recoverbutton_menu(short int)//恢复菜单按钮