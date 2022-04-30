// 快速幂可以说是对位运算的一种应用，它关注的是数的构成方式

#include<bits/stdc++.h>
using namespace std;

int pow(long long a, long long b, int mod){
    // 主要应用的思想有以下几个，我会在代码具体位置进行说明
    long long ans = 1;
    // for循环这里主要是为了将b，也就是指数进行二进制分解，然后根据指数和等于底数乘积的原理进行求解
    for (; b; b>>=1) {
        // 位运算，判断这一位的指数是不是为1
        if(b&1){
            ans = ans * a % mod;
        }
        // a标示a^(2^i)，这里需要自己仔细体会
        a = a * a % mod;
    }
    return ans % mod;
}

int main(){
    long long a, b;
    int mod;
    cin >> a >> b >> mod;
    cout << pow(a, b, mod);
    return 0;
}