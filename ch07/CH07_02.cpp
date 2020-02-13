#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define INDEXBOX 7     //��������Ӽ�
#define MAXNUM 13      //��ƭӼ�
using namespace std;
void creat_table(int); //�ŧi�إ������Ƶ{��
void print_data(int);  //�ŧi�C�L�����Ƶ{��
class list             //�ŧi��C���c
{  
    public:
	int val;
	class list *next;
};
typedef class list node;
typedef node *link;
node indextable[INDEXBOX];  //�ŧi�ʺA�}�C
int main(void)
{  
	int i,data[MAXNUM];
	srand((unsigned)time(NULL));
	for(i=0;i<INDEXBOX;i++) //�M�������
	{  
		indextable[i].val=-1;
		indextable[i].next=NULL;
	}
	cout<<"��l��ơG\n\t";
	for(i=0;i<MAXNUM;i++)
	{  
		data[i]=rand()%30+1; //�üƫإ߭�l���
		cout<<"["<<setw(2)<<data[i]<<"] "; //�æC�L�X��
		if(i%8==7)
			cout<<"\n\t";
	}
	cout<<"\n�����G\n";
	for(i=0;i<MAXNUM;i++)
		creat_table(data[i]); //�إ������
	for(i=0;i<INDEXBOX;i++)
		print_data(i);    //�C�L�����
	cout<<endl;
	return 0;
}
void creat_table(int val) //�إ������Ƶ{��
{  
	link newnode;
	link current;
	int hash;
	hash=val%7;          //�����ư��H7���l��
	newnode=(link)malloc(sizeof(node));
	current=(link)malloc(sizeof(node));
	newnode->val=val;
	newnode->next=NULL;
	*current=indextable[hash];
    if(current->next==NULL) 
        indextable[hash].next=newnode;
    else
        while(current->next!=NULL) current=current->next;
    current->next=newnode; //�N�`�I�[�b��C
}
void print_data(int val)   //�C�L�����Ƶ{��
{  
	link head;
	int i=0;
	head=indextable[val].next;  //�_�l����
	cout<<"   "<<setw(2)<<val<<"�G\t";//���ަ�}
	while(head!=NULL)
	{  
		cout<<"["<<setw(2)<<head->val<<"]-";
		i++;
		if(i%8==7)  //�������
			cout<<"\n\t";
		head=head->next;
	}
	cout<<"\b \n";//�M���̫�@��"-"�Ÿ�
}
