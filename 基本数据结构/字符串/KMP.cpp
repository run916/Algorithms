#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s; //待匹配的字符串
	string p; //模式串
	cin >> s >> p;
	int m = p.length();
	//先从模式串构建DP数组，模式串的前缀[0,m]的后缀与p匹配的最长真前缀的最后一个字符的下标。
	int pi[m];
	int k = -1;
	pi[0] = -1;
	for (int i = 1; i < m; i++)
	{
		while (k != -1 && p[i] != p[k + 1])
			k = pi[k];
		if (p[i] == p[k + 1])
			k++;
		pi[i] = k;
	}
	for (int i = 0; i < m; i++)
		cout << pi[i] << " ";
	cout << endl;
	k = -1;
	//模式串匹配
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		while (k != -1 && s[i] != p[k + 1])
			k = pi[k];
		if (s[i] == p[k + 1])
			k++;
		if (k == m - 1)
		{
			cout << i << " ";
			k = pi[k];
		}
	}
	return 0;
}
