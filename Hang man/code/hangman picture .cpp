#include<stdio.h>
#include<graphics.h>
 int gd=DETECT,gm;
 int x=200,y=100;
void face();
void body();
void hand();
void leg();
int main()
{
    initgraph(&gd,&gm,"");
    face();
    body();
    hand();
    leg();
    getch();
    closegraph();
}

void face()
{
    int r=50;
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    setfillstyle(3,RED);
    circle(x,y,r);
    setfillstyle(SOLID_FILL,RED);
    circle(x-22,y-15,r/10);
    circle(x+15,y-15,r/10);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(x-2,y,x,y-4);
    arc(x,y+18,180,0,20);


}
void body()
{  int top=180,left=150,right=250,bottom=370;
    x=190;y=150;
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
     setfillstyle(SOLID_FILL,RED);
     line(x,y,x,y+30);
     line(x+15,y,x+15,y+30);
     rectangle(left,top,right,bottom);
}
void hand(){
x=150;y=200;
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
line(x,y,40,y+50);
line(x+100,y,x+200,y+50);
}
void leg()
{   x=180,y=360;
setlinestyle(SOLID_LINE,1,THICK_WIDTH);
    line(x,y+10,x,460);
    setlinestyle(SOLID_LINE,1,THICK_WIDTH);
    line(x+40,y+10,x+40,460);
     setfillstyle(SOLID_FILL,RED);

}
