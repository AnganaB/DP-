#include<bits/stdc++.h>

using namespace std;

int count(string x, string y, int m, int n)
{
	int dp[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
		dp[i][0] = 1;
	for (int j = 1; j <= n; j++) // if input string is empty
		dp[0][j] = 0;
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
				dp[i][j] = ((x[i-1] == y[j-1]) ? dp[i-1][j-1] : 0) 
				+ dp[i-1][j];
		}
	}
	return dp[m][n];
}


int main()
{
	string X = "subsequence";	
	string Y = "sue";		
	cout << count(X, Y, X.size(), Y.size()) << endl;
	return 0;
}
