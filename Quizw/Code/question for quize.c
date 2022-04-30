/* This program for quize */
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
int no;
struct question
{
	char ques[500], option[4][30];
	int ans, id;
} emp, skt;
void display();
void input();
void delete ();
void edit();
int check();
void search();
void destory();
void menu();
int main()
{
	while (1)
	{
		system("cls");
		menu();
	}
}
void menu()
{
	int n;
	printf("\n\t\tPlease enter your options\t");
	printf("\n\t\t\t1:- INPUT\n\t\t\t2:- DISPLAY\n\t\t\t3:- DELETE\n\t\t\t4:- SEARCH\n\t\t\t5:- EDIT\n\t\t\t9:- DESTORY\n\t\t\t0:- EXIT\t");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		input();
		break;
	case 2:
		system("cls");
		display();
		break;
	case 3:
		system("cls");
		delete ();
		break;
	case 4:
		system("cls");
		search();
		break;
	case 5:
		system("cls");
		edit();
		break;
	case 9:
		system("cls");
		destory();
		break;
	case 0:
		printf("\nThanks for using our program");
		exit(0);
		break;
	default:
		printf("Invalid options");
		fflush(stdin);
	}
}
void display()
{
	int i, found;
	FILE *src;
	src = fopen("question.skt", "r");
	printf("\n\t\t\tWELCOME TO QUESTIONS BANKE");
	found = 0;
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		found++;
		printf("\n\t\t\t%d ", emp.id);
		printf("%s", emp.ques);
		printf("\n\n\t\t\t");
		for (i = 0; i < 4; i++)
			printf("\t%d.%s\t", i + 1, emp.option[i]);
		printf("\n\n\t\t\tCorrect ans=%d", emp.ans);
	}
	if (found == 0)
		printf("\n\t\t\tThere is empty questions banke");
	fclose(src);
	getch();
}

void input()
{
	int i, k;
	char ch;
	FILE *src;
	src = fopen("question.skt", "a");
	if (src == NULL)
		src = fopen("question.skt", "w");
	do
	{
		printf("\n\t\tEnter the name question\t ");
		fflush(stdin);
		gets(skt.ques);
		for (i = 0; i < 4; i++)
		{
			printf("\n\t\tEnter the %d option\t", i + 1);
			gets(skt.option[i]);
		}
		fflush(stdin);
		printf("\n\t\tEnter the correct answer\t");
		scanf("%d", &skt.ans);
		k = check();
		skt.id = k;
		printf("\n\t\t\tFor your revive\n");
		printf("\n\t\t\t___________________________________________");
		printf("\n\t\t\t%d ", skt.id);
		printf("%s", skt.ques);
		printf("\n\n\t\t\t");
		for (i = 0; i < 4; i++)
			printf("\t%d.%s\t", i + 1, skt.option[i]);
		printf("\n\n\t\t\tCorrect ans=%d", skt.ans);
		printf("\n\t\t\t--------------------------------------------\n");
		printf("\n\t\tPress n for writting to the disk\t");
		fflush(stdin);
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
			goto last;
		if (fwrite(&skt, sizeof(skt), 1, src) == 1)
			printf("\n\t\tSccessfullly written to disk");
	last:
		printf("\n\t\tPress y for to add more\t");
		fflush(stdin);
		scanf("%c", &ch);
	} while (ch == 'y' || ch == 'Y');
	fclose(src);
}

void destory()
{
	printf("\n\t\tWarnning you will lose all data of question");
	char ch;
	printf("\n\t\tPress y for to continue\t");
	fflush(stdin);
	scanf("%c", &ch);
	if (ch == 'y' || ch == 'Y')
	{
		FILE *src;
		src = fopen("question.skt", "w");
		fclose(src);
	}
	// getch();
}

void delete ()
{
	int n, found = 0, i;
	char ch;
	printf("\n\t\t\tEnter the number of question\t");
	scanf("%d", &n);
	FILE *src, *ptr;
	src = fopen("question.skt", "r");
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		if (n == emp.id)
		{
			found++;
			printf("\n\t\t\t___________________________________________");
			printf("\n\t\t\tSucessfully found\n");
			printf("\n\t\t\t%d ", emp.id);
			printf("%s", emp.ques);
			printf("\n\n\t\t\t");
			for (i = 0; i < 4; i++)
				printf("\t%d.%s\t", i + 1, emp.option[i]);
			printf("\n\n\t\t\tCorrect ans=%d", emp.ans);
			printf("\n\t\t\t--------------------------------------------\n");
			printf("\n\t\t\tPress y for to cancell delete");
			fflush(stdin);
			scanf("%c", &ch);
		}
	}
	if (ch == 'y' || ch == 'Y')
	{
		printf("\n\t\t\tSuccessfully deleted cancelled");
		goto last;
	}
	ptr = fopen("temp.bin", "w");
	rewind(src);
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		if (n == emp.id)
			found++;
		else
			fwrite(&emp, sizeof(emp), 1, ptr);
	}
	if (found == 0)
		printf("\n\t\t\tQuestion is not found");
	else
		printf("\n\t\t\tSuccessfully found");
	fclose(ptr);
	fclose(src);

	src = fopen("question.skt", "w");
	ptr = fopen("temp.bin", "r");
	while (fread(&emp, sizeof(emp), 1, ptr) == 1)
		fwrite(&emp, sizeof(emp), 1, src);
	printf("\n\t\t\tSuccessfully delete");
