#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int edge[N];
int last[N];
int nest[N];
int cnt = 1;
void add(int u,int v){
    edge[cnt] = v;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}
vector<int> path;

void dfs(int k){
    path.push_back(k);
    for (int i = last[k]; i;i=nest[i]){
        dfs(edge[i]);
    }
    if(last[k]==0){
        // print
        cout << path.size() << endl;
        for (int i = 0; i < path.size();i++){
            cout << path[i] << " ";
        }
        cout << endl;
        path.clear();
    }
    return;
}

int vise[N];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(last, 0, sizeof(last));
        cnt = 1;
        int n;
        cin >> n;
        int v;
        int root;
        memset(vise, 0, sizeof(vise));
        for (int i = 1; i <= n;i++){
            cin >> v;
            if(v==i){
                root = v;
            }else{
                add(v, i);
                vise[v]++;
            }
        }
        int count = 0;
        for(int i=1;i<=n;i++){
            if(vise[i]==0){
                count++;
            }
        }
        cout << count << endl;
        // find path
        dfs(root);
        cout << endl;
    }
    return 0;
}