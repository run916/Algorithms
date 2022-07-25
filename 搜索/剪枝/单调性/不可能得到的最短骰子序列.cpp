#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls/

class Solution {
public:
    int shortestSequence(vector<int>& roll, int k) {
        // 单调性剪枝
        // 记dp[i][j]表示以i结尾，长度为i的子序列是否都存在。
        // 那么dp[i][j]成立的条件是，对于所有1<=j<=k的j，dp[i-1][j]都为true。
        // 这一位这dp[i][j]要想成真，那么所有长度为i-1的子序列都存在，且该子序列一定位于dp[i][j]成立的元素之前。
        // 所以dp[i][j]成立的位置随着i的递增而单调递增。
        // 因此，我们可以通过一次扫描，找到第一个dp[i][j]不能全部成立的i，这个i就是要求解的答案。
        int n=roll.size();
        int sum[n+1];
        sum[0]=0;
        int dp[k+1];
        memset(dp,0x3f,sizeof(dp));
        int cnt=1;
        for(int i=0;i<n;i++){
            // 一轮结束
            if(sum[i]==k){
                cnt++;
                sum[i]=0;
                memset(dp,0x3f,sizeof(dp));
            }
            if(dp[roll[i]]>i){
                dp[roll[i]]=i;
                sum[i+1]=sum[i]+1;
            }else{
                sum[i+1]=sum[i];
            }
        }
        if(sum[n]==k)cnt++;
        return cnt;
    }
};