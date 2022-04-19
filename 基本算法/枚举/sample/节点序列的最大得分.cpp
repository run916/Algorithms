#include<bits/stdc++.h>
#include "c:\Users\windows\Desktop\Algorithm\Algorithms\std\input.h"
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        // 枚举
        int n=scores.size();
        vector<vector<pair<int,int>>> g(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            g[u].emplace_back(scores[v],v);
            g[v].emplace_back(scores[u],u);
        }
        for(int i=0;i<n;i++){
            sort(g[i].begin(),g[i].end(),[](pair<int,int> &a,pair<int,int> &b){
                return a.first>b.first;
            });
        }
        int ans=-1;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];

            // 组合
            int a=-1,b=-1;
            for(int k=0,j=0;k<2&&j<g[u].size();j++){
                if(g[u][j].second==v){
                    continue;
                }else{
                    a=b;
                    b=g[u][j].second;
                    k++;
                }
            }
            int c=-1,d=-1;
            for(int k=0,j=0;k<2&&j<g[v].size();j++){
                if(g[v][j].second==u){
                    continue;
                }else{
                    c=d;
                    d=g[v][j].second;
                    k++;
                }
            }
            // 不存在合理解
            if(b==-1||d==-1){
                continue;
            }
           
           // 存在可能的解 
            if(a>=0){
                if(c>=0){
                    if(a==c){
                        ans=max(ans,scores[u]+scores[v]+scores[a]+max(scores[b],scores[d]));
                    }else{
                        ans=max(ans,scores[u]+scores[v]+scores[a]+scores[c]);
                    }
                }else{
                    if(a==d){
                        ans=max(ans,scores[u]+scores[v]+scores[a]+scores[b]);
                    }else{
                        ans=max(ans,scores[u]+scores[v]+scores[a]+scores[d]);
                    }
                }
            }else{
                if(c>=0){
                    if(b==c){
                        ans=max(ans,scores[u]+scores[v]+scores[b]+scores[d]);
                    }else{
                        ans=max(ans,scores[u]+scores[v]+scores[b]+scores[c]);
                    }
                }else{
                    if(b!=d){
                        ans=max(ans,scores[u]+scores[v]+scores[b]+scores[d]);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin >> s;
    vector<int> scores = transfer(s);
    cin >> s;
    vector<vector<int>> edges = two_dimension(s);
    Solution solve;
    cout<<solve.maximumScore(scores, edges);
    return 0;
}