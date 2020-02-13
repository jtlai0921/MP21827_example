#include <iostream>
#include <cstdlib>
#include <iomanip>
#define MAX 20
using namespace std;
int fib(int n)
{
    if(n==1 || n==0)
        return n;
    else
        return fib(n-1)+fib(n-2);
}
int fib_search(int data[MAX],int SearchKey)
{
    int index=2; 
    //�O��ƦC���j�M
    while(fib(index)<=MAX)
        index++;
    index--;
    //index >=2
    //�_�l���O���
    int RootNode=fib(index);
    //�W�@�ӶO���
    int diff1=fib(index-1); 
    //�W�G�ӶO��ƧYdiff2=fib(index-2)
    int diff2=RootNode-diff1;
    RootNode--;//�o�C�B�⦡�O�t�X�}�C�����ެO�q0�}�l�x�s���
    while(1)
    {
       if(SearchKey==data[RootNode])
       {
            return RootNode;
       }
       else
       {
            if(index==2) return MAX; //�S�����
            if(SearchKey<data[RootNode])
            {
                RootNode=RootNode-diff2;//���l�𪺷s�O���
                int temp=diff1;
                diff1=diff2;//�W�@�ӶO���
                diff2=temp-diff2;//�W�G�ӶO���
                index=index-1;
            }
           else
           {
                if(index==3) return MAX;
                RootNode=RootNode+diff2;//�k�l�𪺷s�O��� 
                diff1=diff1-diff2;//�W�@�ӶO���
                diff2=diff2-diff1;//�W�G�ӶO���
                index=index-2;
           }         
       }
    }
}
int main(void)
{  
	int data[]={5,7,12,23,25,37,48,54,68,77,
                91,99,102,110,118,120,130,135,136,150};
    int val;
    int i=0;
    int j=0;
	while(1)
	{  
		cout<<"�п�J�j�M���(1-150)�A��J-1�����G";
		cin>>val;//��J�j�M���ƭ�
		if(val==-1)//��J�Ȭ�-1�N�����j��
			break;
		int RootNode=fib_search(data,val);//�Q�ζO��j�M�k��M���
		if(RootNode==MAX)
			cout<<"##### �S�����["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"�b�� "<<setw(2)<<RootNode+1
            <<"�Ӧ�m��� ["<<setw(3)<<data[RootNode]<<"]"<<endl;
	}
	cout<<"��Ƥ��e�G"<<endl;
	for(i=0;i<2;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	return 0;
}
