#include<bits/stdc++.h> 
using namespace std;

// https://leetcode.cn/problems/number-of-people-aware-of-a-secret/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // 简单递推或者dp 
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        int mod=1e9+7;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=i-delay;j>=0&&j>i-forget;j--){
                dp[i]=(dp[i]+dp[j])%mod;
            }  
        }
        long long ans=0;
        for(int i=n;i>n-forget;i--){
            ans+=dp[i];
            ans%=mod;
        }
        return ans;
        
    }
};