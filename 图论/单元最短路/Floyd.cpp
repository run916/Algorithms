#include<bits/stdc++.h>
using namespace std;

double get(pair<int,int> &a,pair<int,int>&b){
    return (double)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(){
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> point(n+1);
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        point[i] = make_pair(x, y);
    }
    vector<vector<double>> mat(n + 1, vector<double>(n + 1,1000000002.0));
    for (int i = 1; i <= n; i++){
        mat[i][i] = 0;
        string s;
        cin>>s;
        for (int j = 1; j <= n; j++){
            if(s[j-1]=='1'){
                mat[i][j] = get(point[i], point[j]);
            }
        }
    }
    // Floyd求解所有点对之间的单元最短路
    vector<vector<double>> dis(mat);
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // 题目中给点的两个分支是不连通的，所以我们只需要将不连通的两部分相互组合即可
    vector<double> maxstep(n+1,0);
    double ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(dis[i][j]>1000000000){
                continue;
            }
            maxstep[i] = max(maxstep[i], dis[i][j]);
            ans = max(ans, maxstep[i]);
        }
    }
    // 可能右多个连通分支，但是每个分支只需要考虑与其他分支的枚举情况即可
    
    vector<int> A;
    vector<int> B;
    double tmp = 1000000000.0;
    for (int k = 1; k <= n; k++){
        A.clear();
        B.clear();
        for (int i = 1; i <= n; i++){
            if(dis[k][i]>1000000000){
                B.push_back(i);
            }else{
                A.push_back(i);
            }
        }
        
        for (int i = 0; i < A.size();i++){
            for (int j = 0; j < B.size();j++){
                tmp = min(tmp, maxstep[A[i]] + maxstep[B[j]] + get(point[A[i]], point[B[j]]));
            }
        }
    }
    ans = max(ans, tmp);
    printf("%.6lf \n", ans);
    return 0;
}