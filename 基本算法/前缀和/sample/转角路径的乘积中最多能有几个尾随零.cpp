#include<bits/stdc++.h>
#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"
using namespace std;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        // 枚举因子2和5的数目即可
        int n=grid.size();
        int m=grid[0].size();
        int lp2[n][m+1],lp5[n][m+1];
        int tp2[n+1][m],tp5[n+1][m];
        memset(lp2,0,sizeof(lp2));
        memset(lp5,0,sizeof(lp5));
        memset(tp2,0,sizeof(tp2));
        memset(tp5,0,sizeof(tp5));
        int two,five;
        int tmp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                two=0,five=0;
                tmp=grid[i][j];
                while(tmp%2==0){
                    two++;
                    tmp/=2;
                }
                lp2[i][j+1]=lp2[i][j]+two;
                tp2[i+1][j]=tp2[i][j]+two;

                tmp=grid[i][j];
                while(tmp%5==0){
                    five++;
                    tmp/=5;
                }
                // 求解前缀和
                lp5[i][j+1]=lp5[i][j]+five;
                tp5[i+1][j]=tp5[i][j]+five;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // 左上
                ans=max(ans,min(lp2[i][j+1]+tp2[i][j],lp5[i][j+1]+tp5[i][j]));
                // 左下
                ans=max(ans,min(lp2[i][j+1]+tp2[n][j]-tp2[i+1][j],lp5[i][j+1]+tp5[n][j]-tp5[i+1][j]));
                // 右上
                ans=max(ans,min(lp2[i][m]-lp2[i][j]+tp2[i][j],lp5[i][m]-lp5[i][j]+tp5[i][j]));
                // 右下
                ans=max(ans,min(lp2[i][m]-lp2[i][j]+tp2[n][j]-tp2[i+1][j],lp5[i][m]-lp5[i][j]+tp5[n][j]-tp5[i+1][j]));
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin >> s;
    vector<vector<int>> grid = two_dimension(s);
    Solution solve;
    cout << solve.maxTrailingZeros(grid);
    return 0;
}