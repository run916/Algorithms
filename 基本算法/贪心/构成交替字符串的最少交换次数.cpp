class Solution {
public:
    int minSwaps(string s) {
        //贪心算法
        //与最小平摊是一样的
        int n=s.length();
        int now=0;
        //先判断是否可行
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')one++;
            else zero++;
        }
        if(abs(zero-one)>1)return -1;
        int ans=n;
        if(one==zero){
            int a=0;
            for(int i=0;i<n;i+=2){
                if(s[i]=='1')a++;
            }
            ans=min(ans,min(n/2-a,a));
        }else{
            if(zero>one){
                int a=0;
                for(int i=0;i<n;i+=2){
                    if(s[i]=='1')a++;
                }
                ans=min(ans,a);
            }else{
                int a=0;
                for(int i=0;i<n;i+=2){
                    if(s[i]=='0')a++;
                }
                ans=min(ans,a);
            }
        }
        return ans;
    }
};
