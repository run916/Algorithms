// 位运算的有一个领域，这个领域主要是利用位运算来优化存储空间
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    // Hamilton回路指的是经过所有点一次的路径长度，
    // 所以我们需要用一个状态来表示经过的点的状态
    // 我们用n个位的二进制数标示一个状态，总的状态数为2^n个。
    int m = 1 << n;
    // 状态压缩动态规划
    int dp[n][m];
    memset(dp, 0x7f, sizeof(dp));
    dp[0][1] = 0;
    for (int i = 1; i < m; i++) {
        // 枚举所有可能到达的点
        for (int j = 0; i >> j; j++) {
            if (i & (1 << j)) {
                // 再次枚举所有可能出发的点
                int k = (i ^ (1 << j));
                for (int d = 0; k >> d; d++) {
                    if (k & (1 << d)) {
                        dp[j][i] = min(dp[j][i], dp[d][k] + mat[d][j]);
                    }
                }
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}