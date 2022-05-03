// https://leetcode-cn.com/problems/word-ladder/
#include<bits/stdc++.h>

using namespace std;

// 这道题有一个很妙的思想——虚拟构图。我们通过添加一些不存在的虚拟节点，可以有效避免遍历时产生的复杂度。

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
        // BFS+优化建图
        int n = wordList.size();
        add(beginWord);
        for (int i = 0; i < n; i++) {
            add(wordList[i]);
        }
        if (hash.count(endWord) == 0) {
            return 0;
        }
        int t = hash[endWord];

        // BFS
        queue < pair < int, int >> que;
        bool vise[g.size() + 1];
        memset(vise, false, sizeof(vise));
        vise[0] = true;
        que.push({ 0, 1});
        int i, k;
        while (!que.empty()) {
            i = que.front().first;
            k = que.front().second;
            que.pop();
            if (i == t) {
                return (k + 1) / 2;
            }
            for (int j = 0; j < g[i].size(); j++) {
                if (!vise[g[i][j]]) {
                    vise[g[i][j]] = true;
                    que.push({
                        g[i][j],
                        k + 1
                    });
                }
            }
        }
        return 0;
    }
};