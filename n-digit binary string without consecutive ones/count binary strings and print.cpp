#include<bits/stdc++.h>

using namespace std;

void countBin(int n, string out, int lastdig)
{
	if (n == 0)
	{
		cout<<out<<"\n";
		return;
	}	
	
	countBin(n-1, out + "0", 0);
	
	if (lastdig == 0)
		countBin(n-1, out + "1", 1);
	
}


int main()
{
	int n = 5;
	string out = "";

	countBin(n, out, 0);

	return 0;
}

