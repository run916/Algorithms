class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        //倒序思考
        int dp[n+1];
        //一定要注意博弈的边界条件以及中间结果。
        memset(dp,128,sizeof(dp));
        dp[n]=0;
        //零和博弈
        int sum[n+1];
        sum[0]=0;
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+stoneValue[i];
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=3;j++){
                if(i+j>n)break;
                dp[i]=max(dp[i],sum[n]-sum[i]-dp[i+j]);
            }
        }
        if(dp[0]*2>sum[n])return "Alice";
        if(dp[0]*2<sum[n])return "Bob";
        return "Tie";

    }
};
