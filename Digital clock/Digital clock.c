/* This project is to work as a stopwatch , timer , clock*/
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
struct element{
int hrs,min,sec}ele;
void stopwatch(struct element);
void timer(struct element );
void clock(struct element);
int main(void)
{ int n;
    printf("\n...... 1 Press for Stopwatch ");
    printf("\n...... 2 Press for Timer ");
    printf("\n...... 3 Press for Clock ");
    printf("\n...... 4 Press for exit ");
    scanf("%d",n);
    switch(n)
    {
    case 1:
        stopwatch();
        break;
    case 2:
        timer();
        break;
    case 3:
        clock();
        break;
    case 4:
        printf("\n Terminating Terminating ....");
        exit(0);
    }
}

void stopwatch()
{
	
}

void timer()
{
}

void clock()
{
	
}


