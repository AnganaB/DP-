#include<bits/stdc++.h>

using namespace std;

int lps(string x, int i, int j, auto &lookup)
{
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	
	string key = to_string(i) + "|" + to_string(j);
	
	if (lookup.find(key) == lookup.end())
	{
		if (x[i] == x[j])
			lookup[key] = lps(x, i+1, j-1, lookup)	+2;
		else
			lookup[key] = max(lps(x, i+1, j, lookup), lps(x, i, j-1, lookup));
	}
	return lookup[key];
}

int main()
{
	string X = "ABBDCACB";
	int n = X.length();
	unordered_map<string, int> lookup;

	cout << "The length of Longest Palindromic Subsequence is " <<
		longestPalindrome(X, 0, n - 1, lookup);

	return 0;
}
