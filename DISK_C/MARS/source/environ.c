//#include <stdio.h>
//#include <graphics.h>
//#include <string.h>
//#include <stdlib.h>
#include "environ.h"

typedef struct environment
{
    int TEMPERATURE;
    int HUMIDITY;
    int OXYGEN;
    int NITROGEN;
	char RADIATION[10];
}envi;

void environ_0()
{
	FILE *p_e, fp;
	int pos = 0;
	int value;
	envi fe;
	char buffer[20];
	int i,j;

	//draw backwindow
	setfillstyle(1,DARKGRAY);
	setcolor(WHITE);
	bar(320 - 240, 240 - 180, 320 + 240, 240 + 180);
	rectangle(80 + 8, 60 + 6, 560 - 8, 420 - 6);
	setcolor(WHITE);
	rectangle(560 - 28, 60 + 6, 560 - 8, 60 + 26);
	rectangle(560 - 48, 60 + 6, 560 - 28, 60 + 26);

	setlinestyle(0, 0, WHITE);
	line(560 - 28, 60 + 6, 560 - 8 , 60 + 26);
	line(560 - 8 , 60 + 6, 560 - 28, 60 + 26);
	line(560 - 48 + 3, 60 + 16, 560 - 28 - 3, 60 + 16);
	line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 - 6);
	line(560 - 28 - 3, 60 + 16, 560 - 36 - 3, 60 + 16 + 6);

	//draw mars
	setfillstyle(0,0);
	bar(90, 70, 90 + 180, 70 + 180);//[90,70]-[270,250]
	setfillstyle(1,RED);
	fillellipse(90 + 90, 70 + 90, 80, 80);

	//draw lines
	for(i = 0; i< 640 ; i += 20)
		for(j = 0; j < 480; j += 20)
		{
			setcolor(WHITE);
			setlinestyle(DOTTED_LINE, 0, 1);
			rectangle(i, j, i + 20, j + 20 );
		}
	/*FILE *fp;
	fp = fopen("test.txt", "w");
	if (fp == NULL) {
	printf("Cannot open file");
	return 1;
	}
	fprintf(fp, "%d %d %d %d %s", 25, 50, 78, 21, "NORMAL");
	fclose(fp);*/


	//read envi_DataFILE *p_e = fopen("environ_Data.txt", "r");
	p_e = fopen ("C:\\mars\\source\\eData.txt","rt+");
	if (p_e == NULL) {
		printf("Cannot open file");
	   //	return;
	}
	//settextstyle(0, 0, 3);
	pos = 0;
	fseek(p_e, (pos) * sizeof(int), SEEK_SET);
   // fe.TEMPERATURE = fscanf(p_e, "%d", &(pos * sizeof(int)));
	fscanf(p_e, "%d", &value);
	fe.TEMPERATURE = value;
   // fe.HUMIDITY    = fscanf(p_e, "%d", &((pos + 1) * sizeof(int)));
	fseek(p_e, (pos + 1) * sizeof(int), SEEK_SET);
	fscanf(p_e, "%d", &value);
	fe.HUMIDITY = value;
	//fe.OXYGEN      = fscanf(p_e, "%d", &((pos + 2) * sizeof(int)));
	fseek(p_e, (pos + 3) * sizeof(int), SEEK_SET);
	fscanf(p_e, "%d", &value);
	fe.OXYGEN = value;
	//fe.NITROGEN    = fscanf(p_e, "%d", &((pos + 3) * sizeof(int)));
	fseek(p_e, (pos + 4) * sizeof(int), SEEK_SET);
	fscanf(p_e, "%d", &value);
	fe.NITROGEN = value;
	//strcpy(fe.RADIATION,"Normal");
	fseek(p_e, (pos + 4) * sizeof(int), SEEK_SET);
	fscanf(p_e, "%s", buffer);
	strcpy(fe.RADIATION, buffer);


	//show mars panel
	setfillstyle(1,BLUE);
	bar(90 - 4, 270 - 3, 90 - 4, 290 - 3 );
	setcolor(WHITE);
	settextstyle(0,0,1);
	//outtextxy(90, 270, "TEMPERATURE(CEL):");
	sprintf( buffer, "TEMPERATURE(CEL):%d", fe.TEMPERATURE);
	outtextxy(280, 80 + 3, buffer);
	sprintf( buffer, "HUMIDITY(RH): %d", fe.HUMIDITY);
	outtextxy(280, 100 + 3, buffer);
	outtextxy(280, 120 + 3, "GAS ENVIRONMENT:");
	sprintf( buffer, "OXYGEON:%d",  fe.OXYGEN);
	outtextxy(280, 140 + 3, buffer);
	sprintf( buffer, "NITROGEN:%d", fe.NITROGEN);
	outtextxy(280, 160 + 3, buffer);
	sprintf( buffer, "RADIATION:%s", fe.RADIATION);
	outtextxy(280, 180 + 3, buffer);

	fclose(p_e);
}