#include<bits/stdc++.h>
using namespace std;

int n;
//dp法
long long DP(){
    long long dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][n]=1;
    //dp的中间态是什么？
    //中间态是进出栈过程的某一个中间的状态
    for(int i=n;i>=0;i--){
    	//递推的顺序是什么？ 
        for(int j=n;j>=0;j--){
            if(j<n)dp[j][i]+=dp[j+1][i];
            if(j>0&&i<n)dp[j][i]+=dp[j-1][i+1];
        }
    }
    return dp[0][0];
}
int main(){
	cin>>n;
	cout<<DP();
	return 0;
}
