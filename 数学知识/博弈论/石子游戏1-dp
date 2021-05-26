class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+piles[i];
        int dp[n][n];
        for(int i=0;i<n;i++)dp[i][i]=piles[i];
        for(int i=1;i<n;i++){
            for(int j=0;j+i<n;j++){
                dp[j][j+i]=max(sum[j+i+1]-sum[j]-dp[j+1][j+i],sum[j+i+1]-sum[j]-dp[j][j+i-1]);
            }
        }
        return dp[0][n-1]*2>sum[n?true:false];

    }
};
