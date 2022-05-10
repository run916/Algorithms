#include<bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/2/

int main(){
    int n, m;
    cin >> n >> m;
    int dp[n+1][m + 1];
    memset(dp, 0, sizeof(dp));
    int v[n], w[n];
    for (int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }
    // dp[i][j]表示前i个元素里面，体积为j的背包可以装的价值最大的石子数量
    // 内循环还外循环可以交换
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= m;j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j-v[i]>=0){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}