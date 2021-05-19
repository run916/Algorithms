class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        //简单地dp问题
        int n=box.size();
        int m=box[0].size();
        //先压缩，再旋转
        for(int i=0;i<n;i++){
            int now=m-1;
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='*'){
                    now=j-1;
                    continue;
                }
                if(box[i][j]=='#'){
                    if(now==j)now--;
                    else{
                        swap(box[i][j],box[i][now]);
                        now--;
                    }
                }
            }
        }
        //旋转矩阵
        vector<vector<char>> ans(m,vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][i]=box[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<=((n-1)/2);j++)swap(ans[i][j],ans[i][n-1-j]);
        }
        return ans;

    }
};
