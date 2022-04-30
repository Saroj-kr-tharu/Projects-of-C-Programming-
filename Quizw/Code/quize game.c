/* This is quize game */
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
COORD c = {0, 0};
COORD max_res, cursor_size;
int score, no, gameover = 0, lifetime = 0, answer = 0;
char usr_nme[50];
struct question
{
	char ques[500], option[4][30];
	int ans, id;
} emp;
void intro();
void user_name();
void logic();
int check(char);
void search();
void gotoxy(int, int);
void scorewala();
void setup();
void question();
int found;
int main()
{
	intro();
	setup();
	user_name();
	system("cls");
	gotoxy(15, 1);
	intro();
	while (1)
	{
		if (gameover == 1)
			break;
		system("cls");
		intro();
		question();
		logic();
		scorewala();
	}
	system("cls");
	gotoxy(15, 6);
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t|                                                                |\n");
	printf("\t\t|               	   	OUCH YOU DIE		                     |\n");
	printf("\t\t|                                                                |");
	printf("\n\t\t------------------------------------------------------------------\n");
	scorewala();
}
void gotoxy(int a, int b)
{
	COORD c;
	c.X = a;
	c.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void user_name()
{	system("cls");
	gotoxy(15, 6);
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t|                                                                |\n");
	printf("\t\t|              ENTER YOUR NAME PLEASE		                 |\n");
	printf("\t\t|                                                                |");
	printf("\n\t\t------------------------------------------------------------------\n");
	fflush(stdin);
	gets(usr_nme);
}
void scorewala()
{
	gotoxy(90, 70);
	printf("Score==%d", score);
	gotoxy(90, 71);
	printf("User name==%s", usr_nme);
	gotoxy(90, 72);
	printf("Life time==%d", lifetime);
}
void logic()
{
	int  n;
	char ch;
top:
	printf("\n");
	fflush(stdin);
	ch = getch();
	//scanf("%d",&ch);
	n = check(ch);
	if (n == 0)
	{	system("cls");
		gotoxy(15, 6);
		printf("\n\t\t________________________________________________________________\n");
		printf("\t\t|                                                                |\n");
		printf("\t\t|              PLEASE ENTER YOUR RIGHT OPTIONS		             |\n");
		printf("\t\t|                                                                |");
		printf("\n\t\t------------------------------------------------------------------\n");
		goto top;
	}
	if (answer == n)
	{	
		gotoxy(15, 20);
		printf("\n\t\t________________________________________________________________\n");
		printf("\t\t|                                                                |\n");
		printf("\t\t|              CONGRATULATIONS YOU HAVE CORRECT ANSWER           |\n");
		printf("\t\t|                                                                |");
		printf("\n\t\t------------------------------------------------------------------\n");
		score += 10;
		system("pause");
	}
	else
	{	
		gotoxy(15, 20);
		printf("\n\t\t________________________________________________________________\n");
		printf("\t\t|                                                                |\n");
		printf("\t\t|         %c      	     INCORRECT ANSWER                        |\n",ch);
		printf("\t\t|                                                                |");
		printf("\n\t\t------------------------------------------------------------------\n");
		score -= 10;
		lifetime++;
		system("pause");
	}
	if (lifetime >= 3)
		gameover = 1;
}
void setup()
{
	score = 0;
	gameover = 0;
	lifetime = 0;
}

void question()
{
joker:
		system("cls");
	gotoxy(15, 6);
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t|                                                                |\n");
	printf("\t\t|     ENTER THE NUMBER OF QUESTIONS TO BE SEARCHED               |\n");
	printf("\t\t|                                                                |");
	printf("\n\t\t------------------------------------------------------------------\n");
	fflush(stdin);
	scanf("%d", &no);
	search(no);
	if (found == 0)
	{
		goto joker;
	}
}

void search(int no)
{
	int i;
	FILE *src;
	found = 0;
	src = fopen("question.skt", "r");
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		if (no == emp.id)
		{
			found++;
			system("cls");
			gotoxy(15, 12);
			printf("\n\t\t___________________________________________________________________________________#");
			printf("\n\t\t|%d ", emp.id);
			printf("%s", emp.ques);
			printf("\n\n\t\t|");
			for (i = 0; i < 4; i++)
				printf("\t%d.%s", i + 1, emp.option[i]);
			printf("|");
			answer = emp.ans;
			printf("\n\t\t--------------------------------------------------------------------------------------\n");
		}
	}
	if (found == 0)
	{	system("cls");
		gotoxy(15, 6);
		printf("\n\t\t________________________________________________________________\n");
		printf("\t\t|                                                                |\n");
		printf("\t\t|               	  Question is not exit                 |\n");
		printf("\t\t|                                                                |");
		printf("\n\t\t------------------------------------------------------------------\n");
	}
	fclose(src);
	getch();
}

void intro()
{	system("cls");
	gotoxy(15, 1);
	printf("\n\t\t________________________________________________________________\n");
	printf("\t\t|################################################################|\n");
	printf("\t\t| ################## WELCOME TO QUIZE PROGRAM ###################|\n");
	printf("\t\t|################################################################|");
	printf("\n\t\t------------------------------------------------------------------\n");
	Sleep(100);
}

int check(char ch)
{
	switch (ch)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	default:
		system("cls");
		gotoxy(15, 6);
		printf("\n\t\t________________________________________________________________\n");
		printf("\t\t|                                                                |\n");
		printf("\t\t| 		 INVALID OPTIONS PLESASE SELECT NEW OPTIONS          |\n");
		printf("\t\t|                                                                |");
		printf("\n\t\t------------------------------------------------------------------\n");
		return 0;
		break;
	}
}
