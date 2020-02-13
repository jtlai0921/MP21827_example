#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define NUM1 4
#define NUM2 4
int process = 0;
int partition(int[], int, int);  
void mergeSort(int[], int, int[], int, int[]); 
void quick(int*,int,int,int);

int main(void) { 
   
    int list1[NUM1] = {16,25,39,27}; 
    int list2[NUM1] = {12,8,45,63}; 
    int list3[NUM1+NUM2] = {0}; 

    cout<<"�Ƨǫe�G"; 
    cout<<"\nlist1[]�G"; 
    int i;
    
    for(i = 0; i < NUM1; i++) 
        cout<<list1[i]<<" ";
        
    cout<<"\nlist2[]�G"; 
    for(i = 0; i < NUM2; i++) { 
        //list2[i] = rand() % 100; 
        cout<<list2[i]<<" ";
    } 
      
    quick(list1,NUM1,0,NUM1-1);
    quick(list2,NUM2,0,NUM2-1);

    cout<<"\n�Ƨǫ�G";
    cout<<"\nlist1[]�G";
    for(i = 0; i < NUM1; i++) 
        cout<<list1[i]<<" ";
    cout<<"\nlist2[]�G";
    for(i = 0; i < NUM2; i++) 
        cout<<list2[i]<<" ";

    // �X�ֱƧ� 
    mergeSort(list1, NUM1, list2, NUM2, list3); 

    cout<<"\n�X�֫�G"; 
    for(i = 0; i < NUM1+NUM2; i++) 
        cout<<list3[i]<<" ";
    cout<<endl;
        
	return 0; 
} 

void quick(int d[],int size,int lf,int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
    //1:�Ĥ@����Ȭ�d[lf]
	if(lf<rg)
	{
		lf_idx=lf+1;
		rg_idx=rg;
    while(1) {
    	for(int i=lf+1;i<=rg;i++)
	//2:�ѥ��V�k��X�@����Ȥj��d[lf]��
		{
			if(d[i]>=d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(int j=rg;j>=lf+1;j--)
	//3:�ѥk�V����X�@����Ȥp��d[lf]��
		{
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)       
		 //4-1:�Ylf_idx<rg_idx
		{					     
			tmp = d[lf_idx];       
			d[lf_idx] = d[rg_idx];
			//�hd[lf_idx]�Md[rg_idx]����
			d[rg_idx] = tmp;      //�M���~��Ƨ� 
        } else {
			break;    //�_�h���X�ƧǹL�{ 
		} 
    }
		if(lf_idx>=rg_idx)      
		 //5-1:�Ylf_idx�j�󵥩�rg_idx
		{       //�h�Nd[lf]�Md[rg_idx]����
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
                                      
			//5-2:�åHrg_idx������I�������k��b
			quick(d,size,lf,rg_idx-1);
			//�H���j�覡���O�����k��b�i��Ƨ�
			quick(d,size,rg_idx+1,rg);
			//���ܧ����Ƨ�
		}
	}
}

void mergeSort(int list1[], int M, int list2[], 
               int N, int list3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while(i < M && j < N) 
	{ 
        if(list1[i] <= list2[j]) 
            list3[k++] = list1[i++]; 
        else 
            list3[k++] = list2[j++]; 
    } 

    while(i < M) 
        list3[k++] = list1[i++]; 
    while(j < N) 
        list3[k++] = list2[j++]; 
} 
