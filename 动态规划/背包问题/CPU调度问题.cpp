#include<bits/stdc++.h>
using namespace std;

// 三个cpu，安排任务，怎么安排最大完成时间最小

int dp[13][41][41][41];
int main(){
    int n;
    cin >> n;
    int v[n];
    int sum = 0;
    for (int i = 0; i < n;i++){
        cin >> v[i];
        sum += v[i];
    }
    int ans = sum;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j <= sum; j ++){
            if(j>=ans){
                break;
            }
            for (int k = 0; k <= sum; k ++){
                if(k>=ans){
                    break;
                }
                for (int d = 0; d <= sum; d ++){
                    if(d>=ans){
                        break;
                    }
                    // 选择不放
                    dp[i + 1][j][k][d] = max(dp[i + 1][j][k][d], dp[i][j][k][d]);
                    // 选择放入背包，分三种情况讨论
                    if(j>=v[i]){
                        dp[i + 1][j][k][d] = max(dp[i + 1][j][k][d], dp[i][j - v[i]][k][d] + v[i]);
                    }
                    if(k>=v[i]){
                        dp[i + 1][j][k][d] = max(dp[i + 1][j][k][d], dp[i][j][k - v[i]][d] + v[i]);
                    }
                    if(d>=v[i]){
                        dp[i + 1][j][k][d] = max(dp[i + 1][j][k][d], dp[i][j][k][d - v[i]] + v[i]);
                    }
                    if(dp[i + 1][j][k][d] == sum){
                        ans = min(ans, max(j, max(d, k)));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}