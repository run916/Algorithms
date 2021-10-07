#include<bits/stdc++.h>
using namespace std;

int main(){
    int num[10] = {1, 2, 3, 4, 5, 6, 7};
    int m = (1 << 7) - 1;
    for (int i = m; i; i = (i - 1) & m) {
        for (int j = 0; i>>j ; j++){
            if(i&(1<<j)){
                cout << num[j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}