#include<bits/stdc++.h>

using namespace std;

int rodCut(int n)
{
	int dp[n+1];
	for (int i = 0; i <= n; i++)
		dp[i] = i;
	for (int i = 2; i <= n; i++) // i starts from fron 2 since if i <= 1; the answer is equal to i
	{
		for (int j = 1; j <= i; j++)
		{
			 dp[i] = max(dp[i], j*(dp[i-j]));
		}
	}
	return dp[n];
}

int main()
{
	int n = 15;

	cout << rodCut(n);

	return 0;
}
