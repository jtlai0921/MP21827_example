#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int n)
{
	int i=2;
	while (i<=n)
	{
		if(n%i==0) //�p�G�㰣,i�On���]��,�^�� false
		    return false;
		i=i+1;
		return true;
	}
}
int main()
{
	int n;
	cout<<"�п�J�@�Ӥj�󵥩�2���Ʀr: "; 
	cin>>n;
	cout<<endl;
	if(n==2)
	{ 
	    cout<<n<<"�O���";
	    return 0;
	} 
	if(is_prime(n))
	    cout<<n<<"�O���";
	else
	    cout<<n<<"���O���";

    return 0;	
}
