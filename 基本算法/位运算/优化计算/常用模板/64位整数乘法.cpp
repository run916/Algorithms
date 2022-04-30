// 类似于快速幂的问题，这里还是将其中一个乘数b进行分解
#include<bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long mod){
    long long ans = 0;
    for (;b; b >>= 1){
        if(b&1){
            ans = (ans + a) % mod;
        }
        a = a * 2 % mod;
    }
    return ans;
}

int main(){
    long long a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p);
    return 0;
}