last:
	fclose(ptr);
	fclose(src);
	// getch();
}

int check()
{
	FILE *src;
	src = fopen("question.skt", "r");
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		no = emp.id;
	}
	fclose(src);
	no += 1;
	return no;
}
void search()
{
	int n, found = 0, i;
	printf("\n\t\t\tEnter the number of question to be search\t");
	scanf("%d", &n);
	FILE *src;
	src = fopen("question.skt", "r");
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		if (n == emp.id)
		{
			found++;
			printf("\n\t\t\t___________________________________________");
			printf("\n\t\t\tSucessfully found\n");
			printf("\n\t\t\t%d ", emp.id);
			printf("%s", emp.ques);
			printf("\n\n\t\t\t");
			for (i = 0; i < 4; i++)
				printf("\t%d.%s\t", i + 1, emp.option[i]);
			printf("\n\n\t\t\tCorrect ans=%d", emp.ans);
			printf("\n\t\t\t--------------------------------------------\n");
		}
	}
	if (found == 0)
		printf("\n\t\t\tQestion is not exit");
	fclose(src);
	getch();
}

void edit()
{
	int n, found = 0, i, records, jo;
	char ch[5], cha;
	strcpy(ch, "skt");
	struct question pro;
	printf("\n\t\t\tEnter the number of question to be modify\t");
	scanf("%d", &n);
	FILE *src;
	src = fopen("question.skt", "r+");
	records = -1;
	while (fread(&emp, sizeof(emp), 1, src) == 1)
	{
		if (n == emp.id)
		{
			found++;
			printf("\n\t\t\t___________________________________________");
			printf("\n\t\t\tSucessfully found\n");
			printf("\n\t\t\t%d ", emp.id);
			printf("\n\t\t\t You cannot change id of questions\n\t\t\tPress 100 for to defualt\t\n\t\t");
			scanf("%d", &jo);
			if (jo == 100)
			{
				pro.id = emp.id;
				printf("\nQuestion id is not changed");
			}

			printf("\n\t\t\t");
			printf("%s", emp.ques);
			printf("\n\t\t\tModify the questions\t");
			fflush(stdin);
			gets(pro.ques);
			if ((strcmp(pro.ques, ch) == 0))
			{
				strcpy(pro.ques, emp.ques);
				printf("\n\t\t\tQuestions is not changed\t");
			}
			printf("\n\n\t\t\t");
			for (i = 0; i < 4; i++)
			{
				printf("\t%d.%s\t", i + 1, emp.option[i]);
				printf("\n\t\t\tModify options %d \t", i + 1);
				fflush(stdin);
				gets(pro.option[i]);
				if ((strcmp(pro.option[i], ch) == 0))
				{
					strcpy(pro.option[i], emp.option[i]);
					printf("\n\t\t\tOption[%d] is not changed", i);
				}
			}
			printf("\n\n\t\t\tCorrect ans=%d", emp.ans);
			printf("\n\t\t\tModify the correct answer\n\t\t\tPress 88 for to set defualt\n");
			scanf("%d", &pro.ans);
			if (pro.ans == 88)
			{
				printf("\n\t\t\tAnswer is not changed");
				pro.ans = emp.ans;
			}
			printf("\n\t\t\tFor your revive\n");
			printf("\n\t\t\t___________________________________________");
			printf("\n\t\t\t%d ", pro.id);
			printf("%s", pro.ques);
			printf("\n\n\t\t\t");
			for (i = 0; i < 4; i++)
				printf("\t%d.%s\t", i + 1, pro.option[i]);
			printf("\n\n\t\t\tCorrect ans=%d", pro.ans);
			printf("\n\t\t\t--------------------------------------------\n");
			printf("\n\t\tPress n for cancelling the modifying\t");
			fflush(stdin);
			scanf("%c", &cha);
			if (cha == 'n' && cha == 'N')
			{
				printf("\n\t\t\tSucessfully Cancell\t");
				goto last;
			}
			fseek(src, sizeof(emp) * (records), SEEK_CUR);
			if ((fwrite(&pro, sizeof(pro), 1, src) == 1))
			{
				printf("\n\t\t\tSuccessfully Modify");
				break;
			}
			printf("\n\t\t\t--------------------------------------------\n");
		}
	}
	if (found == 0)
		printf("\n\t\t\tQestion is not exit");
last:
	fclose(src);
	getch();
}
