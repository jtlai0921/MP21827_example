#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>  //�ϥζüƪ����Y�� 
using namespace std;
class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
};
list del_ptr(list *head,list *ptr);
int main()
{  
	list *ptr;
	int findword=0,find,data[12][2];
	char namedata[12][10]={{"Allen"},{"Moko"},
    {"Lean"},{"Melissa"},{"Angel"},{"Sabrina"},
    {"Joyce"},{"Jasica"},{"Hanson"},{"Amy"},
    {"Bob"},{"Jack"}};
	srand((unsigned)time(NULL));//�H�ɶ����üƪ��ؤl
	cout<<"�y�� ���Z  �y�� ���Z  �y�� ���Z  �y��  ���Z"<<endl;
	cout<<"=============================================="<<endl;
	for(int i=0;i<12;i++)
	{  
		data[i][0]=i+1;
		data[i][1]=rand()%50+51;
	}
	for(int i=0;i<3;i++)
	{  
		for (int j=0;j<4;j++)
			cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]  ";
		cout<<endl;
	}
	list *head=new list;//�إߦ�C��
 	if(!head)
	{  
		cout<<"Error!! �O����t�m����!!"<<endl;
		exit(1);
	}
	head->num=data[0][0];
	for (int j=0;j<10;j++)
		head->name[j]=namedata[0][j];
	head->score=data[0][1];
	head->next=NULL;
	ptr=head;
	for(int i=1;i<12;i++)                   
	{  
		list *newnode=new list;//�إߦ�C
  		newnode->num=data[i][0];
		for (int j=0;j<10;j++)
			newnode->name[j]=namedata[i][j];
		newnode->score=data[i][1];
		newnode->next=NULL;
		ptr->next=newnode;
		ptr=ptr->next;
	}
	while(1)
	{  
		cout<<"�п�J�n�R�������Z�A������J-1�G";
		cin>>findword;
		if(findword==-1)//�j�餤�_����
			break;
		else
		{  
			ptr=head;
			find=0;
			while (ptr!=NULL)
			{  
				if(ptr->score==findword)     
				{  
					*ptr=del_ptr(head,ptr);//�R�����
     				find++;
				}
				ptr=ptr->next;
			}
			if(find==0)
			cout<<"######�S�����######"<<endl;
		}
	}
	ptr=head;
	cout<<"\n\t�y��\t    �m�W\t���Z"<<endl; //�C�L�Ѿl��C���
	cout<<"\t=============================="<<endl;
	while(ptr!=NULL)
	{  
		cout<<"\t["<<ptr->num<<"]\t["<<setw(10)<<ptr->name
            <<"]\t["<<ptr->score<<"]"<<endl;
		ptr=ptr->next;
	}
}
list del_ptr(list *head,list *ptr)//�R���`�I�Ƶ{��
{  
	list *top;
 	top=head;
	if(ptr==head)//[����1]:�R���I�b��C��
	{  
		head=head->next;
		cout<<"�w�R���� "<<ptr->num<<" ���ǥ�!!�m�W�G "
            <<ptr->name<<endl;
	}
	else
	{  
		while(top->next!=ptr)//���R���I���e�@�Ӧ�m
			top=top->next;
		if(ptr->next==NULL)  //[����2]:�R���I�b��C��
		{  
			top->next=NULL;
	 		cout<<"�w�R���� "<<ptr->num<<" ���ǥ�!!�m�W�G "
                <<ptr->name<<endl;
		}
		else  //[����3]:�R���I�b��C�����@�`�I
		{  
			top->next=ptr->next;
			cout<<"�w�R���� "<<ptr->num<<" ���ǥ�!!�m�W�G "
                <<ptr->name<<endl;
		}
	}
    delete []ptr;  //����O����Ŷ�
    return *head;  //�^�Ǧ�C
}
