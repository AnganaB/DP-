#include<bits/stdc++.h>

using namespace std;

int findOptimal(int freq[], int start, int end, int level)
{
	int optimal = INT_MAX;
	if (end < start)
		return 0;
	for (int i = start; i <= end; i++)
	{
		int left = findOptimal(freq, start, i - 1, level + 1);
		int right = findOptimal(freq, i + 1, end, level + 1);
		
		int cost = freq[i]*level + left + right;
		optimal = min(optimal, cost);
		
	}
	return optimal;
}

int main()
{
	int freq[] = { 25, 10, 20 };
	int n = sizeof(freq) / sizeof(freq[0]);

	cout << "The optimal cost of constructing BST is "
			<< findOptimal(freq, 0, n - 1, 1);

	return 0;
}
