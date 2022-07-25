#include<bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-a-number-container-system/

class NumberContainers {
public:
    unordered_map<int,priority_queue<int>> hash;
    unordered_map<int,int> num;
    unordered_map<int,unordered_set<int>> vise;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(num.count(index)){
            vise[num[index]].erase(index);
        }
        num[index]=number;
        vise[number].insert(index);
        hash[number].push(-index);
        return;
    }
    
    int find(int number) {
        while(!hash[number].empty()){
            if(vise[number].count(-hash[number].top())==1){
                return -hash[number].top();
            }
            hash[number].pop();
        }
        // 循环内没找到对应数字的第一个下标，则返回-1.
        return -1;

    }
};