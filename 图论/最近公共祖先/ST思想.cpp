#include<bits/stdc++.h>

using namespace std;

const int N = 1000010;
int edge[N];
int nest[N];
int last[N];
int cnt = 1;

void add(int u, int v) {
    edge[cnt] = v;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

vector < int > num;
int d[N];
bool vise[N];
int has[N];

void dfs(int k) {
    for (int i = last[k]; i; i = nest[i]) {
        if (!vise[edge[i]]) {
            vise[edge[i]] = true;
            d[edge[i]] = d[k] + 1;
            dfs(edge[i]);
            num.push_back(edge[i]);
            has[edge[i]] = num.size() - 1;
            num.push_back(k);
        }
    }
    return;
}

int main() {
    memset(last, 0, sizeof(last));
    // 构建哈希函数，用来记录某一个元素的位置
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", & u, & v);
        add(u, v);
        add(v, u);
    }
    d[s] = 1;
    memset(vise, false, sizeof(vise));
    vise[s] = true;
    dfs(s);
    has[s] = num.size() - 1;
    // ST构建查询的dp数组
    int k = log2(num.size()) + 1;
    int dp[num.size()][k];

    // 初始化
    for (int i = 0; i < num.size(); i++) {
        dp[i][0] = num[i];
    }

    for (int i = 1;
        (1 << i) <= num.size(); i++) { // 注意边界条件，这里应该有等于
        for (int j = 0; j + (1 << i) - 1 < num.size(); j++) {
            if (d[dp[j][i - 1]] < d[dp[j + (1 << i - 1)][i - 1]]) {
                dp[j][i] = dp[j][i - 1];
            } else {
                dp[j][i] = dp[j + (1 << i - 1)][i - 1];
            }
        }
    }
    // 查询
    int l, r;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", & u, & v);
        // 查询
        l = has[u];
        r = has[v];
        if (l > r) {
            swap(l, r);
        }
        k = log2(r - l + 1);
        if (d[dp[l][k]] < d[dp[r - (1 << k) + 1][k]]) {
            cout << dp[l][k] << endl;
        } else {
            cout << dp[r - (1 << k) + 1][k] << endl;
        }
    }
    return 0;
}