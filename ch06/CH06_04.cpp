/*
[�ܽd]:���Y�}���x�}�ÿ�X���G
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int _ROWS = 8;		//�w�q�C��
const int _COLS = 9;		//�w�q���
const int _NOTZERO = 8;		//�w�q�}���x�}������0���Ӽ�

int main ()
{  
    int i,j,tmpRW,tmpCL,tmpNZ;
    int temp=1;
    int Sparse[_ROWS][_COLS];		//�ŧi�}���x�}
    int Compress[_NOTZERO][3];		//�ŧi���Y�x�}
    srand(time(NULL));
    for (i=0;i<_ROWS;i++)			//�N�}���x�}���Ҧ������]��0
        for (j=0;j<_COLS;j++)
            Sparse[i][j]=0;
    tmpNZ=_NOTZERO;
    for (i=1;i<tmpNZ+1;i++)
    {
        tmpRW = rand()%_ROWS;
        tmpCL = rand()%_COLS;
        if(Sparse[tmpRW][tmpCL]!=0)	//�קK�P�@�Ӥ����]�w�⦸�ƭȦӳy�����Y�x�}����0
            tmpNZ++;
        Sparse[tmpRW][tmpCL]=i; //�H�����͵}���x�}���D�s��������
    }
    cout<<"[�}���x�}���U�Ӥ���]"<<endl; //�L�X�}���x�}���U�Ӥ���
    for (i=0;i<_ROWS;i++)
    {  
        for (j=0;j<_COLS;j++)
            cout<<"["<<Sparse[i][j]<<"] ";
        cout<<endl;
    }
    //�}�l���Y�}���x�}
    Compress[0][0] = _ROWS;
    Compress[0][1] = _COLS;
    Compress[0][2] = _NOTZERO;
    for (i=0;i<_ROWS;i++)
        for (j=0;j<_COLS;j++)
            if (Sparse[i][j] != 0)
            {  
                Compress[temp][0]=i;
                Compress[temp][1]=j;
                Compress[temp][2]=Sparse[i][j];
                temp++;
           }
    cout<<"[�}���x�}���Y�᪺���e]"<<endl; //�L�X���Y�x�}���U�Ӥ���
    for (i=0;i<_NOTZERO+1;i++)
    {  
        for (j=0;j<3;j++)
            cout<<"["<<Compress[i][j]<<"] ";
        cout<<endl;
    }
}
