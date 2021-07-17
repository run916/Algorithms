#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int fa[N];
int depth[N]; //保存的是每个节点的当时高度
//查询函数，路径压缩优化
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

//合并函数,秩优化
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    if (depth[x] > depth[y]){
        fa[y] = x;
    }
    else{
        fa[x] = y;
        if (depth[x] == depth[y]){
            depth[y]++;
        }
    }
    return;
}

int main(){
    memset(depth, 1, sizeof(depth));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    int x, y, z;
    for (int i = 0; i < m; i++){
        cin >> z >> x >> y;
        if(z == 1){
            merge(x, y);
        }else{
            if(find(x) == find(y)){
                cout << "Y" << endl;
            }else{
                cout << "N" << endl;
            }
        }
    }
    return 0;
}
