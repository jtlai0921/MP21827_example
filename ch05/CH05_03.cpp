#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int interpolation_search(int*,int);
int main(void)
{  
	int i,j,val=1,num,data[50]={0};
	for (i=0;i<50;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while(1)
	{  
		num=0;
		cout<<"�п�J�j�M���(1-150)�A��J-1�����G";
		cin>>val;
		if(val==-1)
			break;
		num=interpolation_search(data,val);
		if(num==-1)
			cout<<"##### �S�����["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"�b�� "<<setw(2)<<num+1<<"�Ӧ�m��� ["
			    <<setw(3)<<data[num]<<"]"<<endl;
	}
	cout<<"��Ƥ��e�G"<<endl;
	for(i=0;i<5;i++)
	{ 
		for(j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	return 0;
}
int interpolation_search(int data[50],int val)
{  
	int low,mid,high;
	low=0;
	high=49;
	cout<<"�j�M�B�z��......"<<endl;
	while(low<= high && val !=-1)
	{  
		mid=low+((val-data[low])*(high-low)/(data[high]-data[low])); //�����k����
		if (val==data[mid])
			return mid;
		else if (val < data[mid])
		{  
			cout<<val<<" �����m "<<low+1<<"["<<setw(3)<<data[low]<<"]�Τ����� "
			    <<mid+1<<"["<<setw(3)<<data[mid]<<"]�A�䥪�b��"<<endl;
			high=mid-1;	     
		}
		else if(val > data[mid])
		{  
			cout<<val<<" ���󤤶��Ȧ�m "<<mid+1<<"["<<setw(3)<<data[mid]<<"]��"
			    <<high+1<<"["<<setw(3)<<data[high]<<"]�A��k�b��"<<endl;
			low=mid+1;   	     
		}
	}
	return -1;
}
