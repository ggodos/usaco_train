#include <iostream>
#include <cmath>

using namespace std;


bool st(int x)
{
	for(int i=2; i<=sqrt(x); i++) if(!(x%i)) return true;
	return false;
}


int main()
{
	int n;
	cin>>n;
	int n1=n/2, n2=n-n1;
	while(true)
	{
		if(st(n1)&&(st(n2)))
		{
			cout<<n1<<" "<<n2<<endl;
			break;
		}
		n1--;
		n2++;
	}
	return 0;
}
