/* Write a program to make a phone book */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct phone
{
    char name[30], add[50];
    float phone;
    int id;
} ph;

void menu();
void input();
void display();
void search();
void edit();
void delete ();
void destory();
void intro();
void quick(int, int);
COORD coord = {0, 0}; // sets coordinates to 0,0
// COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    while (1)
    {
        system("color 8f && cls");
        intro();
        Sleep(900);
        system("color 0f");
        menu();
    }
}
void menu()
{
    int n;
    printf("\n\t\t <-------- Please select your options ------> ");
   // printf("\n0:- EXIT\n1:- INPUT\n2:- ADD\n3:- SEARCH\n4:- DISPLAY\n5:- EDIT\n6:- DELETE\n9:- DESTORY ALL RECORDS\t");
    printf("\n\t\t <-------- 0 . EXIT ---->");
    printf("\n\t\t <-------- 1 . INPUT ---->");
    printf("\n\t\t <-------- 2 . ADD ---->");
    printf("\n\t\t <-------- 3 . SEARCH ---->");
    printf("\n\t\t <-------- 4 . DISPLAY ---->");
    printf("\n\t\t <-------- 5 . EDIT ---->");
    printf("\n\t\t <-------- 6 . DELETE ---->");
    printf("\n\t\t <-------- 9 . DESTORY ---->");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        system("color 3e && cls");
        input();
        break;
    case 2:
        input();
        break;
    case 3:
        system("color 9e && cls");
        search();
        break;
    case 4:
        system("color 2e && cls");
        display();
        break;
    case 5:
        system("color d");
        edit();
        break;
    case 6:
        system("color 9");
        delete ();
        break;
    case 9:
        system("color b");
        destory();
        break;
    case 0:
        system("color 2");
        printf("\n\t\t <------------ Thanks for using our program ------>");
        exit(0);
        break;
    default:
        system("color 8e");
        printf("\n\t\t <----- INVALID OPTIONS -----> ");
        break;
    }
}

void input()
{
    FILE *src;
    src = fopen("phone.txt", "a+");
    if (src == NULL)
        src = fopen("phone.txt", "w+");
    char ch;
    do
    {
        printf("\n\t\t  Enter the name of guest ---->");
        fflush(stdin);
        gets(ph.name);
        printf("\n\t\t  Enter the address of %s ---->", ph.name);
        gets(ph.add);
        printf("\n\t\t  Enter the phone number of %s ---->", ph.name);
        scanf("%f", &ph.phone);
        if ((fwrite(&ph, sizeof(ph), 1, src)) == 1)
            printf("\n\t\t <----- Successfully written");
        printf("\n\t\t <----- Press y for to add more ---->");
        fflush(stdin);
        //scanf("%c", &ch);
         ch=getch();
    } while (ch == 'y' || ch == 'Y');
    fclose(src);
}
void display()
{
    FILE *src;
    src = fopen("phone.txt", "r");
    printf("\nName of guest\t\t\tAddress\t\t\tPhone number\n");
    while ((fread(&ph, sizeof(ph), 1, src)) == 1)
        printf("%s\t\t%s\t\t\t%.1f\n", ph.name, ph.add, ph.phone);
    getche();
    fclose(src);
}

