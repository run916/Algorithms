#include<bits/stdc++.h>
using namespace std;

long long pow(long long a,long long b,long long p){
    long long ans = 1;
    // 利用数的二进制分解来做这道题
    for (; b; b >>= 1){
        if(b&1){
            ans = ans * a % p;
        }
        a = a * a % p;
    }
    return ans % p;
}

int main(){
    long long a, b, p;
    cin >> a >> b >> p;
    cout << pow(a, b, p);
    return 0;
}