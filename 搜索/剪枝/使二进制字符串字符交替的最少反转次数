class Solution {
public:
    int minFlips(string s) {
        //贪心？
        //分奇数偶数即可
        int n=s.length();
        int a=0;
        int b=0;
        int k=1;
        for(int i=0;i<n;i++){
            k^=1;
            if(k==0){
                if(s[i]=='0')a++;
            }else{
                if(s[i]=='0')b++;
            }
        }
        int c;
        int d;
        if(n%2==1)c=n/2+1-a;
        else c=n/2-a;
        d=n/2-b;
        //先统计出每个状态下的元素数目
        if(n%2==0)return min(c+b,a+d);
        int ans=min(c+b,a+d);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                a--;
                b++;
                swap(a,b);
                swap(d,c);
            }else{
                swap(a,b);
                c--;
                d++;
                swap(c,d);
            }
            ans=min(ans,min(c+b,a+d));
        }
        return ans;
        

    }
};
