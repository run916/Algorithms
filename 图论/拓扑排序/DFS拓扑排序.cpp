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
int finish[N];
int idx = 0;
bool vise[N];

class Solution {
    public:
        bool dfs(int k) {
            vise[k] = true;
            for (int i = last[k]; i; i = nest[i]) {
                if (!vise[edge[i]]) {
                    if(!dfs(edge[i])){
                        return false;
                    }
                } else {
                    // 判断是否存在环，finish初始化为一个较大值，如果是环的话，那么此时edge[i]一定未遍历结束，所以它的finish值一定是初始化的较大值
                    // 如果不是环，那么该节点一定遍历结束，该值一定小于等于当前的idx。
                    if(finish[edge[i]]>=idx){
                        return false;
                    }
                }
            }
            finish[k] = idx;
            idx++;
            return true;
        }
    vector < int > findOrder(int num, vector < vector < int >> & pre) {
        // 初始化
        memset(last, 0, sizeof(last));
        cnt=1;
        memset(vise, false, sizeof(vise));
        memset(finish,0x7f,sizeof(finish));
        idx=0;
        int n = pre.size();
        for (int i = 0; i < n; i++) {
            add(pre[i][1], pre[i][0]);
        }
        for (int i = 0; i < num; i++) {
            if (!vise[i]) {
                if (!dfs(i)) {
                    return {};
                }
            }
        }
        vector < int > ans(num);
        for (int i = 0; i < num; i++) {
            ans[finish[i]] = i;
        }
        reverse(ans.begin(), ans.end());
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