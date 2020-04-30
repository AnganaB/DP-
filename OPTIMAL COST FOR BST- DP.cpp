#include<bits/stdc++.h>

using namespace std;

int sum(int freq[], int i, int j)
{
	int sum = 0;
	for (int k = i; k <= j; k++)
		sum += freq[k];
	return sum;
}


int findOptimal(int freq[], int n)
{
	int cost[n][n];
	for (int i = 0; i < n; i++)
		cost[i][i] = freq[i];
	
	for (int l = 2; l <= n; l++) // all sizes of sequences
	{
		for (int i = 0; i <= n-l+1; i++) // all starting points of sequences
		{
			int j = i + l - 1;
			cost[i][j] = INT_MAX;
			for (int r = i; r <= j; r++) // all roots of sequence ki to kj
			{
				int c = ((r > i)?cost[i][r-1]:0) + ((r < j)?cost[r+1][j]:0) + sum(freq, i, j);
				cost[i][j] = min(cost[i][j], c); 
			}
		}
	}
	return cost[0][n-1];
}



int main()
{
	int freq[] = { 25, 10, 20 };
	int n = sizeof(freq) / sizeof(freq[0]);

	cout << "The optimal cost of constructing BST is "
			<< findOptimal(freq, n);

	return 0;
}
