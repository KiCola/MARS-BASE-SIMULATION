#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"mouse.h"
#include"draw.h"
#include"login.h"
void func_login1()//��¼����1����ʵ��
{
	draw_login1();
	mouseinit();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(165, 250, 275, 275) == 1)//click on "LOGIN" button

		{
			func_login2();
		}
		else if (mouse_press(335, 250, 445, 275) == 1)//click on "EXIT" button
		{
			exit(1);         
		}
		else
			continue;
	}
}
void func_login2()//��¼����2����ʵ��
{
	int state = 0;
	char I[15] = { '\0' };	//�˺�
	char P[10] = { '\0' };	//����
	int state1 = 0;
	int state2 = 0;
	//memset(u, '\0', sizeof(id));   //���𴦴�������id����
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_login2();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		//in range of id
		if (MouseX > 250 && MouseX<470 && MouseY>200 && MouseY<225)
		{
			if (mouse_press(250, 200, 470, 225) == 2)//�ڿ���δ���?
			{
				MouseS = 0;
				//if (state == 0 && state1 == 0)//��ֹ���ظ�����
				//{
				//	lightbutton_admin(250, 200, 470, 225, WHITE, DARKGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ����?
				//	state = 2;
				//}
				continue;
			}
			if (mouse_press(250, 200, 470, 225) == 1)//click on "ID"
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(150, 150, 490, 180);
				bar(150, 150, 490, 180);
				MouseS = 0;
				lightbutton_admin(250, 200, 470, 225, WHITE, DARKGRAY, 1);
				I[0] = '\0';
				inputid(I, 250, 200, 12, DARKGRAY);//input id
				if (strlen(I) != 0)
					state1 = 1;//has input
				else
				{
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(250, 200, 470, 225);
					state1 = 0;//no input
				}
				continue;
			}

		}
		//in range of password
		if (MouseX > 250 && MouseX < 470 && MouseY>230 && MouseY<255)
		{
			if (mouse_press(250, 230, 470, 255) == 2)//no click on "PASSWORD"
			{
				MouseS = 0;
				//if (state == 0 && state2 == 0)
				//{
				//	lightbutton_admin(250, 230, 470, 255, WHITE, DARKGRAY, 2);//��������
				//	state = 2;
				//}
				continue;
			}
			if (mouse_press(250, 230, 470, 255) == 1)//click on "PASSWORD"
		   {
				setfillstyle(SOLID_FILL, WHITE);
				bar(150, 150, 490, 180);
				bar(150, 150, 490, 180);
			    MouseS = 0;
			    lightbutton_admin(250, 230, 470, 255, WHITE, DARKGRAY, 2);//��������
			    P[0] = '\0';
			    inputpassword(P, 250, 230, 8, DARKGRAY);//input password
			    if (strlen(P) != 0)
				    state2 = 1;//has input
				else
				{
					setfillstyle(SOLID_FILL, LIGHTGRAY);
					bar(250, 230, 470, 255);
					state2 = 0;//no input
				}
			    continue;
		    }
		}
		//if (state != 0)
		//{
		//	MouseS = 0;
		//	if (state1 == 0)
		//	{
		//		recoverbutton_admin(1);//�ָ���ť��ɫ
		//	}
		//	if (state2 == 0)
		//	{
		//		recoverbutton_admin(2);
		//	}
		//	if (state == 3 || state == 4 || state == 5)
		//	{
		//		recoverbutton_admin(state);
		//	}
		//	state = 0;
		//}
		if (mouse_press(165, 275, 275, 305) == 1)//click on "LOGIN" button
		{
			if(judge_login(I,P)==1)
			   Tmap();
		}
		if (mouse_press(335, 275, 445, 305) == 1)//click on "EXIT" button
		{
			exit(1);
		}
		else
		{
			MouseS = 0;
			continue;
		}
	}
}
/*void user_login(int *func, USER *u)
{
	int num;
	//char U[15] = {'\0'};6-12λ���û���
	//char P[20] = {'\0'};8-16λ������
	//int state1=0;	//���������Ƿ������state
	int state1 = 0;
	int state2 = 0;
	memset(u, '\0', sizeof(USER));   //���𴦴�������u����
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 260 && MouseX < 260 + 315 && MouseY>190 && MouseY < 220)
		{
			if (mouse_press(260, 190, 260 + 315, 220) == 2)//�û�����δ���?
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)//��ֹ���ظ�����
				{
					lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);//color1Ϊ�߿�ɫ��color2Ϊ����?
					num = 1;
				}
				continue;

				//��������
			}
			else if (mouse_press(260, 190, 260 + 315, 220) == 1)//�û�������
			{
				MouseS = 0;
				lightbutton_login(260, 190, 260 + 315, 220, LIGHTRED, LIGHTGRAY, 1);
				u->user[0] = '\0';
				inputadmin(u->user, 260, 190, 12, LIGHTGRAY);
				//���뺯��
				if (strlen(u->user) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}

		}
		if (MouseX > 260 && MouseX < 260 + 315 && MouseY>250 && MouseY < 280)
		{
			if (mouse_press(260, 250, 260 + 315, 280) == 2)//�����δ���
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);//��������
					num = 2;
				}
				continue;
			}
			else if (mouse_press(260, 250, 260 + 315, 280) == 1)//�������?
			{
				MouseS = 0;
				lightbutton_login(260, 250, 260 + 315, 280, LIGHTRED, LIGHTGRAY, 1);
				u->password[0] = '\0';
				inputpassword(u->password, 260, 250, 16, LIGHTGRAY);
				//���뺯��
				if (strlen(u->password) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}
		if (MouseX > 260 && MouseX < 380 && MouseY>310 && MouseY < 345)
		{
			if (mouse_press(260, 310, 380, 345) == 2)//��¼��δ���?
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(260, 310, 380, 345, WHITE, LIGHTRED, 2);//��������
					num = 3;
				}
				continue;
			}
			else if (mouse_press(260, 310, 380, 345) == 1)//��¼����
			{
				MouseS = 0;
				if (login_complete(u->user, u->password))     //��Ϣ��ȷ
				{
					if (input_uinfo(u))  //����Ϣ����uָ��
					{
						*func = 6;
						return;
					}
					else
					{
						printf("something wrong");
						delay(3000);
						exit(1);
					}
				}
				else
				{
					continue;
				}
				//����¼״̬����
			}
		}
		if (MouseX > 100 && MouseX < 169 && MouseY>380 && MouseY < 405)
		{
			if (mouse_press(100, 380, 169, 405) == 2)//���ؿ�δ���?
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(100, 380, 169, 405, BLUE, LIGHTGRAY, 3);//��������
					num = 4;
				}
				continue;
			}
			else if (mouse_press(100, 380, 169, 405) == 1)//���ؿ���
			{
				MouseS = 0;
				*func = 0;
				//����initmenu����
				return;
			}
		}
		if (MouseX > 290 && MouseX < 350 && MouseY>380 && MouseY < 405)
		{
			if (mouse_press(290, 380, 350, 405) == 2)//ע���δ���
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(290, 380, 350, 405, BLUE, LIGHTGRAY, 4);//��������
					num = 5;
				}
				continue;
			}
			else if (mouse_press(290, 380, 350, 405) == 1)//ע�����?
			{
				MouseS = 0;
				*func = 3;
				return;
				//�л���ע�����?
			}
		}
		if (MouseX > 480 && MouseX < 570 && MouseY> 380 && MouseY < 405)
		{
			if (mouse_press(480, 380, 570, 405) == 2)//��������δ���?
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_login(480, 380, 570, 405, BLUE, LIGHTGRAY, 5);
					num = 6;
				}
				continue;
				//��������
			}
			else if (mouse_press(480, 380, 570, 405) == 1)//����������
			{
				MouseS = 0;
				*func = 4;
				//�л������������?
				return;
			}
		}
		if (num != 0)
		{
			MouseS = 0;
			if (state1 == 0)
			{
				recoverbutton_login(1);//�ָ���ť��ɫ
			}
			if (state2 == 0)
			{
				recoverbutton_login(2);
			}
			if (num == 3 || num == 4 || num == 5 || num == 6)
			{
				recoverbutton_login(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}*/

