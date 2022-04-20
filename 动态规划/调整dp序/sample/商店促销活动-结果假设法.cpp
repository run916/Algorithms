#include<bits/stdc++.h>

#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"

using namespace std;

// https://leetcode-cn.com/contest/cmbchina-2022spring/problems/OK3hsO/
// 结果假设法指的是，我们通过对结果中A，B数组中的元素选择状态，来决定DP的状态转移方程。
// 通过对结果不同状态的分类，可以避免中间结果的存储。

class Solution {
    public:
        int goShopping(vector < int > & priceA, vector < int > & priceB) {
            // 顺序无关，所以按照priceB的价格排序便于处理
            int n = priceA.size();
            vector < vector < int >> price;
            for (int i = 0; i < n; i++) {
                price.push_back({
                    priceA[i],
                    priceB[i]
                });
            }
            sort(price.begin(), price.end(), [](vector < int > & a, vector < int > & b) {
                return a[1] > b[1];
            });

            // 开始dp
            long long dp[n + 1][4][3];
            memset(dp, 0x3f, sizeof(dp));
            dp[0][0][0] = 0;
            // A中物品大于等于3
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 3; k++) {
                        // 选A还是选B，假设最终结果中A中物品数目大于等于3
                        dp[i + 1][j][k] = min(dp[i][max(j - 1, 0)][k] + price[i][0] * 7, dp[i][max(j, 3)][k] + price[i][0] * 7);
                        // 选B的情况
                        dp[i + 1][j][k] = min(dp[i][j][(k + 2) % 3] + (k == 0 ? 0 : price[i][1] * 10), dp[i + 1][j][k]);
                    }
                }
            }
            long long ans = 1e18;
            for (int i = 0; i < 3; i++) {
                ans = min(ans, dp[n][3][i]);
            }
            // 初始化
            memset(dp, 0x3f, sizeof(dp));
            dp[0][0][0] = 0;
            // A中物品小于3
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 3; k++) {
                        // 选A或者B中的较小值
                        dp[i + 1][j][k] = min(dp[i][max(j - 1, 0)][k] + price[i][0] * 10, dp[i][j][(k + 2) % 3] + (k == 0 ? 0 : price[i][1] * 10));
                    }

                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    ans = min(ans, dp[n][i][j]);
                }
            }
            return ans / 10;

        }
};

int main() {
    string s;
    cin >> s;
    vector < int > a = transfer(s);
    cin >> s;
    vector < int > b = transfer(s);
    Solution solve;
    cout << solve.goShopping(a, b);
    return 0;
}