// https://leetcode.cn/problems/the-skyline-problem/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector < vector < int >> getSkyline(vector < vector < int >> & build) {
            // 典型的优先级队列题目
            // 也可以用线段树+离散化求解
            int n = build.size();
            sort(build.begin(), build.end(), [](vector < int > & a, vector < int > & b) {
                return a[0] < b[0];
            });
            set < int > set;
            for (int i = 0; i < n; i++) {
                set.insert(build[i][0]);
                set.insert(build[i][1]);
            }
            priority_queue < pair < int, int >> que;
            vector < vector < int >> ans;
            // 先理清楚逻辑
            int k = 0;
            for (auto &x:set) {
                // 首先将堆顶区间右端点大于num[i]的元素弹出，因为这些肯定不可能是解
                while (!que.empty() && que.top().second <= x) {
                    que.pop();
                }
                // 将新的区间假如到优先级队列中
                while (k < n && x == build[k][0]) {
                    que.push({
                        build[k][2],
                        build[k][1]
                    });
                    k++;
                }
                if(que.empty()){
                    ans.push_back({x, 0});
                }else{
                    ans.push_back({x, que.top().first});
                }

            }
            //return ans;
            // 最后还要去除不合适的元素
            vector < vector < int >> list;
            list.push_back(ans[0]);
            for (int i = 1; i < set.size(); i++) {
                if (ans[i][1] == ans[i - 1][1]) {
                    continue;
                }
                list.push_back(ans[i]);
            }
            return list;
        }
};