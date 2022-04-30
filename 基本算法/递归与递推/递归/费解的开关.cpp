#include<bits/stdc++.h>
using namespace std;

int compute(int state, vector<vector<int>> m) {
    //int[][]形式的参数传递的是指针，而不是形式参数，所以要注意
    int count=0;

    for(int i=0; i<5; i++) {
        if((state&(1<<i))>0) {
            count++;
            m[0][i]^=1;
            m[1][i]^=1;
            if(i-1>=0)m[0][i-1]^=1;
            if(i+1<5)m[0][i+1]^=1;
        }
    }

    for(int i=0; i<4; i++) {
        for(int j=0; j<5; j++) {
            if(m[i][j]==0) {
                count++;
                m[i+1][j]^=1;
                m[i][j]^=1;
                if(j-1>=0)m[i+1][j-1]^=1;
                if(j+1<5)m[i+1][j+1]^=1;
                if(i+2<5)m[i+2][j]^=1;
            }
        }
    }

    for(int i=0; i<5; i++)if(m[4][i]==0)return INT_MAX;
    return count;
}

int main() {
    //遍历第一行即可
    int T;
    cin>>T;
    // 如果上一行的状态确定了，那么要将上一行中所有1的位置变为0的操作只有一种，以此类推，后续所有位置的操作也就确定的。
    // 基于此，我们可以枚举第一开灯的方式，来判断最少需要多少次可以使得所有等变亮。
    for(int j=0; j<T; j++) {
        vector<vector<int>>m(5, vector<int>(5));
        int ans=INT_MAX;
        string str;

        for(int i=0; i<5; i++) {
            cin>>str;

            for(int j=0; j<5; j++) {
                if(str[j]=='1')m[i][j]=1;
                else m[i][j]=0;
            }
        }

        for(int i=0; i<(1<<5); i++) {
            ans=min(ans, compute(i, m));
        }

        if(ans>6)cout<<-1<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}