#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // 首先从(n,0,0)移动成(1,n-1,0)，然后将A的最后一个移动到C。
    // 此时子问题变成了B成A，A成为B，C依然是C的子问题。
    // 而n-1个盘子是一个规模更小的子问题，所以这个该在求解规模为n的原问题时可以看做已知。
    // 我们用dp[i]来存储将i个盘子从一个柱子移动到另一个柱子最少需要的次数
    // 这样dp[i+1]=dp[i]+1+dp[i];
    // 这个时候我们也就得出了汉诺塔问题递归方式该如何求解
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 2 * dp[i - 1] + 1;
    }
    cout << dp[n];
    return 0;
}