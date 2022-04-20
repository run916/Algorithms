#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        int n=gem.size();
        int m=operations.size();
        for(int i=0;i<m;i++){
            int a=operations[i][0];
            int b=operations[i][1];
            int c=gem[a]/2;
            gem[a]-=c;
            gem[b]+=c;
        }
        int h=0;
        int l=INT_MAX;
        for(int i=0;i<n;i++){
            h=max(h,gem[i]);
            l=min(l,gem[i]);
        }
        return h-l;

    }
};