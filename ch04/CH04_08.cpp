/*
[�ܽd]:��ƱƧǪk
*/
// ��ƱƧǪk �Ѥp��j�Ƨ� 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
void radix (int *,int);	// ��ƱƧǪk�Ƶ{�� 
void showdata (int *,int);
void inputarr (int *,int);
int main(void)
{ 
	int size,data[100]={0};
	cout<<"�п�J�}�C�j�p(100�H�U)�G";
	cin>>size;
	cout<<"�z��J����l��ƬO�G"<<endl;
	inputarr (data,size);
	showdata (data,size);
	radix (data,size);
	return 0;
}
void inputarr(int data[],int size)
{
	srand(time(NULL));
	for (int i=0;i<size;i++)
		data[i]=(rand()%999)+1;	
			// �]�wdata �ȳ̤j�� 3 ��� 
}
void showdata(int data[],int size)
{  
	for (int i=0;i<size;i++)
		cout<<setw(5)<<data[i];
	cout<<endl;
}
void radix(int data[],int size)
{  
	for (int n=1;n<=100;n=n*10)		
	// n����ơA�ѭӦ�ƶ}�l�Ƨ� 
	{  
		int tmp[10][100]={0};		
		// �]�w�Ȧs�}�C�A[0~9���][��ƭӼ�]�A�Ҧ����e����0 
		for (int i=0;i<size;i++) // ���Ҧ���� 
		{  
			int m=(data[i]/n)%10;	
			// m��n��ƪ��ȡA�p 36���Q��� (36/10)%10=3 
			tmp[m][i]=data[i];		
			// ��data[i]���ȼȦs��tmp �� 
		}
		int k=0;
		for (int i=0;i<10;i++)
		{  
			for(int j=0;j<size;j++)
			{  
				if(tmp[i][j] != 0)		
				// �]�@�}�l�]�w tmp ={0}�A�G����0�̧Y�� 
				{  
					data[k]=tmp[i][j];	
					// data�Ȧs�b tmp �̪��ȡA��tmp �̪��ȩ� 
					k++;		        // �^data[ ]�� 
				}
			}
		}
		cout<<"�g�L"<<setw(3)<<n<<"��ƱƧǫ�G";
		showdata(data,size);
	} 
}
