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

void dfs(int k){
    for (int i = last[k]; i;i=nest[i]){
        if(!vise[edge[i]]){
            vise[edge[i]] = true;
            dfs(edge[i]);
            ans = max(ans, dp[edge[i]] + dp[k] + 1);
            dp[k] = max(dp[k], dp[edge[i]] + 1);
        }
    }
    ans = max(ans, dp[k]);
    return;
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
    memset(dp, 0, sizeof(dp));
    memset(vise, false, sizeof(vise));
    vise[1] = true;
    dfs(1);
    cout << ans;
    return 0;
}