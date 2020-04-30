#include<bits/stdc++.h>

using namespace std;

int coinChange(int a[], int n, int N)
{
	int table[n][N+1]; 
    for (int i = 0; i < n; i++) 
        table[i][0] = 1; 
   
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 1; j <= N; j++) 
        {  
        	int x = 0, y = 0;
        	if (i >= 1)
        		x = table[i-1][j];
        	if (a[i] <= j)
        		y = table[i][j-a[i]];
        	
            //int x = (i-a[j] >= 0) ? table[i - a[j]][j] : 0; 
            //int y = (j >= 1) ? table[i][j - 1] : 0; 
  
            table[i][j] = x + y; 
        } 
    } 
    return table[n-1][N]; 
}

int main()
{
	int S[] = { 1, 2, 3 };
	int n = sizeof(S) / sizeof(S[0]);
	int N = 4;

	cout << "Total number of ways to get desired change is "
			<< coinChange(S, n, N);

	return 0;	
}
