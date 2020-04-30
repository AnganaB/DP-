#include<bits/stdc++.h>


using namespace std;

string LCSlength(int a, int b, int m, int n, auto &lookup)
{
	if (m==0 || n==0)
		return 0;
	
	string key = to_string(m) + "|" + to_string(n);
	
	if (lookup.find(key) == lookup.end()) // if key is not seen before
	{
		if (a[m-1] == b[n-1])
		{
			lookup[key] = LCS(a, b, m-1, n-1, lookup) + 1;
		}
		else
			lookup[key] = max(LCS(a, b, m-1, n, lookup), LCS(a, b, m, n-1, lookup));
	}
	return lookup[key];
}


int main()
{
	unordered_map<string, int > lookup;
	string X = "ABCBDAB", Y = "BDCABA";
	cout<<LCSlength(X, Y, X.length(), Y.length(), lookup);
}
