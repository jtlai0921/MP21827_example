#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int bin_search(int data[80],int val);
int main(void)
{  
	int num,val=1,data[80]={0};
	for (int i=0;i<80;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while (1)
	{  
		num=0;
		cout<<"�п�J�j�M���(1-150)�A��J-1�����G";
		cin>>val;
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			cout<<"##### �S�����["<<setw(3)<<val<<"] #####"<<endl;
		else
			cout<<"�b�� "<<setw(2)<<num+1<<"�Ӧ�m��� ["<<setw(3)<<data[num]<<"]"<<endl;
	}
	cout<<"��Ƥ��e�G"<<endl;
	for(int i=0;i<8;i++)
	{ 
		for(int j=0;j<10;j++)
			cout<<setw(3)<<i*10+j+1<<"-"<<setw(3)<<data[i*10+j];
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
int bin_search(int data[80],int val)
{  
	int low,mid,high;
	low=0;
	high=79;
	cout<<"�j�M�B�z��......"<<endl;
	while(low <= high && val !=-1)
	{  
		mid=(low+high)/2;
		if(val<data[mid])
		{  
			cout<<val<<" �����m "<<low+1<<"["<<setw(3)<<data[low]<<"]�Τ����� "<<mid+1<<"["<<setw(3)<<data[mid]<<"]�A�䥪�b��"<<endl;
			high=mid-1;	     
		}
		else if(val>data[mid])
		{  
			cout<<val<<" ���󤤶��Ȧ�m "<<mid+1<<"["<<setw(3)<<data[mid]<<"]��"<<high+1<<"["<<setw(3)<<data[high]<<"]�A��k�b��"<<endl;			
   			low=mid+1;   	     
		}
		else
			return mid;
	}
	return -1;
}
