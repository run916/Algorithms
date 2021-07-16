class Solution {
public:
    int stoneGameVII(vector<int>& stone) {
        int n=stone.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+stone[i];
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                dp[j][j+i]=max(sum[j+i+1]-sum[j+1]-dp[j+1][j+i],sum[j+i]-sum[j]-dp[j][j+i-1]);
            }
        }
        return dp[0][n-1];
    }
};
