#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
// 快速幂
long long pow(long long a,long long b,long long p){
    long long ans = 1;
    for (;b;b>>=1){
        if(b&1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
    }
    return ans % mod;
}

long long fac[100010];

// 组合数
long long C(long long n,long long k,long long p){
    return fac[n] * pow(fac[k] * fac[n - k], p - 2, p) % p;
}

int main(){
    // 初始化求出所有的阶乘
    fac[0]=1;
    for (int i = 1; i < 100010;i++){
        fac[i] = fac[i - 1] * i % mod;
    }
    cout << C(4, 3, mod) << endl;
    return 0;
}