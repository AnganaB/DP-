#include<bits/stdc++.h>

using namespace std;

int rodCut(int price[], int n)
{
	int dp[n+1];
	
	for (int i = 0; i <= n; i++)
		dp[i] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], price[j-1] + dp[i-j]);
		}
	return dp[n];
}


int main()
{
	int price [] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = 4;

	cout << "Profit is " << rodCut(price, n);

	return 0;
}
