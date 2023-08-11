#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include"mouse.h"
#include"draw.h"
//#include"menu.h"
#include<stdlib.h>
extern MouseX, MouseY, MouseS, press;
int main(void)
{
	int gd = VGA, gm = VGAHI;
	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	func_login1();
	return 0;
}