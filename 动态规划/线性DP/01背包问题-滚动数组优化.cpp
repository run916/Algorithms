#include<bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/2/

int main(){
    int n, m;
    cin >> n >> m;
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    int v[n], w[n];
    for (int i = 0;i<n;i++){
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i < n; i ++){
        for (int j = m; j >= v[i];j --){
            // 只需要对可能变大的值进行更新即可
            // 需要对dp数组更新的顺序有比较深刻的了解
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}