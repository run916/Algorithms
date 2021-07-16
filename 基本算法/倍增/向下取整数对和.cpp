class Solution {
public:
    int mod=1e9+7;
    int sumOfFlooredPairs(vector<int>& nums) {
        //简单排序+剪枝即可。
        //需要二分。
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        long long dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i]==nums[i-1]){     
                    dp[i]=dp[i-1];
                    ans+=dp[i];
                    continue; 
                }

            }
            int l;
            int r=i-1;
            int k;
            for(;r<n-1;){
                int p=1;
                l=r+1;
                r=l;
                k=nums[l]/nums[i];
                while(p>0){
                    if(r+p>=n||nums[r+p]/nums[i]>k){
                        p/=2;
                        continue;
                    }
                    r+=p;
                    p*=2;
                }
                dp[i]+=(long long)(r-l+1)*k;
                dp[i]%=mod;
            }
            ans+=dp[i];
        }
        return ans%mod;
    }
};
