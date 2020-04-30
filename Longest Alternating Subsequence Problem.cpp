#include<bits/stdc++.h>

using namespace std;

int lookup[50][2];

int Util(int a[], int start, int end, bool flag)
{
	if (lookup[start][flag] == 0) // if the subproblem is seen for the first time
	{
		int res = 0;
		for (int i = start; i <= end; i++)
		{
			if (flag && a[i-1] < a[i])
			{
				res = max(res, 1 + Util(a, i+1, end, !flag));
			}
			else if (!flag && a[i-1] > a[i])
			{
				res = max(res, 1 + Util(a, i+1, end, !flag));
			}
			else
				res = max(res, Util(a, i+1, end, flag));
		}
		lookup[start][flag] = res;
	}
	return lookup[start][flag];
}

int findLongestSeq(int a[], int n)
{
	return 1 + max(Util(a, 1, n-1, true), Util(a, 1, n-1, false));
}


int main()
{
	int arr[] = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The length of Longest Subsequence is "
			<< findLongestSeq(arr, n);

	return 0;	
}
