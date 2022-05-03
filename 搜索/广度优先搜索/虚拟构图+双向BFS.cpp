// https://leetcode-cn.com/problems/word-ladder/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector < vector < int >> g;
    int cnt = 0;
    unordered_map < string, int > hash;

    void add(string & s) {
        string str = s;
        hash[s] = cnt;
        ++cnt;
        g.emplace_back();
        for (int i = 0; i < s.length(); i++) {
            str = s;
            str[i] = '*';
            if (hash.count(str) == 0) {
                hash[str] = cnt;
                g.emplace_back();
                ++cnt;
            }
            g[hash[s]].push_back(hash[str]);
            g[hash[str]].push_back(hash[s]);
        }
        return;
    }

    int ladderLength(string beginWord, string endWord, vector < string > & wordList) {
        // 双向BFS+优化建图
        int n = wordList.size();
        add(beginWord);
        for (int i = 0; i < n; i++) {
            add(wordList[i]);
        }
        if (hash.count(endWord) == 0) {
            return 0;
        }
        int t = hash[endWord];

        // 双向BFS
        queue < pair < int, int >> que;
        int vise[g.size() + 1];
        memset(vise, 0, sizeof(vise));
        vise[0] = 1;
        vise[t] = 2;
        que.push({
            0,
            1
        });
        que.push({
            t,
            1
        });
        int i, k;
        while (!que.empty()) {
            i = que.front().first;
            k = que.front().second;
            que.pop();
            for (int j = 0; j < g[i].size(); j++) {
                if (!vise[g[i][j]]) {
                    vise[g[i][j]] = vise[i];
                    que.push({
                        g[i][j],
                        k + 1
                    });
                } else {
                    if (vise[g[i][j]] != vise[i]) {
                        return k + 1;
                    }
                }
            }
        }
        return 0;
    }
};