#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/fair-distribution-of-cookies/

class Solution {
    public:
        int ans = INT_MAX;
    vector < int > cook;
    int k;
    int n;
    int vise[10];
    void bfs(int d) {
        if (d == n) {
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp = max(tmp, vise[i]);
            }
            ans = min(ans, tmp);
            return;
        }
        for (int i = 0; i < k; i++) {
            vise[i] += cook[d];
            bfs(d + 1);
            vise[i] -= cook[d];
        }
        return;
    }


    int distributeCookies(vector < int > & cook, int k) {
        // bin-packing 问题，这里暴力枚举即可
        this - > cook = cook;
        this - > k = k;
        n = cook.size();
        bfs(0);
        return ans;
    }
};