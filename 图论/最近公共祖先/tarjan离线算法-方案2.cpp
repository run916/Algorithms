#include<bits/stdc++.h>

using namespace std;

//tarjan离线算法实现LCA
const int N = 5000005;
int arr[N];
int find(int x) {
    return x == arr[x] ? x : arr[x] = find(arr[x]);
}
//这里的merge不能用秩平衡定理 
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    arr[x] = y;
    return;
}
//兄弟链表法存储所有边 
int edge[2 * N];
int nest[2 * N];
int last[N];
int cnt = 1;
inline void add(int u, int v) {
    nest[cnt] = last[u];
    edge[cnt] = v;
    last[u] = cnt;
    cnt++;
    return;
}
//用来存储所有的查询以及查询的序号 
vector < int > q[N];
vector < int > qi[N];
void add_query(int u, int v, int id) {
    q[u].push_back(v);
    q[v].push_back(u);
    // 用额外的数组来记录查询序号，可以有效降低时间复杂度
    qi[u].push_back(id);
    qi[v].push_back(id);
    return;
}

int vise[N];
int ans[N];

void DFS(int k) {
    //初次访问 
    vise[k] = 1;
    for (int i = last[k]; i; i = nest[i]) {
        if (vise[edge[i]]) continue;
        DFS(edge[i]);
        //注意这里只能单向合并，可以直接设置父节点 
        merge(edge[i], k);
    }
    //这里一定要注意遍历顺序是后根序。 
    //查看是否已经有可以求解的
    for (int i = 0; i < q[k].size(); i++) {
        if (vise[q[k][i]] == 2) {
            ans[qi[k][i]] = find(q[k][i]);
        }
    }
    //遍历结束 
    vise[k] = 2;
    return;
}
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    //初始化并查集
    for (int i = 1; i <= n; i++) arr[i] = i;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", & u, & v);
        add(u, v);
        add(v, u);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", & u, & v);
        add_query(u, v, i);
        if (u == v) {
            ans[i] = u;
        }
    }
    DFS(s);
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}