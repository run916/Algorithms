#include<bits/stdc++.h>
using namespace std;

void hannuota (int n,char a,char b,char c){
    // 简单的思路就是将a上面n-1个盘子先移动到b，c不变
    // 然后将a中最后一个盘子移动到c
    // 然后将b中n-2个盘子放到a中，在将b中最后一个放到c以此类推
    if(n==0){
        return;
    }else{
        // 汉诺塔函数递推体里面只有n-1是表示规模的，另外的参数指示表示一种转向关系，可以没有
        hannuota(n - 1, a, c, b);
        cout << a << " " << c << endl;
        hannuota(n - 1, b, a, c);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    hannuota(n, 'A', 'B', 'C');
    return 0;
}