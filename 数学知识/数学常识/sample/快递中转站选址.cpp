#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/contest/zj-future2022/problems/kflZMc/

class Solution {
    public:
        int buildTransferStation(vector < vector < int >> & area) {
            // 两个维度可以单独统计，寻找中位数
            int n = area.size();
            int m = area[0].size();
            vector < int > x;
            vector < int > y;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (area[i][j] == 1) {
                        x.push_back(i);
                        y.push_back(j);
                    }

                }
            }
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            int ans = 0;
            for (int i = 0; i < x.size(); i++) {
                ans += abs(x[i] - x[x.size() / 2]);
            }
            for (int i = 0; i < y.size(); i++) {
                ans += abs(y[i] - y[y.size() / 2]);
            }
            return ans;
        }
};