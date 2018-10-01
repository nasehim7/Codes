#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int gr[n + 5];
		for (int i = 0; i < n; i++)
		{
			cin >> gr[i];
		}
		stack<int> s;

		int i = 0;
		int maxArea = 0, area = 0;
		int tp;

		while (i < n)
		{
			if (s.empty() || gr[s.top()] <= gr[i])
			{
				s.push(i++);
			}
			else
			{
				tp = s.top();
				s.pop();

				area = gr[tp] * (s.empty() ? i : i - s.top() - 1);

				if (area > maxArea)
					maxArea = area;
			}
		}


		while (s.empty() == false)
		{
			tp = s.top();
			s.pop();

			area = gr[tp] * (s.empty() ? i : i - s.top() - 1);

			if (area > maxArea)
				maxArea = area;
		}

		cout << maxArea << endl;
	}
}