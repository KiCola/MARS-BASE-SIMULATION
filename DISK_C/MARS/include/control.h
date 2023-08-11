#include <graphics.h>
#include <bios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mouse.h"

#define win_w 320
#define win_h 400
#define subwin_w 300
#define subwin_h 240
#define rate 0.5

typedef struct environment
{
    int TEMPERATURE;
    int HUMIDITY;
    int OXYGEN;
    int NITROGEN;
    char RADIATION[10];
}envi;

typedef struct item
{
	short int type_n;
	short int type_r;
	int key;
}ITEM;



void draw_control();
void draw_jumpmenu(int);
void draw_window(short int);
void item_ctr(ITEM *);
void withdraw(short int);
//void menu(ITEM *);
