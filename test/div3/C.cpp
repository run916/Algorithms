#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int zero[N];
int one[N];
int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        cin >> s;
        int n = s.length();
        bool tag = false;
        bool suit = true;
        // check
        for (int i = n - 1; i >= 0;i--){
            if(s[i]=='1'){
                tag = true;
            }else if(s[i]=='0'){
                if(tag){
                    suit = false;
                    break;
                }
            }
        }
        if(!suit){
            cout << 0 << endl;
            continue;
        }
        // sum
        int a = 0, b = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                a = i;
            }else if(s[i]=='0'&&b==-1){
                b = i;
            }
        }
        if(b==-1){
            b = n-1;
        }
        cout << b - a + 1<< endl;
    }
    return 0;
}