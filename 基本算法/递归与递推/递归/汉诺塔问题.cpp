// https://leetcode-cn.com/problems/hanota-lcci/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        void dfs(int n, stack < int > & a, stack < int > & b, stack < int > & c) {
            if (n == 0) {
                return;
            } else {
                dfs(n - 1, a, c, b);
                c.push(a.top());
                a.pop();
                dfs(n - 1, b, a, c);
            }
            return;
        }
    void hanota(vector < int > & A, vector < int > & B, vector < int > & C) {
        int n = A.size();
        stack < int > a, b, c;
        for (int i = 0; i < n; i++) {
            a.push(A[i]);
        }
        dfs(n, a, b, c);
        while (!c.empty()) {
            C.push_back(c.top());
            c.pop();
        }
        reverse(C.begin(), C.end());
        return;
    }
};