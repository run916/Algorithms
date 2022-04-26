#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // 高度最高位100，桶排序？
        vector<vector<int>> r(101);
        int n=rectangles.size();
        for(int i=0;i<n;i++){
            r[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        for(int i=0;i<101;i++){
            sort(r[i].begin(),r[i].end());
        }
        
        // 二分查找？
        int m=points.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            int x=points[i][0];
            int y=points[i][1];
            for(int k=y;k<=100;k++){
                int l=0,h=r[k].size()-1;
                while(l<=h){
                    int mi=(l+h)/2;
                    if(r[k][mi]<x){
                        l=mi+1;
                    }else{
                        h=mi-1;
                    }                    
                }
                ans[i]+=r[k].size()-l;
            }
            
        }
        return ans;
    }
};