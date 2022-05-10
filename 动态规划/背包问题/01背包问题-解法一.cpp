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
    //dp[i][j]表示前i个元素里面，体积为j的背包可以装的价值最大的石子数量
    for (int j = 0; j <= m; j++){
        for (int i = 0; i < n;i++){
            // 两种选择
            // 如果选择放进背包
            if(j-v[i]>=0){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - v[i]] + w[i]);
            }
            // 选择不放进背包
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}