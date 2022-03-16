#include<bits/stdc++.h>
using namespace std;

// 该方法的时间复杂度为O(nloglogn)，已经极为接近线性时间复杂度，
// 所以该方法也是最为常用的素数筛法。
void primes(int n){
    bool vise[n+1];
    memset(vise, false, sizeof(vise));
    for (int i = 2; i <= n;i++){
        if(vise[i]){
            continue;
        }
        // 下雨i*i的已经被判断过了，所以这里可以直接从i平方开始计算
        for (int j = i; j < n / i; j++){
            vise[i * j] = true;
        }
    }
    for (int i = 2; i < n; i++){
        if(!vise[i]){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    primes(n);
    return 0;
}