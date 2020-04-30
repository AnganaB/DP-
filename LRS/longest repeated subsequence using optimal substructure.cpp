#include<bits/stdc++.h>

using namespace std;

int lrslength(string a, int m, int n)
{
	if (m==0 || n==0)
		return 0;
	if (a[m-1] == a[n-1] && m != n)
	{
		return lrslength(a, m-1, n-1) + 1;
	}
	
	return max(lrslength(a, m-1, n), lrslength(a, m, n-1));
}

int main()
{
	string X = "ATACTCGGA";
	int m = X.length();

	cout << "Length of Longest Repeating Subsequence is " <<
			lrslength(X, m, m);

	return 0;
}
