class Solution {
public:
    int mod=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        //贪心问题？
        //单调栈的矩形面积问题？
        //前缀和+单调栈
        nums.push_back(0);
        int n=nums.size();
        long long sum[n+1];
        sum[0]=0;
        for(int i=1;i<=n;i++)sum[i]=sum[i-1]+nums[i-1];
        stack<int> stack;
        stack.push(0);
        long long ans=(long long)nums[0]*nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[stack.top()])stack.push(i);
            else{
                //计算局部满足条件的值。
                for(;!stack.empty()&&nums[stack.top()]>=nums[i];){
                    int h=nums[stack.top()];
                    stack.pop();
                    if(stack.empty())ans=max(ans,sum[i]*h);
                    else ans=max(ans,(sum[i]-sum[stack.top()+1])*h);
                }
                stack.push(i);
            }
        }
        
        return ans%mod;
    }
};
