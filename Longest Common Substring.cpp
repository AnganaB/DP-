#include<bits/stdc++.h>

using namespace std;

string lcs(string a, string b, int m, int n)
{
	int maxi =0 , end = m;
	int lookup[m+1][n+1];
	memset(lookup, 0, sizeof(lookup));
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
			{
				lookup[i][j] = lookup[i-1][j-1] + 1;
				
				if (lookup[i][j] > maxi)
				{
					maxi = lookup[i][j];
					end = i;
				}
			}
		}
	}
	return a.substr(end-maxi, maxi);
}

int main()
{
	string X = "ABC", Y = "BABA";
	int m = X.length(), n = Y.length();
	cout << "The Longest common substring is " << lcs(X, Y, m, n);

	return 0;	
}
