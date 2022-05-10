#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int num[n];
    for (int i = 0;i<n;i++){
        cin >> num[i];
    }
    //
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 0;i<n;i++){
        sum[i + 1] = sum[i] + num[i];
    }
    int dp[n + 1][m + 2][m + 2];
    memset(dp, 0x3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    // 动态规划
    // dp[i][j][k]，表示第i个位置至少为j，已经安排元素数量为sum时的最少操作次数
    // dp[i][j][k]，可以从dp[i-1][j][k-j]以及dp[i][j+1][k]转移而来
    // 从dp[i-1][j][k-j]转移过来时，第i个位置为j，此时该位置可能从前面借用元素，也可能从后面借用，但是我们都存储sum中。
    // 通过求解abs(k-sum[i])
    for (int i = 0; i<n ;i++){
        for (int j = m; j >= 0; j--){
            for (int k = j; k <= m; k++){
                dp[i + 1][j][k] = min(dp[i + 1][j + 1][k], dp[i + 1][j][k]);
                dp[i + 1][j][k] = min(dp[i][j][k - j] +abs(k-sum[i+1]), dp[i + 1][j][k]);
            }
        }
        // 获得最优解
    }
    // get optimal answer
    int ans = INT_MAX;
    for (int i = 0; i <= m;i++){
        ans = min(ans, dp[n][i][m]);
    }
    cout << ans;
    return 0;
}