#include<bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int ans[n];
    int next[m];
    int l, r; // l+ans[l]或者l+next[l]的值一定是当前已经求解完节点中最大的。

    // 初始化，next[0]=m;
    next[0] = m;
    l = 0;
    r = 0;
    // 先求next数组
    for (int i = 1; i < m; i++) {
        // 分两种情况讨论，如果next[i-l]的值小于r-i+1,这意味着t[next[i-1]+1]!=t[i+next[i-1]+1]，所以此时直接返回next[i]=next[i-l]即可。
        // 注意边界条件限制
        if (i <= r && next[i - l] < r-i+1) {
            next[i] = next[i - l];
        } else {
            // 在这个条件下，一定要尝试从r+1开始匹配，所以我们可以将next初值设为max(0,r-i+1)中较大值
            next[i] = max(0, r - i + 1);
            // 暴力匹配
            while (i + next[i] < m && t[i + next[i]] == t[next[i]]) {
                next[i]++;
            }
            // 更新区间端点，匹配结束后，不论是否扩充了，此时[i,r]一定是最右匹配区间。
            l = i;
            r = i + next[i] - 1;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << next[i] << " ";
    }
    cout << endl;
    // 按照同样的思路求解ans数组
    l = 0;
    r = 0;
    for (int i = 0; i < n; i++) {
        if (i <= r && next[i - l] < r - i + 1) {
            ans[i] = next[i - l];
        } else {
            ans[i] = max(0, r - i + 1);
            while (i + ans[i] < n && ans[i] < m && s[i + ans[i]] == t[ans[i]]) {
                ans[i]++;
            }
            l = i;
            r = i + ans[i] - 1;
        }
    }
    for (int i = 0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}