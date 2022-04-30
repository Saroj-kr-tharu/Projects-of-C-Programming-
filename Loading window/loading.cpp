/* Write a program to show the loading */
#include<stdio.h>
#include<graphics.h>
int main()
{   int gd=DETECT,gm=0,x,y,a,i,error;
    initgraph(&gd,&gm,"");
    error=graphresult();
    if(error!=grOk)
    {    printf("\nUnable to start the graphics system of computer\t");
        exit(1);
    }
    x=getmaxx()/2;
    y=getmaxy()/2;
    setcolor(WHITE);
    setlinestyle(0,30,THICK_WIDTH);
    rectangle(x-200,y-10,x+100,y+30);
    setcolor(WHITE);
    setlinestyle(0,10,THICK_WIDTH);
    a=x-196;
    for(i=0; i<300; i+=5)
    {  Sleep(70);
     settextstyle(SANS_SERIF_FONT,1,3);
    outtextxy(300,220,"LOADING....");
        line(a+i,y-10,a+i,y+30);
    if(i==295)
    { printf("\a");
        settextstyle(SANS_SERIF_FONT,1,3);
        outtextxy(430,300,"SUCCESSFULLY COMPLETED");
    }

    }
    getch();
    closegraph();
}
