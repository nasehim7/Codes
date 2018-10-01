// Edit Distance
#include<iostream>
using namespace std;

void ed(string s, string ss, int a, int b)
{
	int cost[a + 1][b + 1];
	for (int i = 0 ; i <= a; i++)
	{
		for (int j = 0 ; j <= b; j++)
		{
			if (i == 0)
				cost[i][j] = j;
			else if (j == 0)
				cost[i][j] = i;
			else
			{
				if(s[i - 1] == ss[j - 1])
					cost[i][j] = cost[i - 1][j - 1];
				else
				{
					cost[i][j] = 1 + min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1]));
				}
			}
		}
	}
	cout << cost[a][b] << endl;
}

int main()
{
	string s, ss;
	cin >> s >> ss;
	ed(s, ss, s.length(), ss.length());
	return 0;
}