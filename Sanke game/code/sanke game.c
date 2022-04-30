/* Write a program to designed snake game */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
int width=74,height=22; // height and width of the frame
int x,y;  // intialization of the snake head coordinate
int fx,fy; // variable for the food coordinate
int score,flag,gameover=0;
int tailX[100],tailY[100],count=0,speed=210; // variable for to store tail
char user_name[30];
enum direction{up=1,down,right,left,switchoff=99}; //
void display();
void  input();
void setup();
void logic();
void help();
void user_intro();
void start();
void menu();
void highsore();
void gen_food();
int main(void)
{  while(1)
     menu();

}
void start(){
	int i,j,k;
    setup();
    gen_food();
    display();
    while(!gameover){
        input();
        logic();
        display();
        Sleep(speed);
        
    }
    system("cls");
    char str[30];
    int sc;
    FILE *src;
        src=fopen("D:/C programming/Project of c/Sanke game/fike/score.txt","w+");
        fscanf(src,"\n\t\t%s\t\t%d",str,&sc);
        rewind(src);
        if(score>sc)
        fprintf(src,"\n%s\t\t%d",user_name,score);
    printf("\n\t\t%s\tGame over\n\t\tSCORE==%d\n",user_name,score);
    fclose(src);
    system("pause");
}
void display(){
int col,row,k,ch;
system("cls");
for(col=1;col<=height; col++){
    for(row=1; row<=width; row++){
        if( col==1 || col==height  || row==1 || row==width)
             printf("*");
        else if(row==x && y==col)
        printf("%c",2);
        else if(row==fx && col==fy)
            printf("%c",3);
        else if(x==fx && y==fy){
            score+=10;
            count++;
            gen_food();
			speed-=50;}
        else if(x<2 || (x>width-2) || y<2 || (y>height-2)  )
            gameover=1;
        else{ for(k=0; k<count; k++){
            if(row==tailX[k] && col==tailY[k])
               { printf("%c",1);
                  goto joker;
               }
                }
             printf(" ");
        joker:
            score++;
            score--;
        }

        }
        printf("\n");
}
printf("\n\t\tSCORE=%d",score);
}

void gen_food(){
label:
fx=rand()%75;
if(fx==1)
    goto label;
    labe:
fy=rand()%24;
if(fy==1)
    goto labe;
}
void setup(){
x=74/2,y=22/2;
score=0;
gameover=0;
count=0;
speed=210;
gen_food();
}
void input()
{  
    if(kbhit())
    switch(getch()){
case 'a':
    flag=left;
    break;
case 'w':
flag=up;
    break;
case 'j':
  flag=right;
break;
case 'n':
    flag=down;
break;
case 'x':
    flag=switchoff;
break;
    }

}

void logic()
{  int i,prex=tailX[0],prey=tailY[0],prex2,prey2;
    tailX[0]=x;
    tailY[0]=y;
    for(i=1; i<count; i++){
        prex2=tailX[i];
        prey2=tailY[i];
        tailX[i]=prex;
        tailY[i]=prey;
        prex=prex2;
        prey=prey2;
    }
     switch(flag){
case left:
    x--;
    break;
case up:
    y--;
    break;
case right:
    x++;
break;
case down:
    y++;
break;
case switchoff:
    menu();
break;
    }
    for(i=0; i<count; i++)
        if(x==tailX[i] && y==tailY[i])
        gameover=1;
    
}

void menu()
{   int n;
system("cls");
    printf("\n\t\t\tPlease enter your options\n\t\t1:- Start\n\t\t2:- High socre\n\t\t3:- Exit\n\t\t4:- help\t");
    scanf("%d",&n);
    switch(n){
case 1:
    user_intro();
    start();
    break;
case 2:
    highsore();
    break;
case 3:
    printf("\n%s Thanks for using our game",user_name);
    exit(0);
    break;
case 4:
    help();
    break;
default:
    printf("Invalid options");
    fflush(stdin);
    main();
}
}
void user_intro(){
printf("\n\t\tEnter your name please\t");
fflush(stdin);
gets(user_name);
}
void highsore()
{ char name[30];
    int j;
      FILE *src;
    src=fopen("D:/C programming/Project of c/Sanke game/fike/score.txt","r");
        fscanf(src,"\n%s\t\t%d",name,&j);
        printf("\n\t\tHighest score is %d holded by %s",j,name);
        fclose(src);
        getche();
}
void help(){
    system("color 2f");
    printf("\n\t\t__________________________________________________________________\n");
    printf("\t\t|                                                                |\n");
    printf("\t\t|                   DEVELOPER SAROJ KUMAR THARU                  |\n");
    printf("\t\t|  This game is controlled by 4 key with the features of storing |\n");
    printf("\t\t|  highest score with the user name . The keys are:-             |\n");
    printf("\t\t|  1:- a for moving left                                         |\n");
    printf("\t\t|  2:- w for moving up                                           |\n");
    printf("\t\t|  3:- j for moving right                                        |\n");
    printf("\t\t|  4:- n for moving down                                         |\n");
    printf("\t\t|  5:- x for moving main menu                                    |\n");
    printf("\t\t|  :O: means the head of the snake  and small :: means the      |\n");
    printf("\t\t|  snake of the body where as :f: means food .The highest score  |\n");
    printf("\t\t|  is store in the game folder of file folder.                   |\n");
    printf("\t\t------------------------------------------------------------------\n");
    printf("\t\t|  any problem  contact me                                       |\n");
    printf("\t\t|       Email                   Phone              Facebook      |\n");
    printf("\t\t|  sarojc034@gmail.com        9804517468        Dark knight net  |\n");
    printf("\t\t|                                                                |");
    printf("\n\t\t------------------------------------------------------------------\n");
    system("pause");
}
