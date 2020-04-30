#include<bits/stdc++.h>

using namespace std;

int kadane(int a[], int n)
{
	int max_so_far = a[0];
	int max_ending = a[0];
	
	for (int i = 1; i < n; i++)
	{
		max_ending = max_ending + a[i];
		max_ending = max(max_ending, a[i]);
		
		max_so_far = max(max_ending, max_so_far);
	}
	return max_so_far;
}


int main()
{
	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "The sum of contiguous subarray with the largest sum is " <<
			kadane(arr, n);

	return 0;
}
