//四种方法分别实现一次、
#include <bits/stdc++.h>
using namespace std;

int n;
//递推法
long long deduce()
{
    //递推法的思路其实是求解n个节点的二叉树有多少种的方式。
    long long s[n + 1];
    memset(s, 0, sizeof(s));
    s[1] = 1;
    s[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            s[i] += s[j] * s[i - j - 1];
        }
    }
    return s[n];
}
int main()
{
    cin >> n;
    long long ans = deduce();
    cout << ans;
    return 0;
}
