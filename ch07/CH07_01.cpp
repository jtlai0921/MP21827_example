#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX = 10;   //�����̤j����
const int MAXNUM = 7;       //�̤j��ƭӼ�
int print_data(int *,int);
int creat_table(int ,int *);

int main(void)
{  
	int i,index[INDEXBOX],data[MAXNUM];
	srand(time(NULL));     //�̮ɶ���l�ü�
	cout<<"��l�}�C�ȡG\n";
	for(i=0;i<MAXNUM;i++)       //�_�l��ƭ�
		data[i]=rand()%20+1;
	for(i=0;i<INDEXBOX;i++)     //�M�������
		index[i]=-1;
	print_data(data,MAXNUM);    //�C�L�_�l���
	cout<<"������e�G"<<endl;
	for(i=0;i<MAXNUM;i++)       //�إ������
	{  
		creat_table(data[i],index);
		cout<<data[i]<<" =>";  //�C�L��@������������m
		print_data(index,INDEXBOX);
	}
	cout<<"���������G"<<endl;     
	print_data(index,INDEXBOX);  //�C�L�̫᧹�����G
	return 0;
}
int print_data(int *data,int max)  //�C�L�}�C�Ƶ{��
{  
	cout<<"\t";
	for(int i=0;i<max;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
}
int creat_table(int num,int *index)  //�إ������Ƶ{��
{  
	int tmp;
	tmp=num%INDEXBOX;  //������=���%INDEXBOX
	while(1)
	{  
		if(index[tmp]==-1) //�p�G��ƹ�������m�O�Ū�
		{  
			index[tmp]=num; //�h�����s�J���
			break;
		}
		else
			tmp=(tmp+1)%INDEXBOX; //�_�h������m�s��
	}
}
