#include<bits/stdc++.h>

using namespace std;

bool wordBreak(vector<string > const &dict, string s, vector<int > lookup)
{
	int n = s.size();
	
	if (n == 0)
		return true;
	
	if (lookup[n] == -1)
	{
		lookup[n ] = 0; // maek as seen and initially assuming string can't be segmented
		for (int i = 1; i <= n; i++)
		{
			string pref = s.substr(0,i);
			 
			if (find(dict.begin(), dict.end(), pref) == dict.end() && wordBreak(dict, s.substr(i), lookup))
			{
				return lookup[n] = 1;
			}
		}
	}
	return lookup[n];
}


int main()
{
	vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
	string str = "Wordbreakproblem";

	vector<int> lookup(str.length() + 1, -1);

	if (wordBreak(dict, str, lookup))
		cout << "String can be segmented";
	else
		cout << "String can't be segmented";

	return 0;
}
