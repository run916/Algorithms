class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+stones[i];
        if(n==2)return sum[2];
        int dp[n+1];
        dp[n]=sum[n];
        for(int i=n-1;i>=1;i--){
            dp[i]=max(dp[i+1],sum[i]-dp[i+1]);
        }
        return dp[1];
    }
};
