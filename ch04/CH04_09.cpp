/*
[�ܽd]:��n�ƧǪk
*/
#include <iostream>
#include <iomanip>
using namespace std;
void heap(int*,int);
void ad_heap(int*,int,int);
int main(void)
{  
	int data[9]={0,5,6,4,8,3,2,7,1};	
	//��l�}�C���e
	int size=9;
	cout<<"��l�}�C�G";
	for(int i=1;i<size;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	heap(data,size);						
	//�إ߰�n��
	cout<<"\n�Ƨǵ��G�G";
	for(int i=1;i<size;i++)
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
	return 0;
}
void heap(int *data,int size)
{  
	int i,j,tmp;
	for(i=(size/2);i>0;i--)			    
	//�إ߰�n��`�I	
		ad_heap(data,i,size-1);
	cout<<"\n��n���e�G";
	for(i=1;i<size;i++)				
		//��l��n�𤺮e
		cout<<"["<<setw(2)<<data[i]<<"] ";
	cout<<endl;
	for(i=size-2;i>0;i--)			
		//��n�Ƨ�
	{  
		tmp=data[i+1];				
			//�Y���`�I�洫      
		data[i+1]=data[1];
		data[1]=tmp;
		ad_heap(data,1,i);			   
		    //�B�z�Ѿl�`�I
		cout<<"\n�B�z�L�{�G";
		for(j=1;j<size;j++)
			cout<<"["<<setw(2)<<data[j]<<"] ";
	}
}
void ad_heap(int *data,int i,int size)
{  
	int j,tmp,post;
	j=2*i;
	tmp=data[i];
	post=0;
	while(j<=size && post==0)
	{  
		if(j<size)
		{
			if(data[j]<data[j+1])	
				//��X�̤j�`�I
				j++;
		}
		if(tmp>=data[j])				
		//�Y��ڸ��j�A��������L�{
			post=1;
		else
		{  
			data[j/2]=data[j];			
			//�Y��ڸ��p�A�h�~����
			j=2*j;
		}   
   }
   data[j/2]=tmp;					
   	//���w��ڬ����`�I
}
