#include<bits/stdc++.h>
#define maxi 50


using namespace std;


int lrs(string a, int n)
{
	int lookup[n+1][n+1];
	for (int i = 0; i <= n; i++)
		lookup[i][0] = 0;
	for (int j = 0; j <= n; j++)
		lookup[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			{
				if (a[i-1] == a[j-1] && i != j)
					lookup[i][j] = lookup[i-1][j-1] + 1;
				else
					lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
			}
	return lookup[n][n];
}


int main()
{
	string X = "ATACTCGGA";

	int n = X.length();

	cout << "Length of Longest Repeating Subsequence is " <<
			lrs(X, n);

	return 0;
}
