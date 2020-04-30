#include<bits/stdc++.h>

using namespace std;

int coef(int coeff[], int k, int rhs)
{
	if (rhs == 0)
		return 1;
	if (rhs < 0 && k < 0)
		return 0;
	
	int include = coef(coeff, k, rhs - coeff[k]);
	int exclude = coef(coeff, k-1, rhs);
	
	return (include+exclude);
}

int main()
{
	int coeff[] = { 1, 2, 3 };
	int k = sizeof(coeff) / sizeof(coeff[0]);
	int rhs = 4;

	cout << "Total number of solutions are " << coef(coeff, k - 1, rhs);

	return 0;
}
