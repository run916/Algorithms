#include<bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/number-of-flowers-in-full-bloom/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        // 排队
        int n=flowers.size();
        sort(flowers.begin(),flowers.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        priority_queue<int,vector<int>,greater<int>> que;
        vector<pair<int,int>> p;
        for(int i=0;i<persons.size();i++){
            p.push_back({persons[i],i});
        }
        sort(p.begin(),p.end());
        vector<int> ans(p.size());
        int k=0;
        for(int i=0;i<p.size();i++){
            int s=p[i].first;
            // 查询时，先将满足条件的元素加入优先级队列
            for(;k<n&&flowers[k][0]<=s;k++){
                que.push(flowers[k][1]);
            }
            for(;!que.empty()&&que.top()<s;que.pop());
            ans[p[i].second]=que.size();
        }
        return ans;
    }
};