#include<bits/stdc++.h>

#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"

using namespace std;

// https://leetcode-cn.com/problems/course-schedule-ii/

const int N = 10010;
int edge[N];
int nest[N];
int last[N];
int cnt = 1;

void add(int u, int v) {
    edge[cnt] = v;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}
int degree[N];

class Solution {
    public:
        vector < int > findOrder(int num, vector < vector < int >> & pre) {
            // 构图
            int n = pre.size();
            memset(degree, 0, sizeof(degree));
            memset(last, 0, sizeof(last));
            cnt = 1;
            for (int i = 0; i < n; i++) {
                add(pre[i][1], pre[i][0]);
                degree[pre[i][0]]++;
            }
            queue < int > que;
            for (int i = 0; i < num; i++) {
                if (degree[i] == 0) {
                    que.push(i);
                }
            }
            vector < int > ans;
            for (; !que.empty(); que.pop()) {
                int k = que.front();
                ans.push_back(k);
                for (int i = last[k]; i; i = nest[i]) {
                    degree[edge[i]]--;
                    if (degree[edge[i]] == 0) {
                        que.push(edge[i]);
                    }
                }
            }
            if (ans.size() < num) {
                return {};
            }
            return ans;
        }
};


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < vector < int >> pre = two_dimension(s);
    Solution solve;
    vector < int > ans = solve.findOrder(n, pre);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}