void search()
{
    FILE *src;
    src = fopen("phone.txt", "r");
    char ch, ad[30], na[40];
    int found = 0;
    float i;
    printf("\n\t\t <----- Note that if you don't have required information just press any worng info to skip ---->");
    printf("\n \t\t Enter the name to search ----> ");
    fflush(stdin);
    gets(na);
    printf("\n \t\t Enter the address to %s ----> ", na);
    gets(ad);
    printf("\n \t\t Enter the phone number of %s ----> ", na);
    scanf("%f", &i);
    system("color 2e");
    printf("\nName of guest\t\t\tAddress\t\t\tPhone number\n");
    while ((fread(&ph, sizeof(ph), 1, src)) == 1)
        if ((strcmp(strlwr(ph.add), strlwr(ad)) == 0) || (ph.phone == i) || (strcmp(strlwr(ph.name), strlwr(na)) == 0))
        {
            printf("%s\t\t%s\t\t\t%.1f\n", ph.name, ph.add, ph.phone);
            found++;
        }
    if (found == 0) 
        printf("\n\t\t<-----  Unable to find the information --->");
    printf("\n\t\t <----- Total information are \t%d --->", found);
    getche();
    fclose(src);
}
void edit()
{
    FILE *src, *ptr;
    src = fopen("phone.txt", "r+");
    int found = 0, records;
    float i;
    char ad[30], na[40];
    printf("\n\t\t Enter the number to edit ------>");
    scanf("%f", &i);
    records = -1;
    system("color 2e");
    printf("\nName of guest\t\t\tAddress\t\t\tPhone number\n");
    while ((fread(&ph, sizeof(ph), 1, src)) == 1)
    {
        if (ph.phone == i)
        {
            found++;
            printf("\nSuccessfully found\n");
            printf("%s\t\t%s\t\t\t%.1f\n", ph.name, ph.add, ph.phone);
            system("color d");
            printf("\nEnter the new name ------>");
            fflush(stdin);
            gets(ph.name);
            printf("\nEnter the address of %s ------>", ph.name);
            gets(ph.add);
            printf("\nEnter the phone number of %s ------>", ph.name);
            scanf("%f", &ph.phone);
            fseek(src, sizeof(struct phone) * (records), SEEK_CUR);
            if ((fwrite(&ph, sizeof(ph), 1, src)) == 1)
            {
                printf("\n\t\t <------- Modified successfully in the file -------->");
                break;
            }
            // records++;
        }
    }
    if (found == 0)
        printf("\n\t\t <--------- Unable to find the information ----->");
    getche();
    fclose(src);
}
void delete ()
{
    FILE *src, *ptr;
    src = fopen("phone.txt", "r");
    ptr = fopen("phone_temp.txt", "w");
    char ch, ad[30], na[40];
    int found;
    float i;
    printf("\n\t\t <------ Note that if you don't have required information just press any worng info to skip ---->\n");
    printf("\n\t\t  Enter the name to delete ----->");
    fflush(stdin);
    gets(na);
    found = 0;
    system("color 2e");
    printf("\nName of guest\t\t\tAddress\t\t\tPhone number\n");
    while ((fread(&ph, sizeof(ph), 1, src)) == 1)
        if ((strcmp(strlwr(ph.name), strlwr(na)) != 0))
            fwrite(&ph, sizeof(ph), 1, ptr);
        else
        {
            found++;
            printf("%s\t\t%s\t\t\t%.1f\n", ph.name, ph.add, ph.phone);
        }
    fclose(src);
    fclose(ptr);
    src = fopen("phone.txt", "w");
    ptr = fopen("phone_temp.txt", "r");
    system("color 9");
    while ((fread(&ph, sizeof(ph), 1, ptr)) == 1)
        fwrite(&ph, sizeof(ph), 1, src);
    if (found == 0)
        printf("\n\t\t <----- The records is not founded ------>");
    else
        printf("\n\t\t <----- Successfully Deleted ------>");
    getche();
    fclose(src);
    fclose(ptr);
}
void destory()
{
    char ch;
    printf("\n\a<--- Be carefully you are going to destory all records ----> \n <--- press y for to continue ----->");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        FILE *src;
        src = fopen("phone.txt", "w");
        fclose(src);
        printf("\n<----Destroy all records sucessfully----->\n");
    }
    else
    {
        printf("\n<-----Terminated the destory prcess------->\n\a");
    }
    getche();
}

void intro()
{
    gotoxy(10, 3);
    printf("\n_____________________________________________________________\n");
    printf("|***********************************************************|\n");
    printf("|***********************************************************|\n");
    printf("|***********************************************************|\n");
    printf("|************Welcome to Phone book management system********|\n");
    printf("|***********************************************************|\n");
    printf("|***********************************************************|\n");
    printf("|***********************************************************|");
    printf("\n--------------------------------------------------------------\n");
}
