// https://leetcode-cn.com/problems/count-unguarded-cells-in-the-grid/submissions/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int countUnguarded(int m, int n, vector < vector < int >> & guards, vector < vector < int >> & walls) {
            // 模拟每一个警察可以看到的区域，然后用一个标记位，标记所有可以被看到的问题以及墙体还有警察的位置。
            bool vise[m][n];
            memset(vise, false, sizeof(vise));
            bool w[m][n];
            memset(w, false, sizeof(w));
            bool g[m][n];
            memset(g, false, sizeof(g));
            for (int i = 0; i < guards.size(); i++) {
                g[guards[i][0]][guards[i][1]] = true;
            }
            for (int i = 0; i < walls.size(); i++) {
                w[walls[i][0]][walls[i][1]] = true;
            }

            for (int i = 0; i < m; i++) {
                bool tag = false;
                for (int j = 0; j < n; j++) {
                    if (g[i][j]) {
                        tag = true;
                        vise[i][j] = true;
                        continue;
                    }
                    if (w[i][j]) {
                        tag = false;
                        vise[i][j] = true;
                        continue;
                    }
                    if (tag) {
                        vise[i][j] = true;
                    }
                }
                tag = false;
                for (int j = n - 1; j >= 0; j--) {
                    if (g[i][j]) {
                        tag = true;
                        vise[i][j] = true;
                        continue;
                    }
                    if (w[i][j]) {
                        tag = false;
                        vise[i][j] = true;
                        continue;
                    }
                    if (tag) {
                        vise[i][j] = true;
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                bool tag = false;
                for (int i = 0; i < m; i++) {
                    if (g[i][j]) {
                        tag = true;
                        vise[i][j] = true;
                        continue;
                    }
                    if (w[i][j]) {
                        tag = false;
                        vise[i][j] = true;
                        continue;
                    }
                    if (tag) {
                        vise[i][j] = true;
                    }
                }
                tag = false;
                for (int i = m - 1; i >= 0; i--) {
                    if (g[i][j]) {
                        tag = true;
                        vise[i][j] = true;
                        continue;
                    }
                    if (w[i][j]) {
                        tag = false;
                        vise[i][j] = true;
                        continue;
                    }
                    if (tag) {
                        vise[i][j] = true;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (!vise[i][j]) {
                        ans++;
                    }
                }
            }
            return ans;
        }
};