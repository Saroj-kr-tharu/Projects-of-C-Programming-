/* Write a program to desinged  a game like a tic toe tak */
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
COORD c = {0, 0};
COORD max_res, cursor_size;
char ch[10], ch1[10], a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int count = 0;
int first;
void show();
void intro();
void player(int);
int turn();
void sym();
int logic();
void firs_turn();
void ask();
void pui(int);
void menu();
void user2();
void help();
void com_input();
void gotoxy(int, int);
void computer_to_user();
void computer_to_computer();
int main()
{
    while (1)
        menu();
}
void menu()
{
    system("cls");
    int n, no;
    printf("\n\t\tPlease entered your options\n");
    printf("\n\t\t1:- Start\n\t\t2:- Exit\n\t\t3:- About\t");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    top:
        system("cls");
        printf("\n\t\t\tPlease select mode");
        printf("\n\t\t1:- Computer to computer\n\t\t2:- Computer to player\n\t\t3:- 2player\t");
        scanf("%d", &no);
        switch (no)
        {
        case 1:
            computer_to_computer();
            break;
        case 2:
            computer_to_user();
            break;
        case 3:
            user2();
            break;
        default:
            printf("\nInvalid options");
            system("cls");
            goto top;
        }
        break;
    case 2:
        printf("\n\t\tThanks for playing our game");
        exit(0);
        break;
    case 3:
        help();
        break;
    default:
        printf("\n\t\tinvlalid options");
    }
}
void help()
{
    system("color 2f && cls");
    printf("\n\t\t__________________________________________________________________\n");
    printf("\t\t|                                                                |\n");
    printf("\t\t|                   DEVELOPER SAROJ KUMAR THARU                  |\n");
    printf("\t\t|  		This game is known as Tic tak toe		 |\n");
    printf("\t\t| 	 			To play this game		 |\n");
    printf("\t\t|  	Just press position for to set the symbol		 |\n");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\t\t|  any problem  contact me                                       |\n");
    printf("\t\t|       Email                   Phone              Facebook      |\n");
    printf("\t\t|  sarojc034@gmail.com        9804517468        Dark  net  |\n");
    printf("\t\t|                                                                |");
    printf("\n\t\t------------------------------------------------------------------\n");
    system("pause");
    system("cls && color 7");
}
void user2()
{
    int i;
    count = 0;
    system("color 8f && cls");
    intro();
    player(10);
maintop:
    firs_turn();
    system("color 2e && cls");
    show();
    system("color 3e");
    sym();
    system("color 2e && cls");
    show();
top:
    i = logic();
    if (i == 100)
    {
        system("color 9");
        Beep(1200, 450);
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |\n", ch);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (i == 200)
    {
        system("color 9");
        Beep(1200, 450);
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (count == 9)
    {
        system("color d");
        Beep(3100, 500);
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  GAME DRAWED                                |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
        char jo;
        Beep(2100, 900);
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                PRESS Y FOR TO PLAY AGAIN                     |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
        scanf("%c", &jo);
        if (jo == 'y' || jo == 'Y')
        {
            a[0] = '1';
            a[1] = '2';
            a[2] = '3';
            a[3] = '4';
            a[4] = '5';
            a[5] = '6';
            a[6] = '7';
            a[7] = '8';
            a[8] = '9';
            goto maintop;
        }
    }
    else
    {
        sym();
        i = logic();
        system("color 2e && cls");
        show();
        goto top;
    }
    ask();
}
void show()
{
    system("cls");
    printf("\n\t\t\t\t#############################################\n");
    printf("\t\t\t\t#|------------------------------------------|#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c       |#\n", a[0], a[1], a[2]);
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|------------!---------------!-------------|#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c       |#\n", a[3], a[4], a[5]);
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|------------!---------------!-------------|#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c       |#\n", a[6], a[7], a[8]);
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|	      !	 	      !	  	    |#\n");
    printf("\t\t\t\t#|____________!_______________!_____________|#");
    printf("\n\t\t\t\t#############################################\n\t");
    gotoxy(6, 13);
    printf("\nPlayer 1:%s =X", ch);
    gotoxy(6, 14);
    printf("\nPlayer 2:%s =O", ch1);
}
int logic()
{
    if ((a[0] == 'X' && a[1] == 'X' && a[2] == 'X') || (a[3] == 'X' && a[4] == 'X' && a[5] == 'X') || (a[6] == 'X' && a[7] == 'X' && a[8] == 'X'))
        return 100;
    else if ((a[0] == 'O' && a[1] == 'O' && a[2] == 'O') || (a[3] == 'O' && a[4] == 'O' && a[5] == 'O') || (a[6] == 'O' && a[7] == 'O' && a[8] == 'O'))
        return 200;
    else if ((a[0] == 'X' && a[3] == 'X' && a[6] == 'X') || (a[1] == 'X' && a[4] == 'X' && a[7] == 'X') || (a[2] == 'X' && a[5] == 'X' && a[8] == 'X'))
        return 100;
    else if ((a[0] == 'O' && a[3] == 'O' && a[6] == 'O') || (a[1] == 'O' && a[4] == 'O' && a[7] == 'O') || (a[2] == 'O' && a[5] == 'O' && a[8] == 'O'))
        return 200;
    else if ((a[0] == 'X' && a[4] == 'X' && a[8] == 'X') || (a[2] == 'X' && a[4] == 'X' && a[6] == 'X'))
        return 100;
    else if ((a[0] == 'O' && a[4] == 'O' && a[8] == 'O') || (a[2] == 'O' && a[4] == 'O' && a[6] == 'O'))
        return 200;
}
void intro()
{
    printf("\a\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|                                                             |\n");
    printf("\t\t\t\t|                  WELCOME TO TIC TAK TOE GAME                |\n");
    printf("\t\t\t\t|                                                             |");
    printf("\n\t\t\t\t---------------------------------------------------------------\n");
}
void ask()
{
    char jo;
    Beep(1500, 400);
    printf("\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|     PRESS Y FOR TO PLAY AGAIN AND M FOR MANI MENU             |", ch1);
    printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    fflush(stdin);
    scanf("%c", &jo);
    if (jo == 'y' || jo == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        system("cls");
        main();
    }
    else if (jo == 'm' || jo == 'M')
        ;
    {
        if (jo == 'y' || jo == 'Y')
        {
            a[0] = '1';
            a[1] = '2';
            a[2] = '3';
            a[3] = '4';
            a[4] = '5';
            a[5] = '6';
            a[6] = '7';
            a[7] = '8';
            a[8] = '9';
            menu();
        }
    }
}
void player(int n)
{
    if (n == 10)
    {
        fflush(stdin);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                ENTER THE FIRST NAME OF THE PLAYER 1          |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        gets(ch);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                ENTER THE FIRST NAME OF THE PLAYER 2          |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
        gets(ch1);
        system("cls");
    }
    else if (n == 2)
    {
        fflush(stdin);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                ENTER THE FIRST NAME OF USER		          |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        gets(ch);
        strcpy(ch1, "Computer");
        system("cls");
    }
    else if (n == 3)
    {
        strcpy(ch, "Computer200");
        strcpy(ch1, "Computer100");
    }
}
void sym()
{
    int n, pos, j, found;
top:
    n = turn();
    if (n == 100)
    {
        system("color b");
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|           %s  ENTER THE POSITION                             |\t", ch);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        first--;
    }
    else
    {
        system("color 2");
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|           %s  ENTER THE POSITION                             |\t", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        first--;
    }
    fflush(stdin);
    scanf("%d", &pos);
    pos--;
    found = 0;
    for (j = 0; j < 9; j++)
    {
        if (j == pos)
        {
            if (a[j] == 'X' || a[j] == 'O')
                found = 0;
            else
            {
                found++;
                break;
            }
        }
        else
            found == 0;
    }
    if (pos >= 9)
    {
        system("cls");
        show();
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                 INVALID POSITION                            |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
        goto top;
    }
    if (found == 0)
    {
        system("cls");
        show();
        gotoxy(0, 25);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|            THIS POSITION IS ALREADY USE                       |\t\n");
        printf("\t\t\t\t|            PLEASE USE ANOTHER POSITION                        |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        goto top;
    }
    pui(pos);
    count++;
}
void firs_turn()
{
    int j;
top:
    printf("\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|           WHO WANT TO START THE GAME???????                  |\n", ch);
    printf("\t\t\t\t|               PRESS 1 FOR %s\t\t2 FOR %s                \t", ch, ch1);
    printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    fflush(stdin);
    scanf("%d", &first);
    if (first == 1)
    {
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|           %s  FIRST TURN IS YOUR                            |\t", ch);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    }
    else if (first == 2)
    {
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|           %s  FIRST TURN IS YOUR                            |\t", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    }
    else
    {
        system("color 4 && cls");
        Beep(300, 800);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                 INVALID OPTIONS                             |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        goto top;
    }
}
void pui(int p)
{
    int i, n;
    n = turn();
    if (n == 99)
    {
        for (i = 0; i < 9; i++)
            if (p == i)
                a[i] = 'O';
    }

    else if (n == 100)
    {
        for (i = 0; i < 9; i++)
            if (p == i)
                a[i] = 'X';
    }
}

int turn()
{
    if (first % 2 == 0)
    {
        first++;
        return 99;
    }
    else
    {
        first++;
        return 100;
    }
}

void computer_to_user()
{
    int i;
    count = 0;
    system("color 8f && cls");
    intro();
    player(2);
maintop:
    firs_turn();
    system("color 2e && cls");
    show();
    system("color 3e");
    com_input(1);
    system("color 2e && cls");
    show();
top:
    i = logic();
    if (i == 100)
    {
        system("color 9");
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |\n", ch);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (i == 200)
    {
        system("color 9");
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (count == 9)
    {
        system("color d");
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  GAME DRAWED                                |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
        char jo;
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                PRESS Y FOR TO PLAY AGAIN                     |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
        scanf("%c", &jo);
        if (jo == 'y' || jo == 'Y')
        {
            a[0] = '1';
            a[1] = '2';
            a[2] = '3';
            a[3] = '4';
            a[4] = '5';
            a[5] = '6';
            a[6] = '7';
            a[7] = '8';
            a[8] = '9';
            goto maintop;
        }
    }
    else
    {
        com_input(1);
        i = logic();
        system("color 2e && cls");
        show();
        goto top;
    }
    ask();
}

void com_input(int p)
{
    int n, pos, j, found, un, first_pos = first, invalid = 0;
top:
    n = turn();
    first_pos = first;
    if (invalid >= 2)
    {
        if (first_pos % 2 == 0)
            first -= 1;
        else
            first -= 2;
    }
    if (p == 1)
    {
        if (n == 100)
        {
            system("color b");
            gotoxy(0, 20);
            printf("\n\t\t\t\t_______________________________________________________________\n");
            printf("\t\t\t\t|           %s  ENTER THE POSITION                             |\t", ch);
            printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
            first--;
            fflush(stdin);
            scanf("%d", &un);
        }
        else
        {
            system("color 2");
            un = rand() % 9;
            gotoxy(0, 20);
            printf("\n\t\t\t\t_______________________________________________________________\n");
            printf("\t\t\t\t|           %s  SELECTED %d POSITION                           |\t", ch1, un);
            printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
            Sleep(1000);
            first--;
        }
    }
    else if (p == 2)
    {
        if (n == 100)
        {
            un = rand() % 10;
            system("color b");
            gotoxy(0, 20);
            printf("\n\t\t\t\t_______________________________________________________________\n");
            printf("\t\t\t\t|           %s  SELECTED %d POSITION                            |\t", ch, un);
            printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
            Sleep(1000);
            first--;
        }
        else
        {
            system("color 2");
            un = rand() % 10;
            gotoxy(0, 20);
            printf("\n\t\t\t\t_______________________________________________________________\n");
            printf("\t\t\t\t|           %s  SELECTED %d POSITION                           |\t", ch1, un);
            printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
            Sleep(1000);
            first--;
        }
    }
    pos = un;
    pos--;
    found = 0;
    for (j = 0; j < 9; j++)
    {
        if (j == pos)
        {
            if (a[j] == 'X' || a[j] == 'O')
            {
                found = 0;
                invalid = 0;
            }
            else
            {
                found++;
                break;
            }
        }
        else
            found == 0;
    }
    if (pos >= 9)
    {
        system("cls");
        show();
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                 INVALID POSITION                            |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        invalid++;
        if (first_pos % 2 == 0)
            first += 1;
        else
            first += 2;
        goto top;
    }
    if (found == 0)
    {
        system("cls");
        show();
        gotoxy(0, 23);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|            THIS POSITION IS ALREADY USE                       |\t\n");
        printf("\t\t\t\t|            PLEASE USE ANOTHER POSITION                        |\t");
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        invalid++;
        if (first_pos % 2 == 0)
            first += 1;
        else
            first += 2;
        system("cls");
        show();
        goto top;
    }
    pui(pos);
    count++;
}

void computer_to_computer()
{
    int i, rando;
    count = 0;
    system("color 8f && cls");
    intro();
    player(3);
lab:
    rando = rand() % 3;
    if (rando == 0)
        goto lab;
    else
        first = rando;
maintop:
    system("cls");
    show();
    com_input(2);
    system("cls");
    show();
top:
    i = logic();
    if (i == 100)
    {
        system("color 9");
        Beep(1200, 450);
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |\n", ch);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (i == 200)
    {
        system("color 9");
        Beep(1200, 450);
        gotoxy(0, 20);
        printf("\a\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  %s WON THIS GAME                           |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
    }
    else if (count == 9)
    {
        system("color d");
        Beep(3100, 500);
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                  GAME DRAWED                                |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n");
        char jo;
        Beep(2100, 900);
        gotoxy(0, 20);
        printf("\n\t\t\t\t_______________________________________________________________\n");
        printf("\t\t\t\t|                PRESS Y FOR TO PLAY AGAIN                     |", ch1);
        printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
        scanf("%c", &jo);
        if (jo == 'y' || jo == 'Y')
        {
            a[0] = '1';
            a[1] = '2';
            a[2] = '3';
            a[3] = '4';
            a[4] = '5';
            a[5] = '6';
            a[6] = '7';
            a[7] = '8';
            a[8] = '9';
            goto maintop;
        }
    }
    else
    {
        com_input(2);
        i = logic();
        system("color 2e && cls");
        show();
        goto top;
    }
    ask();
}
void gotoxy(int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
