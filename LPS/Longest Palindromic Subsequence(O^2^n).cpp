#include<bits/stdc++.h>

using namespace std;

int lps(string x, int i, int j)
{
	if (i > j)
		return 0;
	if (i == j) // palindrome
		return 1;
	
	if (x[i] == x[j])
	{
		return lps(x, i+1, j-1) + 2;
	}
	return max(lps(x, i+1, j), lps(x, i, j-1));
}

int main()
{
	string X = "ABBDCACB";
	int n = X.length();

	cout << "The length of Longest Palindromic Subsequence is "
			<< lps(X, 0, n - 1);

	return 0;
}
