#include<bits/stdc++.h>
#define maxi 50
using namespace std;
int lookup[maxi][maxi];

void diff(string a, string b, int m, int n)
{
	if (m > 0 && n > 0 && a[m-1] == b[n-1])
	{
		diff(a, b, m-1, n-1);
		cout << " " << a[m-1];	
	}	
	else if (m > 0 && (n == 0 || lookup[m-1][n] >= lookup[m][n-1]))
	{
		diff(a, b, m-1, n);
		cout << "-" << a[m-1];
	}
	else if (n > 0 && (m == 0 || lookup[m-1][n] < lookup[m][n-1]))
	{
		diff(a, b, m, n-1);
		cout << "+" << b[n-1];
	}
	
}

int lcslength(string a, string b, int m, int n)
{
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			{
				if (a[i-1] == b[j-1])
					lookup[i][j] = lookup[i-1][j-1] + 1;
				else
					lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
			}
	return lookup[n][n];
}


int main()
{
	string X = "ABCDFGHJQZ";
	string Y = "ABCDEFGIJKRXYZ";
	int m = X.length(), n = Y.length();
	lcslength(X, Y, m, n);

	diff(X, Y, m, n);

	return 0;
}
