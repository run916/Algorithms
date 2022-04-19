#include<bits/stdc++.h>
using namespace std;

// 子集枚举通常有两种方式，一种是dfs枚举，一种则是二进制枚举，这里介绍二进制枚举的模板

int main(){
    int k;
    cin >> k;
    cout << (bitset<10>)k << endl;
    for (int i=k; i;i=k&(i-1)){
        cout << (bitset<10>)i << " ";
    }
    return 0;
}