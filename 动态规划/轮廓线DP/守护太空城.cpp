#include<bits/stdc++.h>

#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"

using namespace std;

class Solution {
    public:
        int defendSpaceCity(vector < int > & time, vector < int > & position) {
            int n = time.size();
            // vise数组用来记录一个位置被使用的情况
            bool vise[6][101];
            memset(vise, false, sizeof(vise));
            for (int i = 0; i < n; i++) {
                vise[time[i] - 1][position[i]] = true;
            }

            n = * max_element(position.begin(), position.end()) + 1;
            int m = * max_element(time.begin(), time.end());

            // 注意dp数组的定义方式，定义成一维更符合轮廓线类似于滑动窗口一样移动的规律
            int dp[n * m + 1][1 << m];
            memset(dp, 0x3f, sizeof(dp));
            dp[0][0] = 0;
            for (int k = 0; k < n * m; k++) {
                int i = k / m;
                int j = k % m;
                for (int s = 0; s < (1 << m); s++) {
                    if (s & 1) {
                        dp[k + 1][s >> 1] = min(dp[k + 1][s >> 1], dp[k][s]);
                    } else {
                        // 枚举轮廓线上的防护罩开启方式，需要注意的是防护罩不能连续开启
                        for (int l = 1; j + l <= m && (s & ((1 << l) - 1)) == 0; l++) {
                            // 连续l个位置开启单个防护罩
                            dp[k + l][s >> l] = min(dp[k + l][s >> l], dp[k][s] + l + 1);
                            // 连续l个位置开启关联防护罩
                            dp[k + l][(s >> l) + (((1 << l) - 1) << (m - l))] = min(dp[k + l][(s >> l) + (((1 << l) - 1) << (m - l))], dp[k][s] + l + 2);
                        }
                        // 当前时刻不开启防护罩
                        if (!vise[j][i]) {
                            dp[k + 1][s >> 1] = min(dp[k + 1][s >> 1], dp[k][s]);
                        }
                    }
                }
            }
            return dp[n * m][0];
        }
};

int main() {
    string s;
    cin >> s;
    vector < int > time = transfer(s);
    cin >> s;
    vector < int > pos = transfer(s);
    Solution solve;
    cout << solve.defendSpaceCity(time, pos);
    return 0;
}