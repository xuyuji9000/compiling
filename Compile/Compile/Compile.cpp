// Compile.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <stdio.h>
#include <string>

#include <sstream>
//#include "source.h"
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


//全局变量
char prog[PROG_LENGTH],token[TOKEN_LENGTH];
//用于传递变量的中间变量
char ch;
//p为缓冲区prog指针，m是token指针,sum是用于存储数字值得空间
int syn,p,m,n;
double sum;
//关键字
char *rwtab[6] = {"begin","if","then","while","do","end"};


int _tmain(int argc, _TCHAR* argv[])
{
	//声明函数
	int scaner();
	
	char c = 'y';
	while(c == 'y')
		{
		cout<<"print in:"<<endl;
		p=0;
		//获取字符
		do{
			//*************************************添加代码
			ch = getchar();
			prog[p]=ch;
			p++;
		}while(ch != '#');
		for (;p < 80;p++) {
			prog[p] = NULL;
		};
		//printf("%s",prog);
		p=0;
	

		do {
	//		char a;
	//		scanf("%s",&a);
			int i = scaner();
			switch(i)
			{
			//********************************添加代码
				//输出 数的二元组
				//输出错误
				//输出 其他单词二元组
			case -1:printf("");break;
			case 0:printf("[%d %s]\n",syn,token);break;
			case 1:printf("[%d %s]\n",syn,token);break;
			case 2:printf("[%d %s]\n",syn,token);break;
			case 3:printf("[%d %s]\n",syn,token);break;
			case 4:printf("[%d %s]\n",syn,token);break;
			case 5:printf("[%d %s]\n",syn,token);break;
			case 6:printf("[%d %s]\n",syn,token);break;
			case 10:printf("[%d %s]\n",syn,token);break;
			case 11:printf("[%d %g]\n",syn,sum);break;
			case 13:printf("[%d %s]\n",syn,token);break;//+
			case 14:printf("[%d %s]\n",syn,token);break;//-
			case 15:printf("[%d %s]\n",syn,token);break;//*
			case 16:printf("[%d %s]\n",syn,token);break;///
			case 17:printf("[%d %s]\n",syn,token);break;//:
			case 18:printf("[%d %s]\n",syn,token);break;//:=
			case 20:printf("[%d %s]\n",syn,token);break;//<
			case 21:printf("[%d %s]\n",syn,token);break;//<>
			case 22:printf("[%d %s]\n",syn,token);break;//<=
			case 23:printf("[%d %s]\n",syn,token);break;//>
			case 24:printf("[%d %s]\n",syn,token);break;//>=
			case 25:printf("[%d %s]\n",syn,token);break;
			case 26:printf("[%d %s]\n",syn,token);break;
			case 27:printf("[%d %s]\n",syn,token);break;
			case 28:printf("[%d %s]\n",syn,token);break;
			case 29:printf("[%d %s]\n",syn,token);break;
		
			}
		} while(syn != 0);
	

		//cmd控制语句，控制停顿
		//system("pause");
		cout<<"do you want to carry on?"<<endl;
		cin>>c;

	}
	return 0;
}

