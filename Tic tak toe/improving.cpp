/* Write a program to desinged  a game like a tic toe tak */
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
char ch[10],ch1[10],a[9]={'1','2','3','4','5','6','7','8','9'};
int count=0;
char first;
void show();
void intro();
void player();
int turn();
void sym();
int logic();
void firs_turn();
void ask();
void pui(int);


int main()
{   int i;
    count=0;
    system("color 8f");
    intro();
    player();
    maintop:
    firs_turn();
    system("color 2e && cls");
    show();
    system("color 3e");
      sym();
      system("color 2e && cls");
      show();
      top:
      i=logic();
     if(i==100)
    {system("color 9");
Beep(1200,450);
Beep(1900,400);
Beep(2000,300);
Beep(2100,200);
    printf("\a\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|                  %s WON THIS GAME                           |\n",ch);
    printf("\n\t\t\t\t---------------------------------------------------------------\n");
         }
    else if(i==200){
    system("color 9");
Beep(1200,450);
Beep(1900,400);
Beep(2000,300);
Beep(2100,200);
    printf("\a\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|                  %s WON THIS GAME                           |",ch1);
    printf("\n\t\t\t\t---------------------------------------------------------------\n");
}
    else if(count==9){
    system("color d");
    Beep(3100,500);
   printf("\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|                  GAME DRAWED                                |",ch1);
    printf("\n\t\t\t\t---------------------------------------------------------------\n");
    char jo;
    Beep(2100,900);
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|                PRESS Y FOR TO PLAY AGAIN                     |",ch1);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
fflush(stdin);
scanf("%c",&jo);
   if(jo=='y' || jo=='Y'){
    a[0]='1';
   a[1]='2';
   a[2]='3';
   a[3]='4';
   a[4]='5';
   a[5]='6';
   a[6]='7';
   a[7]='8';
   a[8]='9';
   goto maintop;

}   }
    else{
        sym();
        i=logic();
       system("color 2e && cls");
        show();
        goto top;
    }
    ask();

}


void show()
{
    printf("\n\t\t\t\t##########################################\n");
    printf("\t\t\t\t#|--------------------------------------|#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c   |#\n",a[0],a[1],a[2]);
    printf("\t\t\t\t#|------------!---------------!---------|#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c   |#\n",a[3],a[4],a[5]);
    printf("\t\t\t\t#|------------!---------------!---------|#\n");
    printf("\t\t\t\t#|    %c       !      %c        !     %c   |#\n",a[6],a[7],a[8]);
    printf("\t\t\t\t#|____________!_______________!_________|#");
    printf("\n\t\t\t\t##########################################\n\t");
    printf("\n\t\tPlayer 1:%s =X",ch);
    printf("\n\t\tPlayer 2:%s =O",ch1);
}


int logic(){
if((a[0]=='X' && a[1]=='X' && a[2]=='X')|| (a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[6]=='X' && a[7]=='X' && a[8]=='X'))
return 100;
else if((a[0]=='O' && a[1]=='O' && a[2]=='O')|| (a[3]=='O' && a[4]=='O' && a[5]=='O') || (a[6]=='O' && a[7]=='O' && a[8]=='O'))
return 200;
else if( (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[2]=='X' && a[5]=='X' && a[8]=='X'))
    return 100;
else if( (a[0]=='O' && a[3]=='O' && a[6]=='O') || (a[1]=='O' && a[4]=='O' && a[7]=='O') || (a[2]=='O' && a[5]=='O' && a[8]=='O'))
    return 200;
else if( (a[0]=='X' && a[4]=='X' && a[8]=='X') || (a[2]=='X' && a[4]=='X' && a[6]=='X') )
return 100;
else if( (a[0]=='O' && a[4]=='O' && a[8]=='O') || (a[2]=='O' && a[4]=='O' && a[6]=='O'))
return 200;
}


void intro(){
    printf("\a\n\t\t\t\t_______________________________________________________________\n");
    printf("\t\t\t\t|                                                             |\n");
    printf("\t\t\t\t|                  WELCOME TO TIC TAK TOE GAME                |\n");
    printf("\t\t\t\t|                                                             |");
    printf("\n\t\t\t\t---------------------------------------------------------------\n");
}


void ask(){
char jo;
Beep(1500,400);
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|                PRESS Y FOR TO PLAY AGAIN                     |",ch1);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
fflush(stdin);
scanf("%c",&jo);
   if(jo=='y' || jo=='Y'){
    a[0]='1';
   a[1]='2';
   a[2]='3';
   a[3]='4';
   a[4]='5';
   a[5]='6';
   a[6]='7';
   a[7]='8';
   a[8]='9';
   system("cls");
   main();
   }
}


void player(){
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


void sym()
{ int n,pos,j,found;
    top:
        n=turn();
    if(n==100){
system("color b");
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|           %s  ENTER THE POSITION                             |\t",ch);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        first--;
    }
    else{
            system("color 2");
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|           %s  ENTER THE POSITION                             |\t",ch1);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    first--;
    }
fflush(stdin);
 scanf("%d",&pos);
pos--;
found=0;
    for(j=0; j<9; j++){
    if(j==pos){
        if(a[j]=='X' || a[j]=='O')
           found=0;
    else{
    found++;
    break;}
    }
    else
found==0;
}
 if(pos>=9){system("cls");
 show();
 Beep(300,800);
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|                 INVALID POSITION                            |\t");
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
        fflush(stdin);
goto top;
    }
if(found==0)
{   system("cls");
    show();
    Beep(500,800);
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
{  int j;
    top:
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|           WHO WANT TO START THE GAME???????                  |\n",ch);
printf("\t\t\t\t|               PRESS 1 FOR %s\t\t2 FOR %s                \t",ch,ch1);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    fflush(stdin);
    first=kbhit();
    if(first%2!=0){
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|           %s  FIRST TURN IS YOUR                            |\t",ch);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    }
    else if(first%2==0)
{
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|           %s  FIRST TURN IS YOUR                            |\t",ch1);
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    }
    else
{ system("color 4 && cls");
Beep(300,800);
printf("\n\t\t\t\t_______________________________________________________________\n");
printf("\t\t\t\t|                 INVALID OPTIONS                             |\t");
printf("\n\t\t\t\t---------------------------------------------------------------\n\t");
    goto top;
    }
}
void pui(int p){
int i,n;
n=turn();
if(n==99){
    for(i=0; i<9; i++)
    if(p==i)
        a[i]='O';
}

else if(n==100){
   for(i=0; i<9; i++)
    if(p==i)
        a[i]='X';
}
}

int turn(){
    if(first%2==0){
            first++;
       return 99;
    }
    else{first++;
        return 100;
        }
}
