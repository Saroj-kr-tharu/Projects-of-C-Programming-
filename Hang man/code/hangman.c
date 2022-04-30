/* This project is compeletely based on the dec c++ software having 0 errors and 0 warmming  */
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>
char user_name[30],ch,result[5],temp[5]="_____";
int value,gameover=0,turn=0;
void gotoxy(int , int );
void intro();
void logic();
void show();
void input();
int main()
{	intro();
	printf("\n\t\t <----- Enter the name of the user ------> ");
	gets(user_name);
	strcpy(result,"saroj");
	input();
	logic();
	show();
	while(!gameover)
	{
		input();
		logic();
		show();
	}
	printf("\n\t\t <----- Successfully won %s game ------> ",user_name);
	getch();
	return 0;
}
void input()
{
	printf("\n\t\t <----- Enter the guess character ------> \t");
	fflush(stdin);
	scanf("%c",&ch);
}
void gotoxy(int x, int y)
{	COORD c;
	c.X=x,c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void show()
{  	system("cls");
	gotoxy(25,4);
	int i;
	printf("\n\t\t\t#############################################");
	printf("\n\t\t\t\t\t\t#");
	for(i=0; i<5; i++)
	printf("%c",temp[i]);
	printf("#");
	printf("\n\t\t\t #############################################");

}
void logic()
{ 	int i;
	for(i=0; i<5; i++)
	if((strcmp(result[i],ch))==0)
	 strcpy(temp[i],ch);
	else{
	strcpy(temp[i],'_');
	turn++;
	}
	 if(turn>4)
	 gameover=1;

}
void intro()
{
	gotoxy(25,2);
	printf("#___________________________________________#");
	printf("\n\t\t\t #					     #");
	printf("\n\t\t\t #		Welcome to hang game	     #");
	printf("\n\t\t\t #					     #");
	printf("\n\t\t\t #-------------------------------------------#");
}
