#include<bits/stdc++.h>

using namespace std;

int findMinInsertions(string s, int l , int h)
{
	if (l > h)
		return INT_MAX;
	if (l == h)
		return 0;
	if (l == (h-1))
		return (s[l] == s[h])? 0:1;
	if (s[l] == s[h])
		return findMinInsertions(s, l+1, h-1);
	return min(findMinInsertions(s, l+1, h), findMinInsertions(s, l, h-1))+1;
	
}

int main()
{
	string s = "geeks"; 
    cout << findMinInsertions(s, 0, s.length() - 1); 
    return 0;
}
