#include<bits/stdc++.h>
using namespace std;

const int N = 400010;
int max_array[N];
int min_array[N];
int lazy[N];
bool vise[N];
int num[100010];

// 更新节点值
void up(int rt){
    max_array[rt] = max(max_array[rt << 1], max_array[rt << 1 | 1]);
    min_array[rt] = min(min_array[rt << 1], min_array[rt << 1 | 1]);
    return;
}

// 构建线段树
void build(int l,int r,int rt){
    if(l==r){
        max_array[rt] = num[l];
        min_array[rt] = num[l];
        return;
    }
    int m = (l + r) / 2;
    if(l<=m){
        build(l, m, rt << 1);
    }
    if(r>m){
        build(m + 1, r, rt << 1 | 1);
    }
    up(rt);
    return;
}

// 惰性更新
void down(int ln,int rn,int rt){
    if(vise[rt]){
        max_array[rt << 1] = lazy[rt];
        max_array[rt << 1 | 1] = lazy[rt];
        min_array[rt << 1] = lazy[rt];
        min_array[rt << 1 | 1] = lazy[rt];
        lazy[rt << 1] = lazy[rt];
        lazy[rt << 1 | 1] = lazy[rt];
        vise[rt] = false;
    }
    return;
}

// 点更新
void update(int x,int v,int l,int r,int rt){
    if(l==r){
        max_array[rt] = v;
        min_array[rt] = v;
        return;
    }
    int m = (l + r) / 2;
    // 惰性更新
    down(m - l + 1, r - m, rt);
    if(x<=m){
        update(x, v, l, m, rt << 1);
    }else{
        update(x, v, m + 1, r, rt << 1 | 1);
    }
    up(rt);
    return;
}

// 区间更新
void update(int x,int y,int v,int l,int r,int rt){
    if(x<=l&&y>=r){
        max_array[rt] =  v;
        min_array[rt] =  v;
        lazy[rt] = v;
        vise[rt] = true;
        return;
    }
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    if(x<=m){
        update(x, y, v, l, m, rt << 1);
    }
    if(y>m){
        update(x, y, v, m + 1, r, rt << 1 | 1);
    }
    up(rt);
    return;
}

// 区间查询
int query_max(int x,int y,int l,int r,int rt){
    if(x<=l&&y>=r){
        return max_array[rt];
    }
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    int ans = INT_MIN;
    if(x<=m){
        ans = max(ans, query_max(x, y, l, m, rt << 1));
    }
    if(y>m){
        ans = max(ans, query_max(x, y, m + 1, r, rt << 1 | 1));
    }
    return ans;
}

// 区间查询
int query_min(int x,int y,int l,int r,int rt){
    if(x<=l&&y>=r){
        return min_array[rt];
    }
    int m = (l + r) / 2;
    down(m - l + 1, r - m, rt);
    int ans = INT_MAX;
    if(x<=m){
        ans = min(ans, query_min(x, y, l, m, rt << 1));
    }
    if(y>m){
        ans = min(ans, query_min(x, y, m + 1, r, rt << 1 | 1));
    }
    return ans;
}

int main(){
    // 初始化
    memset(vise, false, sizeof(vise));
    int n, k;
    cin >> n >> k;
    for (int i = 0;i<n;i++){
        cin >> num[i];
    }
    build(0, n - 1, 1);
    for (int i = k - 1; i < n; i++){
        cout << query_max(i - k + 1, i, 0, n - 1, 1) << " ";
        cout << query_min(i - k + 1, i, 0, n - 1, 1) << endl;
    }
    // cout << endl;
    // update(2, 7, 0, n - 1, 1);
    // for (int i = k - 1; i < n; i++){
    //     cout << query_max(i - k + 1, i, 0, n - 1, 1) << " ";
    //     cout << query_min(i - k + 1, i, 0, n - 1, 1) << endl;
    // }
    // cout << endl;
    // update(2, -6, 0, n - 1, 1);
    // for (int i = k - 1; i < n; i++){
    //     cout << query_max(i - k + 1, i, 0, n - 1, 1) << " ";
    //     cout << query_min(i - k + 1, i, 0, n - 1, 1) << endl;
    // }
    // cout << endl;
    // update(1, 2, 8, 0, n - 1, 1);
    // for (int i = k - 1; i < n; i++){
    //     cout << query_max(i - k + 1, i, 0, n - 1, 1) << " ";
    //     cout << query_min(i - k + 1, i, 0, n - 1, 1) << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n;i++){
    //     cout << query_min(i, i, 0, n - 1, 1) << " ";
    // }
    return 0;
}
