#include<bits/stdc++.h>

using namespace std;

// https://leetcode-cn.com/contest/cmbchina-2022spring/problems/Dk2Ytp/

class Solution {
    public:

        vector < int > lightSticks(int height, int width, vector < int > & indices) {
            // bfs求解
            int n = height + 1;
            int m = width + 1;
            vector < vector < int >> g(n * m);
            int cnt = -1;
            unordered_map < int, bool > hash;
            for (int i = 0; i < indices.size(); i++) {
                hash[indices[i]] = true;
            }
            // 构图
            int s; // 记录一个有邻接边的顶点
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < m - 1; j++) {
                    cnt++;
                    if (hash.count(cnt)) {
                        continue;
                    }
                    g[i * m + j].push_back(i * m + j + 1);
                    g[i * m + j + 1].push_back(i * m + j);
                    s = i * m + j;
                }
                for (int j = 0; j < m && i < n-1; j++) {
                    cnt++;
                    if (hash.count(cnt)) {
                        continue;
                    }
                    g[i * m + j].push_back((i + 1) * m + j);
                    g[(i + 1) * m + j].push_back(i * m + j);
                    s = i * m + j;
                }
            }

            // 先判断所有边是否在同一个连通分支
            vector < int > ans;
            bool vise[n * m];
            int d[n * m];
            queue < int > que;
            que.push(s);
            memset(vise, false, sizeof(vise));
            vise[s] = true;
            while (!que.empty()) {
                int k = que.front();
                que.pop();
                for (int i = 0; i < g[k].size(); i++) {
                    if (!vise[g[k][i]]) {
                        vise[g[k][i]] = true;
                        que.push(g[k][i]);
                    }
                }
            }
            // 判断是否连通，否则直接跳出
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i * m + j].size() && vise[i * m + j] == false) {
                        return {};
                    }
                }
            }

            // bfs判断
            int r = INT_MAX;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i * m + j].size() == 0) {
                        continue;
                    }
                    while (!que.empty()) {
                        que.pop();
                    }
                    memset(vise, false, sizeof(vise));
                    que.push(i * m + j);
                    vise[i * m + j] = true;
                    d[i * m + j] = 0;
                    int tmp = 0;
                    while (!que.empty()) {
                        int k = que.front();
                        que.pop();
                        tmp = max(tmp, d[k]);
                        for (int j = 0; j < g[k].size(); j++) {
                            if (!vise[g[k][j]]) {
                                vise[g[k][j]] = true;
                                que.push(g[k][j]);
                                d[g[k][j]] = d[k] + 1;
                            }
                        }
                    }
                    if (tmp > r) {
                        continue;
                    } else if (tmp < r) {
                        r = tmp;
                        ans.clear();
                        ans.push_back(i * m + j);
                    } else {
                        ans.push_back(i * m + j);
                    }
                }
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
};