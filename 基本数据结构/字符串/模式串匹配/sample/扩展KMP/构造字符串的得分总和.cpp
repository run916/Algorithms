#include<bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/sum-of-scores-of-built-strings/

class Solution {
public:
    long long sumScores(string s) {
        // 扩展KMP算法
        int n=s.length();
        int next[n];
        next[0]=n;
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<=r&& next[i-l]<r-i+1){
                next[i]=next[i-l];
            }else{
                next[i]=max(0,r-i+1);
                // 暴力匹配
                while(i+next[i]<n&&s[i+next[i]]==s[next[i]]){
                    next[i]++;
                }
                l=i;
                r=next[i]+i-1;
            }
        }
        long long ans=n;
        for(int i=1;i<n;i++){
            ans+=next[i];
        }
        return ans;
        
    }
};