#include<bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int m = b.length();
    int next[m];
    next[0] = m;
    int l = 0, r = 0;
    for (int i = 1; i < m; i++) {
        if (i <= r && next[i - l] < r - i + 1) {
            next[i] = next[i - l];
        } else {
            next[i] = max(0, r - i + 1);
            while (i + next[i] < m && b[next[i]] == b[i + next[i]]) {
                next[i]++;
            }
            l = i;
            r = next[i] + i - 1;
        }
    }
    // 输出第一个解
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans ^= ((long long)i + 1) * (next[i] + 1);
    }
    cout << ans << endl;
    // 求解a的LCP数组
    int n = a.length();
    int nest[n];
    // 注意这里要将r初始化为-1，因为循环是从0开始的，否则会在i=0的时候，nest[i]=max(0,r-i+1)处的值会变成1，从而跳过第一个位置的比较，出错。
    l = 0, r = -1;
    for (int i = 0; i < n; i++) {
        if (i <= r && next[i - l] < r - i + 1) {
            nest[i] = next[i - l];
        } else {
            nest[i] = max(0, r - i + 1);
            while (i + nest[i] < n && nest[i] < m && a[i + nest[i]] == b[nest[i]]) {
                nest[i]++;
            }
            l = i;
            r = i + nest[i] - 1;
        }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= ((long long)i + 1) * (nest[i] + 1);
    }
    cout << ans << endl;
    return 0;
}