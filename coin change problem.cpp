#include<bits/stdc++.h>

using namespace std;

int count(int a[], int n, int N)
{
	int cnt = 0;
	if (N == 0)
		return 1;
	if (N < 0 || n < 0)
		return 0;
	
	int include = count(a, n, N - a[n]);
	int exclude = count(a, n - 1, N);
	return (include + exclude);
}

int main()
{
	int S[] = { 1, 3, 5, 7 };
	int n = sizeof(S) / sizeof(S[0]);
	int N = 8;

	cout << "Total number of ways to get desired change is "
			<< count(S, n, N);

	return 0;
}
