// https://www.acwing.com/problem/content/101/
#include<iostream>

#include<cstring>

using namespace std;

const int N = 5050;

int s[N][N];

int main() {
    int N, R;
    cin >> N >> R;
    int n = R, m = R;
    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        s[x][y] += w;
        n = max(n, x), m = max(m, y); //至少是R*R初坐标
    }
    //求二维前缀和
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    //求边长为R的正方形的最大值
    int res = 0;
    for (int i = R; i <= n; i++)
        for (int j = R; j <= m; j++)
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
    cout << res << endl;
    return 0;
}