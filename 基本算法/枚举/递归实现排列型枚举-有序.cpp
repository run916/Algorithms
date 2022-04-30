#include<bits/stdc++.h>

using namespace std;

int n;
int ans[10];
bool vise[10];

void dfs(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    //使用一个辅助数组来定序是一种非常巧妙地编程技巧，值得我们仔细揣摩
    //除了对于元素不相同的数组，对于元素相同的数组，我们也可以使用一个局部的位置数组，
    //来限制当前位置同一个元素的枚举次数只有一次。
    for (int i = 1; i <= n; i++) {
        if (!vise[i]) {
            vise[i] = true;
            ans[k] = i;
            dfs(k + 1);
            vise[i] = false;
        }
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