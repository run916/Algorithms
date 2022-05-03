// https://leetcode-cn.com/problems/dungeon-game/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int calculateMinimumHP(vector < vector < int >> & dungeon) {
            // 逆向思维
            int n = dungeon.size();
            int m = dungeon[0].size();
            dungeon[n - 1][m - 1] = dungeon[n - 1][m - 1] > 0 ? 0 : dungeon[n - 1][m - 1];
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i == n - 1 && j == m - 1) {
                        continue;
                    }
                    dungeon[i][j] = dungeon[i][j] + max(j + 1 < m ? dungeon[i][j + 1] : -1e9, i + 1 < n ? dungeon[i + 1][j] : -1e9);
                    if (dungeon[i][j] > 0) {
                        dungeon[i][j] = 0;
                    }
                }
            }
            return -dungeon[0][0] + 1;
        }
};