#include<bits/stdc++.h>

using namespace std;

bool partition1(int a[], int n, int p, int q, int r)
{
	if (p == 0 && q == 0 && r == 0)
		return true;
	if (n < 0)
		return false;
	bool P = false;
	if ((p - a[n]) >= 0)
		P = partition1(a, n-1, p - a[n], q, r);
	
	bool Q = false;
	if (!P && (q - a[n]) >= 0)
		Q = partition1(a, n-1, p, q - a[n], r);
	
	bool R = false;
	if ((!P && !Q) && (r - a[n]) >= 0)
		R = partition1(a, n-1, p, q, r - a[n]);
		
	return P||Q||R;
}

bool partition(int a[], int n)
{
	if (n < 3)
		return false;
		
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum+=a[i];
	
	return !(sum%3) && partition1(a, n-1, sum/3, sum/3, sum/3);
}


int main()
{
	int S[] = { 7, 3, 2, 1, 5, 4, 8 };
	int n = sizeof(S) / sizeof(S[0]);

	if (partition(S, n))
		std::cout << "Yes";
	else
		std::cout << "No";

	return 0;
}
