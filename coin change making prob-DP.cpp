#include<bits/stdc++.h>

using namespace std;

int coinChange(int a[], int n, int N) // N = desired change
{
	int dp[N+1];
	dp[0] = 0;
	
	for (int i = 1; i <= N; i++)
	{
		dp[i] = INT_MAX; // initialize to maximum
		int res = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if ((i - a[j]) >= 0)
				res = dp[i-a[j]];
			
			if (res != INT_MAX)
				dp[i] = min(res+1, dp[i]);
		}
	}
	return dp[N];
}


int main()
{
	int S[] = { 1, 2, 3, 4 };
	int n = sizeof(S) / sizeof(S[0]);
	int N = 15;

	cout << "Minimum number of coins required to get desired change is "
			<< coinChange(S, n, N);

	return 0;
}
