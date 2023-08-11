#ifndef _SUBCITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include "mouse.h"

typedef struct build
{
	short type;
	int  nx;
	int  ny;
	struct build *next;
}Build;

void draw_sci(Build*);
void draw_button1(int a, int b, int c, int d, char s[]);
void subcity_ctr();
void subcity();
Build*  new_node(Build* head, Build* temp);
void free_list(Build* head);
void Build_select(Build* );

#endif