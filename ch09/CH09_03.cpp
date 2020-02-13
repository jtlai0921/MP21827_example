#include <iostream>
#include <iomanip>
using namespace std;
class tree //�`�I��C���c�ŧi
{  
    public :
	    int data; //�`�I��� 
	    class tree *left,*right; //�`�I�����ФΥk���� 
};
typedef class tree node;
typedef node *btree;
btree creat_tree(btree,int);
void pre(btree);
void in(btree);
void post(btree);
int main(void)
{  
	int arr[]={7,4,1,5,16,8,11,12,15,9,2};//��l�}�C���e 
	btree ptr=NULL; //�ŧi��� 
	cout<<"[��l�}�C���e]"<<endl;
	for (int i=0;i<11;i++)//�إߤG����A�ñN�G���𤺮e�C�L�X�� 
	{  
	    ptr=creat_tree(ptr,arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"[�G���𪺤��e]"<<endl;
	cout<<"�e�Ǩ��X���G�G"<<endl;//�C�L�e�B���B��Ǩ��X���G 
	pre(ptr);
	cout<<endl;
	cout<<"���Ǩ��X���G�G"<<endl;
	in(ptr);
	cout<<endl;
	cout<<"��Ǩ��X���G�G"<<endl;
	post(ptr);
	cout<<endl;
	return 0;
}
btree creat_tree(btree root,int val)//�إߤG���𪺰Ƶ{�� 
{  
	btree newnode,current,backup;   //�ŧi�@�ӷs�`�Inewnode�s��}�C��� 
	newnode = new node; //current��backup�s��Ȧs���� 
	newnode->data=val;  //���w�s�`�I����ƤΥ��k���� 
	newnode->left=NULL;
	newnode->right=NULL;
	if (root==NULL)//�p�Groot���ŭȡA��s�`�I�Ǧ^��@��� 
	{  
		root=newnode;
		return root;
	}
	else //�Yroot���O��ڡA�h�إߤG���� 
	{  
		for(current=root;current!=NULL;) //current�ƻsroot�A�H�O�d�ثe����ڭ� 
		{  
			backup=current; //�O�d���`�I 
			if(current->data > val)//�����ڸ`�I�ηs�`�I��� 
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)//��s�`�I�M��ڳs���_�� 
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root; //�Ǧ^����� 
}
void pre(btree ptr) //�e�Ǩ��X 
{  
	if (ptr != NULL)
	{  
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		pre(ptr->left);
		pre(ptr->right);
	}
}
void in(btree ptr) //���Ǩ��X 
{  
	if (ptr != NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}
void post(btree ptr)//��Ǩ��X
{  
	if (ptr != NULL)
	{  
		post(ptr->left);
		post(ptr->right);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
	}
}
