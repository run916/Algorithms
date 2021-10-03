
#include <bits/stdc++.h>
using namespace std;

int n;

long long deduce()
{
    
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
