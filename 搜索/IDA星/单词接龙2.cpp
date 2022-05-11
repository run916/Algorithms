// https://leetcode.cn/problems/word-ladder-ii/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector < vector < int >> g; //图
    vector < string > word;
    int t = -1;
    bool vise[5010];
    int dis[5010];
    vector < vector < string >> ans;
    vector < string > tmp;
    void dfs(int k) {
        if (k == t) {
            ans.push_back(tmp);
            return;
        }
        // 先剪枝
        if (tmp.size() + dis[k] > dis[0] + 1) {
            return;
        }
        // 遍历
        for (int i = 0; i < g[k].size(); i++) {
            vise[g[k][i]] = true;
            tmp.push_back(word[g[k][i]]);
            dfs(g[k][i]);
            tmp.pop_back();
            vise[g[k][i]] = false;
        }
        return;
    }
    vector < vector < string >> findLadders(string beginWord, string endWord, vector < string > & wordList) {
        // DFS？
        int n = wordList.size();
        int m = wordList[0].length();
        word.push_back(beginWord);
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                t = i + 1;
            }
            word.push_back(wordList[i]);
        }
        if (t <= 0) {
            return {};
        }
        // 构图
        g = vector < vector < int >> (n + 1);
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int count = 0;
                for (int k = 0; k < m; k++) {
                    if (word[i][k] != word[j][k]) {
                        count++;
                    }
                }
                if (count == 1) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        // 在求解之前，先得到每个节点到达t的最短距离
        memset(dis, 0x3f, sizeof(dis));
        memset(vise, false, sizeof(vise));
        queue < int > que;
        que.push(t);
        dis[t] = 0;
        vise[t] = true;
        while (!que.empty()) {
            int k = que.front();
            que.pop();
            for (int i = 0; i < g[k].size(); i++) {
                if (!vise[g[k][i]]) {
                    vise[g[k][i]] = true;
                    dis[g[k][i]] = dis[k] + 1;
                    que.push(g[k][i]);
                }
            }
        }
        memset(vise, false, sizeof(vise));
        vise[0] = true;
        tmp.push_back(word[0]);
        dfs(0);
        return ans;
    }
};