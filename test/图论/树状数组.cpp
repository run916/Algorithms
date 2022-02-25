#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int arr[N];

int lowbit(int x){
    return x & (-x);
}

void update(int x,int v,int n){
    for (int i = x; i <= n;i+=lowbit(i)){
        arr[i] += v;
    }
    return;
}

// 梳妆数组只能查询[1,x]之内元素的和，所以要求特定区间的元素和，需要查询两次

long long query(int x){
    long long ans = 0;
    for (int i = x; i;i-=lowbit(i)){
        ans += arr[i];
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    int x;
    for (int i = 0;i<n;i++){
        cin >> x;
        update(i + 1, x, n);
    }
    for (int i = 0;i<m;i++){
        int s, x, k;
        cin >> s >> x >> k;
        if(s==1){
            update(x, k, n);
        }else{
            cout << query(k) - query(x - 1) << endl;
        }
    }
    return 0;
}