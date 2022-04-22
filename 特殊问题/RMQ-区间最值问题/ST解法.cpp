#include<bits/stdc++.h>

using namespace std;

int main() {
    // dp思想
    int n, k;
    cin >> n >> k;
    vector < int > num(n);
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    int l = log2(n) + 1;
    int dp[n][l];
    int bp[n][l];
    // 初始化
    for (int i = 0;i<n;i++){
        for (int j = 0; j < l;j++){
            dp[i][j] = INT_MIN;
            bp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = num[i];
        bp[i][0] = num[i];
    }

    for (int i = 1; (1<<i)<n; i++) {
        for (int j = 0; j + (1 << i)-1 < n; j++) {// 注意这里的区间边界一定要减去1
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
            bp[j][i] = min(bp[j][i - 1], bp[j + (1 << (i - 1))][i - 1]);
        }
    }

    l = log2(k);
    // 查询
    for (int i = 0; i + k - 1 < n; i++){
        cout << max(dp[i][l], dp[i + k - (1 << l)][l]) << " ";
        cout << min(bp[i][l], bp[i + k - (1 << l)][l]) << endl;
    }
    return 0;
}