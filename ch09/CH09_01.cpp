#include <iostream>
using namespace std;

class tree //�`�I��C���c�ŧi
{  
	public:
	int data; //�`�I���
	class tree *left,*right; //�`�I�����ФΥk����
};
typedef class tree node;
typedef node *btree;
void Inorder(btree ptr);
int main(void)
{  
	int i,level;
	int data[]={0,6,3,5,9,7,8,4,2}; //��l�}�C
	int btree[16]={0}; //�s��G���ư}�C
	cout<<"��l�}�C���e�G"<<endl;
	for (i=1;i<9;i++)
		cout<<"["<<data[i]<<"] ";
	cout<<endl;
	for(i=1;i<9;i++)   //���l�}�C�����ȳv�@���
	{  
		for(level=1;btree[level]!=0;)
		//�����ڤΰ}�C������
		{  
			if(data[i]>btree[level])
			//�p�G�}�C�����Ȥj���ڡA�h���k�l����
				level=level*2+1;
			else  //�p�G�}�C�����Ȥp��ε����ڡA�h�����l����
				level=level*2;
		}     //�p�G�l��`�I���Ȥ���0�A�h�A�P�}�C�����Ȥ���@��
		btree[level]=data[i];  //��}�C�ȩ�J�G����
	}
	cout<<"�G���𤺮e�G"<<endl;
	for (i=1;i<16;i++)
		cout<<"["<<btree[i]<<"] ";
	cout<<endl;
	return 0;
}
void Inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->left); //���X���l��
		cout<<"["<<ptr->data<<"]"; //���X�C�L���
		Inorder(ptr->right); //���X�k�l��
	}
}
