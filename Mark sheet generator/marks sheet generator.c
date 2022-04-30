/* Write a program to designed the mark sheet generator designed by Saroj kumar tharu */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct student
{
    int clas, roll;
    float eng, math, che, phy, com, total, percentage;
    char name[30], grade[2];

} stu;
void menu();
void grade(float);
void add_student();
void display();
void destory();
void search();
void delete ();
void edit();
FILE *src, *ptr;
int main()
{
    while (1)
    {
        system("cls");
        menu();
        getche();
    }
}
void menu()
{
    int n;
    printf("\n\t\t__________________________________________________________________\n");
    printf("\t\t|             PLEASE SELECT YOUR CHOICE                           |\n");
    printf("\t\t|                  1:- ADD STUDENT                                |\n");
    printf("\t\t|                  2:- EDIT                                       |\n");
    printf("\t\t|                  3:- DELETE                                     |\n");
    printf("\t\t|                  4:- DISPLAY                                    |\n");
    printf("\t\t|                  5:- SEARCH                                     |\n");
    printf("\t\t|                  0:- DESTORY ALL RECORDS                        |\n");
    printf("\t\t|                  9:- EXIT                                       |");
    printf("\n\t\t-------------------------------------------------------------------\n\t");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        fflush(stdin);
        add_student();
        break;
    case 2:
        fflush(stdin);
        edit();
        break;
    case 3:
        delete ();
        break;
    case 4:
        display();
        break;
    case 5:
        search();
        break;
    case 9:
        printf("\n\t\t________________________________________________________________\n");
        printf("\t\t|                  THANKS                                    |\n");
        printf("\t\t|                    FOR                                     |\n");
        printf("\t\t|                 USING OUR PROGRAM                          |");
        printf("\n\t\t------------------------------------------------------------------\n");
        exit(0);
        break;
    case 0:
        destory();
        break;
    default:
        fflush(stdin);
        printf("\n\t\t <----- Invalid options ----->");
    }
}

