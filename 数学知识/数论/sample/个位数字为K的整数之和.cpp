#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/

class Solution {
    public:
        int minimumNumbers(int num, int k) {
            // 数学
            if (num == 0) {
                return 0;
            }
            for (int i = 1; i <= 10; i++) {
                if (k * i % 10 == num % 10 && k * i <= num) {
                    return i;
                }
            }
            return -1;

        }
};