/*********************************************
FUNCTION:judge_login
DESCRIPTION��id\password�Ƿ�ƥ��
INPUT:id,pass
RETURN:��
***********************************************/
int judge_login(char* id, char* pass)
{
	setfillstyle(SOLID_FILL, WHITE);
	bar(475, 200, 490, 225);
	bar(475, 230, 490, 255);
	if (strlen(id) == 0)
	{
		puthz(150, 150, "δ����", 16, 17, RED);
	}
	if (strlen(pass) == 0)
	{
		puthz(150, 150, "δ����", 16, 17, RED);
		return 0;
	}
	if (strcmp(id, "aia") == 0);
	else
	{
		puthz(150,150, "�û�������", 16, 20, RED);
		return 0;
	}
	if (strcmp(pass, "hust") == 0)
	{
		puthz(150,150, "��½�ɹ�", 16, 20, RED);
		delay(1000);
		return 1;
	}
	puthz(150,150, "��Ϣ����", 16, 20, RED);
	return 0;
}
void draw_login1()//����¼����1
{
  setbkcolor(BLACK);
  setfillstyle(7,RED);
  setcolor(RED);
  circle(130,140,120);
  floodfill(150,150,RED);
  setcolor(LIGHTBLUE);
  circle(600,400,300);
  setcolor(WHITE);
  circle(600,400,310);
  setfillstyle(8,BLUE);
  floodfill(600,400,LIGHTBLUE);
  settextstyle(4,0,5);
  outtextxy(60,100,"MARS");
  settextstyle(4,0,7);
  outtextxy(400,300,"EARTH");
  setfillstyle(1,DARKGRAY);
  bar(150,150,500,340);
  setfillstyle(1,WHITE);
  bar(140,140,490,330);
  settextstyle(1,0,3);
  setcolor(RED);
  outtextxy(250, 160, "MARS HOME");
  settextstyle(1, 0, 2);
  setcolor(BLACK);
  outtextxy(220, 190, "SIMULATION SYSTEM");
  setfillstyle(1, DARKGRAY);
  bar(170, 250, 280, 280);
  bar(340, 250, 450, 280);
  setfillstyle(1,WHITE);
  bar(165,275,275,250);
  bar(335,275,445,250);
  setlinestyle(0, 0, 1);
  rectangle(165, 250, 275, 275);
  rectangle(335, 250, 445, 275);
  outtextxy(190, 250, "LOGIN");
  outtextxy(370, 250, "EXIT");
}
void draw_login2()//����¼����2
{
  setbkcolor(BLACK);
  setfillstyle(7,RED);
  setcolor(RED);
  circle(130,140,120);
  floodfill(150,150,RED);
  setcolor(LIGHTBLUE);
  circle(600,400,300);
  setcolor(WHITE);
  circle(600,400,310);
  setfillstyle(8,BLUE);
  floodfill(600,400,LIGHTBLUE);
  settextstyle(4,0,5);
  outtextxy(60,100,"MARS");
  settextstyle(4,0,7);
  outtextxy(400,300,"EARTH");
  setfillstyle(1,DARKGRAY);
  bar(150,150,500,345);
  setfillstyle(1,WHITE);
  bar(140,140,490,335);
  setcolor(BLACK);
  settextstyle(1,0,2);
  outtextxy(150,200,"       ID:");
  outtextxy(150,230,"Password:");
  setfillstyle(1,LIGHTGRAY);
  bar(250,200,470,225);
  bar(250,230,470,255);
  setfillstyle(1, DARKGRAY);
  bar(170, 280, 280, 310);
  bar(340, 280, 450, 310);
  setfillstyle(1, WHITE);
  bar(165, 275, 275, 305);
  bar(335, 275, 445, 305);
  setlinestyle(0, 0, 1);
  rectangle(165, 275, 275, 305);
  rectangle(335, 275, 445, 305);
  outtextxy(190, 275, "LOGIN");
  outtextxy(370, 275, "EXIT");
}
void lightbutton_admin(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{
	case 1:
		break;
	case 2:
		break;
	/*case 3:
		puthz(420 - 110, 360 + 35, "��¼", 24, 28, LIGHTRED);
		break;
	case 4:
		puthz(420 + 60, 360 + 35, "����", 24, 28, LIGHTBLUE);
		break;*/
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
//void recoverbutton_admin(int status)
//{
//	clrmous(MouseX, MouseY);
//	if (status == 1 || status == 2)
//	{
//		setfillstyle(SOLID_FILL, LIGHTGRAY);
//		setlinestyle(SOLID_LINE, 0, 1);
//	}
//	else if (status == 3)
//	{
//		setfillstyle(SOLID_FILL, RED);
//	}
//	else if (status == 4)
//	{
//		setfillstyle(SOLID_FILL, BLUE);
//	}
//	switch (status)
//	{
//	case 1:
//		bar(230, 120 + 30, 230 + 380, 120 + 60);
//		puthz(230 + 15, 120 + 38, "�������˺�", 16, 20, WHITE);
//		break;
//	case 2:
//		bar(230, 240 + 30, 230 + 380, 240 + 60);
//		puthz(230 + 15, 240 + 38, "����������", 16, 20, WHITE);
//		break;
//	case 3:
//		bar(200 + 220 - 120, 360 + 30, 200 + 220 - 50, 360 + 30 + 35);
//		puthz(420 - 110, 360 + 35, "��¼", 24, 28, WHITE);
//		break;
//	case 4:
//		bar(200 + 220 + 50, 360 + 30, 200 + 220 + 120, 360 + 30 + 35);
//		puthz(420 + 60, 360 + 35, "����", 24, 28, WHITE);
//		break;
//	}
//}
/*********************************************
FUNCTION:inputid
DESCRIPTION�������˺š�����֤�ŵ��������ص���Ϣ
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputid(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ����������?
{
	int k = 0;
	int i = 0;
	char t;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);//��
	}
	while (1)
	{

		t = bioskey(0);
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24); //�ڸǹ��?
					outtextxy(x1 + 8 + i * 18, y1 - 1, id + i);//���t�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��?
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��?
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��?
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��?
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//�˸��?
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��?
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 24);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��?
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 24);//�ڸǹ��?
				break;
			}
		}
	}
}
/*********************************************
FUNCTION:inputpassword
DESCRIPTION���������ܣ������������Ҫ���ص����?
INPUT:id,x1,y1,charnum,color
RETURN:��
***********************************************/
void inputpassword(char* id, int x1, int y1, int charnum, int color)
{
	int k = 0;
	int i = 0;
	char t;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 20);
	while (bioskey(1))
	{
		k = bioskey(0);
	}
	while (1)
	{
		t = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//033��ʾEsc
			{
				if (t != '\b')
				{
					*(id + i) = t;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��?
					outtextxy(x1 + 8 + i * 18, y1 + 4, "*");//���?*�ַ�
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);
				}
				else if (t == '\b' && i > 0)//�˸��?
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��?
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��?
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��?
				break;
			}
		}
		else if (i >= charnum)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)//�˸��?
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��?
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//���ƹ��?
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//�ڸǹ��?
				break;
			}
		}
	}
}