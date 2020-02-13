/*
[�ܽd]:Dijkstra�t��k(���I��������I���̵u���|)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999 //�L�a�j
using namespace std;
int Graph_Matrix[SIZE][SIZE];//�ϧΰ}�C
int distance[SIZE];//���|���צC
//�إ߹ϧ� 
void BuildGraph_Matrix(int *Path_Cost)
{
    int Start_Point;//��u���_�I 
    int End_Point; //��u�����I
    int i, j;
    for ( i = 1; i < SIZE; i++ )
        for ( j = 1; j < SIZE; j++ )
            if ( i == j )
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
        cout<<"vex"<<i;
        for ( j = 1; j < SIZE; j++ )
            if ( Graph_Matrix[i][j] == INFINITE )
                cout<<setw(5)<<'x';
            else
                cout<<setw(5)<<Graph_Matrix[i][j];
        cout<<endl;
    }
}
//���I��������I�̵u�Z�� 
void shortestPath(int vertex1, int vertex_total)
{       
    extern int distance[SIZE];//�ŧi���~���ܼ� 
    int shortest_vertex = 1; //�����̵u�Z�������I
    int shortest_distance;   //�����̵u�Z��
    int goal[SIZE]; //�ΨӬ����ӳ��I�O�_�Q���
    int i,j;
    for ( i = 1; i <= vertex_total; i++ )
    { 
        goal[i] = 0;    
        distance[i] = Graph_Matrix[vertex1][i]; 
    }
    goal[vertex1] = 1;  
    distance[vertex1] = 0;  
    cout<<endl;   
    for (i=1; i<=vertex_total-1; i++ ) 
    {      
        shortest_distance = INFINITE;      
        //��̵u�Z���� 
        for (j=1;j<=vertex_total;j++ )
            if (goal[j]==0&&shortest_distance>distance[j])
            {
                shortest_distance=distance[j];                                              
                shortest_vertex=j;              
            }
        goal[shortest_vertex] = 1;   
        //�p��}�l���I��U���I�̵u�Z��
        for (j=1;j<=vertex_total;j++ )
        {
            if ( goal[j] == 0 && 
                distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
                <distance[j])
            {
                distance[j]=distance[shortest_vertex]
                +Graph_Matrix[shortest_vertex][j];
            }       
        }
   }
}
//�D�{��
int main(void) 
{
    extern int distance[SIZE];//�ŧi���~���ܼ�
    int Path_Cost[7][3] = { {1, 2, 10}, 
                            {2, 3, 20},
                            {2, 4, 25},
                            {3, 5, 18},
                            {4, 5, 22},
                            {4, 6, 95},
                            {5, 6, 77} }; 
    int j;
    BuildGraph_Matrix(&Path_Cost[0][0]);
    cout<<"=================================="<<endl;
    cout<<"���d�ҹϧΪ��۾F�x�}�p�U: "<<endl;
    cout<<"=================================="<<endl;
    cout<<"���I vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
    printGraph_Matrix();  //��ܹϧ�
    shortestPath(1,NUMBER); //��M�̵u���|
    cout<<"=================================="<<endl;
    cout<<"���I1��U���I�̵u�Z�����̲׵��G"<<endl;
    cout<<"=================================="<<endl;
    for (j=1;j<SIZE;j++) 
        cout<<"���I 1�쳻�I"<<setw(2)<<j<<"���̵u�Z��="
        <<setw(3)<<distance[j]<<endl;
    cout<<endl;
    return 0; 
}
