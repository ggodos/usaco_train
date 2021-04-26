#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n, t, q=0;
	vector<int> peop;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>t;
		peop.push_back(t);
	}
	auto pmax = max_element(begin(peop), end(peop));
	
	if(equal(peop.begin()+1, peop.end(), peop.begin())==false)
		for(int i=0; i<n; i++)
		{
			q += *pmax - peop.at(i);
		}
	
	
	cout<<q;
	return 0;
}
