#include<bits/stdc++.h>

using namespace std;

int n;
int ans[10];

void dfs(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    // 交叉
    for (int i = k; i <= n; i++) {
        swap(ans[i], ans[k]);
        dfs(k + 1);
        swap(ans[i], ans[k]);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    dfs(1);
    return 0;
}