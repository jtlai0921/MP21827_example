#include <iostream>
#include <iomanip>
using namespace std;
class tree
{  
    public:
        int data;
        class tree *left,*right;
};
typedef class tree node;
typedef node *btree;

btree creat_tree(btree,int);
btree pre(btree,int); //�j�M�G����Ƶ{��

int main(void)
{  
	int data,arr[]={7,4,1,5,13,8,11,12,15,9,2};
	btree ptr=NULL;
	cout<<"[��l�}�C���e]"<<endl;
	for (int i=0;i<11;i++)              
	{  
	    ptr=creat_tree(ptr,arr[i]);//�إߤG����
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"�п�J�j�M�ȡG"<<endl;
	cin>>data;
	if((pre(ptr,data)) !=NULL)//�j�M�G����
		cout<<"�A�n�䪺�� ["<<setw(3)<<data<<"] �����!!"<<endl;
	else
		cout<<"�z�n�䪺�ȨS���!!"<<endl;
	return 0;
}
btree creat_tree(btree root,int val)
{  
	btree newnode,current,backup;
	newnode = new node;
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}
btree pre(btree ptr,int val)//�j�M�G����Ƶ{��
{  
	int i=1;//�P�_���榸�ƪ��ܼ�
	while(1)
	{  
		if(ptr==NULL) //�S���N�Ǧ^NULL
			return NULL;
		if(ptr->data==val)//�`�I�ȵ���j�M��
		{  
			cout<<"�@�j�M "<<setw(3)<<i<<" ��"<<endl;
			return ptr;
		}
		else if(ptr->data > val)//�`�I�Ȥj��j�M��
			ptr=ptr->left;
		else
			ptr=ptr->right;
		i++;
	}   
}
