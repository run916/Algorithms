class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int q[n];
        int l=0;
        int r=-1;
        for(int i=0;i<k-1;i++){
            for(;l<=r&&nums[q[r]]<nums[i];r--);
            q[++r]=i;
        }
        vector<int> ans;
        for(int i=k-1;i<n;i++){
            for(;l<=r&&nums[q[r]]<nums[i];r--);
            q[++r]=i;
            for(;l<=r&&q[l]<i-k+1;l++);
            ans.push_back(nums[q[l]]);
        }
        return ans;
    }
};
