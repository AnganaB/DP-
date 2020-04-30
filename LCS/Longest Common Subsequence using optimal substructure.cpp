#include<bits/stdc++.h>

using namespace std;

int LCSLength(string a, string b, int m, int n)
{
	if (m==0 || n==0)
		return 0;
	if (a[m-1] == b[n-1])
	{
		return LCSLength(a, b, m-1, n-1) + 1;
	}
	
	return max(LCSLength(a, b, m-1, n), LCSLength(a, b, m, n-1));
	
}

int main()
{
	string a = "ABCBDAB", b = "BDCABA";

	cout << LCSLength(a, b, a.length(), b.length());
	return 0;
}
