#include <iostream>
#include <iomanip>
using namespace std;
void bubble (int *);   //�ŧi��w�ƧǰƵ{��
void showdata (int *); //�ŧi�C�L�}�C�Ƶ{��
int main(void)
{
    int data[6]={4,6,2,7,8,9}; //��l���
    cout<<"��}��w�ƧǪk\n��l��Ƭ��G\t";
    showdata(data);
    bubble(data);
    return 0;
}
void showdata (int data[]) //�Q�ΰj��C�L���
{
	for (int i=0;i<6;i++)
		cout<<setw(3)<<data[i];
	cout<<endl;
}
void bubble (int data[])
{
	for(int i=5;i>=0;i--)
	{
		int flag=0;  //flag�ΨӧP�_�O�_������洫���ʧ@
		for (int j=0;j<i;j++)
		{
			if (data[j+1]<data[j])
			{
				int tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;    //�p�G������L�洫�A�hflag����0
			}
		}
		if (flag==0)
			break;
		/*
		����槹�@�����y�N�P�_�O�_���L�洫�ʧ@�A�p�G�S���洫�L���
		�A��ܦ��ɰ}�C�w�����ƧǡA�G�i�������X�j��
		*/
		cout<<"�� "<<6-i<<" ���ƧǡG\t";
		for (int j=0;j<6;j++)
			cout<<setw(3)<<data[j];
		cout<<endl;		    
	}
	cout<<"�Ƨǫᵲ�G���G\t";
	showdata (data);
}
