#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-a-food-rating-system/

class FoodRatings {
public:
    // 重载比较函数
    struct cmp{
        size_t operator () (const pair<int,string>& a,const pair<int,string>& b) const {
            if(a.first < b.first){
                return true;
            }else if(a.first==b.first){
                if(a.second>b.second){
                    return true;
                }
            }
            return false;
        }
    };    
    // 优先级队列
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>> hash;
    unordered_map<string,int> has;
    unordered_map<string,string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        hash.clear();
        has.clear();
        cui.clear();
        int n=foods.size();
        for(int i=0;i<n;i++){
            has[foods[i]]=ratings[i];
            hash[cuisines[i]].push({ratings[i],foods[i]});
            cui[foods[i]]=cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        has[food]=newRating;
        hash[cui[food]].push({newRating,food});
        return;
    }
    
    string highestRated(string cuisine) {
        // 惰性删除
        while(!hash[cuisine].empty()){
            if(has[hash[cuisine].top().second]!=hash[cuisine].top().first){
                hash[cuisine].pop();
            }else{
                break;
            }
        }
        return hash[cuisine].top().second;
    }
};