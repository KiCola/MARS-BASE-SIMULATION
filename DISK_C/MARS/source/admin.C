#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include"mouse.h"

/*****************************************
admin.c
COPYRIGHT:	lyn
FUNCTION:	void admin_login()
ABSTRACT:login for administrator
******************************************/
void func_login()
{
	int state = 0;
    char I[15] = { '\0' };	//管理员账号
    char P[10] = { '\0' };	//管理员密码
    int state1 = 0;
    int state2 = 0;
    while (1)
   {
	newmouse(&MouseX, &MouseY, &press);
	if (MouseX > 0 && MouseX < 640 && MouseY > 0 && MouseY<480)
	{
		if (mouse_press(230, 120 + 30, 230 + 380, 120 + 60) == 2)//管理员框未点击
		{
			MouseS = 2;
			if (state == 0 && state1 == 0)//防止被重复标亮
			{
				lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);//color1为边框色，color2为填充色
				state = 1;
			}
			continue;

			//标亮函数
		}
		else if (mouse_press(230, 120 + 30, 230 + 380, 120 + 60) == 1)//管理员框点击
		{
			MouseS = 0;
			lightbutton_admin(230, 120 + 30, 230 + 380, 120 + 60, WHITE, DARKGRAY, 1);
			A[0] = '\0';
			inputadmin(A, 230, 120 + 30, 12, DARKGRAY);
			//输入函数
			if (strlen(A) != 0)
				state1 = 1;
			else
				state1 = 0;
			continue;
		}
	}
	if (MouseX > 230 && MouseX < 230 + 380 && MouseY>240 + 30 && 240 + 60)
	{
		if (mouse_press(230, 240 + 30, 230 + 380, 240 + 60) == 2)//密码框未点击
		{
			MouseS = 2;
			if (state == 0 && state2 == 0)
			{
				lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);//标亮函数
				state = 2;
			}
			continue;
		}
		else if (mouse_press(230, 240 + 30, 230 + 380, 240 + 60) == 1)//密码框点击
		{
			MouseS = 0;
			lightbutton_admin(230, 240 + 30, 230 + 380, 240 + 60, WHITE, DARKGRAY, 2);
			P[0] = '\0';
			inputpassword(P, 230, 240 + 30, 8, DARKGRAY);
			if (strlen(P) != 0)
				state2 = 1;
			else
				state2 = 0;
			continue;
			//输入函数
		}
	}
	if (MouseX > 200 + 220 - 120 && MouseX < 200 + 220 - 50 && MouseY>360 + 30 && 360 + 30 + 35)
	{
		if (mouse_press(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35) == 2)//登录框未点击
		{
			MouseS = 1;
			if (state == 0)
			{
				lightbutton_admin(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35, WHITE, RED, 3);//标亮函数
				state = 3;
			}
			continue;
		}
		else if (mouse_press(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35) == 1)//登录框点击
		{
			MouseS = 0;
			if (admin_judge(A, P))
			{
				//admin_control();
			}
			else
			{
				continue;
			}
			continue;
			//检查是否与录入数据库的管理员身份相符

		}
	}
	if (MouseX > 200 + 220 + 50 && MouseX < 200 + 220 + 120 && MouseY>360 + 30 && 360 + 30 + 35)
	{
		if (mouse_press(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35) == 2)//返回框未点击
		{
			MouseS = 1;
			if (state == 0)
			{
				lightbutton_admin(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35, WHITE, BLUE, 4);//标亮函数
				state = 4;
			}
			continue;
		}
		else if (mouse_press(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35) == 1)//返回框点击
		{
			MouseS = 0;
			*func = 0;
			return;
			//切换至初始化界面
		}
	}
	if (state != 0)
	{
		MouseS = 0;
		if (state1 == 0)
		{
			recoverbutton_admin(1);//恢复按钮颜色
		}
		if (state2 == 0)
		{
			recoverbutton_admin(2);
		}
		if (state == 3 || state == 4 || state == 5)
		{
			recoverbutton_admin(state);
		}
		state = 0;
	}
	if (MouseS != 0)
	{
		MouseS = 0;
	}
}
}
