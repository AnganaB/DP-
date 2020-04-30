#include<bits/stdc++.h>

using namespace std;

int lrslength(string a, int m, int n, auto &lookup)
{
	if (m==0 || n==0)
		return 0;
	string key = to_string(m) + "|" + to_string(n);
	
	if (lookup.find(key) == lookup.end())
	{
		if (a[m-1] == a[n-1] && m!=n)
			lookup[key] = lrslength(a, m-1, n-1, lookup) + 1;
		else
			lookup[key] = max(lrslength(a, m-1, n, lookup), lrslength(a, m, n-1, lookup));

	}
	
	return lookup[key];
	
}

int main()
{
	string X = "ATACTCGGA";
	int m = X.length();

	// create a map to store solutions of subproblems
	unordered_map<string, int> lookup;

	cout << "Length of Longest Repeating Subsequence is " <<
			LRSLength(X, m, m, lookup);

	return 0;
	return 0;
}
