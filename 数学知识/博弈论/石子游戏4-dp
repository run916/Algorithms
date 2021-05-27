class Solution {
public:
    bool winnerSquareGame(int n) {
        //与NIM博弈类似。
        //与之前的思考类似。
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        dp[1]=true;
        for(int i=2;i<=n;i++){
            //搞清楚父子问题，才能搞清楚递推顺序。
            for(int j=1;j<=sqrt(i);j++){
                if(!dp[i-j*j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
