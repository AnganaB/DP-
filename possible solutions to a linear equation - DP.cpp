#include<bits/stdc++.h>

using namespace std;

int linear(int coeff[], int k, int rhs)
{
	int dp[k][rhs+1];
	
	for (int i = 0; i < k; i++)
		dp[i][0] = 1;
	
	for (int i = 0; i < k; i++)
		for (int j = 1; j <= rhs; j++)
		{
			int include=0, exclude=0;
			if (i >= 1)
				exclude = dp[i-1][j];
			if (coeff[i] <= j)
				include = dp[i][j-coeff[i]];
			
			dp[i][j] = exclude+include;
		}
	
	return dp[k-1][rhs];
	
}

int main()
{
	int coeff[] = { 1, 3, 5, 7 };
	int k = sizeof(coeff) / sizeof(coeff[0]);
	int rhs = 8;

	cout << "Total number of solutions are " << linear(coeff, k , rhs);

	return 0;
}
