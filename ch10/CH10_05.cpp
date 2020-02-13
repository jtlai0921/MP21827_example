/*
[�ܽd]:Floyd�t��k(�Ҧ����I��⤧�����̵u�Z��)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 //�L�a�j
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];//�ϧΰ}�C
int distance[SIZE][SIZE];//���|���װ}�C
//�إ߹ϧ� 
void BuildGraph_Matrix(int *Path_Cost)
{
    int Start_Point;//��u���_�I
    int End_Point;  //��u�����I 
    int i, j;
    for ( i = 1; i < SIZE; i++ )
        for ( j = 1; j < SIZE; j++ )
            if (i==j)
                Graph_Matrix[i][j] = 0; //�﨤�u�]��0
            else
                Graph_Matrix[i][j] = INFINITE;  
    //�s�J�ϧΪ���u
    i=0;
    while(i<SIZE)
    {
        Start_Point = Path_Cost[i*3]; 
        End_Point = Path_Cost[i*3+1]; 
        Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
        i++;
    }
}
//�L�X�ϧ�
void printGraph_Matrix()
{
   int i, j;
   for ( i = 1; i < SIZE; i++ )
   {
        cout<<"vex%d"<<i;
        for ( j = 1; j < SIZE; j++ )
            if ( Graph_Matrix[i][j] == INFINITE )
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
   }
}
//���I��������I�̵u�Z�� 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   extern int distance[SIZE][SIZE];//�ŧi���~���ܼ� 
   //�ϧΪ��װ}�C��l��
   for (i=1;i<=vertex_total;i++ )
        for (j=i;j<=vertex_total;j++ )
        {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
        }
   //�Q��Floyd�t��k��X�Ҧ����I��⤧�����̵u�Z��
   for (k=1;k<=vertex_total;k++ ) 
        for (i=1;i<=vertex_total;i++ )
            for (j=1;j<=vertex_total;j++ )
                if (distance[i][k]+distance[k][j]<distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];   
}
//�D�{��
int main(void) 
{
    extern int distance[SIZE][SIZE];//�ŧi���~���ܼ�
    int Path_Cost[7][3] = { {1, 2, 10}, 
                        {2, 3, 20},
                        {2, 4, 25},
                        {3, 5, 18},
                        {4, 5, 22},
                        {4, 6, 95},
                        {5, 6, 77} }; 
    int i,j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"=================================="<<endl;
    cout<<"���d�ҹϧΪ��۾F�x�}�p�U: "<<endl;
    cout<<"=================================="<<endl;
    cout<<"���I vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix();  //��ܹϧΪ��۾F�x�}
    cout<<"=================================="<<endl;
    cout<<"�Ҧ����I��⤧�����̵u�Z��: "<<endl;
    cout<<"=================================="<<endl;
    shortestPath(NUMBER); //�p��Ҧ����I�����̵u���|
    //�D�o��⳻�I�����̵u���|���װ}�C��A�N��L�X
    cout<<"���I vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    for ( i = 1; i <= NUMBER; i++ )
    {
        cout<<"vex"<<i;
        for ( j = 1; j <= NUMBER; j++ )
        {
            cout<<setw(5)<<distance[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return 0; 
}
