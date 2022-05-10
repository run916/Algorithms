#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    int num[50];
    while(t--){
        cin >> n;
        for (int i = 1;i<=n;i++){
            cin >> num[i];
        }
        int ans = 0;
        bool tag = true;
        for (int i = n-1;i>=1;i--){
            while(num[i]&&num[i]>=num[i+1]){
                num[i] /= 2;
                ans++;
            }
            if(num[i]>=num[i+1]){
                tag = false;
            }
        }
        if(tag){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}