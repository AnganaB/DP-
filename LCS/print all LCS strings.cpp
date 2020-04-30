#include<bits/stdc++.h>
#define max 50

using namespace std;

int lookup[max][max];

//function to return all LCS of substrings of a[0..m-1], b[0..n-1]
vector<string > lcs(string a, string b, int m, int n)
{
	if (m==0 || n==0)
	{
		vector<string > v(1);
		return v;
	}
	
	if (a[m-1] == b[n-1])
	{
		vector<string > v = lcs(a, b, m-1, n-1);// find all substrings after removing last characters and storing them in vector v
		
		//append current character to the end of all strings in vector lcs;
		
		for (string &s: v)
		{
			s.append(a[m-1]);
		}
		
		return v;
	}
	if (lookup[m-1][n] > lookup[m][n-1])
		lcs(a, b, m-1, n);
	else if (lookup[m-1][n] < lookup[m][n-1])
		lcs(a, b, m, n-1);
	// if both are same add both to the vectors, .e. consider both
	vector<string > bottom = lcs(a, b, m-1, n);
	vector<string > left = lcs(a, b, m, n-1);
	// merge both vectors
	
	bottom.insert(bottom.end(), left.begin(), left.end());
	
	return bottom;
		
}

void LCSlength(string a, string b, int m, int n)
{
	int lookup[m+1][n+1];
	
	for (int i = 0; i <= m; i++)
		lookup[i][0] = 0;
	for (int i = 0; i <= n; i++)
		lookup[0][i] = 0;
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i-1] == b[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
				
		}
	}
//	return lookup[m][n];
}

set<string > LCSmain(string a, string b)
{
	int m = a.length(), n = b.length();
	LCSlength(a, b, m, n);
	vector<string > v = lcs(a, b, m, n);
	set<string > lcs1(make_move_iterator(v.begin()), make_move_iterator(v.end()));// converting vector to set since vector can contain duplicate elements
	
	return lcs1;
}

int main()
{
	string X = "ABCBDAB", Y = "BDCABA";

	set<string> lc = LCSmain(X, Y);

	// print set elements
	for (string str : lc)
		cout << str << endl;

	return 0;
}
