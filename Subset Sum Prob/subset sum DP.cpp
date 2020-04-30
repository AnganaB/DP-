#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int a[], int n, int sum)
{
	bool dp[n+1][sum+1];
	
	for (int i = 0; i <= n; i++)
		dp[i][0] = true;
		
	for (int j = 1; j <= sum; j++)
		dp[0][j] = false;
		
	for (int  i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
		{
			if (a[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
			}
		}
	
	return dp[n][sum];
}

int main()
{
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
