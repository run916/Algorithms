class Solution {
public:
    int gcd(int x,int y){
        if(x==1||y==1){
            return 1;
        }
        while(y){
            x%=y;
            swap(x,y);
        }
        return x;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // 二分+判定？
        // 质因数分解
        int m=numsDivide.size();
        int max_gcd;
        if(m>1){
            max_gcd=gcd(numsDivide[0],numsDivide[1]);
        }else{
            max_gcd=numsDivide[0];
        }
        
        for(int i=2;i<m;i++){
            max_gcd=gcd(max_gcd,numsDivide[i]);
        }
        // 排序
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(max_gcd%nums[i]==0){
                return i;
            }
        }
        return -1;
        
    }
};