void add_student()
{
    src = fopen("file.txt", "a");
    if (src == NULL)
        src = fopen("file.txt", "w");
    float total;
    char ch;
    fflush(stdin);
    printf("\n\t\tEnter the name of student ------> ");
    gets(stu.name);
    // strcpy(c,stu.name);
    fflush(stdin);
    printf("\t\tEnter the class of %s ", stu.name);
    printf(" ------>");
    scanf("%d", &stu.clas);
    printf("\t\tEnter the roll no of %s ", stu.name);
    printf(" ------>");
    scanf("%d", &stu.roll);
    printf(" \t\t Enter the marks of english-math-chemistry-physics-computer of %s ", stu.name);
    printf(" ------>");
    scanf("%f-%f-%f-%f-%f", &stu.eng, &stu.math, &stu.che, &stu.phy, &stu.com);
    stu.total = stu.eng + stu.math + stu.che + stu.phy + stu.com;
    stu.percentage = stu.total / 5;
    grade(stu.percentage);

    printf("\n\t\t_________________________________________");
    printf("\n\a\t\tFor your revieve\n");
    printf("\n\t\tName of student           ----> %s", stu.name);
    // printf("\n\t\tName of student         ----> \t%s",c);
    printf("\n\t\tRoll no of %s             ----> %d", stu.name, stu.roll);
    printf("\n\t\tClass of %s               ----> %d", stu.name, stu.clas);
    printf("\n\t\tMarks in english          ----> %.2f", stu.eng);
    printf("\n\t\tMarks in  math            ----> %.1f", stu.math);
    printf("\n\t\tMarks in Chemistry        ----> %.2f", stu.che);
    printf("\n\t\tMarks in  Physics         ----> %.2f", stu.phy);
    printf("\n\t\tMarks in Computer         ----> %.2f", stu.com);
    printf("\n\t\tPercentage of %s          ----> %.1f", stu.name, stu.percentage);
    printf("\n\t\tTotal marks of %s         ----> %.1f", stu.name, stu.total);
    printf("\n\t\tGrade marks of %s         ----> %s", stu.name, stu.grade);
    printf("\n\t\t----------------------------------------- ");
    printf("\n <------- Press y for to cancel and other key for to registered ----->");
    fflush(stdin);
    //strcpy(stu.name,c);
    //scanf("%c",&ch);
    ch=getch();
    if(ch!='y' || ch=='Y'){
        if (fwrite(&stu, sizeof(stu), 1, src) == 1)
            printf("\n <---- Successfully registred ----->");
    }
    else{
        printf("\n <---- Successfully not registred ----->");
     }
    fclose(src);
}
void search()
{
    src = fopen("file.txt", "r");
    int found = 0, id;
    printf("\n\t\t <------- Enter the roll no to be searched ------->");
    scanf("%d", &id);
    while (fread(&stu, sizeof(stu), 1, src) == 1)
        if (stu.roll == id)
        {
            printf("\n\t\t_________________________________________");
            found++;
            printf("\n\a\t\t <------ For your revieve ------> ");
            printf("\n\t\tName of student           -----> %s", stu.name);
            printf("\n\t\tRoll no of %s             -----> %d", stu.name, stu.roll);
            printf("\n\t\tClass of %s               -----> %d", stu.name, stu.clas);
            printf("\n\t\tMarks in english          -----> %.2f", stu.eng);
            printf("\n\t\tMarks in  math            -----> %.1f", stu.math);
            printf("\n\t\tMarks in Chemistry        -----> %.2f", stu.che);
            printf("\n\t\tMarks in  Physics         -----> %.2f", stu.phy);
            printf("\n\t\tMarks in Computer         -----> %.2f", stu.com);
            printf("\n\t\tPercentage of %s          -----> %.1f", stu.name, stu.percentage);
            printf("\n\t\tTotal marks of %s         -----> %.1f", stu.name, stu.total);
            printf("\n\t\tGrade marks of %s         -----> %s", stu.name, stu.grade);
            printf("\n\t\t-----------------------------------------\n");
        }

    if (found == 0)
        printf("\n\t\t <-------- NO records is exit please enter valid rollno ------>");

    fclose(src);
}
void display()
{
    src = fopen("file.txt", "r");
    int found = 0;
    printf("\n\t\t___________________________________________________________________________________");
    printf("\n\t\tName\t\t\t\tclass\t\tRollno\t\tGrade");
    while (fread(&stu, sizeof(stu), 1, src) == 1)
    {
        found++;
        printf("\n\t\t%s\t\t\t\t%d\t\t%d\t\t%s", stu.name, stu.clas, stu.roll, stu.grade);
    }
    printf("\n\t\t--------------------------------------------------------------------------------------\n");
    if (found == 0)
        printf("\n\t\t <------- No any records exit ------>");
    fclose(src);
}
void grade(float per)
{
    char ch[3];
    if (per > 90 && per <= 100)
        strcpy(stu.grade, "A+");

    else if (per > 80 && per <= 90)
        strcpy(stu.grade, "A");

    else if (per > 70 && per <= 80)
        strcpy(stu.grade, "B+");

    else if (per > 60 && per <= 70)
        strcpy(stu.grade, "B");

    else if (per > 50 && per <= 60)
        strcpy(stu.grade, "C+");

    else if (per > 40 && per <= 50)
        strcpy(stu.grade, "C");

    else if (per > 30 && per <= 40)
        strcpy(stu.grade, "D+");

    else if (per > 20 && per <= 30)
        strcpy(stu.grade, "D");

    else // per>10 && per<=30
        strcpy(stu.grade, "E+");
}
void destory()
{
    char ch;
    printf("\n\t\t <------- Warning you are going to destroyed all exited records -----> \n\t\t <------ Press y for to cancel -------->\t");
    fflush(stdin);
    // scanf("%c",&ch);
    ch = getch();
    if (ch == 'y' || ch == 'Y')
    {
        printf("\n\t\t <---- Sccessfully cacell ------>");
        goto end;
    }
    else
        printf("\n\t\t <----- Successfully destoryed all records ------> ");
    src = fopen("file.txt", "w");
end:
    fclose(src);
}

