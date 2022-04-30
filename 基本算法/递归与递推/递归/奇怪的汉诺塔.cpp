// https://www.acwing.com/problem/content/98/
#include<bits/stdc++.h>

using namespace std;


int main() {
    // 先求解出3柱汉诺塔问题的解
    int d[13];
    d[0] = 0;
    for (int i = 1; i <= 12; i++) {
        d[i] = 2 * d[i - 1] + 1;
    }
    // 然后求解四柱汉诺塔问题
    // 四柱汉诺塔问题的最优解一定是先将k个盘子移动到B，
    // 然后按照三柱移动方式将剩余的移动到D，
    // 然后将剩余的盘子按照四柱移动方式，从B移动到D。
    // 证明：
    // 未知
    int dp[13];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= 12; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], 2 * dp[j] + d[i - j]);
        }
    }
    for (int i = 1; i <= 12; i++) {
        cout << dp[i] << endl;
    }
    return 0;
}