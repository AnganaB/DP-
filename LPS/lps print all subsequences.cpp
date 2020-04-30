#include<bits/stdc++.h>
#define maxi 50

using namespace std;
int lookup[maxi][maxi];

string lps(string a, string b, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return string("");
	}
	
	if (a[m-1] == b[n-1])
		return lps(a, b, m-1, n-1) + a[m-1];
	
	if (lookup[m-1][n] > lookup[m][n-1])
		return lps(a, b, m-1, n);
	
	return lps(a, b, m, n-1);
}

int lpslength(string a, string b, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i][j-1] , lookup[i-1][j]);
		}
	}
	
	return lookup[n][n];
	
}


int main()
{
	string X = "ABBDCACB";
	int m = X.length();
	string Y = X;
	reverse(Y.begin(), Y.end());
	cout << "The length of Longest Palindromic Subsequence is "
			<< lpslength(X, Y, m) << '\n';

	// Print Longest Palindromic Subsequence using lookup table
	cout << "The Longest Palindromic Subsequence is "
			<< lps(X, Y, m, m);

	return 0;
}
