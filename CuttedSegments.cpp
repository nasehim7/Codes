#include<iostream>
using namespace std;

int main()
{
	int t, n, x, y, z;
	cin >> t;
	while(t--)
	{
		cin >> n >> x >> y >> z;
		int dp[4005] = {0};
		for (int i = 1; i <= n; i++)
		{
			if (i == x || i == y || i == z)
				dp[i] = max(dp[i], 1);

			if (i - x > 0)
				dp[i] = max(dp[i], (dp[i - x] == 0) ? dp[i - x] : dp[i - x] + 1);
			if (i - y > 0)
				dp[i] = max(dp[i], (dp[i - y] == 0) ? dp[i - y] : dp[i - y] + 1);
			if (i - z > 0)
				dp[i] = max(dp[i], (dp[i - z] == 0) ? dp[i - z] : dp[i - z] + 1);
		}
		cout << dp[n] << endl;
	}
	return 0;
}