#include<bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/description/94/

int main() {
    int n;
    cin >> n;
    int state = (1 << n) - 1;
    //这句循环是子集枚举的最为核心的要点，我们一定要理清思路逻辑。
    for (int i = state; i; i = (i - 1) & state) {
        for (int j = 0; i >> j; j++) {
            if ((i >> j) & 1) cout << j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}