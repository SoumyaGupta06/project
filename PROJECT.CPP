#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#define NUM 10

float calc(int n1, int n2, int optn)
{
	fstream qs;
	float x;
	qs.open("ques.txt",ios::app);
	switch(optn)
	{
		case 0: x=n1+n2;
			qs<<n1<<"+"<<n2<<"\n";
			break;
		case 1: x=n1-n2;
			qs<<n1<<"-"<<n2<<"\n";
			break;
		case 2: x=n1*n2;
			qs<<n1<<"*"<<n2<<"\n";
			break;
		case 3: x=n1/n2;
			qs<<n1<<"/"<<n2<<"\n";
			break;
		default: exit(0);
	}
	qs.close();
	return x;
}

void ques()
{
	int i,n1,n2,optn;
	float ans;
	fstream qs,sol;
	sol.open("ans.txt",ios::out);
	cout<<"Solve the following: ";
	for(i=1;i<=NUM;i++)
	{
		n1=random(100);
		n2=random(100);
		optn=random(4);
		ans=calc(n1,n2,optn);
		sol<<ans<<"\n";
	}
	sol.close();
}
void inputAns()
{
	fstream qs,inp;
	int i,val;
	inp.open("inputAnswers.txt",ios::out);
	char str[10];
	qs.open("ques.txt",ios::in);
	for(i=1;i<=NUM;i++)
	{
		qs.getline(str,10,'\n');
		cout<<"\nQues "<<i<<": "<<str;
		cout<<"\tAns= ";
		cin>>val;
		inp<<val<<"\n";
	}
	qs.close();
	inp.close();
}

void compare()
{
	fstream result,sol,inp;
	result.open("result.txt",ios::out);
	sol.open("ans.txt",ios::in);
	inp.open("inputAnswers.txt",ios::in);
	char str[10],str1[10];
	int i;
	for(i=1;i<=NUM;i++)
	{
		sol.getline(str,10,'\n');
		inp.getline(str1,10,'\n');
		if(strcmp(str,str1)==0)
			result<<1<<"\n";
		else
			result<<0<<"\n";

	}
	sol.close();
	inp.close();
	result.close();
}

void display()
{
	fstream result;
	result.open("result.txt",ios::in);
	int count=0,i,per;
	char str[5];
	for(i=1;i<=NUM;i++)
	{
		result.getline(str,5,'\n');
		if(*str=='1')
			count++;
	}
	per=count*10;
	cout<<"Percentage scored : "<<per<<"%\n";
	result.close();
}


void main()
{
	clrscr();
	ques();
	inputAns();
	compare();
	display();
	getch();
}