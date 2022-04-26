#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/PT07Z/

const int N = 20010;
int edge[N];
int nest[N];
int last[N];
int cnt = 1;
void add(int u,int v){
    edge[cnt] = v;
    nest[cnt] = last[u];
    last[u] = cnt;
    cnt++;
    return;
}

int dp[N];
bool vise[N];
int ans = 0;
queue<int> que;

int bfs(int k){
    while(!que.empty()){
        que.pop();
    }
    que.push(k);
    dp[k] = 0;
    vise[k] = true;
    int v;
    while(!que.empty()){
        v = que.front();
        for (int i = last[que.front()];i;i=nest[i]){
            if(!vise[edge[i]]){
                vise[edge[i]] = true;
                que.push(edge[i]);
                dp[edge[i]] = dp[que.front()] + 1;
            }
        }
        que.pop();
    }
    return v;
}



int main(){
    int n;
    cin >> n;
    int u, v;
    for (int i = 0;i<n-1;i++){
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    memset(vise, false, sizeof(vise));
    v = bfs(1);
    memset(vise, false, sizeof(vise));
    bfs(v);
    int ans = 0;
    for (int i = 1;i<=n;i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}