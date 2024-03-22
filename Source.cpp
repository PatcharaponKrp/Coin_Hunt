#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<thread>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define screen_x 101
#define screen_y 26
HANDLE wHnd;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
CHAR_INFO consoleBuffer[screen_x * screen_y];
int right, left, up, down;
int sumdi = right + left + up + down;
int direction; //0 = UP 1 = DOWN 2 = LT 3= RT 
int Lastex1, Lastey1, Lastex2, Lastey2, Lastex3,Lastey3, randix, randiy, randitype,coincount, c, ix, iy, armorget, freezeen,nub;
int nextstage = 0;
int hp = 3;
int timer = 0;
int timerA = 0;
int timerF = 0;
int timerS = 0;
int m = 2, s = 0;
int countdown = 1;
int score = 0;
int check;
char ch = '1';
int speed;
char name[5000];
char oldbotton;
int speedx[2] = { 15,10 };
int speedy[2] = { 25,15 };
int cx1[30];
int cy1[30];
int cx2[40];
int cy2[40];
int cx3[50];
int cy3[50];
int Fx[3] = {6,44,0};
int Fy[3] = { 5,19,0 };
int Ax[3] = { 6,44,0 };
int Ay[3] = { 5,19,0 };
int Sx[3] = { 6,44,0 };
int Sy[3] = { 5,19,0 };
int Tx[3] = { 6,44,0 };
int Ty[3] = { 5,19,0 };
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void startscreen1(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("  ______   ______    __  .__   __.     __    __   __    __  .__   __. .___________.\n");
}

void startscreen2(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf(" /      | /  __  \\  |  | |  \\ |  |    |  |  |  | |  |  |  | |  \\ |  | |           |\n");
}

void startscreen3(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("|  ,----\'|  |  |  | |  | |   \\|  |    |  |__|  | |  |  |  | |   \\|  | `---|  |----`\n");
}

void startscreen4(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("|  |     |  |  |  | |  | |  . `  |    |   __   | |  |  |  | |  . `  |     |  |     \n");
}

void startscreen5(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("|  `----.|  `--\'  | |  | |  |\\   |    |  |  |  | |  `--\'  | |  |\\   |     |  |    \n");
}

void startscreen6(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf(" \\______| \\______/  |__| |__| \\__|    |__|  |__|  \\______/  |__| \\__|     |__|     \n");
}

void overscreen1(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf(" _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      \n");
}

void overscreen2(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf(" /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     \n");
}

void overscreen3(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    \n");
}

void overscreen4(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     \n");
}

void overscreen5(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--\'  |    \\    /    |  |____ |  |\\  \\----.\n");
}

void overscreen6(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf(" \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|");
}

void winscreen1(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("____    ____  ______    __    __     ____    __    ____  __  .__   __.\n");
}

void winscreen2(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("\\   \\  /   / /  __  \\  |  |  |  |    \\   \\  /  \\  /   / |  | |  \\ |  | \n");
}

void winscreen3(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf(" \\   \\/   / |  |  |  | |  |  |  |     \\   \\/    \\/   /  |  | |   \\|  | \n");
}

void winscreen4(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("  \\_    _/  |  |  |  | |  |  |  |      \\            /   |  | |  . `  | \n");
}

void winscreen5(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("    |  |    |  `--\'  | |  `--\'  |       \\    /\\    /    |  | |  |\\   | \n");
}

void winscreen6(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("    |__|     \\______/   \\______/         \\__/  \\__/     |__| |__| \\__|");
}


int clearscreen(int a, int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	return a, b;
}

void blink(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("                          ");
}
void pressspace(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("press spacebar to continue");
}

void yourscore(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("Your score is ");
}

void startscreen(char ch) {
	startscreen1(10, 8);
	Sleep(100);
	startscreen2(10, 9);
	Sleep(100);
	startscreen3(10, 10);
	Sleep(100);
	startscreen4(10, 11);
	Sleep(100);
	startscreen5(10, 12);
	Sleep(100);
	startscreen6(10, 13);
	Sleep(100);
	pressspace(37, 17);
	Sleep(500);
	blink(37, 17);
	Sleep(500);
}




char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}



void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}

void draw_characterLeft(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf(">");
}
void draw_characterRight(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf("<");
}

void draw_characterUp(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf("v");
}

void draw_characterDown(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf("^");
}

void clear_character(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" ");
}

void freeze(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("F");
}

void armor(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("A");
}

void speedraise(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(1, 0);
	printf("S");
}

void timeraise(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2, 0);
	printf("T");
}

void drawE1(int bx, int by)
{
	COORD c = { bx, by };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf("E");
}

void drawE2(int bx, int by)
{
	COORD c = { bx, by };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("E");

}

void drawE3(int bx, int by)
{
	COORD c = { bx, by };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf("E");

}

void clearE(int bx, int by)
{
	COORD c = { bx,by };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" ");
}

