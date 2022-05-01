#include<bits/stdc++.h>

using namespace std;

// pair_hash
struct pair_hash{
    // 只有类，结构体才有常函数，也就意味着常函数一定是成员函数
    size_t operator ()(const pair<int,int> & a)const{
        string str = to_string(a.first) + to_string(a.second);
        return hash<string>()(str);
    }
};

const int N = 1000010;
// 领接链表
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
// 并查集
int fa[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
    return;
}

// dfs过程中，离线查询所有结果
bool vise[N];// 标记数组，用来标记某个节点是否被遍历
bool finish[N];// 标记数组，用来标记该节点的子树是否全部被遍历
unordered_map <pair< int, int > , int , pair_hash> has;// 记录结果
vector < vector < int >> query;
void dfs(int k) {
    for (int i = last[k]; i; i = nest[i]) {
        if (!vise[edge[i]]) {
            vise[edge[i]] = true;
            dfs(edge[i]);
            // dfs结束后合并子集
            if(find(k)!=find(edge[i])){
                merge(edge[i], k);
            }
        }
    }
    for (int i = 0; i < query[k].size(); i++) {
        if (finish[query[k][i]]) {
            has[make_pair(k, query[k][i])] = find(query[k][i]);
        }
    }
    finish[k] = true;
    return;
}

int main() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", & u, & v);
        add(u, v);
        add(v, u);
    }
    // 每个节点拉出一条查询链表
    query = vector<vector<int>>(n + 1);
    vector < vector < int >> ans;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", & u, & v);
        query[u].push_back(v);
        query[v].push_back(u);
        ans.push_back({u, v});
    }
    memset(vise, false, sizeof(vise));
    memset(finish, false, sizeof(finish));
    vise[s] = true;
    dfs(s);
    // 输出答案
    for (int i = 0; i < m;i++){
        if(ans[i][0]==ans[i][1]){
            printf("%d \n", ans[i][0]);
        }else{
            cout << max(has[{ans[i][0], ans[i][1]}], has[{ans[i][1], ans[i][0]}]) << endl;
        }
            
    }
    return 0;
}