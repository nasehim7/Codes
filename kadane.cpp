#include<iostream>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[1005];
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}

		int mx = -1e5, mend = 0;
		for (int i = 1; i <= n; i++)
		{
			mend += a[i];
			if (mend < 0)
				mend = 0;
			else if (mend > mx)
				mx = mend;
		}

		cout << mx ;
	}
	return 0;
}