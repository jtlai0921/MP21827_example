/*
[�ܽd]:��@��C��ƪ��s�J�M���X
*/
#include <iostream>
using namespace std;
const int MAX=20;//�w�q��C���j�p
int main(void)
{
	int front,rear,val,queue[MAX]={0};
	char ch;
	front=rear=-1;
	while(rear<MAX-1&&ch!='E')
	{  
		cout<<"[I]�s�J�@�Ӽƭ�[G]���X�@�Ӽƭ�[E]����: ";
		cin>>ch;
		switch(ch)
		{
			case 'I':
				cout<<"[�п�J�ƭ�]: ";
				cin>>val;
				rear++;
				queue[rear]=val;
				break;
			case 'G':
				if(rear>front)
				{  
					front++;
					cout<<"[���X�ƭȬ�]: ["<<queue[front]<<"]";
					cout<<endl;
					queue[front]=0;
				}
				else
				{  
					cout<<"[��C�w�g�ŤF]"<<endl;
					exit(0);
				}
				break;
			default:
				cout<<endl;
				break;
		}
	}
	if(rear==MAX-1) cout<<"[��C�w�g���F]"<<endl;
	cout<<"[�ثe��C�������]:";
	if (front>=rear)
	{
		cout<<"�S��"<<endl;
		cout<<"[��C�w�g�ŤF]"<<endl;
	}
	else
	{
		while (rear>front)
		{  
			front++;
			cout<<"["<<queue[front]<<"]\t";
		}
		cout<<endl;
	}
	return 0;
}
