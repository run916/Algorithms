#include<bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/94/
bool vise[16];
int n;

void dfs(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= 15; i++) {
            if (vise[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    dfs(k + 1);
    vise[k] = true;
    dfs(k + 1);
    vise[k] = false;
    return;
}

int main() {
    cin >> n;
    memset(vise, false, sizeof(vise));
    dfs(1);
    return 0;
}