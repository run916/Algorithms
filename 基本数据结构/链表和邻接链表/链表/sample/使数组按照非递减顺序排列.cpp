#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/steps-to-make-array-non-decreasing/

class Solution {
    public:
        int totalSteps(vector < int > & nums) {
            // 链表模拟？什么思路？
            // 用一个数组存储所有可能向右删除的点
            // 用一个链表存储剩余元素。

            // 添加哨兵
            nums.push_back(1e9 + 1);
            int n = nums.size();
            int list[n];
            vector < int > v;
            for (int i = n - 2; i >= 0; i--) {
                list[i] = i + 1;
                if (nums[i] > nums[i + 1]) {
                    v.push_back(i);
                }
            }
            int op = 0;
            bool vise[n];
            memset(vise, true, sizeof(vise));
            for (;; op++) {
                vector < int > a;
                for (int i = 0; i < v.size(); i++) {
                    if (vise[v[i]] && nums[v[i]] > nums[list[v[i]]]) {
                        vise[list[v[i]]] = false;
                        list[v[i]] = list[list[v[i]]];
                        a.push_back(v[i]);
                    }
                }
                if (a.size()) {
                    // swap函数用来压缩空间，也即实际上就是地址交换了
                    v.swap(a);
                } else {
                    break;
                }
            }
            return op;
        }
};