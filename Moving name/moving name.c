/* Write a program that should control by user keyboard and display in the keyboard*/
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void gotoxy(int ,int);
void quick(int , int, char[]);
int main(void)
{   char cha[30],ch;
    int x=55,y=12;
    system("color 9");
    gotoxy(10,2);
     printf("\nEnter your name please\t");
     gets(cha);
     system("color c");
     while(1)
    {   system("color 4");
    gotoxy(10,2);
printf("\nPress w for upper and v for down ; for right and a for left and press q for exit\t");
         quick(x,y,cha);
        fflush(stdin);
     ch=getche();
     switch(ch)
     {
    case 'w':
        system("color b && cls");
        y--;
        quick(x,y,cha);
        break;
    case 'v':
        y++;
        system("color d && cls");
        quick(x,y,cha);
        break;
    case ';':
        system("color e && cls");
        x++;
    quick(x,y,cha);
        break;
    case 'a':
        system("color 1 && cls");
        x--;
        quick(x,y,cha);
        break;
    case 'q':
        system("color 2");
        printf("\nThanks for using our program .....");
        exit(0);
        break;
    default:
        printf("\a");
        break;
        }
     }
     return 0;
}
void gotoxy(int a,int b)
{     COORD c;
    c.X=a;
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void quick(int a, int b, char cha[])
{    gotoxy(a,b);
       printf("%s",cha);
}
