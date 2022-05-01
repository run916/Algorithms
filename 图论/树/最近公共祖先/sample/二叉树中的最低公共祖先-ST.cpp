#include<bits/stdc++.h>

using namespace std;
//LCA ST算法实现
// https://www.acwing.com/problem/content/1646/
# define N 100001
int ins[N];
int mid[N];
unordered_map < int, int > has; //构建二叉树时，用于寻找中序遍历中节点的位置 
unordered_map < int, int > tran; //节点编码，编码到1到N的自然数上 
unordered_map < int, int > retran; //解码，返回原始的输入数据 
int edge[2 * N][2];
int last[N];
int id = 0;
//添加边 
inline void add(int u, int v) { //添加边，一定要记住  
    edge[id][0] = last[u];
    edge[id][1] = v;
    last[u] = id;
    id++;
    edge[id][0] = last[v];
    edge[id][1] = u;
    last[v] = id;
    id++;
    return;
}
void dfs(int l, int r, int pre, int later, int k) {
    if (k > 0) add(k, ins[l]);
    if (l == r) return;
    int index = has[ins[l]];
    int dis = index - pre;
    if (dis >= 1) dfs(l + 1, l + dis, pre, index - 1, ins[l]);
    if (l + dis + 1 <= r) dfs(l + dis + 1, r, index + 1, later, ins[l]);
    return;
}
//arr中存的是深度，而ans中存的是节点的坐标 
int arr[2 * N];
int ans[2 * N];
int dep[N];
int first[N];
int cnt = 0;
void DFS(int k) {
    for (int i = last[k]; i != -1; i = edge[i][0]) {
        if (dep[edge[i][1]] == 0) {
            dep[edge[i][1]] = dep[k] + 1;
            DFS(edge[i][1]);
            first[edge[i][1]] = cnt;
            arr[cnt] = dep[edge[i][1]];
            ans[cnt] = edge[i][1];
            cnt++;
            //每遍历一次子树，就将父节点添加一次 
            arr[cnt] = dep[k];
            ans[cnt] = k;
            cnt++;
        }
    }
    return;
}
int main() {
    int m, n;
    cin >> m >> n;
    //重映射，数据中给出的节点的值，而不是序号，这里随便指定一个序号。 
    for (int i = 0; i < n; i++) cin >> mid[i];
    for (int i = 0; i < n; i++) cin >> ins[i];
    for (int i = 0; i < n; i++) {
        tran[ins[i]] = i + 1;
        retran[i + 1] = ins[i];
    }
    for (int i = 0; i < n; i++) ins[i] = tran[ins[i]];
    for (int i = 0; i < n; i++) mid[i] = tran[mid[i]];
    for (int i = 0; i < n; i++) has[mid[i]] = i;
    memset(last, -1, sizeof(last)); //last是一定要初始化为-1的，否则无法DFS 
    dfs(0, n - 1, 0, n - 1, 0);
    //初始化第一个位置 
    memset(dep, 0, sizeof(dep));
    memset(ans, 0, sizeof(ans));
    dep[ins[0]] = 1;
    DFS(ins[0]); //生成一个特殊的DFS序列 
    //注意单独处理出根节点的first数组,由于最后一个一定是根节点，所以我们直接将first设置为cnt-1即可
    first[ins[0]] = cnt - 1;
    //预处理ST算法的DP数组 
    int dp[cnt][(int) log2(cnt) + 1];
    for (int i = 0; i < cnt; i++) dp[i][0] = i; //保存的是下标 
    //C++当数组开辟空间不够时，会占用重写已经开辟的空间，造成不可预知的错误 
    //一定有一个最值 
    for (int i = 1; (1 << i) <= cnt; i++) {
        for (int j = 0; j + (1 << i) - 1 < cnt; j++) {
            if (arr[dp[j][i - 1]] < arr[dp[j + (1 << i - 1)][i - 1]]) {
                dp[j][i] = dp[j][i - 1];
            } else {
                dp[j][i] = dp[j + (1 << i - 1)][i - 1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int a = tran[u];
        int b = tran[v];
        bool tag = false;
        if (a == 0) {
            cout << "ERROR: " << u;
            tag = true;
        }
        if (b == 0) {
            if (tag) {
                cout << " and " << v << " are not found." << endl;
                continue;
            } else {
                cout << "ERROR: " << v << " is not found." << endl;
                continue;
            }

        }
        if (tag) {
            cout << " is not found." << endl;
            continue;
        }
        bool tip = false;
        if (first[a] > first[b]) {
            swap(a, b);
            swap(u, v);
            tip = true;
        }
        int f;
        int k = log2(first[b] - first[a] + 1);
        if (arr[dp[first[a]][k]] < arr[dp[first[b] - (1 << k) + 1][k]]) {
            f = ans[dp[first[a]][k]];
        } else {
            f = ans[dp[first[b] - (1 << k) + 1][k]];
        }
        if (f == a) {
            cout << u << " is an ancestor of " << v << "." << endl;
            continue;
        }
        if (f == b) {
            cout << v << " is an ancestor of " << u << "." << endl;
            continue;
        }
        if (!tip) cout << "LCA of " << u << " and " << v << " is " << retran[f] << "." << endl;
        else cout << "LCA of " << v << " and " << u << " is " << retran[f] << "." << endl;
    }
    return 0;


}