#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int edge[N];
int nest[N];
int val[N];
int last[N];
int cnt = 2;

void add(int u,int v,int w){
    edge[cnt] = v;
    nest[cnt] = last[u];
    val[cnt] = w;
    last[u] = cnt;
    cnt++;
    return;
}

int s,t;
int pre[N];
int in[N];
int d[N];
queue<int> que;

int dinic(int k,int flow){
    
}