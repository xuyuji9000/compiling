// Compile.cpp : �������̨Ӧ�ó������ڵ㡣
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


//ȫ�ֱ���
char prog[PROG_LENGTH],token[TOKEN_LENGTH];
//���ڴ��ݱ������м����
char ch;
//pΪ������progָ�룬m��tokenָ��,sum�����ڴ洢����ֵ�ÿռ�
int syn,p,m,n;
double sum;
//�ؼ���
char *rwtab[6] = {"begin","if","then","while","do","end"};


int _tmain(int argc, _TCHAR* argv[])
{
	//��������
	int scaner();
	
	char c = 'y';
	while(c == 'y')
		{
		cout<<"print in:"<<endl;
		p=0;
		//��ȡ�ַ�
		do{
			//*************************************���Ӵ���
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
			//********************************���Ӵ���
				//��� ���Ķ�Ԫ��
				//�������
				//��� �������ʶ�Ԫ��
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
		
			}
		} while(syn != 0);
	

		//cmd������䣬����ͣ��
		//system("pause");
		cout<<"do you want to carry on?"<<endl;
		cin>>c;

	}
	return 0;
}

int scaner()
{
	for(n = 0;n < 8;n++)token[n]=NULL;				//���ʷ����ַ�����������token�ÿ�
	ch = prog[p++];									
	while(ch == ' ')ch = prog[p++];//ȥ���ո��Ӱ��
	while(ch == 10)ch = prog[p++];//10 asc���ǻس���ֵ��ȥ���س���Ӱ��
	m = 0;
//�����ĸ��ʼ
	if(ch >= 'A'&&ch <= 'z')
	{
		while ((ch >= 'A'&&ch <= 'z')||(ch >= '1'&&ch <= '9')) {
			token[m++] = ch;
			ch = prog[p++];
		}
		token[m++] = '\0';
		//printf("%s",token);
		p--;//����һ���ַ�
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
//������ֿ�ʼ
	//��ʼ��sum
	sum = 0;
	int con = 1;
	int index = 0;
	if (ch >= '0'&&ch <= '9') {
		while (ch >= '0'&&ch <= '9') {
			sum = sum * 10 + ch - '0';
			ch = prog[p++];
		}
		//number,�ڶ���,ʹ�� con ����
		if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
		{
			ch = prog[p++];
			while (ch >= '0'&&ch <= '9') {
				sum = sum + pow(0.1,con) * (ch - '0');//con �޴�
				ch = prog[p++];
				con++;//�´�ʹ��ǰ��'0',con �޴�
			}
		}
		//number,�ڶ��㣬ʹ�� index ����
			if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') {//�жϣ���ָ������ָ��û������������
				ch = prog[p++];//��e/E����
				while (ch >= '0'&&ch <= '9') {
					index = index*10 + ch - '0';
					ch = prog[p++];
				}
				sum = sum * pow(10.0,index);
			}
			if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') {//�жϣ���ָ����������������
				ch = prog[p++];
				if (ch == '-') {//ָ������Ϊ'-'
					ch = prog[p++];
					while (ch >= '0'&&ch <= '9') {
						index = index*10 + ch - '0';
						ch = prog[p++];
					}
					index = -1 * index;
					sum = sum * pow(10.0,index);
				}
				else if (ch == '+') {//ָ������Ϊ'+'
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


//�������,'#'��ʶ��
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
					ch = prog[p++];//����'+'
					while (ch >= '0'&&ch <= '9') {
					sum = sum * 10 + ch - '0';
					ch = prog[p++];
					}
					//number,�ڶ���,ʹ�� con ����
					if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
					{
						ch = prog[p++];
						while (ch >= '0'&&ch <= '9') {
							sum = sum + pow(0.1,con) * (ch - '0');//con �޴�
							ch = prog[p++];
							con++;//�´�ʹ��ǰ��'0',con �޴�
						}
					}
					//number,�ڶ��㣬ʹ�� index ����
						if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') {//�жϣ���ָ������ָ��û������������
							ch = prog[p++];//��e/E����
							while (ch >= '0'&&ch <= '9') {
								index = index*10 + ch - '0';
								ch = prog[p++];
							}
							sum = sum * pow(10.0,index);
						}
						else if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') 
						{//�жϣ���ָ����������������
							ch = prog[p++];
							if (ch == '-') {//ָ������Ϊ'-'
								ch = prog[p++];
								while (ch >= '0'&&ch <= '9') {
									index = index*10 + ch - '0';
									ch = prog[p++];
								}
								index = -1 * index;
								sum = sum * pow(10.0,index);
							}
							else if (ch == '+') {//ָ������Ϊ'+'
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
							string str = buf;//��char*ת��Ϊstring
							str = "ERROR WORD:" + str + 'e' + prog[p];
							cout<<str<<endl;
							p+=1;
							syn = -1;
							return -1;
						}
					p--;
					syn = 11;
					return syn;	//����number���ֱ����			
					}
			syn = 13;token[0] = ch;return syn;//����+���ֱ����
			}
		case '-':
			{	
				/*����+��ĸ������*/
				if (prog[p] >= '0'&&prog[p] <= '9' ) 
				{
					ch = prog[p++];//����'-'
					while (ch >= '0'&&ch <= '9') 
					{
					sum = sum * 10 + ch - '0';
					ch = prog[p++];
					}
					//number,�ڶ���,ʹ�� con ����
					if(ch == '.'&&prog[p] >= '0'&&prog[p] <= '9')
					{
						ch = prog[p++];
						while (ch >= '0'&&ch <= '9') {
							sum = sum + pow(0.1,con) * (ch - '0');//con �޴�
							ch = prog[p++];
							con++;//�´�ʹ��ǰ��'0',con �޴�
						}
					}
					/*�˴����� '.x' ����x�������֣��򱨴�������������ַ���*/
					//number,�ڶ��㣬ʹ�� index ����
						if ((ch == 'E'||ch == 'e')&&prog[p] >= '0'&&prog[p] <= '9') 
						{//�жϣ���ָ������ָ��û������������
							ch = prog[p++];//��e/E����
							while (ch >= '0'&&ch <= '9') {
								index = index*10 + ch - '0';
								ch = prog[p++];
							}
							sum = sum * pow(10.0,index);
						}
						else if ((ch == 'E'||ch == 'e')&&(prog[p] == '+'||prog[p] == '-')&&prog[p+1] >= '0'&&prog[p+1] <= '9') 
						{//�жϣ���ָ����������������
							ch = prog[p++];
							if (ch == '-') {//ָ������Ϊ'-'
								ch = prog[p++];
								while (ch >= '0'&&ch <= '9') {
									index = index*10 + ch - '0';
									ch = prog[p++];
								}
								index = -1 * index;
								sum = sum * pow(10.0,index);
							}
							else if (ch == '+') {//ָ������Ϊ'+'
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
							string str = buf;//��char*ת��Ϊstring
							str = "ERROR WORD" + str + 'e' + prog[p];
							cout<<str<<endl;
							p+=1;
							syn = -1;
							return -1;
							////ר�����ڱ�������������ַ���
							//if(ch == 'e'&&(prog[p] > '9' || prog[p] < '0'))
							//{
							//	char buf[30];							
							//	sprintf_s(buf,"%f",sum);//����һ�����⣬���������ȥ��
							//	cout<<buf<<endl;
							//	syn = -1;
							//	/*ת��Ϊ����������ַ���*/
							//}
						}
					sum = -1 * sum;//'-'��
					p--;
					syn = 11;
					return syn;	//����number���ֱ����	
				}
				syn = 14;token[0] = ch;return syn;
			}
		case '*':syn = 15;token[0] = ch;return syn;
		case '/':
			{
				//�ж�ע��
				
				syn = 16;token[0] = ch;return syn;
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
