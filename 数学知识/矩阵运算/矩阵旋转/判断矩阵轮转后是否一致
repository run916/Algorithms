class Solution {
public:
    int n;
    bool check(vector<vector<int>> & a,vector<vector<int>> & b){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]!=b[i][j])return false;
            }
        }
        return true;
    }
    void transmit(vector<vector<int>> & a){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(a[i][j],a[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=(n-1)/2;j++)swap(a[i][j],a[i][n-1-j]);
        }
        return;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //尝试呗
        //先转置再交换
        n=mat.size();
        for(int i=0;i<4;i++){
            transmit(mat);
            if(check(mat,target))return true;
        }
        return false;
        
    }
};
