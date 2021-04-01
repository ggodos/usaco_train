#include <iostream>
#define NUMS X(k) X(l) X(m) X(n)

using namespace std;

int main()
{
	int d, q=0;
	#define X(s) int s=0; cin >> s; int s##t = s;
	NUMS
	#undef X
	cin >> d;
	bool flag = false;
	#define X(s) \
		if((s)==0) \
		{\
			s=s##t; \
			flag = false; \
		}
	for(int i=0; i<d+1; i++, k--, l--, m--, n--)
	{
		flag = true;
		NUMS
		if(flag==false) q++;
	}
	#undef X
	cout<<q;
	return 0;
}