int scaner()
{
	for(n = 0;n < 8;n++)token[n]=NULL;				//单词符号字符串缓冲区，token置空
	ch = prog[p++];									
	while(ch == ' ')ch = prog[p++];//去除空格的影响
	while(ch == 10)ch = prog[p++];//10 asc码是回车键值，去除回车的影响
	m = 0;
//检查字母开始
	if(ch >= 'A'&&ch <= 'z')
	{
		while ((ch >= 'A'&&ch <= 'z')||(ch >= '1'&&ch <= '9')) {
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';
		//printf("%s",token);
		p--;//回退一个字符
		syn = 10;
		for (n= 0;n < 6;n++) {
			if(strcmp(token,rwtab[n]) == 0){
				//printf("%d",n);
				switch(n)
				{
				case 0:syn = 1;return syn;//printf("[begin %d]",syn);break;
				case 1:syn = 2;return syn;//printf("[if %d]",syn);break;
				case 2:syn = 3;return syn;
				case 3:syn = 4;return syn;
				case 4:syn = 5;return syn;
				case 5:syn = 6;return syn;
				}
			}
		}
		if(syn == 10)
		{
			return syn;
		}
	}
//检查数字开始
	//初始化sum
	sum = 0;
	int con = 1;
	int index = 0;
	if (ch >= '0'&&ch <= '9') {
		while (ch >= '0'&&ch <= '9') {
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		//number,第二层,使用 con 变量
		if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
		{
			ch = prog[p++];
			while (ch >= '0'&&ch <= '9') {
				sum = sum + pow(0.1,con) * (ch - '0');//con 无错
				ch = prog[p++];
				con++;//下次使用前置'0',con 无错
			}
		}
		//number,第二层，使用 index 变量
			if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') {//判断，有指数量，指数没有正负号输入
				ch = prog[p++];//将e/E跳过
				while (ch >= '0'&&ch <= '9') {
					index = index*10 + ch - '0';
					ch = prog[p++];
				}
				sum = sum * pow(10.0,index);
			}
			if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') {//判断，有指数，有正负号输入
				ch = prog[p++];
				if (ch == '-') {//指数符号为'-'
					ch = prog[p++];
					while (ch >= '0'&&ch <= '9') {
						index = index*10 + ch - '0';
						ch = prog[p++];
					}
					index = -1 * index;
					sum = sum * pow(10.0,index);
				}
				else if (ch == '+') {//指数符号为'+'
					ch = prog[p++];
					while (ch >= '0'&&ch <= '9') {
						index = index*10 + ch - '0';
						ch = prog[p++];
					}
					sum = sum * pow(10.0,index);
				}
			}
		p--;
		syn = 11;
		return syn;
	}


//放在最后,'#'的识别
	else
		switch(ch)
	{
		case '<':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if(ch == '>'){
				syn = 21;
				token[m++] = ch;
				return syn;
			}
			else if (ch == '=') {
				syn = 22;
				token[m++] = ch;
				return syn;
			}
			else 
			{
				syn = 20;
				p--;
				return syn;
			}
		case ':':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=') {
				syn = 18;
				token[m++] = ch;
				return syn;
			}
			else
			{
				syn = 17;
				token[m++] = ch;
				return syn;
			}
		case '>':
			m = 0;
			token[m++] = ch;
			ch = prog[p++];
			if (ch == '=') {
				syn = 24;
				token[m++] = ch;
				return syn;
			}
			else
			{
				syn = 23;
				p--;
				return syn;
			}
		case '+':
			{
				if (prog[p] >= '0'&&prog[p] <= '9' ) {
					ch = prog[p++];//跳过'+'
					while (ch >= '0'&&ch <= '9') {
					sum = sum * 10 + ch - '0';
					ch = prog[p++];
					}
					//number,第二层,使用 con 变量
					if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
					{
						ch = prog[p++];
						while (ch >= '0'&&ch <= '9') {
							sum = sum + pow(0.1,con) * (ch - '0');//con 无错
							ch = prog[p++];
							con++;//下次使用前置'0',con 无错
						}
					}
					//number,第二层，使用 index 变量
						if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') {//判断，有指数量，指数没有正负号输入
							ch = prog[p++];//将e/E跳过
							while (ch >= '0'&&ch <= '9') {
								index = index*10 + ch - '0';
								ch = prog[p++];
							}
							sum = sum * pow(10.0,index);
						}
						else if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') 
						{//判断，有指数，有正负号输入
							ch = prog[p++];
							if (ch == '-') {//指数符号为'-'
								ch = prog[p++];
								while (ch >= '0'&&ch <= '9') {
									index = index*10 + ch - '0';
									ch = prog[p++];
								}
								index = -1 * index;
								sum = sum * pow(10.0,index);
							}
							else if (ch == '+') {//指数符号为'+'
								ch = prog[p++];
								if(ch >= '0'&&ch <= '9')
								{
									while (ch >= '0'&&ch <= '9') {
										index = index*10 + ch - '0';
										ch = prog[p++];
									}
								sum = sum * pow(10.0,index);
								}
							}							
						}
						else if((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&(prog[p+1] >= '9'||prog[p+1] <= '0'))
						{
							
							char buf[30];
							sprintf_s(buf,"%lf",sum);
							string str = buf;//将char*转换为string
							str = "ERROR WORD:" + str + 'e' + prog[p];
							cout<<str<<endl;
							p+=1;
							syn = -1;
							return -1;
						}
					p--;
					syn = 11;
					return syn;	//返回number的种别编码			
					}
			syn = 13;token[0] = ch;return syn;//返回+的种别编码
			}
		case '-':
			{	
				/*数字+字母，报错*/
				if (prog[p] >= '0'&&prog[p] <= '9' ) 
				{
					ch = prog[p++];//跳过'-'
					while (ch >= '0'&&ch <= '9') 
					{
					sum = sum * 10 + ch - '0';
					ch = prog[p++];
					}
					//number,第二层,使用 con 变量
					if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
					{
						ch = prog[p++];
						while (ch >= '0'&&ch <= '9') {
							sum = sum + pow(0.1,con) * (ch - '0');//con 无错
							ch = prog[p++];
							con++;//下次使用前置'0',con 无错
						}
					}
					/*此处添加 '.x' 这里x不是数字，则报错，并输出错误字符串*/
					//number,第二层，使用 index 变量
						if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') 
						{//判断，有指数量，指数没有正负号输入
							ch = prog[p++];//将e/E跳过
							while (ch >= '0'&&ch <= '9') {
								index = index*10 + ch - '0';
								ch = prog[p++];
							}
							sum = sum * pow(10.0,index);
						}
						else if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') 
						{//判断，有指数，有正负号输入
							ch = prog[p++];
							if (ch == '-') {//指数符号为'-'
								ch = prog[p++];
								while (ch >= '0'&&ch <= '9') {
									index = index*10 + ch - '0';
									ch = prog[p++];
								}
								index = -1 * index;
								sum = sum * pow(10.0,index);
							}
							else if (ch == '+') {//指数符号为'+'
								ch = prog[p++];
								while (ch >= '0'&&ch <= '9') {
									index = index*10 + ch - '0';
									ch = prog[p++];
								}
								sum = sum * pow(10.0,index);
							}
						}
						else if((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&(prog[p+1] >= '9'||prog[p+1] <= '0'))
						{
							
							char buf[30];
							sprintf_s(buf,"%lf",sum);
							string str = buf;//将char*转换为string
							str = "ERROR WORD:-" + str + 'e' + prog[p];
							cout<<str<<endl;
							p+=1;
							syn = -1;
							return -1;
							////专门用于报错，输出错误字符串
							//if(ch == 'e'&&(prog[p] > '9' || prog[p] < '0'))
							//{
							//	char buf[30];							
							//	sprintf_s(buf,"%f",sum);//还有一点问题，将多余的零去除
							//	cout<<buf<<endl;
							//	syn = -1;
							//	/*转化为可以输出的字符串*/
							//}
						}
					sum = -1 * sum;//'-'数
					p--;
					syn = 11;
					return syn;	//返回number的种别编码	
				}
				syn = 14;token[0] = ch;return syn;
			}
		case '*':syn = 15;token[0] = ch;return syn;
		case '/':
			{
				//判断注释
				if(prog[p] == '*')
				{
					token[m++] = ch;
					while((prog[p-2]=='*' && ch=='/')!=1)
					{
						ch = prog[p++];
						token[m++] = ch;					
					}
					syn = 29;
					return syn;
				}
				
				//syn = 16;token[0] = ch;return syn;
			}
		case '=':syn = 25;token[0] = ch;return syn;
		case ';':syn = 26;token[0] = ch;return syn;
		case '(':syn = 27;token[0] = ch;return syn;
		case ')':syn = 28;token[0] = ch;return syn;

		case '#': 
			syn = 0;token[0]=ch;return syn;
			//the lasr error
		default:
			syn = -1;return syn;
	}
	system("pause");
	return 0;
}

