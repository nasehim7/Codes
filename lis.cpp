// LIS

#include<iostream>
using namespace std;

void lis(int *a, int n)
{
	int tmp[n], mx = -1;

	for (int i = 0; i < n; i++)
	{
		tmp[i] = 1;
	}

	for(int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] >  a[j] && tmp[i] < tmp[j] + 1)
				tmp[i] = tmp[j] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		mx = max(mx, tmp[i]);
	}

	cout << mx << endl;
}


int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	lis(a, n);
	return 0;
}