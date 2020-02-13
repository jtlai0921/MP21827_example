#include <iostream>
#include <iomanip>
#include <ctime>
#include<cstdlib>
using namespace std;
const int INDEXBOX=7;  //��������Ӽ�
const int MAXNUM=13;   //��ƭӼ�
void creat_table(int); //�ŧi�إ������Ƶ{��
void print_data(int);  //�ŧi�C�L�����Ƶ{��
int findnum(int);      //�ŧi����j�M�Ƶ{��
class list	//�ŧi��C���O 
{
	public:
	int val;
	list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];//�ŧi�ʺA�}�C
int main(void)
{  
	int i,num,data[MAXNUM];
	srand(time(NULL));
	for(i=0;i<INDEXBOX;i++)//�M�������
	{  
		indextable[i].val=i;
		indextable[i].next=NULL;
	}
	cout<<"��l��ơG\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1;//�üƫإ߭�l���
		cout<<"["<<setw(2)<<data[i]<<"] ";//�æC�L�X��
		
		if (i%8==7)
			cout<<"\n\t";
	}
	cout<<endl;
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]);//�إ������
	while(1)
	{  
		cout<<"�п�J�j�M���(1-30)�A�����п�J-1�G";
		cin>>num;
		if(num==-1)
			break;
		i=findnum(num);
		if(i==0)
			cout<<"#####�S����� "<<num<<" #####"<<endl;
		else
			cout<<"��� "<<num<<"�A�@��F "<<i<<" ��!"<<endl;
	}
	cout<<"\n�����G"<<endl;
	for(i=0;i<INDEXBOX;i++)
		print_data(i);//�C�L�����
	cout<<endl;
	return 0;
}
void creat_table(int val)//�إ������Ƶ{��
{  
	link newnode;
	int hash;
	hash=val%7; //�����ư��H7���l��
	newnode=(link)malloc(sizeof(node));
	if(!newnode)
	{  
		cout<<"ERROR!! �O����t�m����!!"<<endl;
		exit(1);
	}
	newnode->val=val;
	newnode->next=NULL;
	newnode->next=indextable[hash].next;//�[�J�`�I
	indextable[hash].next=newnode;
}
void print_data(int val)//�C�L�����Ƶ{��
{  
	link head;
	int i=0;
	head=indextable[val].next;//�_�l����
	cout<<setw(2)<<val<<"�G\t";//���ަ�}
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)//�������
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b "<<endl;//�M���̫�@��"-"�Ÿ�
}
int findnum(int num)  //����j�M�Ƶ{��
{  
	link ptr;
	int i=0,hash;
	hash=num%7;
	ptr=indextable[hash].next;
	while(ptr!=NULL)
	{  
		i++;
		if(ptr->val==num)
			return i;
		else
			ptr=ptr->next;
	}
	return 0;
}
