#include <bits/stdc++.h>
using namespace std;

int main()
{
	//原理就是利用KMP的思想，然后查看pi数组中的元素是否呈现周期关系
	//不过要注意的是这里我们pi中记录的是最大真前缀的长度。
	int id = 0;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		string s;
		cin >> s;
		int k = -1;
		int pi[n];
		pi[0] = -1;
		for (int i = 1; i < n; i++)
		{
			while (k != -1 && s[i] != s[k + 1])
				k = pi[k];
			if (s[i] == s[k + 1])
				k++;
			pi[i] = k;
		}
		id++;
		cout << "Test case #" << id << endl;
		for (int i = 1; i < n; i++)
		{
			pi[i]++;
			if (pi[i] == 0)
				continue;
			if (pi[i] % (i + 1 - pi[i]) == 0)
			{
				cout << i + 1 << " " << (i + 1) / (i + 1 - pi[i]) << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
