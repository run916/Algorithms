#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    string p;
    cin>>s>>p;

    // 预处理模式串，得到pi数组
    // pi[i]标示p.substr(1,i)与p的可以匹配的最大前缀的最后一个字符的下标
    int m = p.length();
    int pi[m];
    pi[0] = -1;
    int k = -1;
    for (int i = 1; i <m; i++){
        while(k!=-1&&p[i]!=p[k+1]){
            k = pi[k];
        }
        if(p[i]==p[k+1]){
            k++;
        }
        pi[i] = k;
    }

    for (int i = 0; i < m;i++){
        cout << pi[i] << " ";
    }
    cout << endl;

    // 字符串匹配
    int n = s.length();
    k = -1;
    for (int i = 0; i < n; i ++){
        while(k != -1 && s[i]!=p[k+1]){
            k = pi[k];
        }
        if(s[i]==p[k+1]){
            k++;
        }
        if(k==m-1){
            cout << "success" << endl;
        }
    }
    return 0;
}