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

            long long ans = 1e18;

            // 开始dp
            long long dp[n + 1][4][3];
            memset(dp, 0x3f, sizeof(dp));
            dp[0][0][0] = 0;

            long long ap[n + 1][4][3];
            memset(ap, 0, sizeof(ap));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 3; k++) {
                        // 选A还是选B，需要根据A中元素的数目来决定当前DP数组中的值
                        if (j < 3 && j > 0) {
                            dp[i + 1][j][k] = dp[i][j - 1][k] + price[i][0] * 10;
                            ap[i + 1][j][k] = ap[i][j - 1][k] + price[i][0] * 10;
                        } else if (j == 3) {
                            dp[i + 1][j][k] = min(dp[i][j - 1][k] - ap[i][j - 1][k] + (price[i][0] + ap[i][j - 1][k] / 10) * 7, dp[i][3][k] + price[i][0] * 7);
                        }
                        // 选B的情况
                        if (dp[i][j][(k + 2) % 3] + (k == 0 ? 0 : price[i][1] * 10) <= dp[i + 1][j][k]) {
                            dp[i + 1][j][k] = min(dp[i][j][(k + 2) % 3] + (k == 0 ? 0 : price[i][1] * 10), dp[i + 1][j][k]);
                            ap[i + 1][j][k] = ap[i][j][(k + 2) % 3];
                        }
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
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