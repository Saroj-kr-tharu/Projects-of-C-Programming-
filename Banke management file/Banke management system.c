/* This program is designed to make a program like banke management system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct info
{
	char name_bank[30], name_branch[30], name_holder[30], address[30], type[30];
	int accno;
	float amount, phone;
} ban, man;
struct usr
{
	char user_name[30], password[30];
} logi;
void Add_account();
void search_account();
void withdraw();
void deposit();
void edit();
void menu();
void destory();
void intro();
void view();
void delete ();
void login();
void admin();
void user();
void gotoxy(int, int);
FILE *src, *ptr;
int main(void)
{
	system("color 8f && cls");
	intro();
	system("color 4");
	login();
	while (1)
	{
		system("color 8f && cls");
		intro();
		Sleep(100);
		system("color 0f");
		menu();
	}
}
void menu()
{
	int n;
	printf("\nPlease enter your options\n");
	printf("\n0:- Exit\n1:- Add new account\n2:- Search account\n3:- Withdraw money\n4:- Deposit amount\n5:- Edit account\n6:- View all account\n7:- Delete\n9:- Destory all records\t");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("color 3e && cls");
		Add_account();
		getche();
		break;
	case 2:
		system("color 9e && cls");
		search_account();
		getche();
		break;
	case 3:
		system("color 2e && cls");
		withdraw();
		getche();
		break;
	case 4:
		system("color d");
		deposit();
		getche();
		break;
	case 5:
		system("color 2");
		edit();
		break;
	case 6:
		system("color 3f");
		view();
		break;
	case 7:
		system("color 74");
		delete ();
		break;
	case 0:
		system("color 8e");
		printf("\nThanks for using our program");
		exit(0);
		break;
	case 9:
		system("color b");
		destory();
		getche();
		break;
	case 99:
		system("color 2");
		admin();
		break;
	default:
		system("color 4");
		fflush(stdin);
		printf("\nInvalid options");
		break;
	}
}
void Add_account()
{
	src = fopen(file1.txt", "a+");
	if (src == NULL)
		src = fopen(file1.txt", "w+");
	char ch;
	int n;
	fflush(stdin);
	printf("\nEnter the name of the banke\t");
	gets(ban.name_bank);
	printf("\nEnter the name of branch of %s\t", ban.name_bank);
	gets(ban.name_branch);
top:
	printf("\nEnter the account number\t");
	scanf("%d", &ban.accno);
	rewind(src);
	while (fread(&man, sizeof(man), 1, src) == 1)
		if (man.accno == ban.accno)
		{
			printf("\nThis account number is already in use please use another account number ");
			goto top;
		}
no:
	printf("\nAccount type\n1:-Current Account\t2:-Saving Account\t3:-Recuuring deposit account\t4:-Fixed deposit \t");
	scanf("%d", &n);
	if (n == 1)
		strcpy(ban.type, "current");
	else if (n == 2)
		strcpy(ban.type, "saving");
	else if (n == 3)
		strcpy(ban.type, "recurring");
	else if (n == 4)
		strcpy(ban.type, "fixed");
	else
	{
		printf("\nInvalid options");
		goto no;
	}
	fflush(stdin);
	printf("\nEnter the name of customer\t");
	gets(ban.name_holder);
	printf("\nEnter the address of %s\t", ban.name_holder);
	gets(ban.address);
	printf("\nEnter the phone number of %s\t", ban.name_holder);
	scanf("%f", &ban.phone);
	ban.amount = 0;

	printf("\n_________________________________________");
	printf("\n\aFor your revieve\n");
	printf("\nName of banke            :-\t%s", ban.name_bank);
	printf("\nName of branch           :-\t%s", ban.name_branch);
	printf("\nAccount number           :-\t%d", ban.accno);
	printf("\nAccount type             :-\t%s", ban.type);
	printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
	printf("\nName of account holder   :-\t%s", ban.name_holder);
	printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
	printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
	printf("\n-----------------------------------------\nPress y for to registred or another key for destory\t");
	fflush(stdin);
	scanf("%c", &ch);
	fseek(src, 0, SEEK_END);
	if (ch == 'y' || ch == 'Y')
		if ((fwrite(&ban, sizeof(ban), 1, src)) == 1)
			printf("\nSucessfully written");
		else
			printf("\nSucessfully destoryed");
	fclose(src);
}
void search_account()
{
	src = fopen(file1.txt", "r");
	int id, ch, found = 0;
	char cha[30], chi[30], chn[30];
	float cl;
	printf("\nPlease enter your options to search specific account");
	printf("\n1:- Name of holder\n2:- Name of banke\n3:- Phone number of holder\n4:- Name of branch\n0:- Account no\t");
	fflush(stdin);
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		fflush(stdin);
		rewind(src);
		printf("\nEnter the name of customer\t");
		gets(chi);
		found = 0;
		while (fread(&ban, sizeof(ban), 1, src) == 1)
			if ((strcmp(strlwr(ban.name_holder), strlwr(chi)) == 0))
			{
				found++;
				printf("\n_________________________________________________");
				printf("\nSucessfully founded");
				printf("\nName of banke            :-\t%s", ban.name_bank);
				printf("\nName of branch           :-\t%s", ban.name_branch);
				printf("\nAccount number          :-\t%d", ban.accno);
				printf("\nAccount type             :-\t%s", ban.type);
				printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
				printf("\nName of account holder   :-\t%s", ban.name_holder);
				printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
				printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
				printf("\n--------------------------------------------------------\n");
			}
		if (found == 0)
			printf("\nUnable to find");
		break;
	case 2:
		fflush(stdin);
		printf("\nEnter the name of banke\t");
		gets(cha);
		rewind(src);
		found = 0;
		while (fread(&ban, sizeof(ban), 1, src) == 1)
			if ((strcmp(strlwr(ban.name_bank), strlwr(cha)) == 0))
			{
				found++;
				printf("\n_________________________________________________");
				printf("\nSucessfully founded");
				printf("\nName of banke            :-\t%s", ban.name_bank);
				printf("\nName of branch           :-\t%s", ban.name_branch);
				printf("\nAccount number          :-\t%d", ban.accno);
				printf("\nAccount type             :-\t%s", ban.type);
				printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
				printf("\nName of account holder   :-\t%s", ban.name_holder);
				printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
				printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
				printf("\n--------------------------------------------------------\n");
			}
		if (found == 0)
			printf("\nUnable to find");
		break;
	case 3:
		printf("\nEnter the phone number of customer\t");
		scanf("%f", &cl);
		rewind(src);
		while (fread(&ban, sizeof(ban), 1, src) == 1)
			if (ban.phone == cl)
			{
				found++;
				printf("\n_________________________________________________");
				printf("\nSucessfully founded");
				printf("\nName of banke            :-\t%s", ban.name_bank);
				printf("\nName of branch           :-\t%s", ban.name_branch);
				printf("\nAccount number          :-\t%d", ban.accno);
				printf("\nAccount type             :-\t%s", ban.type);
				printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
				printf("\nName of account holder   :-\t%s", ban.name_holder);
				printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
				printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
				printf("\n--------------------------------------------------------\n");
			}
		if (found == 0)
			printf("\nUnable to find");
		break;
	case 4:
		fflush(stdin);
		printf("\nEnter name of branch\t");
		gets(chn);
		while (fread(&ban, sizeof(ban), 1, src) == 1)
			if ((strcmp(strlwr(ban.name_branch), strlwr(chn)) == 0))
			{
				found++;
				printf("\n_________________________________________________");
				printf("\nSucessfully founded");
				printf("\nName of banke            :-\t%s", ban.name_bank);
				printf("\nName of branch           :-\t%s", ban.name_branch);
				printf("\nAccount number          :-\t%d", ban.accno);
				printf("\nAccount type             :-\t%s", ban.type);
				printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
				printf("\nName of account holder   :-\t%s", ban.name_holder);
				printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
				printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
				printf("\n--------------------------------------------------------\n");
			}
		if (found == 0)
			printf("\nUnable to find");
		break;
	case 0:
		printf("\nEnter your account number \t");
		scanf("%d", &id);
		rewind(src);
		while (fread(&ban, sizeof(ban), 1, src) == 1)
			if (ban.accno == id)
			{
				found++;
				printf("\n_________________________________________________");
				printf("\nSucessfully founded");
				printf("\nName of banke            :-\t%s", ban.name_bank);
				printf("\nName of branch           :-\t%s", ban.name_branch);
				printf("\nAccount number          :-\t%d", ban.accno);
				printf("\nAccount type             :-\t%s", ban.type);
				printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
				printf("\nName of account holder   :-\t%s", ban.name_holder);
				printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
				printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
				printf("\n--------------------------------------------------------\n");
			}
		if (found == 0)
			printf("\nUnable to find");
		break;
	default:
		printf("\nInvalid options");
		break;
	}
	fclose(src);
}
void withdraw()
{
	src = fopen(file1.txt", "r+");
	int id, found = 0, records;
	float amt;
	printf("\nEnter your account number \t");
	scanf("%d", &id);
	records = -1;
	while (fread(&ban, sizeof(ban), 1, src) == 1)
		if (ban.accno == id)
		{
			found++;
			printf("\n_________________________________________________");
			printf("\nSucessfully founded");
			printf("\nName of banke            :-\t%s", ban.name_bank);
			printf("\nName of branch           :-\t%s", ban.name_branch);
			printf("\nAccount number          :-\t%d", ban.accno);
			printf("\nAccount type             :-\t%s", ban.type);
			printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
			printf("\nName of account holder   :-\t%s", ban.name_holder);
			printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
			printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
			printf("\n--------------------------------------------------------\n");

			printf("\nEnter the amount to withdraw\t");
			scanf("%f", &amt);
			if (amt > ban.amount)
				printf("\nYour withdraw amount is more than you current amount\n");
			else if (amt >= 100)
			{
				ban.amount -= amt;
				strcpy(man.name_bank, ban.name_bank);
				strcpy(man.name_branch, ban.name_branch);
				strcpy(man.name_holder, ban.name_holder);
				strcpy(man.address, ban.address);
				strcpy(man.type, ban.type);
				man.phone = ban.phone;
				man.accno = ban.accno;
				man.amount = ban.amount;
				fseek(src, sizeof(ban) * (records), SEEK_CUR);
				fwrite(&man, sizeof(man), 1, src);
				printf("\nSuccessfully withdrawed");
				break;
			}
			else
				printf("\n Please withdraw more than 100");
		}
	if (found == 0)
		printf("\nUnable to find");
	fclose(src);
}
void deposit()
{
	src = fopen(file1.txt", "r+");
	int id, found = 0, records;
	float amt;
	printf("\nEnter your account number \t");
	scanf("%d", &id);
	records = -1;
	while (fread(&ban, sizeof(ban), 1, src) == 1)
		if (ban.accno == id)
		{
			found++;
			printf("\n_________________________________________________");
			printf("\nRevive of your account");
			printf("\nName of banke            :-\t%s", ban.name_bank);
			printf("\nName of branch           :-\t%s", ban.name_branch);
			printf("\nAccount number          :-\t%d", ban.accno);
			printf("\nAccount type             :-\t%s", ban.type);
			printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
			printf("\nName of account holder   :-\t%s", ban.name_holder);
			printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
			printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
			printf("\n--------------------------------------------------------\n");

			printf("\nEnter the amount to deposit\t");
			scanf("%f", &amt);
			ban.amount += amt;
			strcpy(man.name_bank, ban.name_bank);
			strcpy(man.name_branch, ban.name_branch);
			strcpy(man.name_holder, ban.name_holder);
			strcpy(man.address, ban.address);
			strcpy(man.type, ban.type);
			man.phone = ban.phone;
			man.accno = ban.accno;
			man.amount = ban.amount;
			fseek(src, sizeof(ban) * (records), SEEK_CUR);
			if (fwrite(&man, sizeof(man), 1, src) == 1)
				printf("\nSuccessfully deposited");
			break;
		}
	if (found == 0)
		printf("\nUnable to find");
	fclose(src);
}
void edit()
{
	src = fopen(file1.txt", "r+");
	int id, found = 0, records;
	printf("\nEnter your account number \t");
	scanf("%d", &id);
	records = -1;
	while (fread(&ban, sizeof(ban), 1, src) == 1)
		if (ban.accno == id)
		{
			found++;
			printf("\n_________________________________________________");
			printf("\nSucessfully founded");
			printf("\nName of banke            :-\t%s", ban.name_bank);
			printf("\nName of branch           :-\t%s", ban.name_branch);
			printf("\nAccount number          :-\t%d", ban.accno);
			printf("\nAccount type             :-\t%s", ban.type);
			printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
			printf("\nName of account holder   :-\t%s", ban.name_holder);
			printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
			printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
			printf("\n--------------------------------------------------------\n");
			printf("\nWarning you cannot change the account number and amount\t");
			printf("\nEnter the name of customer\t");
			fflush(stdin);
			gets(man.name_holder);
			printf("\nEnter the address of %s\t", man.name_holder);
			gets(man.address);
			man.accno = ban.accno;
			man.amount = ban.amount;
			strcpy(man.name_bank, ban.name_bank);
			strcpy(man.name_branch, ban.name_branch);
			strcpy(man.type, ban.type);
			printf("\nEnter the phone number of %s\t", man.name_holder);
			scanf("%f", &man.phone);
			fseek(src, sizeof(ban) * (records), SEEK_CUR);
			if ((fwrite(&man, sizeof(man), 1, src)) == 1)
			{
				printf("\nSuccessfully modified");
				break;
			}
		}
	if (found == 0)
		printf("\nUnable to find account\n Please add new account ");
	fclose(src);
}

void destory()
{
	char ch;
	printf("\n\aWarning this process will destory your all records\t");
	printf("\n\aPress y for to proceed this\a");
	scanf(" %c", &ch);
	if (ch == 'y' || ch == 'Y')
	{
		src = fopen(file1.txt", "w");
		fclose(src);
		printf("\nSuccessfully destoryed all records");
	}
	else
		printf("\nDestroying process is terminated\t");
}
void intro()
{
	printf("\n\t\t_____________________________________________________________\n");
	printf("\t\t|***********************************************************|\n");
	printf("\t\t|***********************************************************|\n");
	printf("\t\t|***********************************************************|\n");
	printf("\t\t|************Welcome to Banke management system*************|\n");
	printf("\t\t|***********************************************************|\n");
	printf("\t\t|***********************************************************|\n");
	printf("\t\t|***********************************************************|");
	printf("\n\t\t-------------------------------------------------------------\n");
}

void login()
{
	src = fopen(admin.skt", "rb");
	char no, nme[10], pass[30];
	int found = 0;
	printf("\n\t\t\tLogin your self to use this program");
top:
	rewind(src);
	printf("\n\t\t\tEnter the user name\t ");
	fflush(stdin);
	gets(nme);
	printf("\n\t\t\tEnter the password of %s\t", nme);
	fflush(stdin);
	gets(pass);
	while (fread(&logi, sizeof(logi), 1, src) == 1)
	{
		if ((strcmp(logi.user_name, nme) == 0) && (strcmp(logi.password, pass) == 0))
		{
			system("color 2 && cls");
			printf("\n\a Login successfully");
			found++;
		}
	}
	if (found == 0)
	{
		printf("\n\t\t\tunable to login\npress y for to reenter detail");
		fflush(stdin);
		no = getche();
		if (no == 'y' || no == 'Y')
			goto top;
		else
			exit(0);
	}
	fclose(src);
}
void admin()
{
	char name[] = "Saroj", password[] = "joker", pass[20], no, nme[10];
	printf("\n\t\t\tWelcome to user management center ");
top:
	printf("\n\t\t\tEnter the master user name\t ");
	fflush(stdin);
	gets(nme);
	printf("\n\t\t\tEnter the master password \t");
	fflush(stdin);
	gets(pass);
	if ((strcmp(name, nme) == 0) && (strcmp(password, pass) == 0))
	{
		system("color 2 && cls");
		printf("\n\t\t\t\a Login successfully");
		user();
	}
	else
	{
		printf("\n\t\t\tunable to login\npress y for to reenter password");
		fflush(stdin);
		no = getche();
		if (no == 'y' || no == 'Y')
			goto top;
		else
			exit(0);
	}
}

void user()
{
	int ch;
	char c;
	while (1)
	{
		printf("\n\t\t\tEnter your options\n");
		printf("\n\t\t\t1:- ADD USER\n\t\t\t2:- DELETE USER\n\t\t\t3:- EDIT PASSWORD\n\t\t\t5:- DISPLAY\n\t\t\t0:- Exit\t");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			src = fopen(admin.skt", "a+b");
			if (src == NULL)
				src = fopen(admin.skt", "wb");
			printf("\n\t\t\tEnter the new user name\t");
			fflush(stdin);
			gets(logi.user_name);
			printf("\n\t\t\tEnter the password of %s\t", logi.user_name);
			gets(logi.password);
			printf("\n\t\t\t_________________________________________________");
			printf("\n\t\t\tRevive of new user");
			printf("\n\t\t\tUSERNAME      :-\t%s", logi.user_name);
			printf("\n\t\t\tPASSWORD      :-\t%s", logi.password);
			printf("\n\t\t\t--------------------------------------------------------\n");
			printf("\n\t\t\t Press y for to registred\t");
			fflush(stdin);
			c = getche();
			if (c == 'y')
			{
				if (fwrite(&logi, sizeof(logi), 1, src) == 1)
					printf("\n\t\t\t\aSuccessfully Added new user");
			}
			else
				printf("\n\t\t\t\aSuccessfully destoryed");
			fclose(src);
			break;

		case 2:
			ptr = fopen(temp.skt", "wb");
			src = fopen(admin.skt", "rb");
			char nme[30], pass[30];
			int found = 0;
			printf("\n\t\t\tEnter the user name\t");
			fflush(stdin);
			gets(nme);
			printf("\n\t\t\tEnter the password of %s\t", nme);
			gets(pass);
			found = 0;
			while (fread(&logi, sizeof(logi), 1, src) == 1)
				if ((strcmp(logi.user_name, nme) == 0) && (strcmp(logi.password, pass) == 0))
				{
					found++;
					printf("\n\t\t\t_________________________________________________");
					printf("\n\t\t\tRevive of new user");
					printf("\n\t\t\tUSERNAME      :-\t%s", logi.user_name);
					printf("\n\t\t\tPASSWORD      :-\t%s", logi.password);
					printf("\n\t\t\t--------------------------------------------------------\n");
				}
			if (found == 0)
			{
				printf("\n\t\t\tUser name and password not exit");
				goto end;
			}
			else
			{
				rewind(src);
				while (fread(&logi, sizeof(logi), 1, src) == 1)
					if ((strcmp(logi.user_name, nme) != 0) && (strcmp(logi.password, pass) != 0))
						fwrite(&logi, sizeof(logi), 1, ptr);
			}
			fclose(src);
			fclose(ptr);
			src = fopen(admin.skt", "wb");
			ptr = fopen(temp.skt", "rb");
			while (fread(&logi, sizeof(logi), 1, ptr) == 1)
				fwrite(&logi, sizeof(logi), 1, src);
			printf("\n\t\t\tSuccessfully deleted");
			fclose(src);
			fclose(ptr);
		end:
			break;
		case 3:
			src = fopen(admin.skt", "r+b");
			int records;
			printf("\n\t\t\tEnter the user name\t");
			fflush(stdin);
			gets(nme);
			printf("\n\t\t\tEnter the password of %s\t", nme);
			gets(pass);
			found = 0;
			records = -1;
			while (fread(&logi, sizeof(logi), 1, src) == 1)
				if ((strcmp(logi.user_name, nme) == 0) && (strcmp(logi.password, pass) == 0))
				{
					found++;
					printf("\n\t\t\t_________________________________________________");
					printf("\n\t\t\tRevive of new user");
					printf("\n\t\t\tUSERNAME      :-\t%s", logi.user_name);
					printf("\n\t\t\tPASSWORD      :-\t%s", logi.password);
					printf("\n\t\t\t--------------------------------------------------------\n");
					printf("\n\t\t\tEnter the new user name\t");
					fflush(stdin);
					gets(logi.user_name);
					printf("\n\t\t\tEnter the new password of %s\t", logi.user_name);
					gets(logi.password);
					fseek(src, sizeof(logi) * (records), SEEK_CUR);
					if (fwrite(&logi, sizeof(logi), 1, src) == 1)
					{
						printf("\n\t\t\tSuccessfully modified");
						break;
					}
				}
			if (found == 0)
				printf("\n\t\t\tUser name and password not exit");
			fclose(src);
			break;
		case 5:
			src = fopen(admin.skt", "rb");
			while (fread(&logi, sizeof(logi), 1, src) == 1)
			{
				printf("\n\t\t\t_________________________________________________");
				printf("\n\t\t\tUSERNAME      :-\t%s", logi.user_name);
				printf("\n\t\t\tPASSWORD      :-\t%s", logi.password);
				printf("\n\t\t\t--------------------------------------------------------\n");
			}
			fclose(src);
			break;
		case 0:
			printf("\n\t\t\tTerminating .......");
			main();
			break;
		default:
			printf("\n\t\t\t\aInvalid options");

			break;
		}
	}
	fclose(src);
}

void view()
{
	src = fopen(file1.txt", "r");
	printf("\n\t\tAccount no:\t\tName of Banke\t\tType\t\tName of holder\n");
	while (fread(&ban, sizeof(ban), 1, src) == 1)
		printf("\t\t%d\t\t\t%s\t\t\t%s\t\t\t%s\n", ban.accno, ban.name_bank, ban.type, ban.name_holder);
	getche();
	fclose(src);
}
void delete ()
{
	FILE *src, *ptr;
	src = fopen(file1.txt", "r");
	ptr = fopen(temp.skt", "w");
	char ch;
	int found, id;
	float i;
	found = 0;
	system("color 2e");
	printf("\nEnter the account number to be delete\t");
	scanf("%d", &id);
	while ((fread(&ban, sizeof(ban), 1, src)) == 1)
	{
		if (ban.accno == id)
		{
			printf("\n_________________________________________________");
			printf("\nRevive your account");
			printf("\nName of banke            :-\t%s", ban.name_bank);
			printf("\nName of branch           :-\t%s", ban.name_branch);
			printf("\nAccount number          :-\t%d", ban.accno);
			printf("\nAccount type             :-\t%s", ban.type);
			printf("\nCurrent amount of %d     :-\t%.3f", ban.accno, ban.amount);
			printf("\nName of account holder   :-\t%s", ban.name_holder);
			printf("\nAddress of %s            :-\t%s", ban.name_holder, ban.address);
			printf("\nPhone number of %s       :-\t%.1f", ban.name_holder, ban.phone);
			printf("\n--------------------------------------------------------\n");
			printf("\npress y to cancel the deletion\t");
			fflush(stdin);
			scanf("%c", &ch);
			if (ch == 'y' || ch == 'y')
			{
				printf("\n\aSuccessfully cancall");
				goto end;
			}
		}
	}
	rewind(src);
	while ((fread(&ban, sizeof(ban), 1, src)) == 1)
		if (ban.accno != id)
			fwrite(&ban, sizeof(ban), 1, ptr);
		else
			found++;
	if (found == 0)
	{
		printf("\nThe records is not founded\n");
		goto end;
	}
	fclose(src);
	fclose(ptr);
	src = fopen(file1.txt", "w");
	ptr = fopen(temp.skt", "r");
	system("color 9");
	while ((fread(&ban, sizeof(ban), 1, ptr)) == 1)
		fwrite(&ban, sizeof(ban), 1, src);
	if (found > 0)
		printf("\nSuccessfully Deleted");
end:
	getche();
	fclose(src);
	fclose(ptr);
}
