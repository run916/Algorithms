#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a==1||b==1){
        return 1;
    }
    while(b){
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main(){
    cout << gcd(4, 6) << endl;
    return 0;
}