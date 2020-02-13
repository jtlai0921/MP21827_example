#include <iostream>
using namespace std;
class list
{  
	public:
	    int val;
        class list *next;
};
typedef class list node;
typedef node *link;
class list* head[9];
void dfs(int);
int run[9];
int main(void)
{  
	link ptr,newnode;
    //�ϧ���u�}�C�ŧi
    int data[20][2]={{1,2},{2,1},{1,3},{3,1},
	                 {2,4},{4,2},{2,5},{5,2},					
	                 {3,6},{6,3},{3,7},{7,3},
	                 {4,5},{5,4},{6,7},{7,6},
					 {5,8},{8,5},{6,8},{8,6}};

	for (int i=1;i<=8;i++)//�@���K�ӳ��I
	{  
		run[i]=0;         //�]�w�Ҧ����I���|�����X�L
		head[i]= new node;   
		head[i]->val=i;   //�]�w�U�Ӧ�C�������
		head[i]->next=NULL;
		ptr=head[i];      //�]�w���Ь���C��
		for(int j=0;j<20;j++) //�G�Q����u
		{  
			if(data[j][0]==i) //�p�G�_�I�M��C���۵��A�h�⳻�I�[�J��C
			{  
				newnode =new node;
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;//�[�J�s�`�I
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		} 
	}
	cout<<"�ϧΪ��F����C���e�G"<<endl;//�C�L�ϧΪ��F����C���e
	for(int i=1;i<=8;i++)
	{
		ptr=head[i];
		cout<<"���I "<<i<<"=> ";
		ptr = ptr->next;
		while(ptr!=NULL)
		{
		    cout<<"["<<ptr->val<<"] ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	cout<<"�`���u�����X���I�G"<<endl;//�C�L�`���u�����X�����I
	dfs(1);
	cout<<endl;
}
void dfs(int current) //�`���u�����X�Ƶ{��
{  
	link ptr;
	run[current]=1;
	cout<<"["<<current<<"] ";
	ptr=head[current]->next;
	while(ptr!=NULL)
	{		
		if (run[ptr->val]==0)//�p�G���I�|�����X�A
			dfs(ptr->val);   //�N�i��dfs�����j�I�s
		ptr=ptr->next;
	}
}

