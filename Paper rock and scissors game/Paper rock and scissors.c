/* This program is designed to prepare a game of paper rock and scissors between two player */
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int player;
player user,computer;
int menu();
void intro();
void logic(char []);
int main(){
    char ch[30];
    system("color 3f");
    printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                                                                |\n");
    printf("\t\t|                    ENTER YOUR NAME PLEASE                      |\n");
    printf("\t\t|                                                                |");
    printf("\n\t\t------------------------------------------------------------------\n");
    fflush(stdin);
    gets(ch);
    while(1)
    {   system("color 2f && cls");
        intro();
        logic(ch);
        getche();
    }

}
int  menu(){
    int n;
    printf("\n\t\t__________________________________________________________________\n");
    printf("\t\t|             PLEASE SELECT YOUR CHOICE                           |\n");
    printf("\t\t|                  1:- ROCK                                       |\n");
    printf("\t\t|                  2:- PAPER                                      |\n");
    printf("\t\t|                  3:- SCISSORS                                   |\n");
    printf("\t\t|                  4:- EXIT                                       |");
    printf("\n\t\t-------------------------------------------------------------------\n\t");
scanf("%d",&n);
return n;
}
void logic(char ch[])
{     no:
    computer=rand()%4;
    if(computer==0)
        goto no;
    user=menu();
    switch(user)
    {
    case 1:  //user===Rock
        if(computer==1)  //user=rock computer==rock
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                      GAME DRAW                              |\n");
    printf("\t\t|                   %s==ROCK                                  |\n",ch);
    printf("\t\t|                   COMPUTER==ROCK                            |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else if(computer==2) //user==rock computer== paper
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                   COMPUTER WON                                 |\n");
    printf("\t\t|                   %s==ROCK                                     |\n",ch);
    printf("\t\t|                   COMPUTER==PAPER                               |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else //user==rock computer==scissors
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                      %s WON                                 |\n",ch);
    printf("\t\t|                   %s==ROCK                                  |\n",ch);
    printf("\t\t|                   COMPUTER==SCISSORS                        |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        break;
    case 2: // user==Paper
        if(computer==1)  //user=Paper computer==rock
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                    %s WON                                     |\n",ch);
    printf("\t\t|                   %s==PAPER                                  |\n",ch);
    printf("\t\t|                   COMPUTER==ROCK                              |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else if(computer==2) //user==paper computer== paper
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                   GAME DRAW                                     |\n");
    printf("\t\t|                   %s==PAPER                                  |\n",ch);
    printf("\t\t|                   COMPUTER==PAPER                           |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else // user==Paper computer==scissors
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                    COMPUTER WON                           |\n");
    printf("\t\t|                   %s==PAPER                                  |\n",ch);
    printf("\t\t|                   COMPUTER==SCISSORS                           |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        break;
    case 3: //user=scissors
        if(computer==1)  //user=scissors computer==rock
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                    COMPUTER WON                           |\n");
    printf("\t\t|                   %s==SCISSORS                            |\n",ch);
    printf("\t\t|                   COMPUTER==ROCK                           |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else if(computer==2) //user==Scissors computer== paper
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                    %s WON                                  |\n",ch);
    printf("\t\t|                   %s==SCISSORS                            |\n",ch);
    printf("\t\t|                   COMPUTER==PAPER                           |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
        else // user==Scissors computer==scissors
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                    GAME DRAW                                  |\n");
    printf("\t\t|                   %s==SCISSORS                               |\n",ch);
    printf("\t\t|                   COMPUTER==SCISSORS                           |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
            break;

    case 4: // compter exit
   {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                  THANKS %s                                  |\n",ch);
    printf("\t\t|                    FOR                                      |\n");
    printf("\t\t|                 PLAYING OUR GAME                             |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }
    exit(0);
        break;
    default:
    {printf("\n\t\t________________________________________________________________\n");
    printf("\t\t|                                                                |\n");
    printf("\t\t|                    INVALID OPTIONS                             |\n");
    printf("\t\t|                                                                |");
    printf("\n\t\t------------------------------------------------------------------\n");
    }

    }

}
void intro()
{   printf("\n\t\t_____________________________________________________________\n");
    printf("\t\t|***********************************************************|\n");
    printf("\t\t|***********************************************************|\n");
    printf("\t\t|***********************************************************|\n");
    printf("\t\t|************Welcome to Paper rock and scissors game********|\n");
    printf("\t\t|***********************************************************|\n");
    printf("\t\t|***********************************************************|\n");
    printf("\t\t|***********************************************************|");
    printf("\n\t\t--------------------------------------------------------------\n");
}

