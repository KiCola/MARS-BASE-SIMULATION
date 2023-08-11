#include "subcity.h"

#define N 7
#define rate 3

Build* new_node(Build* head, Build* temp)
{
	Build* new_node = (Build*) malloc(sizeof(Build));
	new_node->type = temp->type;
	new_node->nx = temp->nx;
	new_node->ny = temp->ny;
	new_node->next = head;
	return new_node;
}

void list_init(Build *node)
{
	int i;
	short int pos[N][3]={{0,0,0},{-30,-40,1},{30,40,1},{30,-40,3},{-30,40,2},{-50,0,3},{50,0,2}};
	for(i = 0; i < N; i++)
	{
		node[i].type = pos[i][2];
		node[i].nx   = pos[i][0];
		node[i].ny   = pos[i][1];
	}
	for(i = 0; i < 6; i++)
	{
		node[i].next = &node[i+1];
	}
	node[6].next = NULL;

}

void free_list(Build *head) 
{
	Build *current_node = head;
	Build *next_node;
	while(current_node != NULL) {
		next_node = current_node->next;
		free(current_node);
        current_node = next_node;
    }
    printf("successfully freed");
}


void subcity()
{
	Build* node = (Build*) calloc(N, sizeof(Build));
	int gd = VGA, gm = VGAHI;
	//initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");
	cleardevice();
	list_init(node);
	draw_menu();
	draw_sci(node);
	//Build_select(node);
	subcity_ctr();
	
}

void draw_sci(Build* node)
{
	//draw_menu();
	int pixel_rad = 5;
	register int i,j;
	short int step_x;
	short int step_y;
	//int key;
	//short int pos[N][2] = { {0,0}, {-30,-40},{10,55},{13,-26},{-50,50} };
	short int pos[N][3]={{0,0,0},{-30,-40,1},{30,40,1},{30,-40,3},{-30,40,2},{-50,0,3},{50,0,2}};
/*	Build* head = NULL;

	// create linked list
	Build* node1 = (Build*) malloc(sizeof(Build));
	Build* node2 = (Build*) malloc(sizeof(Build));
	Build* node3 = (Build*) malloc(sizeof(Build));
	Build* node4 = (Build*) malloc(sizeof(Build));
	Build* node5 = (Build*) malloc(sizeof(Build));
	Build* node6 = (Build*) malloc(sizeof(Build));
	Build* node7 = (Build*) malloc(sizeof(Build));
	Build* read_head;*/

	//Build* node = (Build*) calloc(N, sizeof(Build));

	/*node[i]->type = 0;
	node[i]->nx = 0;
	node1->ny = 0;
	node1->next = node2;

	node2->type = 1;
	node2->nx = -30;
	node2->ny = -40;
	node2->next = node3;

	node3->type = 1;
	node3->nx = 30;
	node3->ny = 40;
	node3->next = node4;

	node4->type = 3;
	node4->nx = 30;
	node4->ny = -40;
	node4->next = node5;

	node5->type = 2;
	node5->nx = -30;
	node5->ny = 40;
	node5->next = node6;

	node6->type = 3;
	node6->nx = -50;
	node6->ny = 0;
	node6->next = node7;

	node7->type = 0;
	node7->nx = 50;
	node7->ny = 0;
	node7->next = NULL;

	head = node1;*/
	/*draw the submap*/

	for(i = 0; i< 640 ; i += 20)
        for(j = 0; j < 480; j += 20)
        {
            setcolor(WHITE);
            setlinestyle(DOTTED_LINE, 0, 1);
            rectangle(i, j, i + 20, j + 20 );
        }

	setbkcolor(BLACK);
	setcolor(RED);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

	circle(180, 245, 160);
	circle(180, 245, 150);
	//setfillpatter(10,LIGHTBLUE);
	setfillstyle(7, LIGHTGRAY);
	fillellipse(180, 245, 150, 150);

	/*draw the func_menu1*/
	setfillstyle(1, LIGHTBLUE);
	bar(360 + 5, 100 + 3, 600 + 5, 240 + 3);
	setfillstyle(1, LIGHTGRAY);
	bar(360, 100, 600, 240);
	setcolor(LIGHTBLUE);
	rectangle(360 + 5, 100 + 3, 600 - 5, 240 - 3);

    setfillstyle(1,LIGHTBLUE);
	bar(360 + 4, 120, 600 - 4, 140 - 2);
	bar(360 + 4, 150, 600 - 4, 170 - 2);
	bar(360 + 4, 180, 600 - 4, 190 - 2);

	setcolor(WHITE);
	settextstyle(3, 0, 1);
	outtextxy(360 + 10, 120, "Add Buildings");
	outtextxy(360 + 10, 150, "Inspect process");
	outtextxy(360 + 10, 180, "destroy Buildings(!)");


	/*draw the func_menu2*/
	setfillstyle(1, LIGHTCYAN);
	bar(360 + 5, 260 + 3, 600 + 5, 400 + 3);
	setfillstyle(1, LIGHTGRAY);
	bar(360, 260, 600, 400);
	setcolor(LIGHTCYAN);
	rectangle(360 + 5, 260 + 3, 600 - 5, 400 - 3);

	/*draw buttons*/
	draw_button1(180 - 40, 415, 180 + 40, 445, "MAPS");

	/*draw subcity map*/
	setcolor(WHITE);
	for (i = 0; i < N; i++)
	{
		//paint_line(pos[i][2], 0, 1);
		paint_line(node[i].type);
		circle(180 + node[i].nx * rate, 245 + node[i].ny * rate, pixel_rad * rate);
	}
}


void draw_button1(int a, int b, int c, int d, char s[])
{
	setfillstyle(1, DARKGRAY);
	bar(a, b, c, d);
	setfillstyle(1, WHITE);
	bar(a - 5, b - 5, c - 5, d - 5);
	setcolor(BLACK);
	setlinestyle(0, 0, 1);
	rectangle(a - 5, b - 5, c - 5, d - 5);
	settextstyle(1, 0, 3);
	//outtextxy(a+(c-a)/10, b+(d-b)/10, s);
	outtextxy(a, b - 3, s);
}

void subcity_ctr()
{
	int key;
	mouseinit();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		//180-40,415,180+40,445
		if (MouseX > 0 && MouseX < 640 && MouseY > 0 && MouseY < 480)
		{
			menu_ctr();
			if (mouse_press(180 - 40, 415, 180 + 40, 445)== 1)
			{
				cleardevice();
				submap();
			}
		}
		
		//keyboard
		key = bioskey(1);
		if (key == 0x011b) //ESC
		{
			exit(1);
		}
		
	}
}


/*void Build_select(Build* node)
{

}*/