/*
[�ܽd]:�D�XMxN�x�}����m�x�}
*/
#include <iostream>
using namespace std;

int main()
{
	int M,N,row,col;
	cout<<"[��JMxN�x�}������]"<<endl;
	cout<<"�п�J����M: ";
	cin>>M;
	cout<<"�п�J����N: ";
	cin>>N;
	
   	int *arrA = new int[M*N];//�ŧi�ʺA�}�C 
	int *arrB = new int[M*N];
 	cout<<"[�п�J�x�}���e]"<<endl;
	for(row=1;row<=M;row++)
	{
		for(col=1;col<=N;col++)
		{
			cout<<"a"<<row<<col<<"=";
			cin>>arrA[(row-1)*N+(col-1)];
		}
	}
	cout<<"[��J�x�}���e��]"<<endl;
	for(row=1;row<=M;row++)
	{
		for(col=1;col<=N;col++)
		{
			cout<<arrA[(row-1)*N+(col-1)]<<"\t";
		}
		cout<<endl;
	}
	//�i��x�}��m���ʧ@
	for(row=1;row<=N;row++)
		for(col=1;col<=M;col++)
			arrB[(col-1)*N+(row-1)]=arrA[(row-1)+(col-1)*N];

	cout<<"[��m�x�}���e��]"<<endl;
	for(row=1;row<=N;row++)
	{
		for(col=1;col<=M;col++)
		{
			cout<<arrB[(col-1)*N+(row-1)]<<"\t";
		}
		cout<<endl;
	}
}
