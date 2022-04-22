class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        //根据数据范围我们判断出需要用动态规划求解
        int n=dist.size();
        long long dp[n+1][n];//表示是只考虑前i个元素，跳跃j次后花费的最小时间
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,n-1);j++){
                //考虑第i个位置是否跳过
                if(j>0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+dist[i-1]);//跳过
                dp[i][j]=min(dp[i][j],((dp[i-1][j]+speed-1)/speed)*speed+dist[i-1]);//不跳过
            }
        }
        for(int i=0;i<n;i++)if(dp[n][i]<=(long long)hoursBefore*speed)return i;
        return -1;
    }
};
