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
void in(btree);
int main(void)
{  
	int data;
	btree ptr=NULL;
	cout<<"�п�J��ơA�����п�J-1�G"<<endl;
	while (1)                         
	{  
		cin>>data; //��J���
		if(data==-1)//������J
			break;                      
		ptr=creat_tree(ptr,data);//�إߤG����
	}
	cout<<"=============="<<endl;
	cout<<"�Ƨǧ������G�G"<<endl;
	in(ptr); //���Ǩ��X
	cout<<endl;
	return 0;
}
btree creat_tree(btree root,int val)//�إߤG����Ƶ{��
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
void in(btree ptr)//���Ǩ��X�Ƶ{��
{  
	if(ptr!=NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
