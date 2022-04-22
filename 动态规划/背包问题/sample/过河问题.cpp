#include<bits/stdc++.h>
using namespace std;

// 题目描述：有货物序列A[a1,a2,...,an]，A[i]标示第i个货物的到达时间为ai。
// 有一个船，最大运输量为m，每次运输时间为t
// 输入A,m,t求运输完所有货物的最小时间

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    int dp[n + 1][m + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][m] = 0;
    for (int i = 0; i < n; i++){
        // 当前船载了一个人
        for (int j = 1; j <= m;j++){
            dp[i + 1][1] = min(dp[i + 1][1], max(dp[i][j], A[i]) + t);
        }
        // 当前船载了多人
        for (int j = 2; j <= m; j++){
            dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j - 1] - t, A[i]) + t);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < m;i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}