int selectTop5(int score,char name[5000])
{
	FILE* fptr;
	struct player
	{
		char name[20];
		int score;
	} p[6];

	int i = 0, j = 0, k = 0;
	struct player temp;

	fptr = fopen("playerscore.txt", "rb");
	if (fptr == (FILE*)NULL)
		printf("Can't open file\n");
	else

		while (fread(&p, sizeof(struct player), 5, fptr) != 0)
		{
			i++;
		}
	fclose(fptr);
	setcolor(6, 0);
	
	p[5].score = score;
	strcpy(p[5].name,name);




	for (j = 0; j < 5; j++)
	{
		for (k = 0; k < (5 - j); k++)
		{
			if (p[k].score < p[k + 1].score)
			{
				temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	}



	fptr = fopen("playerscore.txt", "wb");


	for (int i = 0; i < 5; i++)
	{
		fwrite(&p, sizeof(struct player), 5, fptr);
	}
	fclose(fptr);



	return 0;
}



void showtop5score()
{


	FILE* fptr;

	struct player
	{
		char name[20];
		int score;
	} p[5];


	int i = 0;
	setcolor(6, 0);
	printf("\n\t\t\t  --------<HALL OF FAME>--------\n");


	fptr = fopen("playerscore.txt", "rb");
	if (fptr == (FILE*)NULL)
		printf("Cannot open file\n");
	else

		while (fread(&p, sizeof(struct player), 5, fptr) != 0)
		{

			printf("\t\t\tPlayer %d : %s\n", i + 1, p[i].name);
			printf("\t\t\tScore : %d\n", p[i].score);
			printf(" \t\t\t  ---------------------------\n");
			i++;
		}
	fclose(fptr);
}

void world1() {
	FILE* fmap1;
	fmap1 = fopen("map1.txt", "r");
	char map1[2550];
	for (int i = 0; i < 25; i++)
	{
		fgets(map1, 2550, fmap1);
		printf("%s", map1);

	}

	fclose(fmap1);
}

void world2() {
	FILE* fmap2;
	fmap2 = fopen("map2.txt", "r");
	char map2[2550];
	for (int i = 0; i < 25; i++)
	{
		fgets(map2, 2550, fmap2);
		printf("%s", map2);
	}

	fclose(fmap2);
}

void world3() {
	FILE* fmap3;
	fmap3 = fopen("map3.txt", "r");
	char map3[2550];
	for (int i = 0; i < 25; i++)
	{
		fgets(map3, 2550, fmap3);
		printf("%s", map3);
	}

	fclose(fmap3);
}
void Typename(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(3, 0);
	printf("Enter your name : ");
}


void Showscore(int x, int y, int score)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(5, 0);
	printf("%d", score);
}


void ShowHp(int x, int y, int hp)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf(" %d", hp);
}

void Showtime(int x, int y, int m, int s)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(4, 0);
	printf(" %2d : %2d", m, s);
}
void overscreen(char ch) {
	overscreen1(5, 8);
	Sleep(100);
	overscreen2(5, 9);
	Sleep(100);
	overscreen3(5, 10);
	Sleep(100);
	overscreen4(5, 11);
	Sleep(100);
	overscreen5(5, 12);
	Sleep(100);
	overscreen6(5, 13);
	Sleep(100);
	yourscore(37, 17);
	Showscore(52, 17, score);
	Sleep(500);
	blink(37, 17);
	Sleep(500);
}

void winscreen(char ch) {
	winscreen1(11, 8);
	Sleep(100);
	winscreen2(11, 9);
	Sleep(100);
	winscreen3(11, 10);
	Sleep(100);
	winscreen4(11, 11);
	Sleep(100);
	winscreen5(11, 12);
	Sleep(100);
	winscreen6(11, 13);
	Sleep(100);
	yourscore(37, 17);
	Showscore(52, 17, score);
	Sleep(500);
	blink(37, 17);
	Sleep(500);
}
void spawncoin(int cx, int cy)
{
	COORD c = { cx,cy };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(6, 0);
	printf("o");
}

void counttime()
{
	if (countdown == 1)
	{
		if (s != 0 && timer % 10 == 0)
		{

			s--;
			Showtime(70, 7, m, s);
		}
		if (s == 0 && m != 0)
		{
			s = 59;
			m--;
			Showtime(70, 7, m, s);
		}
		if (s == 0 && m == 0)
		{
			nextstage = 0;
			ch = 'x';
		}
		if (hp == 0)
		{
			nextstage = 0;
			ch = 'x';
		}
	}
}

void E1up(int ex1,int ey1) {
	drawE1(ex1, --ey1);
	Sleep(20);
	clearE(ex1, ey1+1);

}

void E1down(int ex1, int ey1) {
	drawE1(ex1, ++ey1);
	Sleep(20);
	clearE(ex1, ey1-1);
	Sleep(50);

}

void E1right(int ex1, int ey1) {
	drawE1(++ex1, ey1);
	Sleep(20);
	clearE(ex1-1, ey1);
	Sleep(50);

}

void E1left(int ex1, int ey1) {
	drawE1(--ex1, ey1);
	Sleep(20);
	clearE(ex1+1, ey1);
	Sleep(50);
}

void E2up(int ex2, int ey2) {
	drawE2(ex2, --ey2);
	Sleep(20);
	clearE(ex2, ey2 + 1);

}

void E2down(int ex2, int ey2) {
	drawE2(ex2, ++ey2);
	Sleep(20);
	clearE(ex2, ey2 - 1);
	Sleep(50);

}

void E2right(int ex2, int ey2) {
	drawE2(++ex2, ey2);
	Sleep(20);
	clearE(ex2 - 1, ey2);
	Sleep(50);

}

void E2left(int ex2, int ey2) {
	drawE2(--ex2, ey2);
	Sleep(20);
	clearE(ex2 + 1, ey2);
	Sleep(50);
}

void E3up(int ex3, int ey3) {
	drawE3(ex3, --ey3);
	Sleep(20);
	clearE(ex3, ey3 + 1);

}

void E3down(int ex3, int ey3) {
	drawE3(ex3, ++ey3);
	Sleep(20);
	clearE(ex3, ey3 - 1);
	Sleep(50);

}

void E3right(int ex3, int ey3) {
	drawE3(++ex3, ey3);
	Sleep(20);
	clearE(ex3 - 1, ey3);
	Sleep(50);

}

void E3left(int ex3, int ey3) {
	drawE3(--ex3, ey3);
	Sleep(20);
	clearE(ex3 + 1, ey3);
	Sleep(50);
}



void randitem()
{
	
	if(randitype==0 )randitype = (rand() % 4) + 1;
	if (randitype == 1)
	{
	 freeze(Fx[0],Fy[0]);
	}
	else if (randitype == 2)
	{
		armor(Ax[0],Ay[1]);
	}
	else if (randitype == 3)
	{
		speedraise(Sx[1],Sy[0]);
	}
	else if (randitype == 4)
	{
		timeraise(Tx[1],Ty[1]);
	}
}

