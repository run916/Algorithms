#include<bits/stdc++.h>

using namespace std;

// https://www.luogu.com.cn/problem/P3379

// 邻接链表
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

int lowbit(int x) {
    return x & (-x);
}


int d[N]; // 记录树中某一个节点的深度
int dp[N][20]; // 存储祖先

// dfs求解节点深度，同时求解dp数组的值。
void dfs(int k) {
    // 先求解dp数组的值，由于乘2的关系，我们只需要保证区间长度乘以2的值小于深度约束即可
    for (int i = 1;(1 << i) < d[k]; i++) {
        dp[k][i] = dp[dp[k][i - 1]][i - 1];
    }
    // 然后dfs遍历
    for (int i = last[k]; i; i = nest[i]) {
        if (d[edge[i]] == 0) {
            d[edge[i]] = d[k] + 1;
            dp[edge[i]][0] = k;
            dfs(edge[i]);
        }
    }
    return;
}

// lca 查询
int lca(int u, int v) {
    // 需要先将u和v转化到同一层
    if (d[u] < d[v]) {
        swap(u, v);
    }
    // 开始调整，这里用数的二进制分解快速找到对应的节点
    int dis = d[u] - d[v];
    // 利用数的二进制分解快速求解，妙啊，一定要学会这种操作
    for (int i = dis; i; i -= lowbit(i)) {
        u = dp[u][(int) log2(lowbit(i)) ];
    }

    // 判断是否相等，如果相等则证明这两个点的最近公共祖先就是高度较低的节点
    if (u == v) {
        return u;
    }

    // 倍增查找
    int k = log2(d[u]);
    for (int i = k; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int main() {
    memset(last, 0, sizeof(last));
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", & u, & v);
        add(u, v);
        add(v, u);
    }
    memset(d, 0, sizeof(d));
    d[s] = 1;
    dp[s][0] = -1;
    dfs(s);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", & u, & v);
        cout << lca(u, v) << endl;
    }
    return 0;
}