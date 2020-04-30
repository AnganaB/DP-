#include<bits/stdc++.h>

using namespace std;

int maxExp(int a[], int n)
{
	int l1[n+1], l2[n], l3[n-1], l4[n-2];
	for (int i = 0; i <= n-3; i++)
		l1[i] = l2[i] = l3[i] = l4[i] = INT_MIN;
	l3[n-2] = l2[n-2] = l1[n-2] = INT_MIN;
	l2[n-1] = l1[n-1] = l1[n] =INT_MIN;
	
	for (int i = (n-1); i >= 0; i--)
		l1[i] = max(l1[i+1], a[i]);
	
	for (int i = (n-2); i >= 0; i--)
		l2[i] = max(l2[i+1], l1[i+1] - a[i]);
	
	for (int i = (n-3); i >= 0; i--)
		l3[i] = max(l3[i+1], l2[i+1] + a[i]);
	
	for (int i = (n-4); i >= 0; i--)
		l4[i] = max(l4[i+1], l3[i+1] - a[i]);
		
	return l4[0];
}


int main()
{
	int A[] = { 3, 9, 10, 1, 30, 40 };
	int n = sizeof(A) / sizeof(A[0]);

	// array should have atleast 4 elements
	if (n >= 4)
		cout << maxExp(A, n);

	return 0;
}
