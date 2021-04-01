#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> v;
	while(n)
	{
		if(!(n%2))
		{
			v.push_back(2);
			n -= 2;
		}
		else
		{
			v.push_back(3);
			n -= 3;
		}
	}
	cout<<v.size()<<endl;
	for(int i : v) cout<<i<<" ";
	return 0;
}
