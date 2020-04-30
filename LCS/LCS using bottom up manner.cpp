#include<bits/stdc++.h>

using namespace std;

int LCSlength(string a, string b, int m, int n)
{
	int lookup[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;
	for (int i = 0; i <= n; i++)
		lookup[0][i] = 0;
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
				
		}
	}
	return lookup[m][n];
}

int main()
{
	string X = "ABCBDAB", Y = "BDCABA";
	cout<<LCSlength(X, Y, X.length(), Y.length());
}

