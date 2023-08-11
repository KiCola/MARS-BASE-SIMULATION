#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>

#define N 7
#define s_width 160
#define s_height 120
#define m_width 560
#define m_height 420
 

void paint_fill(short int color, short int pattern);
void paint_line(short int color,short style, short int width);
void submap_draw();
void mars_rover();
//void submap();



void submap(short int (*pos)[3])
{
    int gd = VGA, gm = VGAHI;
    //initgraph(&gd,&gm,"C:\\BORLANDC\\BGI");
	cleardevice();

	submap_draw();
    mars_rover();
}

void submap_draw()
{

    int pixel_rad=10;
    register int i,j;
	int x,y;
	short int pos[N][3]={{0,0,0},{-30,-40,1},{30,40,1},{30,-40,3},{-30,40,2},{-50,0,3},{50,0,2}};


	setbkcolor(BLACK);

	//draw the main_map
	setfillstyle(1, DARKGRAY);
	bar(40, 30, 40 + m_width, 30 + m_height);// [40,30]-[600,450]
	setcolor(RED);
	setlinestyle( 0, 0, 3);
	//circle(320, 240, 220);

	//draw submap_zoom
	setlinestyle(0, 0, 1);
	setcolor(WHITE);
	bar(40, 30, 40 + s_width, 30 + s_height);
	rectangle(40, 30, 40 + s_width, 30 + s_height);
	setcolor(LIGHTRED);
	circle(120, 30 + 60, 55);
	setcolor(RED);
	circle(120, 30 + 60, 50);
	setfillstyle(7, WHITE);
	fillellipse(120, 30 + 60, 50, 50);


	 for(i = 0; i< 640 ; i += 20)
        for(j = 0; j < 480; j += 20)
        {
            setcolor(WHITE);
            setlinestyle(DOTTED_LINE, 0, 1);
            rectangle(i, j, i + 20, j + 20 );
        }


	setcolor(WHITE);
	for(i = 0; i < N; i++)
	{
		paint_line(pos[i][2], 0, 1);
		circle(120 + pos[i][0] / 3 , 30 + 60 + pos[i][1] / 3, pixel_rad / 1.5);
	}

	for(i = 0; i < N; i++)
	{
		//paint_line(pos[0][0], 2, 3);
			setlinestyle(0, 0, 1);
			setcolor(WHITE);
			for (x = 320 + pos[i][0] * 3 - pixel_rad * 3; x <= 320 + pos[i][0] * 3 + pixel_rad * 3; x += 3) 
			{
				for (y =  240 + pos[i][1] * 3 - pixel_rad * 3; y <=  240 + pos[i][1] * 3 + pixel_rad * 3; y += 3) 
				{
					
					moveto(x, y);
					lineto(x+1, y);
					lineto(x+1, y+1);
					lineto(x, y+1);
					lineto(x, y);
					delay(10);
				}
		    }
			paint_fill(pos[i][2],2);
			fillellipse(320 + pos[i][0] * 3 , 240 + pos[i][1] * 3, pixel_rad * 3, pixel_rad * 3);
	}
}

void mars_rover()
{
	int key;
	int x = m_width / 2 + 40;
	int y = m_height / 2 + 30;
	void *buffer_in;
	//void *buffer_out;
	unsigned s;
	short subBuild;

	setfillstyle(SOLID_FILL, WHITE);
	bar(x, y, x + 20, y + 20);


	s = imagesize(x, y, x + 20, y + 20);
	buffer_in = malloc(s);
	getimage(x, y, x + 20, y + 20, buffer_in);
	while (1)
	{

		if(bioskey(1))
		{
			key = bioskey(0);
			if(key == 0x011b) //ESC
			{
				free(buffer_in);
				exit(1);
			}

			else if(key == 0x4b00) //left button
			{
				if((x - 20)<0)continue;
				putimage(x, y, buffer_in, 0);
				x -= 20;
				getimage(x, y, x + 20, y + 20, buffer_in);
				setfillstyle(1,WHITE);
				bar(x, y, x + 20, y + 20);
			}

			else if(key == 0x4d00) //right button
			{
				if((x + 20)>600)continue;
				putimage(x, y, buffer_in, 0);
				x += 20;
				getimage(x, y, x + 20, y + 20, buffer_in);
				setfillstyle(1,WHITE);
				bar(x, y, x + 20, y + 20);
			}

		   else if(key == 0x4800) //up button
			{
				if((y - 20)<0)continue;
				putimage(x, y, buffer_in, 0);
				y -= 20;
				getimage(x, y, x + 20, y + 20, buffer_in);
				setfillstyle(1,WHITE);
				bar(x, y, x + 20, y + 20);
			}

			else if(key == 0x5000)  //down button
			{
				if((y + 20)>450)continue;
				putimage(x, y, buffer_in, 0);
				y += 20;
				getimage(x, y, x + 20, y + 20, buffer_in);
				setfillstyle(1,WHITE);
				bar(x, y, x + 20, y + 20);
			}

			if(key == 0x1c0d)
			{
				exit(1);
			}
		   /* else if(key == 0x4800)  // W for up
			{
				putimage(x, y, buffer_in, 0);
				y -= 20;
				getimage(x, y, x + 20, y + 20, buffer_in);
				setfillstyle(1,WHITE);
				bar(x, y, x + 20, y + 20);
			}*/

		}

	   //	subBuild = judge_area(&x, &y);

	}
	free(buffer_in);

}

void paint_fill(short int color, short pattern)
{
   switch(color)
   {
		case 0:
		{
			setfillstyle(pattern,WHITE);
			break;
		}

		case 1:
		{
			setfillstyle(pattern, RED);
			break;
		}

		case 2:
		{
			setfillstyle(pattern, BLUE);
			break;
		}

		case 3:
		{
			setfillstyle(pattern, YELLOW);
			break;
		}

   }
}

void paint_line(short int color, short style,short width)
{
	switch (color)
	{
		case 0:
		{	
			setlinestyle(style, 0, width);
			setcolor(WHITE);
			break;
		}

		case 1:
		{	
			setlinestyle(style, 0, width);
			setcolor(RED);
			break;
		}

		case 2:
		{	
			setlinestyle(style, 0, width);
			setcolor(BLUE);
			break;
		}

		case 3:
		{
			setlinestyle(style, 0, width);
			setcolor(YELLOW);
			break;
		}
	}
}

