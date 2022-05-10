// https://codeforces.com/contest/1675/problem/F

#include<bits/stdc++.h>

using namespace std;

const int N = 200010;
int edge[2*N];
int nest[2*N];
int last[N];
int cnt = 1;
void add(int u, int v) {
    edge[cnt] = v;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}
int s, t;
int dis[N];
int d[N];
bool vise[N];
bool num[N];

void dfs(int k) {
    vise[k] = true;
    int tmp = 0;
    for (int i = last[k]; i; i = nest[i]) {
        if (!vise[edge[i]]) {
            d[edge[i]] = d[k] + 1;
            dfs(edge[i]);
            if (dis[edge[i]] >= 0) {
                tmp += dis[edge[i]] + 2;
            }
        }
    }
    if (num[k]) {
        dis[k] = 0;
    }
    if (tmp > 0) {
        dis[k] = tmp;
    }
    return;
}

int main() {
    int m;
    cin >> m;
    int n, k;
    while (m--) {
        // initial
        memset(d, 0, sizeof(d));
        memset(dis, -1, sizeof(dis));
        memset(vise, false, sizeof(vise));
        memset(num, false, sizeof(num));
        memset(last, 0, sizeof(last));
        cnt = 1;

        cin >> n >> k;
        cin >> s>>t;
        num[t] = true;
        int a;
        for (int i = 0; i < k; i++) {
            cin >> a;
            num[a] = true;
        }
        int u, v;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        d[s] = 0;
        dfs(s);
        cout << dis[s] - d[t] << endl;
    }
    return 0;
}