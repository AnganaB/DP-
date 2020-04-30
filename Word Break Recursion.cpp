#include<bits/stdc++.h>

using namespace std;

void wordBreak(vector<string >  &dict, string str, string out)
{
	if (str.size() == 0)
	{
		cout<<out<<"\n";
		return;
	}
	
	for (int i = 1; i <= str.size(); i++)
	{
		string prefix = str.substr(0,i);
		
		if (dict.find(prefix) != dict.end())
			wordBreak(dict, str.substr(i), out + " " + prefix);
	}
}

int main()
{
	vector<string> dict = { "this", "th", "is", "famous", "Word", "break", 
			"b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

	// input string
	string str = "Wordbreakproblem";
	
	wordBreak(dict, str, "");

	return 0;
}
