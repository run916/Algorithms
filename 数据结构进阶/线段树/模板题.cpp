#include<bits/stdc++.h>
using namespace std;

const int N = 400010;
long long duan[N];
long long lazy[N];


long long arr[N];
void up(int rt){
    duan[rt] = duan[rt << 1] + duan[rt << 1 | 1];
    return;
}

void build(int l, int r, int rt){
    if(l == r){
        duan[rt] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    up(rt);
    return;
}


void down(int ln, int rn, int rt){
    if(lazy[rt]){
        duan[rt << 1] += (long long) ln * lazy[rt];
        duan[rt << 1 | 1] += (long long) rn * lazy[rt];
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
    return;
}

void update(int x, int v, int l, int r, int rt){
    if(l == r){
        duan[rt] += v;
        return;
    }
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    if(x<=m)
        update(x, v, l, m, rt << 1);
    else
        update(x, v, m + 1, r, rt << 1 | 1);
    up(rt);
    return;
}

void update(int x, int y, int v, int l, int r, int rt){
    if(x <= l && y >= r){
        duan[rt] += (long long)(r - l + 1) * v;
        lazy[rt] += v;
        return;
    }
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    if(x <= m)
        update(x, y, v, l, m, rt << 1);
    if(y > m)
        update(x, y, v, m + 1, r, rt << 1 | 1);
    up(rt);
    return;
}

long long query(int x,int y,int l,int r,int rt){
    if(x <= l && r <= y){
        return duan[rt];
    }
    long long ans = 0;
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    if(x <= m)
        ans += query(x, y, l, m, rt << 1);
    if(y > m)
        ans += query(x, y, m + 1, r, rt << 1 | 1);
    return ans;
}

int main(){
    memset(lazy, 0, sizeof(lazy));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
    }
    build(0, n - 1, 1);
    int op;
    long long x, y, k;
    for (int i = 0; i < m; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d %d %lld", &x, &y, &k);
            update(x - 1, y - 1, k, 0, n - 1, 1);
        }else{
            scanf("%d %d", &x, &y);
            printf("%lld \n", query(x - 1, y - 1, 0, n - 1, 1));
        }
    }
    return 0;
}