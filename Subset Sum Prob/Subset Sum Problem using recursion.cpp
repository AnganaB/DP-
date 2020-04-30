#include<bits/stdc++.h>

using namespace std;

bool subsetSum(int a[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n < 0 || sum < 0)
		return false;

	bool include = subsetSum(a, n-1, sum-a[n]);
	bool exclude = subsetSum(a, n-1, sum);
	
	return include || exclude;
}

int main()
{
	int arr[] = { 7, 3, 2, 5, 8 };
	int sum = 14;
	int n = sizeof(arr) / sizeof(arr[0]);

	if (subsetSum(arr, n - 1, sum))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
