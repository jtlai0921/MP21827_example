/*
[�ܽd]:�B���ӯx�}�ۭ������G
*/
#include <iostream>
using namespace std;

void MatrixMultiply(int*,int*,int*,int,int,int);
int main()
{
	int M,N,P;
	int i,j;
	//�x�}A���� 
 	cout<<"�п�J�x�}A������(M,N): "<<endl;
 	cout<<"M= ";
	cin>>M;
	cout<<"N= ";
	cin>>N;
	int *A = new int[M*N];
	cout<<"[�п�J�x�}A���U�Ӥ���]"<<endl;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		    {
               cout<<"a"<<i<<j<<"=";
			   cin>>A[i*N+j];
            }
	//�x�}B���� 
 	cout<<"�п�J�x�}B������(N,P): "<<endl;
	cout<<"N= ";
	cin>>N;
	cout<<"P= ";
	cin>>P;
	int *B = new int [N*P];
	cout<<"[�п�J�x�}B���U�Ӥ���]"<<endl;
	for(i=0;i<N;i++)
		for(j=0;j<P;j++)
        {
           cout<<"b"<<i<<j<<"=";
		   cin>>B[i*P+j];
        }	
	int *C = new int [M*P];
	MatrixMultiply(A,B,C,M,N,P); //�I�s��� 
	cout<<"[AxB�����G�O]"<<endl;
	for(i=0;i<M;i++)
	{
		for(j=0;j<P;j++)
			cout<<C[i*P+j]<<"\t";
		cout<<endl;
	}
}
//�i��x�}�ۭ� 
void MatrixMultiply(int* arrA,int* arrB,int* arrC,int M,int N,int P)
{
	if(M<=0||N<=0||P<=0)
	{
		cout<<"[���~:����M,N,P�����j��0]"<<endl;
		return;
	}
	for(int i=0;i<M;i++)
		for(int j=0;j<P;j++)
		{
			int Temp;
			Temp = 0;
			for(int k=0;k<N;k++)
				Temp = Temp + arrA[i*N+k]*arrB[k*P+j];
			arrC[i*P+j] = Temp;
		}
}