void edit()
{
    src = fopen("file.txt", "r+");
    int found = 0, records, id;
    float i;
    char ad[30], na[40];
    printf("\n  Enter the rollno to edit ");
    printf(" ------> ");
    scanf("%d", &id);
    records = -1;

    while ((fread(&stu, sizeof(stu), 1, src)) == 1)
    {
        if (stu.roll == id)
        {
            found++;
            printf("\n <----- Successfully found ----->");
            printf("\n\t\t_________________________________________");
            printf("\n\a\t\t<----- For your revieve ----->");
            printf("\n\t\tName of student           :-\t%s", stu.name);

            printf("\n\t\tRoll no of %s             ----> %d", stu.name, stu.roll);
            printf("\n\t\tClass of %s               ----> %d", stu.name, stu.clas);
            printf("\n\t\tMarks in english          ----> %.2f", stu.eng);
            printf("\n\t\tMarks in  math            ----> %.1f", stu.math);
            printf("\n\t\tMarks in Chemistry        ----> %.2f", stu.che);
            printf("\n\t\tMarks in  Physics         ----> %.2f", stu.phy);
            printf("\n\t\tMarks in Computer         ----> %.2f", stu.com);
            printf("\n\t\tPercentage of %s          ----> %.1f", stu.name, stu.percentage);
            printf("\n\t\tTotal marks of %s         ----> %.1f", stu.name, stu.total);

            printf("\n\t\tGrade marks of %s         :-\t%s", stu.name, stu.grade);

            printf("\n\t\t-----------------------------------------");

            printf("\n\t\tEnter the new name of %s -----> ", stu.name);
            fflush(stdin);
            gets(stu.name);
            printf("\n\t\tEnter the roll no of %s -----> ", stu.name);
            scanf("%d", &stu.roll);
            printf("\n\t\tEnter the class of %s -----> ", stu.name);
            scanf("%d", &stu.clas);
            printf("\n\t\t  Enter the marks of english-math-chemistry-physics-computer of %s\t", stu.name);
            printf(" ------>");
            scanf("%f-%f-%f-%f-%f", &stu.eng, &stu.math, &stu.che, &stu.phy, &stu.com);
            stu.total = stu.eng + stu.math + stu.che + stu.phy + stu.com;
            stu.percentage = stu.total / 5;
            grade(stu.percentage);
            fseek(src, sizeof(struct student) * (records), SEEK_CUR);
            if ((fwrite(&stu, sizeof(stu), 1, src)) == 1)
            {
                printf("\n \t\t <----- Modified successfully in the file -------->");
                break;
            }
            // records++;
        }
    }
    if (found == 0)
        printf("\n\t\t <------- Unable to find the information -------> \t");
    getche();
    fclose(src);
}

void delete ()
{
    src = fopen("file.txt", "r");
    ptr = fopen("temp.txt", "w");
    int found, id;
    printf("\n\t\t  Enter the rollno to delete -------> \t");
    scanf("%d", &id);
    found = 0;
    printf("\n\t\t___________________________________________________________________________________");
    printf("\n\t\tName\t\t\t\tclass\t\tRollno\t\tGrade");
    while ((fread(&stu, sizeof(stu), 1, src)) == 1)
        if (stu.roll != id)
            fwrite(&stu, sizeof(stu), 1, ptr);
        else
        {
            found++;
            printf("\n\t\t%s\t\t\t\t%d\t\t%d\t\t%s", stu.name, stu.clas, stu.roll, stu.grade);
            printf("\n\t\t--------------------------------------------------------------------------------------\n");
        }
    fclose(src);
    fclose(ptr);
    src = fopen("file.txt", "w");
    ptr = fopen("temp.txt", "r");
    while ((fread(&stu, sizeof(stu), 1, ptr)) == 1)
        fwrite(&stu, sizeof(stu), 1, src);
    if (found == 0)
        printf("\n\t\t <------- The records is not founded ------>\n");
    else
        printf("\n\t\t <----- Successfully Deleted ------>");
    getche();
    fclose(src);
    fclose(ptr);
}