void enemydir1()
{
	int enemy1;
	if (right == 0 && left == 0 && up == 0 && down == 0)
	{
		enemy1 = (rand() % 3) + 1;

		if (enemy1 == 1)direction = 2;
		else if (enemy1 == 2)direction = 1;
		else direction = 3;
	}
	else {
		enemy1 = (rand() % 4) + 1;

		if (enemy1 == 1)direction = 2;
		else if (enemy1 == 2)direction = 3;
		if (enemy1 == 3)direction = 0;
		else if (enemy1 == 4)direction = 1;
	}
}

void enemydir2()
{
	int enemy2;
	if (right == 0 && left == 0 && up == 0 && down == 0)
	{
		enemy2 = (rand() % 3) + 1;

		if (enemy2 == 1)direction = 2;
		else if (enemy2 == 2)direction = 1;
		else direction = 3;
	}
	else {
		enemy2 = (rand() % 4) + 1;

		if (enemy2 == 1)direction = 2;
		else if (enemy2 == 2)direction = 3;
		if (enemy2 == 3)direction = 0;
		else if (enemy2 == 4)direction = 1;
	}
}

void enemydir3()
{
	int enemy3;
	if (right == 0 && left == 0 && up == 0 && down == 0)
	{
		enemy3 = (rand() % 3) + 1;

		if (enemy3 == 1)direction = 2;
		else if (enemy3 == 2)direction = 1;
		else direction = 3;
	}
	else {
		enemy3 = (rand() % 4) + 1;

		if (enemy3 == 1)direction = 2;
		else if (enemy3 == 2)direction = 3;
		if (enemy3 == 3)direction = 0;
		else if (enemy3 == 4)direction = 1;
	}
}
void enemydirfinal1(int sumdi)
{
	int ex1, ey1;
	srand((unsigned)time(NULL));
	switch (sumdi)
	{
	case 1: {
		direction = 1;
		break;
	}
	case 2: {
		direction = 0;
		break;
	}
	case 3: {
		ey1 = rand() % 2;
		if (ey1 == 0)direction = 0;
		else direction = 1;
		break;
	}
	case 4: {
		direction = 2;
		break;
	}
	case 5: {
		ey1 = rand() % 2;
		if (ey1 == 0)direction = 2;
		else direction = 1;
		break;
	}
	case 6: {
		ey1 = rand() % 2;
		if (ey1 == 0) direction = 2;
		else direction = 0;
		break;
	}
	case 7: {
		ey1 = rand() % 3;
		if (ey1 == 0) direction = 2;
		else if (ey1 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 8: {
		direction = 3;
		break;
	}
	case 9: {
		ey1 = rand() % 2;
		if (ey1 == 0) direction = 3;
		else direction = 1;
		break;
	}
	case 10: {
		ey1 = rand() % 2;
		if (ey1 == 0) direction = 3;
		else direction = 0;
		break;
	}
	case 11: {
		ey1 = rand() % 3;
		if (ey1 == 0) direction = 3;
		else if (ey1 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 12: {
		ey1 = rand() % 2;
		if (ey1 == 0) direction = 2;
		else direction = 3;
		break;
	}
	case 13: {
		ey1 = rand() % 3;
		if (ey1 == 0) direction = 2;
		else if (ey1 == 1) direction = 1;
		else direction = 3;
		break;
	}
	case 14: {
		ey1 = rand() % 3;
		if (ey1 == 0)direction = 2;
		else if (ey1 == 0) direction = 3;
		else direction = 0;
		break;
	}
	default:;
	}
}

void enemydirfinal2(int sumdi)
{
	int ex2, ey2;
	srand((unsigned)time(NULL));
	switch (sumdi)
	{
	case 1: {
		direction = 1;
		break;
	}
	case 2: {
		direction = 0;
		break;
	}
	case 3: {
		ey2 = rand() % 2;
		if (ey2 == 0)direction = 0;
		else direction = 1;
		break;
	}
	case 4: {
		direction = 2;
		break;
	}
	case 5: {
		ey2 = rand() % 2;
		if (ey2 == 0)direction = 2;
		else direction = 1;
		break;
	}
	case 6: {
		ey2 = rand() % 2;
		if (ey2 == 0) direction = 2;
		else direction = 0;
		break;
	}
	case 7: {
		ey2 = rand() % 3;
		if (ey2 == 0) direction = 2;
		else if (ey2 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 8: {
		direction = 3;
		break;
	}
	case 9: {
		ey2 = rand() % 2;
		if (ey2 == 0) direction = 3;
		else direction = 1;
		break;
	}
	case 10: {
		ey2 = rand() % 2;
		if (ey2 == 0) direction = 3;
		else direction = 0;
		break;
	}
	case 11: {
		ey2 = rand() % 3;
		if (ey2 == 0) direction = 3;
		else if (ey2 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 12: {
		ey2 = rand() % 2;
		if (ey2 == 0) direction = 2;
		else direction = 3;
		break;
	}
	case 13: {
		ey2 = rand() % 3;
		if (ey2 == 0) direction = 2;
		else if (ey2 == 1) direction = 1;
		else direction = 3;
		break;
	}
	case 14: {
		ey2 = rand() % 3;
		if (ey2 == 0)direction = 2;
		else if (ey2 == 0) direction = 3;
		else direction = 0;
		break;
	}
	default:;
	}
}

void enemydirfinal3(int sumdi)
{
	int ex3, ey3;
	srand((unsigned)time(NULL));
	switch (sumdi)
	{
	case 1: {
		direction = 1;
		break;
	}
	case 2: {
		direction = 0;
		break;
	}
	case 3: {
		ey3 = rand() % 2;
		if (ey3 == 0)direction = 0;
		else direction = 1;
		break;
	}
	case 4: {
		direction = 2;
		break;
	}
	case 5: {
		ey3 = rand() % 2;
		if (ey3 == 0)direction = 2;
		else direction = 1;
		break;
	}
	case 6: {
		ey3 = rand() % 2;
		if (ey3 == 0) direction = 2;
		else direction = 0;
		break;
	}
	case 7: {
		ey3 = rand() % 3;
		if (ey3 == 0) direction = 2;
		else if (ey3 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 8: {
		direction = 3;
		break;
	}
	case 9: {
		ey3 = rand() % 2;
		if (ey3 == 0) direction = 3;
		else direction = 1;
		break;
	}
	case 10: {
		ey3 = rand() % 2;
		if (ey3 == 0) direction = 3;
		else direction = 0;
		break;
	}
	case 11: {
		ey3 = rand() % 3;
		if (ey3 == 0) direction = 3;
		else if (ey3 == 1) direction = 1;
		else direction = 0;
		break;
	}
	case 12: {
		ey3 = rand() % 2;
		if (ey3 == 0) direction = 2;
		else direction = 3;
		break;
	}
	case 13: {
		ey3 = rand() % 3;
		if (ey3 == 0) direction = 2;
		else if (ey3 == 1) direction = 1;
		else direction = 3;
		break;
	}
	case 14: {
		ey3 = rand() % 3;
		if (ey3 == 0)direction = 2;
		else if (ey3 == 0) direction = 3;
		else direction = 0;
		break;
	}
	default:;
	}
}


void generatecoinmap1x() {
	FILE* coin1;
	coin1 = fopen("positioncoinx1.txt", "r");
	char buffer[30];
	for (int i = 0; i < 30; i++)
	{
		fgets(buffer, 30, coin1);
		cx1[i] = atoi(buffer);
	}
	fclose(coin1);
}

void generatecoinmap1y() {
	FILE* coin2;
	coin2 = fopen("positioncoiny1.txt", "r");
	char buffer[30];
	for (int i = 0; i < 30; i++)
	{
		fgets(buffer, 30, coin2);
		cy1[i] = atoi(buffer);
	}
	fclose(coin2);
}

void generatecoinmap2x() {
	FILE* coin3;
	coin3 = fopen("positioncoinx2.txt", "r");
	char buffer[40];
	for (int i = 0; i < 40; i++)
	{
		fgets(buffer, 40, coin3);
		cx2[i] = atoi(buffer);
	}
	fclose(coin3);
}

void generatecoinmap2y() {
	FILE* coin4;
	coin4 = fopen("positioncoiny2.txt", "r");
	char buffer[40];
	for (int i = 0; i < 40; i++)
	{
		fgets(buffer, 40, coin4);
		cy2[i] = atoi(buffer);
	}
	fclose(coin4);
}

void generatecoinmap3x() {
	FILE* coin5;
	coin5 = fopen("positioncoinx3.txt", "r");
	char buffer[50];
	for (int i = 0; i < 50; i++)
	{
		fgets(buffer, 50, coin5);
		cx3[i] = atoi(buffer);
	}
	fclose(coin5);
}

void generatecoinmap3y() {
	FILE* coin6;
	coin6 = fopen("positioncoiny3.txt", "r");
	char buffer[50];
	for (int i = 0; i < 50; i++)
	{
		fgets(buffer, 50, coin6);
		cy3[i] = atoi(buffer);
	}
	fclose(coin6);
}

int main()
{
	srand(time(NULL));
	setcursor(0);
	do
	{
		startscreen(ch);
		if (_kbhit()) {
			ch = _getch();
			startscreen(ch);
		}

	} while (ch != ' ');
	clearscreen(26, 101);
	Typename(34, 11);
	scanf("%s",name);
	int x, y;
	world1();
	generatecoinmap1x();
	generatecoinmap1y();
    x = 6;
	y = 19;
	int ex1 = 10, ey1 = 12;
	draw_characterUp(x, y);
	drawE1(ex1, ey1);
	do
	{
		for (int c = 0; c < 30; c++)
		{
			spawncoin(cx1[c], cy1[c]);
		}
		enemydir1();
		enemydirfinal1(sumdi);
		if (direction == 2 && cursor(ex1 - 1, ey1) != '=' && direction == 2 && cursor(ex1 - 1, ey1) != '|')
		{
			drawE1(--ex1, ey1);
			Sleep(10);
			clearE(ex1 + 1, ey1);
		}
		if (direction == 3 && cursor(ex1 + 1, ey1) != '=' && direction == 3 && cursor(ex1 + 1, ey1) != '|')
		{
			drawE1(++ex1, ey1);
			Sleep(10);
			clearE(ex1 - 1, ey1);
		}
		if (direction == 0 && cursor(ex1, ey1 - 1) != '=' && cursor(ex1, ey1 - 1) != '-' && cursor(ex1, ey1 - 1) != '.' && cursor(ex1, ey1 - 1) != '|')
		{
			drawE1(ex1, --ey1);
			Sleep(10);
			clearE(ex1, ey1 + 1);
		}
		if (direction == 1 && cursor(ex1, ey1 + 1) != '=' && cursor(ex1, ey1 + 1) != '-' && cursor(ex1, ey1 + 1) != '.' && cursor(ex1, ey1 - 1) != '|')
		{
			drawE1(ex1, ++ey1);
			Sleep(10);
			clearE(ex1, ey1 - 1);
		}
		if (cursor(x, y) == cursor(ex1, ey1))
		{
			if (armorget == 1)
			{
				ex1 = 8;
				ey1 = 14;
			}
			if (armorget != 1)
			{
				std::thread
					q1(Beep, 500, 100);
				q1.detach();
				hp--;
				clear_character(x, y);
				x = 6;
				y = 19;
				draw_characterUp(x, y);
			}
		}
		if (x < 2)
		{
			clear_character(x, y);
			x = 47;
			draw_characterLeft(x, y);
		}
		if (x > 47)
		{
			clear_character(x, y);
			x = 2;
			draw_characterRight(x, y);
		}
		if (y < 2)
		{
			clear_character(x, y);
			y = 22;
			draw_characterUp(x, y);
		}
		if (y > 22)
		{
			clear_character(x, y);
			y = 2;
			draw_characterDown(x, y);
		}
		if (ex1 < 2)
		{
			clearE(ex1, ey1);
			ex1 = 47;
			drawE1(ex1, ey1);
		}
		if (ex1 > 47)
		{
			clearE(ex1, ey1);
			ex1 = 2;
			drawE1(ex1, ey1);
		}
		if (ey1 < 2)
		{
			clearE(ex1, ey1);
			ey1 = 22;
			drawE1(ex1, ey1);
		}
		if (ey1 > 22)
		{
			clearE(ex1, ey1);
			ey1 = 2;
			drawE1(ex1, ey1);
		}
		counttime();
		setConsole(screen_x, screen_y);
		Showscore(87, 7, score);
		ShowHp(57, 7, hp);
		Showtime(70, 7, m, s);
		if (_kbhit()) {
			Showscore(87, 7, score);
			ShowHp(57, 7, hp);
			counttime();
			Showtime(70, 7, m, s);
			ch = _getch();
			if (ch == 'a') {
				if (cursor(x - 1, y) == '=' || cursor(x - 1, y) == '|')
				{
					draw_characterLeft(x, y);
				}
				else
				{
					draw_characterLeft(--x, y);
					Sleep(20);
					clear_character(x + 1, y);
					draw_characterLeft(x, y);
					Sleep(speedx[speed]);
				}
			}
			if (ch == 'd') {
				if (cursor(x + 1, y) == '=' || cursor(x + 1, y) == '|')
				{
					draw_characterRight(x, y);
				}
				else
				{
					draw_characterRight(++x, y);
					Sleep(20);
					clear_character(x - 1, y);
					draw_characterRight(x, y);
					Sleep(speedx[speed]);
				}
			}

			if (ch == 'w') {
				if (cursor(x, y - 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
				{
					draw_characterUp(x, y);
				}
				else
				{
					draw_characterUp(x, --y);
					Sleep(20);
					clear_character(x, y + 1);
					Sleep(speedy[speed]);
				}
			}
			if (ch == 's') {
				if (cursor(x, y + 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
				{
					draw_characterDown(x, y);
				}
				else
				{
					draw_characterDown(x, ++y);
					Sleep(20);
					clear_character(x, y - 1);
					Sleep(speedy[speed]);
				}
			}
			oldbotton = ch;
			fflush(stdin);
		}
		for (int c = 0; c < 30; c++)
		{
			if (cursor(x, y) == cursor(cx1[c], cy1[c]))
			{
				std::thread
				q1(Beep, 800, 100);
				q1.detach();
				score += 100;
				cx1[c] = 0 + coincount ;
				cy1[c] = 0;
				coincount++;
			}
		}
		if (score % 1000 == 0 && score != 0)
		{
			randitem();
			if (cursor(x, y-1) ==cursor(Fx[0],Fy[0]))
			{
				timerF= 0;
				if (timer%10==0)
				{
					timerF++;
				}
				Lastex1 = ex1;
				Lastey1 = ey1;
				std::thread
				q1(Beep, 800, 100);
				q1.detach();
			}
			if (cursor(x, y+1) == cursor(Ax[0], Ay[1]))
			{
				timerA=0;
				if (timer % 10 == 0)
				{
					timerA++;
				}
				std::thread
				q1(Beep, 800, 100);
				q1.detach();
				armorget = 1;
				randitype = 0;
			}
			if (cursor(x, y) == cursor(Tx[1], Ty[1])&&nub==0)
			{
				std::thread
				q1(Beep, 800, 100);
				q1.detach();
				m=m+1;
				nub++;
				randitype = 0;
			}
			if (cursor(x, y) == cursor(Sx[1], Sy[0]))
			{
				timerS = 0;
				if (timer % 10 == 0)
				{
					timerS++;
				}
				std::thread
				q1(Beep, 800, 100);
				q1.detach();
				speed = 1;
			}
			if (timerF==10 )
			{
				freezeen = 0;
				randitype = 0;
			}
			if (timerS==10 )
			{
				speed = 0;
				randitype = 0;
			}
			if (timerA==10)
			{
				armorget = 0;
				if (ex1 == 8 && ey1 == 14)
				{
					ey1 += 2;
				}
				randitype = 0;
			}
			if (freezeen == 1)
			{
				ex1 = Lastex1;
				ey1 = Lastey1;
			}
		}

		if (coincount == 30)
		{
			nextstage = 1;
			ch = 'x';
		}

		timer++;
		Sleep(100);
	} while (ch != 'x');

	clearscreen(26, 101);
	ch = ' ';
	if (nextstage == 1)
	{
		coincount = 0;
		int x, y;
		setcolor(1, 0);
		world2();
		generatecoinmap2x();
		generatecoinmap2y();
		x = 19;
		y = 16;
		int ex1 = 20, ey1 = 13;
		int ex2 = 30, ey2 = 13;
		draw_characterUp(x, y);
		drawE1(ex1, ey1);
		drawE2(ex2, ey2);
		m = m + 1;
		ch = ' ';
		do
		{
			if (ch = 'x'&&coincount!=40)
			{
				nextstage = 0;
			}
			for (int c = 0; c < 40; c++)
			{
				spawncoin(cx2[c], cy2[c]);
			}
			enemydir1();
			enemydir2();
			enemydirfinal1(sumdi);
			if (direction == 2 && cursor(ex1 - 1, ey1) != '=' && direction == 2 && cursor(ex1 - 1, ey1) != '|')
			{
				drawE1(--ex1, ey1);
				Sleep(10);
				clearE(ex1 + 1, ey1);
			}
			if (direction == 3 && cursor(ex1 + 1, ey1) != '=' && direction == 3 && cursor(ex1 + 1, ey1) != '|')
			{
				drawE1(++ex1, ey1);
				Sleep(10);
				clearE(ex1 - 1, ey1);
			}
			if (direction == 0 && cursor(ex1, ey1 - 1) != '=' && cursor(ex1, ey1 - 1) != '-' && cursor(ex1, ey1 - 1) != '.' && cursor(ex1, ey1 - 1) != '|')
			{
				drawE1(ex1, --ey1);
				Sleep(10);
				clearE(ex1, ey1 + 1);
			}
			if (direction == 1 && cursor(ex1, ey1 + 1) != '=' && cursor(ex1, ey1 + 1) != '-' && cursor(ex1, ey1 + 1) != '.' && cursor(ex1, ey1 - 1) != '|')
			{
				drawE1(ex1, ++ey1);
				Sleep(10);
				clearE(ex1, ey1 - 1);
			}
			if (cursor(x, y) == cursor(ex1, ey1))
			{
				if (armorget == 1)
				{
					ex1 = 23;
					ey1 = 13;
				}
				if (armorget != 1)
				{
					std::thread
						q1(Beep, 500, 100);
					q1.detach();
					hp--;
					clear_character(x, y);
					x = 6;
					y = 19;
					draw_characterUp(x, y);
				}
			}
			enemydirfinal2(sumdi);
			if (direction == 2 && cursor(ex2 - 1, ey2) != '=' && direction == 2 && cursor(ex2 - 1, ey2) != '|')
			{
				drawE2(--ex2, ey2);
				Sleep(10);
				clearE(ex2 + 1, ey2);
			}
			if (direction == 3 && cursor(ex2 + 1, ey2) != '=' && direction == 3 && cursor(ex2 + 1, ey2) != '|')
			{
				drawE2(++ex2, ey2);
				Sleep(10);
				clearE(ex2 - 1, ey2);
			}
			if (direction == 0 && cursor(ex2, ey2 - 1) != '=' && cursor(ex2, ey2 - 1) != '-' && cursor(ex2, ey2 - 1) != '.' && cursor(ex2, ey2 - 1) != '|')
			{
				drawE2(ex2, --ey2);
				Sleep(10);
				clearE(ex2, ey2 + 1);
			}
			if (direction == 1 && cursor(ex2, ey2 + 1) != '=' && cursor(ex2, ey2 + 1) != '-' && cursor(ex2, ey2 + 1) != '.' && cursor(ex2, ey2 - 1) != '|')
			{
				drawE2(ex2, ++ey2);
				Sleep(10);
				clearE(ex2, ey2 - 1);
			}
			if (cursor(x, y) == cursor(ex2, ey2))
			{
				if (armorget == 1)
				{
					ex2 = 27;
					ey2 = 13;
				}
				if (armorget != 1)
				{
					std::thread
					q1(Beep, 500, 100);
					q1.detach();
					hp--;
					clear_character(x, y);
					x = 6;
					y = 19;
					draw_characterUp(x, y);
				}
			}
			if (x < 2)
			{
				clear_character(x, y);
				x = 47;
				draw_characterLeft(x, y);
			}
			if (x > 47)
			{
				clear_character(x, y);
				x = 2;
				draw_characterRight(x, y);
			}
			if (ex1 < 2)
			{
				clearE(ex1, ey1);
				ex1 = 47;
				drawE1(ex1, ey1);
			}
			if (ex1 > 47)
			{
				clearE(ex1, ey1);
				ex1 = 2;
				drawE1(ex1, ey1);
			}
			if (ex2 < 2)
			{
				clearE(ex2, ey2);
				ex2 = 47;
				drawE2(ex2, ey2);
			}
			if (ex2 > 47)
			{
				clearE(ex2, ey2);
				ex2 = 2;
				drawE2(ex2, ey2);
			}
			counttime();
			setConsole(screen_x, screen_y);
			Showscore(87, 7, score);
			ShowHp(57, 7, hp);
			Showtime(70, 7, m, s);
			if (_kbhit()) {
				Showscore(87, 7, score);
				ShowHp(57, 7, hp);
				counttime();
				Showtime(70, 7, m, s);
				ch = _getch();
				if (ch == 'a') {
					if (cursor(x - 1, y) == '=' || cursor(x - 1, y) == '|')
					{
						draw_characterLeft(x, y);
					}
					else
					{
						draw_characterLeft(--x, y);
						Sleep(20);
						clear_character(x + 1, y);
						draw_characterLeft(x, y);
						Sleep(speedx[speed]);
					}
				}
				if (ch == 'd') {
					if (cursor(x + 1, y) == '=' || cursor(x + 1, y) == '|')
					{
						draw_characterRight(x, y);
					}
					else
					{
						draw_characterRight(++x, y);
						Sleep(20);
						clear_character(x - 1, y);
						draw_characterRight(x, y);
						Sleep(speedx[speed]);
					}
				}

				if (ch == 'w') {
					if (cursor(x, y - 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
					{
						draw_characterUp(x, y);
					}
					else
					{
						draw_characterUp(x, --y);
						Sleep(20);
						clear_character(x, y + 1);
						Sleep(speedy[speed]);
					}
				}
				if (ch == 's') {
					if (cursor(x, y + 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
					{
						draw_characterDown(x, y);
					}
					else
					{
						draw_characterDown(x, ++y);
						Sleep(20);
						clear_character(x, y - 1);
						Sleep(speedy[speed]);
					}
				}


				oldbotton = ch;
				fflush(stdin);
			}
			for (int c = 0; c < 40; c++)
			{
				if (cursor(x, y) == cursor(cx2[c], cy2[c]))
				{
					std::thread
					q1(Beep, 800, 100);
					q1.detach();
					score += 100;
					cx2[c] = 0 + coincount;
					cy2[c] = 0;
					coincount++;
				}
			}
			if (score % 1000 == 0 && score != 0)
			{
				randitem();
				if (cursor(x, y) == cursor(Fx[0], Fy[0]+1))
				{
					timerF = 0;
					if (timer % 10 == 0)
					{
						timerF++;
					}
					Lastex1 = ex1;
					Lastey1 = ey1;
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
				}
				if (cursor(x, y) == cursor(Ax[0], Ay[1]+1))
				{
					timerA = 0;
					if (timer % 10 == 0)
					{
						timerA++;
					}
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					armorget = 1;
					randitype = 0;
				}
				if (cursor(x, y) == cursor(Tx[1],Ty[1]+1))
				{
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					m++;
					randitype = 0;
				}
				if (cursor(x, y) == cursor(Sx[1], Sy[0]+1))
				{
					timerS = 0;
					if (timer % 10 == 0)
					{
						timerS++;
					}
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					speed = 1;
				}
				if (timerF == 10)
				{
					freezeen = 0;
					randitype = 0;
				}
				if (timerS == 10)
				{
					speed = 0;
					randitype = 0;
				}
				if (timerA == 10)
				{
					armorget = 0;
					if (ex1 == 8 && ey1 == 14)
					{
						ey1 += 2;
					}
					randitype = 0;
				}
				if (freezeen == 1)
				{
					ex1 = Lastex1;
					ey1 = Lastey1;
					ex2 = Lastex2;
					ey2 = Lastey2;
				}

			}

			if (coincount == 40)
			{
				nextstage = 2;
				ch = 'x';
			}

			timer++;
			Sleep(100);
		} while (ch != 'x');
	}
	clearscreen(26, 101);
	ch = ' ';
	if (nextstage == 2)
	{
		nub == 0;
		coincount = 0;
		int x, y;
		setcolor(2, 0);
		world3();
		generatecoinmap3x();
		generatecoinmap3y();
		x = 25;
		y = 5;
		int ex1 = 25, ey1 = 9;
		int ex2 = 33, ey2 = 15;
		int ex3 = 15, ey3 = 15;
		draw_characterUp(x, y);
		drawE1(ex1, ey1);
		drawE2(ex2, ey2);
		drawE3(ex3, ey3);
		ch = ' ';
		m = m + 1;
		do
		{
			
			for (int c = 0; c < 50; c++)
			{
				spawncoin(cx3[c], cy3[c]);
			}
			enemydir1();
			enemydir2();
			enemydir3();
			enemydirfinal1(sumdi);
			if (direction == 2 && cursor(ex1 - 1, ey1) != '=' && direction == 2 && cursor(ex1 - 1, ey1) != '|')
			{
				drawE1(--ex1, ey1);
				Sleep(10);
				clearE(ex1 + 1, ey1);
			}
			if (direction == 3 && cursor(ex1 + 1, ey1) != '=' && direction == 3 && cursor(ex1 + 1, ey1) != '|')
			{
				drawE1(++ex1, ey1);
				Sleep(10);
				clearE(ex1 - 1, ey1);
			}
			if (direction == 0 && cursor(ex1, ey1 - 1) != '=' && cursor(ex1, ey1 - 1) != '-' && cursor(ex1, ey1 - 1) != '.' && cursor(ex1, ey1 - 1) != '|')
			{
				drawE1(ex1, --ey1);
				Sleep(10);
				clearE(ex1, ey1 + 1);
			}
			if (direction == 1 && cursor(ex1, ey1 + 1) != '=' && cursor(ex1, ey1 + 1) != '-' && cursor(ex1, ey1 + 1) != '.' && cursor(ex1, ey1 - 1) != '|')
			{
				drawE1(ex1, ++ey1);
				Sleep(10);
				clearE(ex1, ey1 - 1);
			}
			if (cursor(x, y) == cursor(ex1, ey1))
			{
				if (armorget == 1)
				{
					ex1 = 23;
					ey1 = 18;
				}
				std::thread
					q1(Beep, 500, 100);
				q1.detach();
				hp--;
				clear_character(x, y);
				x = 25;
				y = 5;
				draw_characterUp(x, y);
			}
			enemydirfinal2(sumdi);
			if (direction == 2 && cursor(ex2 - 1, ey2) != '=' && direction == 2 && cursor(ex2 - 1, ey2) != '|')
			{
				drawE2(--ex2, ey2);
				Sleep(10);
				clearE(ex2 + 1, ey2);
			}
			if (direction == 3 && cursor(ex2 + 1, ey2) != '=' && direction == 3 && cursor(ex2 + 1, ey2) != '|')
			{
				drawE2(++ex2, ey2);
				Sleep(10);
				clearE(ex2 - 1, ey2);
			}
			if (direction == 0 && cursor(ex2, ey2 - 1) != '=' && cursor(ex2, ey2 - 1) != '-' && cursor(ex2, ey2 - 1) != '.' && cursor(ex2, ey2 - 1) != '|')
			{
				drawE2(ex2, --ey2);
				Sleep(10);
				clearE(ex2, ey2 + 1);
			}
			if (direction == 1 && cursor(ex2, ey2 + 1) != '=' && cursor(ex2, ey2 + 1) != '-' && cursor(ex2, ey2 + 1) != '.' && cursor(ex2, ey2 - 1) != '|')
			{
				drawE2(ex2, ++ey2);
				Sleep(10);
				clearE(ex2, ey2 - 1);
			}
			if (cursor(x, y) == cursor(ex2, ey2))
			{
				if (armorget == 1)
				{
					ex2 = 27;
					ey2 = 18;
				}
				std::thread
					q1(Beep, 500, 100);
				q1.detach();
				hp--;
				clear_character(x, y);
				x = 6;
				y = 19;
				draw_characterUp(x, y);
			}
			enemydirfinal3(sumdi);
			if (direction == 2 && cursor(ex3 - 1, ey3) != '=' && direction == 2 && cursor(ex3 - 1, ey3) != '|')
			{
				drawE3(--ex3, ey3);
				Sleep(10);
				clearE(ex3 + 1, ey3);
			}
			if (direction == 3 && cursor(ex3 + 1, ey3) != '=' && direction == 3 && cursor(ex3 + 1, ey3) != '|')
			{
				drawE3(++ex3, ey3);
				Sleep(10);
				clearE(ex3 - 1, ey3);
			}
			if (direction == 0 && cursor(ex3, ey3 - 1) != '=' && cursor(ex3, ey3 - 1) != '-' && cursor(ex3, ey3 - 1) != '.' && cursor(ex3, ey3 - 1) != '|')
			{
				drawE3(ex3, --ey3);
				Sleep(10);
				clearE(ex3, ey3 + 1);
			}
			if (direction == 1 && cursor(ex3, ey3 + 1) != '=' && cursor(ex3, ey3 + 1) != '-' && cursor(ex3, ey3 + 1) != '.' && cursor(ex3, ey3- 1) != '|')
			{
				drawE3(ex3, ++ey3);
				Sleep(10);
				clearE(ex3, ey3 - 1);
			}
			if (cursor(x, y) == cursor(ex3, ey3))
			{
				if (armorget == 1)
				{
					ex3 = 25;
					ey3 = 18;
				}
				std::thread
				q1(Beep, 500, 100);
				q1.detach();
				hp--;
				clear_character(x, y);
				x = 5;
				y = 19;
				draw_characterUp(x, y);
			}
			if (x < 2)
			{
				clear_character(x, y);
				x = 47;
				draw_characterLeft(x, y);
			}
			if (x > 47)
			{
				clear_character(x, y);
				x = 2;
				draw_characterRight(x, y);
			}
		
			if (ex1 < 2)
			{
				clearE(ex1, ey1);
				ex1 = 47;
				drawE1(ex1, ey1);
			}
			if (ex1 > 47)
			{
				clearE(ex1, ey1);
				ex1 = 2;
				drawE1(ex1, ey1);
			}
			if (ex2 < 2)
			{
				clearE(ex2, ey2);
				ex2 = 47;
				drawE2(ex2, ey2);
			}
			if (ex2 > 47)
			{
				clearE(ex2, ey2);
				ex2 = 2;
				drawE2(ex2, ey2);
			}
			if (ex3 < 2)
			{
				clearE(ex3, ey3);
				ex3 = 47;
				drawE3(ex3, ey3);
			}
			if (ex3 > 47)
			{
				clearE(ex3, ey3);
				ex3 = 2;
				drawE3(ex3, ey3);
			}
			counttime();
			setConsole(screen_x, screen_y);
			Showscore(87, 7, score);
			ShowHp(57, 7, hp);
			Showtime(70, 7, m, s);
			if (_kbhit()) {
				Showscore(87, 7, score);
				ShowHp(57, 7, hp);
				counttime();
				Showtime(70, 7, m, s);
				ch = _getch();
				if (ch == 'a') {
					if (cursor(x - 1, y) == '=' || cursor(x - 1, y) == '|')
					{
						draw_characterLeft(x, y);
					}
					else
					{
						draw_characterLeft(--x, y);
						Sleep(20);
						clear_character(x + 1, y);
						draw_characterLeft(x, y);
						Sleep(speedx[speed]);
					}
				}
				if (ch == 'd') {
					if (cursor(x + 1, y) == '=' || cursor(x + 1, y) == '|')
					{
						draw_characterRight(x, y);
					}
					else
					{
						draw_characterRight(++x, y);
						Sleep(20);
						clear_character(x - 1, y);
						draw_characterRight(x, y);
						Sleep(speedx[speed]);
					}
				}

				if (ch == 'w') {
					if (cursor(x, y - 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
					{
						draw_characterUp(x, y);
					}
					else
					{
						draw_characterUp(x, --y);
						Sleep(20);
						clear_character(x, y + 1);
						Sleep(speedy[speed]);
					}
				}
				if (ch == 's') {
					if (cursor(x, y + 1) == '=' || cursor(x, y + 1) == '|' || cursor(x, y + 1) == '.')
					{
						draw_characterDown(x, y);
					}
					else
					{
						draw_characterDown(x, ++y);
						Sleep(20);
						clear_character(x, y - 1);
						Sleep(speedy[speed]);
					}
				}


				oldbotton = ch;
				fflush(stdin);
			}
			for (int c = 0; c < 50; c++)
			{
				if (cursor(x, y) == cursor(cx3[c], cy3[c]))
				{
					std::thread
					q1(Beep, 800, 100);
					q1.detach();
					score += 100;
					cx3[c] = 0 + coincount;
					cy3[c] = 0;
					coincount++;
				}
			}
			if (score % 1000 == 0 && score != 0)
			{
				randitem();
				if (cursor(x, y-1) == cursor(Fx[0], Fy[0]))
				{
					timerF = 0;
					if (timer % 10 == 0)
					{
						timerF++;
					}
					Lastex1 = ex1;
					Lastey1 = ey1;
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					freezeen = 1;
				}
				if (cursor(x, y+1) == cursor(Ax[0], Ay[1]))
				{
					timerA = 0;
					if (timer % 10 == 0)
					{
						timerA++;
					}
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					armorget = 1;
				}
				if (cursor(x, y) == cursor(Tx[1],Ty[1])&&nub==0)
				{
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					m = m + 1;
					nub++;
					randitype = 0;
				}
				if (cursor(x, y) == cursor(Sx[1], Sy[0]))
				{
					timerS = 0;
					if (timer % 10 == 0)
					{
						timerS++;
					}
					std::thread
						q1(Beep, 800, 100);
					q1.detach();
					speed = 1;
				}
				if (timerF == 10)
				{
					freezeen = 0;
					randitype = 0;
				}
				if (timerS == 10)
				{
					speed = 0;
					randitype = 0;
				}
				if (timerA == 10)
				{
					armorget = 0;
					if (ex1 == 8 && ey1 == 14)
					{
						ey1 += 2;
					}
					randitype = 0;
				}
				if (freezeen == 1)
				{
					ex1 = Lastex1;
					ey1 = Lastey1;
					ex2 = Lastex2;
					ey2 = Lastey2;
					ex3 = Lastex3;
					ey3 = Lastey3;
				}
			}

			if (ch = 'x'&&coincount!=50)
			{
				nextstage = 0;
			}
			if (coincount == 50)
			{
				nextstage = 3;
				ch = 'x';
			}
			timer++;
			Sleep(100);
		} while (ch != 'x');
	}
	if (nextstage == 3) {
		clearscreen(26, 101);
		winscreen(ch);
		Sleep(3000);
        nextstage = 4;
	}
	else if (nextstage == 0)
	{
		clearscreen(26, 101);
		overscreen(ch);
		Sleep(3000);
		nextstage = 4;
	}

	if (nextstage == 4) {
		clearscreen(26, 101);
		selectTop5(score,name);
		showtop5score();
	}
	return 0;
}
