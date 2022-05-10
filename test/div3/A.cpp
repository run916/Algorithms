#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> x >> y;
        int d = max(x - a, 0);
        int e = max(y - b, 0);
        if(c>=d+e){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}