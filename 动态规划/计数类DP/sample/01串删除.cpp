#include<bits/stdc++.h>
using namespace std;

// 题目描述：
// 给定一个只包括0和1的字符串，0和1相邻时只能删除0,11和00可以任意删除某一个0或者1，求通过这种删除方式可以得到多少不同的字串。

// 计数类DP问题的关键在如何保证统计的过程中实现不重不漏

int main(){
    string s;
    cin >> s;
    int n = s.length();

    // dp数组用来记录当前长度的字符串可以生成的字串数目
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // tp数组，tp[i]表示以i个0结尾的字串元素数目
    long long  tp[n + 1];
    memset(tp, 0, sizeof(tp));
    int count = 0;
    long long sum = 0;

    // 记录字符串中最后一个1的位置
    int cnt = 0;
    // 记录已经遍历过，以几个0结尾的字串数目
    for (int i = 0; i < n;i++){
        if(s[i]=='0'){
            count++;
            sum -= tp[count];
            // 分两种情况
            if(cnt>0){
                // 如果之前有1，则包括以0结尾的字串数目以及以1结尾的字串数目
                dp[i + 1] = dp[i] + dp[cnt];
                // 如果之前有1，那么则更新tp[count]为前面1的值
                tp[count] = dp[i - count + 1];
            }else{
                // 如果没有1，则字串总数目加1即可
                // 如果之前没有1，则直接赋值为1
                dp[i + 1] = dp[i] + 1;
                tp[count] = 1;
            }
            // 更新以不同长度的0结尾的元素数目
            sum += tp[count];
        }else{
            int tmp = cnt;
            cnt = i + 1;
            count = 0;
            // 同样分两种情况
            if(i>0 && s[i-1]=='1'){
                // 如果前面一位是1，那么需要统计以
                dp[i + 1] = dp[i] + 1;
            }else{
                // 如果前一位是'0'，则需要分别统
                dp[i + 1] = dp[tmp] + 1;
            }
            dp[i + 1] += sum;
        }
    }
    cout << dp[n] << endl;
    return 0;
}