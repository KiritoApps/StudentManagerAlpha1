/*  Student Manager by KiritoApps  */
/*	https://github.com/KiritoApps  */
/*	我要亲手解放这个世界，哼哼  */
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*  Define Arguments  */
int Student[30],StuNum;
int SortedScore[30],Backup[30];
int Sum;
float Avg,StuNumFloat;

void ShowMenu();
int Terminate();
void GenerateBackup();
void WaitForUser();
void ShowResult();
void GenerateReport();
void FindStuInfo();
void SortByList();
void SortByMark();
void CalcTotalAvg();
void GetScore();
void GetUserChoice();

/*  Main Part of Program **/
int main()
{
	ShowMenu();
	return 0;
}
/* Moudles of STUMGR */
void ShowMenu()
{
	printf("Welcome to Student Score Manager!\n");
	printf("1.Input Record\n");
	printf("2.Calculate total and average score of course\n");
	printf("3.Sort in descending order by score\n");
	printf("4.Sort in ascending order by number\n");
	printf("5.Search by number\n");
	printf("6.Statistic analysis\n");
	printf("7.List record\n");
	printf("8.Exit\n");
	GetUserChoice();
}
void GetUserChoice()
{
	int i;
	scanf("%d",&i);
	switch(i)
	{
		case 1:{
			GetScore();
			break;
		}
		case 2:{
			CalcTotalAvg();
			break;
		}
		case 3:{
			SortByMark();
			break;
		}
		case 4:{
			SortByList();
			break;
		}
		case 5:{
			FindStuInfo();
			break;
		}
		case 6:{
			GenerateReport();
			break;
		}
		case 7:{
			ShowResult();
			break;
		}
		case 8:{
			Terminate();
			break;
		}
		default:{
			ShowMenu();
			break;
		}
	}
}
void GetScore()
{
	int i;
	system("cls");
	printf("Input Total Student Numbers\n");
	scanf("%d",&StuNum);
	for(i=0;i<StuNum;i++)
	{
		scanf("%d",&Student[i]);
	}
	WaitForUser();
}
void CalcTotalAvg()
{
	int i;
	StuNumFloat = StuNum;
	system("cls");
	for(i=0;i<StuNum;i++)
	{
		Sum = Sum + Student[i];
	}
	Avg = Sum / StuNumFloat;
	printf("The Sum Score is: %d\n",Sum);
	printf("The Average Score is: %f\n",Avg);
	WaitForUser();
}
void SortByMark()
{
	int i,j,Temp;
	system("cls");
	GenerateBackup();
	for(i=0;i<StuNum-1;i++)
	{
		for(j=0;j<StuNum-1;j++)
		{
			if(SortedScore[j] < SortedScore[j+1])
			{
				Temp = SortedScore[j];
				SortedScore[j] = SortedScore[j+1];
				SortedScore[j+1] = Temp;
			}
			
		}
	}
	printf("NO.				Score\n");
	for(i=0;i<StuNum;i++)
	{
		printf("%d			 	 %d\n",i+1,SortedScore[i]);
	}	
	WaitForUser();
}
void SortByList()
{
	int i;
	system("cls");
	printf("NO.				Score\n");
	for(i=0;i<StuNum;i++)
	{
		printf("%d			 	 %d\n",i+1,Student[i]);
	}
	WaitForUser();
}
void FindStuInfo()
{
	int a,i,Temp;
	system("cls");
	printf("Input Student Number: ");
	scanf("%d",&a);
	Temp = Student[a-1];
	for(i=0;i<StuNum;i++)
	{
		if(SortedScore[i] == Temp)
		{
			printf("NO.				Score\n");
			printf("%d			 	 %d\n",i+1,Temp);
			break;
		}
	}
	WaitForUser();
}
void GenerateReport()
{
	int i;
	int A=0,B=0,C=0,D=0,F=0;
	float PA,PB,PC,PD,PF;
	system("cls");
	for(i=0;i<StuNum;i++)
	{
		if((SortedScore[i] <=100) && (SortedScore[i] >= 90))
		{
			A++;
		}
		else if((SortedScore[i] <=89) && (SortedScore[i] >= 80))
		{
			B++;
		}
		else if((SortedScore[i] <=79) && (SortedScore[i] >= 70))
		{
			C++;
		}
		else if((SortedScore[i] <=69) && (SortedScore[i] >= 60))
		{
			D++;
		}
		else if((SortedScore[i] <=59))
		{
			F++;
		}
	}
	PA = A / StuNumFloat;
	PB = B / StuNumFloat;
	PC = C / StuNumFloat;
	PD = D / StuNumFloat;
	PF = F / StuNumFloat;
	printf("Level A is: %f\n",PA);
	printf("Level B is: %f\n",PB);
	printf("Level C is: %f\n",PC);
	printf("Level D is: %f\n",PD);
	printf("Level F is: %f\n",PF);
	WaitForUser();
}
void ShowResult()
{
	int i;
	system("cls");
	printf("The Sum Score is: %d\n",Sum);
	printf("The Average Score is: %f\n",Avg);
	printf("NO.				Score\n");
	for(i=0;i<StuNum;i++)
	{
		printf("%d			 	 %d\n",i+1,Student[i]);
	}
	WaitForUser();
	
}
void WaitForUser()
{
	printf("Press anykey to continue...");
	getchar();
	getchar();
	system("cls");
	ShowMenu();
}
void GenerateBackup()
{
	int i;
	for(i=0;i<StuNum;i++)
	{
		SortedScore[i] = Student[i];
		Backup[i] = Student[i];
	}
}
int Terminate()
{	
	system("cls");
	printf("Thanks for using!See you next time!\n");
	return 0;
}
