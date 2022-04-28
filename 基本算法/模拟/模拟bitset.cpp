#include<bits/stdc++.h>

using namespace std;

// https://leetcode-cn.com/problems/design-bitset/

class Bitset {
    public:
        Bitset(int size) {
            bit = vector < int > (size);
            n = size;
            num1 = 0;
        }

    void fix(int idx) {
        if (k) {
            if (bit[idx] == 1) {
                num1--;
                bit[idx] = 0;
            }
        } else {
            if (bit[idx] == 0) {
                num1++;
                bit[idx] = 1;
            }
        }

        return;
    }

    void unfix(int idx) {
        if (k) {
            if (bit[idx] == 0) {
                num1++;
                bit[idx] = 1;
            }
        } else {
            if (bit[idx] == 1) {
                num1--;
                bit[idx] = 0;
            }
        }
        return;
    }

    void flip() {
        k ^= 1;
        return;
    }

    bool all() {
        // 首先判断是否需要反转
        if (k) {
            if (num1 == 0) return true;
            else return false;
        } else {
            if (num1 == n) return true;
            else return false;
        }

    }

    bool one() {
        if (k) {
            if (n - num1 > 0) return true;
            else return false;
        } else {
            if (num1 > 0) return true;
            else return false;
        }

    }

    int count() {
        if (k) {
            return n - num1;
        } else {
            return num1;
        }
    }

    string toString() {
        if (k) {
            for (int i = 0; i < n; i++) {
                bit[i] ^= 1;
            }
            num1 = n - num1;
            k = 0;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (bit[i] == 0) {
                ans += "0";
            } else {
                ans += "1";
            }
        }
        return ans;
    }
    private:
        vector < int > bit;
    int n;
    int num1;
    int k = 0;
};