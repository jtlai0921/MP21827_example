/*
[�ܽd]:���J�ƧǪk
*/
#include <iostream>
#include <iomanip>
#define SIZE 6  //�w�q�}�C�j�p
using namespace std;

void inser (int *);//�ŧi���J�ƧǪk�Ƶ{��
void showdata (int *);//�ŧi�C�L�}�C�Ƶ{��
void inputarr (int *,int);//�ŧi��J�}�C�Ƶ{��
int  main(void)
{ 
    int data[SIZE];
	inputarr(data,SIZE);//��}�C�W�٤ΰ}�C�j�p�ǵ��Ƶ{��
	cout<<"�z��J����l�}�C�O�G";
	showdata (data);
	inser(data);
	return 0;
}
void inputarr(int data[],int size)
{
	for (int i=0;i<size;i++)//�Q�ΰj���J�}�C���
	{ 
		cout<<"�п�J�� "<<i+1<<" �Ӥ����G";
		cin>>data[i];
	}
}
void showdata(int data[])
{  
	for (int i=0;i<SIZE;i++)
		cout<<setw(3)<<data[i];//�C�L�}�C���
	cout<<endl;
}
void inser(int data[])
{  
	int i; //i�����y����
	int j; //�Hj�өw����������
	for (i=1;i<SIZE;i++)  //���y�j�馸�Ƭ�SIZE-1
	{  
 		int tmp;  //tmp�ΨӼȦs���
		tmp=data[i];
        j=i-1;
	    while (j>=0 && tmp<data[j]) //�p�G�ĤG�����p��Ĥ@����
		{							 
			data[j+1]=data[j];		//�N��Ҧ�����������@�Ӧ�m		
			j--;
		}
		data[j+1]=tmp;              //�̤p���������Ĥ@�Ӥ���	
		cout<<"�� "<<i<<" �����ˡG";
		showdata(data);
	}
}
