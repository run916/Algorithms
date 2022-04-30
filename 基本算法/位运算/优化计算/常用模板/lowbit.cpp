#include<bits/stdc++.h>
using namespace std;

// lowbit运算可以获取一个数最低位的1，常用于状态压缩动态规划获取前一个状态的值，或者树状数组中。

int lowbit(int x){
    return x & (-x);
}