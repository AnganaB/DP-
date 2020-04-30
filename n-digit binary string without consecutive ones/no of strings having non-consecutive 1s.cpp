#include<bits/stdc++.h>

using namespace std;

int countBin(int n)
{
	int dp[n+1][2];
	dp[0][0] = 0, dp[0][1] = 0;
	dp[1][0] = 2, dp[1][1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	return dp[n][0];
}


int main()
{
	int n = 5;

	cout << "Number of " << n << "-digit binary strings without any "
		"consecutive 1's are " << countBin(n);

	return 0;
}
