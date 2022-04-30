#include<bits/stdc++.h>

using namespace std;

// https://ac.nowcoder.com/acm/problem/17857

int main() {
    int n, m;
    cin >> n >> m;
    int op[n][2];
    string s;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> s >> a;
        if (s == "AND") {
            op[i][0] = 1;
        } else if (s == "OR") {
            op[i][0] = 2;
        } else {
            op[i][0] = 3;
        }
        op[i][1] = a;
    }
    // 开始判断
    int k = log2(m);
    int ans = 0;
    for (int i = k; i >= 0; i--) {
        if (ans + (1 << i) > m) {
            continue;
        }
        // 符合约束，开始判断，需要额外注意的是，第i位为0或者1，都要判断一遍。
        int d = (1 << i);
        int p = 0;
        for (int j = 0; j < n; j++) {
            if (op[j][0] == 1) {
                d &= op[j][1];
                p &= op[j][1];
            } else if (op[j][0] == 2) {
                d |= op[j][1];
                p |= op[j][1];
            } else {
                d ^= op[j][1];
                p ^= op[j][1];
            }
        }
        // 这里如果第i位是0，操作结束后，最终结果为1，那么这个位置就应该设置为0。
        if ((1 << i) & p) {
            continue;
        } else if ((1 << i) & d) {
            // 只有初始为0，结果为0，初始为1，结果为1时，这里才需要将第i位置为1。
            ans += (1 << i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (op[i][0] == 1) {
            ans &= op[i][1];
        } else if (op[i][0] == 2) {
            ans |= op[i][1];
        } else {
            ans ^= op[i][1];
        }
    }
    cout << ans;
    return 0;
}