#include<bits/stdc++.h>

using namespace std;

int coinChange(int a[], int n, int N) // N = desired change
{
	if (N == 0)
		return 0;
	if (N < 0)
		return INT_MAX;
	
	int coins = INT_MAX;
	
	for (int i = 0; i < n; i++)
	{
		int res = coinChange(a, n, N - a[i]);
		
		if (res != INT_MAX)
			coins = min(res+1, coins);
	}
	return coins;
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
