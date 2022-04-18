#include<bits/stdc++.h>
#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"
using namespace std;

// https://leetcode-cn.com/problems/longest-path-with-different-adjacent-characters/submissions/

class Solution {
public:
    vector<vector<int>> g;
    int dp[100010];
    string s;
    int ans=0;
    void dfs(int k){
        int tmp;
        for(int i=0;i<g[k].size();i++){
            dfs(g[k][i]);
            // 计算分叉之间的最长路径
            if(i==0){
                if(s[k]!=s[g[k][0]]){
                    tmp = dp[g[k][0]] + 1;
                }else{
                    tmp = 1;
                }
                ans = max(ans, tmp);
            }else{
                if(s[k]!=s[g[k][i]]){
                    ans = max(ans, tmp + dp[g[k][i]]);
                    tmp = max(tmp, dp[g[k][i]] + 1);
                }
            }
            // 更新dp值
            if(s[g[k][i]]!=s[k]){
                dp[k] = max(dp[k], dp[g[k][i]] + 1);
            }
        }
        // 最后对于叶子节点dp值为1
        dp[k] = max(1, dp[k]);
        ans = max(ans, dp[k]);
        return ;
    }
    
    int longestPath(vector<int>& parent, string s) {
        // 树形dp
        int n = s.length();
        g = vector<vector<int>>(n);
        for(int i=1;i<n;i++){
            g[parent[i]].push_back(i);
        }
        this->s=s;
        dfs(0);
        return ans;
    }
};

int main(){
    string s;
    vector<int> p;
    cin >> s;
    p = transfer(s);
    cin >> s;
    s = del_quote(s);
    Solution solve;
    int ans=solve.longestPath(p, s);
    cout << ans;
    return 0;
}