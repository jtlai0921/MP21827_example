/*
[�ܽd]:�¦ձƧǪk
*/
#include <iostream>
#include <iomanip>
#define SIZE 8 //�w�q�x�}�j�p
using namespace std;

void shell (int *,int);  //�ŧi�ƧǪk�Ƶ{��
void showdata (int *);   //�ŧi�C�L�}�C�Ƶ{��
void inputarr (int *,int);//�ŧi��J�}�C�Ƶ{��
int main(void)
{ 
	int data[SIZE];
	inputarr(data,SIZE);
	cout<<"�z��J����l�}�C�O�G";
	showdata(data);
	shell(data,SIZE);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)
	{ 
		cout<<"�п�J�� "<<i+1<<" �Ӥ����G";
		cin>>data[i];
	}
}
void showdata(int data[])
{  	
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void shell(int data[],int size)
{  
	int i;        //i�����y����
	int j;        //�Hj�өw����������
	int k=1;      //k�C�L�p��
	int tmp;      //tmp�ΨӼȦs���
	int jmp;      //�]�w���Z�첾�q
	jmp=size/2;
	while (jmp != 0)
	{  
		for (i=jmp ;i<size ;i++)
		{  
			tmp=data[i];
			j=i-jmp;
			while(tmp<data[j] && j>=0)  //���J�ƧǪk
			{  
				data[j+jmp] = data[j];
				j=j-jmp;
			}	
			data[jmp+j]=tmp;
		}
		cout<<"�� "<<k++<<" ���ƧǡG";
		showdata (data);
		jmp=jmp/2;    //����j���
	}
}
