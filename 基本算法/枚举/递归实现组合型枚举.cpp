#include<bits/stdc++.h>

using namespace std;
// https://www.acwing.com/problem/content/95/

bool vise[51];
int num = 0;
int n, m;

void dfs(int k) {
    // 加判断条件，及时剪枝，如果元素数量不够，或者已经超过了m个，就不继续往下执行了
    if (num + n + 1 - k < m || num > m) {
        return;
    }
    if (k == n + 1) {
        for (int i = 1; i <= n; i++) {
            if (vise[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        return;
    }
    // 选择第k个元素
    vise[k] = true;
    num++;
    dfs(k + 1);
    num--;
    vise[k] = false;
    // 不选第k个元素
    dfs(k + 1);
    return;
}

int main() {
    cin >> n >> m;
    memset(vise, false, sizeof(vise));
    dfs(1);
    return 0;
}