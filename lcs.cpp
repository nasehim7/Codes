#include<iostream>
using namespace std;

void lcs(string s, string ss)
{
	int a = s.length();
	int b = ss.length();
	int lcs[a + 1][b + 1];
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if(s[i - 1] == ss[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << lcs[a][b] << endl;

	char fin[lcs[a][b] + 1];
	fin[lcs[a][b]] = '\0';

	int i = a, j = b, len = lcs[a][b] - 1;
	while (i > 0 && j > 0)
	{
		if (s[i - 1] == ss[j - 1])
		{
			fin[len] = s[i - 1];
			len--;
			i--;
			j--;
		}
		else
		{
			if (lcs[i - 1][j] > lcs[i][j - 1])
				i--;
			else
				j--;
		}
	}

	for (i = 0; i < lcs[a][b]; i++)
		cout << fin[i] ;
	cout << endl;
}

int main()
{
	string s, ss;
	cin >> s >> ss;
	lcs(s, ss);
	return 0;
}