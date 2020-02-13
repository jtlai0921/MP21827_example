/*
[�ܽd]:�̤p�����X�i��
*/
#include <iostream>
#define VERTS	6 //�ϧγ��I��
using namespace std;
class edge  //�䪺���c�ŧi
{  
    public:
        int from,to;
	    int find,val;
	    class edge* next;
};
typedef class edge node;
typedef node* mst;
void mintree(mst head);
mst findmincost(mst head);    
int v[VERTS+1];
int main(void)
{  
	int data[10][3]={{1,2,6},{1,6,12},
            {1,5,10},{2,3,3},//������}�C
            {2,4,5},{2,6,8},{3,4,7},{4,6,11},
			{4,5,9},{5,6,16}};
	mst head,ptr,newnode;
	head=NULL;
	cout<<"�إ߹ϧΦ�C�G"<<endl;
	for(int i=0;i<10;i++)//�إ߹ϧΦ�C
	{  
		for(int j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
			    newnode = new node;
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	ptr=head;
	while(ptr!=NULL)//�C�L�ϧΦ�C
	{  
		cout<<"�_�l���I ["<<ptr->from<<"]\t�פ�I ["
        <<ptr->to<<"]\t���|���� ["<<ptr->val<<"]";
		cout<<endl;
		ptr=ptr->next;
	}
	cout<<"�إ̤߳p�����X�i��G"<<endl;
	mintree(head); //�إ̤߳p�����X�i��
	delete newnode;
}
mst findmincost(mst head)//�j�M�����̤p����
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval && ptr->find==0)
		{   //���pptr->val���Ȥp��minval
		    minval=ptr->val; //�N��ptr->val�]���̤p��
			retptr=ptr;//�åB��ptr�����U��
		}
		ptr=ptr->next;
	}
	retptr->find=1; //�Nretptr�]���w��쪺��
	return retptr;  //�Ǧ^retptr
}
void mintree(mst head) //�̤p�����X�i��Ƶ{��
{
	mst ptr,mceptr;
	int result=0;
	ptr=head;

	for(int i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1 && v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			cout<<"�_�l���I ["<<mceptr->from
            <<"]\t�פ�I ["<<mceptr->to<<"]\t���|���� ["
            <<mceptr->val<<"]"<<endl;
		ptr=ptr->next;
	}
}
