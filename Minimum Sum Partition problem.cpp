#include<bits/stdc++.h>

using namespace std;
unordered_map<string, int > lookup;

int minPartition(int a[], int n, int a1, int a2)
{
	if (n < 0)
		return abs(a1 - a2);
	
	string key = to_string(n) + "|" + to_string(a1); // only included a1 since a2 is nothing but = a-a1;
	
	if (lookup.find(key) == lookup.find())
	{
		int inc = minPartition(a, n-1, a1 + a[n], a2);
		int exc = minPartition(a, n-1, a1, a2 + a[n]);
		
		lookup[key] = min(inc, exc);
	}
	return lookup[key];
}


int main()
{
	int S[] = { 10, 20, 15, 5, 25 };
	int n = sizeof(S) / sizeof(S[0]);

	cout << "The minimum difference is " << minPartition(S, n - 1, 0, 0);

	return 0;
}
}
