/*
[�ܽd]:�h�����ۥ[
*/
#include <iostream>
using namespace std;
class list //�ŧi��C���c
{  
	public :
	int coef,exp;
	class list *next;
};
typedef class list node;
typedef node *link;
link creat_link(int data[4]);
void print_link(link head);
link sum_link(link a,link b);
int main()
{  
	link a,b,c;
	int data1[4]={3,0,4,2}; //�h����A���Y��
	int data2[4]={6,8,6,9}; //�h����B���Y��
	cout<<"��l�h�����G"<<endl<<"A=";
	a=creat_link(data1);  //�إߦh����A
	b=creat_link(data2);  //�إߦh����B
	print_link(a);   //�C�L�h����A
	cout<<"B=";
	print_link(b);   //�C�L�h����B
	cout<<"�h�����ۥ[���G�G\nC=";
	c=sum_link(a,b); //C��A�BB�h�����ۥ[���G
	print_link(c);   //�C�L�h����C
}
link creat_link(int data[4])//�إߦh�����Ƶ{��
{
	link head,newnode,ptr;
	for(int i=0;i<4;i++)
	{  
		newnode = new node;
		if(!newnode)
		{  
			cout<<"Error!! �O����t�m����!!"<<endl;
			exit(1);
		}
		if(i==0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			head=newnode;
			ptr=head;
		}
		else if(data[i]!=0)
		{  
			newnode->coef=data[i];
			newnode->exp=3-i;
			newnode->next=NULL;
			ptr->next=newnode;
			ptr=newnode;
		}
	}
	return head;
}
void print_link(link head) //�C�L�h�����Ƶ{��
{  
	while(head!=NULL) 
	{  
		if(head->exp==1 && head->coef!=0)//X^1�ɤ���ܫ���
			cout<<head->coef<<"X + ";
		else if(head->exp!=0 && head->coef!=0)
			cout<<head->coef<<"X^"<<head->exp<<" + ";
		else if(head->coef!=0)           //X^0�ɤ�����ܼ�
			cout<<head->coef;
		head=head->next;
	}
	cout<<endl;
}
link sum_link(link a,link b) //�h�����ۥ[�Ƶ{��
{  
	int sum[4],i=0;
	link ptr;
	ptr=b;
	while(a!=NULL) //�P�_�h����1
	{  
		b=ptr; //���Ƥ��A��B������
		while(b!=NULL)
		{  
			if(a->exp==b->exp)//���Ƭ۵��A�Y�Ƭۥ[
			{  
				sum[i]=a->coef+b->coef;
				a=a->next;
				b=b->next;
				i++;
			}
			else if(b->exp > a->exp)//B���Ƹ��j�A���w�Y�Ƶ�C
			{  
				sum[i]=b->coef;
				b=b->next;
				i++;
			}
			else if(a->exp > b->exp)//A���Ƹ��j�A���w�Y�Ƶ�C
			{  
				sum[i]=a->coef;
				a=a->next;
				i++;
			}
		}
	}
	return creat_link(sum);//�إ߬ۥ[���G��CC
}
