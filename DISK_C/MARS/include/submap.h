#ifndef _SUBMAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include "mouse.h"

void submap_draw();
void mars_rover();
void submap();
void paint_fill(short int color, short int pattern);
void paint_line(short int color,short style, short int width);

#endif