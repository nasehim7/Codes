#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, w;
		cin >> n >> w;
		int wt[n + 5], val[n + 5];
		for (int i = 0; i < n; i++)
		{
			cin >> wt[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> val[i];
		}

		int k[n + 2][w + 2];

		for(int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= w; j++)
			{
				if (i == 0 || j == 0)
				{
					k[i][j] = 0;
				}
				else if(wt[i - 1] <= j)
				{
					k[i][j] = max(val[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
				}
				else 
					k[i][j] = k[i - 1][j];
			}
		}

		cout << k[n][w] << endl;
	}
	return 0;
}