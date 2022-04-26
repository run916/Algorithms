#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        //简单数学问题，判断一下即可
        priority_queue<pair<int,int>> que;
        que.emplace(memory1,2);
        que.emplace(memory2,1);
        int i=1;
        for(;;i++){
            int k=que.top().first;
            if(k>=i){
                que.emplace(k-i,que.top().second);
                que.pop();
            }else{
                break;
            }
        }
        vector<int> ans(3);
        ans[0]=i;
        ans[que.top().second]=que.top().first;
        que.pop();
        ans[que.top().second]=que.top().first;
        swap(ans[1],ans[2]);
        return ans;
    }
};
