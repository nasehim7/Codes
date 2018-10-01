#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 5];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int mx = -1;
		int temp[n + 5];
		for (int i = 0; i < n; i++)
		{
			temp[i] = a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i ; j++)
			{
				if (a[i] > a[j] && (temp[i] < temp[j] + a[i]))
				{
					temp[i] = temp[j] + a[i];
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			mx = max(mx, temp[i]);
		}

		cout << mx << endl;
	}
	return 0;
}