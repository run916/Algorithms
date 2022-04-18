#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, p;
    cin >> s >> p;
    int n = s.length();
    int m = p.length();
    int pi[m];
    int k = -1;
    pi[0] = -1;
    //什么逻辑呢？
    //首先pi[k]表示的是p与子串p[0,k]的真后缀匹配的字符串的最大长度是多少，不过这里我们保存的是最长前缀的最后一个元素的下标。
    //p与自身匹配的过程
    for (int i = 1; i < m; i++){
        while(k!=-1&&p[i]!=p[k+1])
            k = pi[k];
        if(p[i]==p[k+1])
            k++;
        pi[i] = k;
    }
    //p与s的匹配过程，也即这里是两个单独的匹配过程逻辑是一致的，但是与自身匹配时需要记录pi，与s匹配时只需要匹配即可。
    k = -1;
    for (int i = 0; i < n; i++){
        while(k!=-1&&s[i]!=p[k+1])
            k = pi[k];
        if(s[i] == p[k+1])
            k++;
        if(k == m-1){
            cout << i - k +1 << endl;
            k = pi[k];
        }
    }
    for (int i = 0; i < m; i++){
        cout << pi[i] + 1 << " ";
    }
    return 0;
}