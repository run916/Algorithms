#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-a-food-rating-system/

class FoodRatings {
public:
    // 重载比较函数
    struct Data{
        int rate;
        string food;
        
        Data(int a,string s):rate(a),food(s){};
        bool operator < (const Data & a)const {
            if(rate<a.rate){
                return true;
            }else if(rate==a.rate){
                if(food>a.food){
                    return true;
                }
            }
            return false;
        }
    };    
    // 优先级队列
    unordered_map<string,priority_queue<Data>> hash;
    unordered_map<string,int> has;
    unordered_map<string,string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        hash.clear();
        has.clear();
        cui.clear();
        int n=foods.size();
        for(int i=0;i<n;i++){
            has[foods[i]]=ratings[i];
            Data mdata={ratings[i],foods[i]};
            // push 只能传入常量
            hash[cuisines[i]].push(mdata);
            cui[foods[i]]=cuisines[i];
        }
    }

    void changeRating(string food, int newRating) {
        has[food]=newRating;
        Data mdata={newRating,food};
        hash[cui[food]].push(mdata);
        return;
    }
    
    string highestRated(string cuisine) {
        // 惰性删除
        while(!hash[cuisine].empty()){
            if(has[hash[cuisine].top().food]!=hash[cuisine].top().rate){
                hash[cuisine].pop();
            }else{
                break;
            }
        }
        return hash[cuisine].top().food;
    }
};