#include<bits/stdc++.h>

using namespace std;

int knapSack(int v[], int w[], int n, int W)
{
	int dp[n+1][W+1];
	
	for (int i = 0; i <= W; i++)
		dp[0][i] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= W; j++)
		{
			if ((j-w[i]) < 0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
		}
	return dp[n][W];
}


int main()
{
	int v[] = { 20, 5, 10, 40, 15, 25 };
	int w[] = {  1, 2,  3,  8,  7, 4 };
	int W = 10;
	int n = sizeof(v) / sizeof(v[0]);

	cout << "Knapsack value is " << knapSack(v, w, n, W);

	return 0;
}
