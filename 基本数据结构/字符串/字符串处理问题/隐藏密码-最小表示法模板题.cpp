#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s = "";
	string str;
	while (cin >> str)
		s += str;
	s += s;
	int pre = 0;
	int later = 1;
	int ans;
	for (; pre < n && later < n;)
	{
		int i = 0;
		for (; i < n; i++)
		{
			if (s[pre + i] > s[later + i])
			{
				pre += i + 1;
				if (pre == later)
					pre++;
				break;
			}
			if (s[pre + i] < s[later + i])
			{
				later += i + 1;
				if (later == pre)
					later++;
				break;
			}
		}
		if (i == n)
			break;
	}
	ans = min(later, pre);
	cout << ans;
	return 0;
}
