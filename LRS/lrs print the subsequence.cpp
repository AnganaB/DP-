#include<bits/stdc++.h>
#define maxi 50


using namespace std;
int lookup[maxi][maxi];

string lrs(string a, int m, int n)
{
	if (m == 0 || n == 0)
		return string("");
	
	if (a[m-1] == a[n-1] && m != n)
		return lrs(a, m-1, n-1) + a[m-1];
	
	if (lookup[m-1][n] > lookup[n][n-1])
		return lrs(a, m-1, n);
	
	return lrs(a, m, n-1);
}




int lrslength(string a, int n)
{
	
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
			lrslength(X, n);
	cout << " And the string is: "<< lrs(X, n, n);
	return 0;
}
