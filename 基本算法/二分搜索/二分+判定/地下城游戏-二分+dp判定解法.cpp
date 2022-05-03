// https://leetcode-cn.com/problems/dungeon-game/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int calculateMinimumHP(vector < vector < int >> & dungeon) {
            // 二分+判定
            int l = 1, r = 1e9;
            int n = dungeon.size();
            int m = dungeon[0].size();
            int h[n][m];
            while (l <= r) {
                int mi = (l + r) / 2;
                memset(h, 128, sizeof(h));
                h[0][0] = mi + dungeon[0][0];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (j > 0 && h[i][j - 1] > 0) {
                            h[i][j] = max(h[i][j], h[i][j - 1] + dungeon[i][j]);
                        }
                        if (i > 0 && h[i - 1][j] > 0) {
                            h[i][j] = max(h[i][j], h[i - 1][j] + dungeon[i][j]);
                        }
                    }
                }
                if (h[n - 1][m - 1] > 0) {
                    r = mi - 1;
                } else {
                    l = mi + 1;
                }
            }
            return l;
        }
};